#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

//void MinFilter(Mat& src_image, Mat& dst_image, int k_size = 3) {
//    dst_image = Mat::zeros(src_image.size(), src_image.type());
//    int max_rows = src_image.rows;          // 行像素数
//    int max_cols = src_image.cols;          // 列像素数
//    int channels = src_image.channels();    // 图片是几通道的
//
//    int p = (k_size - 1) / 2;               // -(k−1)/2 ~ (k−1)/2
//
//    int mint;                         // 初始最大值
//
//    // 对每个像素点进行处理
//    for (int row = 0; row < max_rows; ++row) {
//        for (int col = 0; col < max_cols; ++col) {
//            // 1通道，灰度值
//            if (channels == 1) {
//                mint = 255;
//                // 以当前像素点为中心的k*k的矩阵中，取最小值
//                for (int i = row - p; i <= row + p; ++i)
//                    for (int j = col - p; j <= col + p; ++j)
//                        if (i >= 0 && i < max_rows && j >= 0 && j < max_cols)
//                            if (src_image.at<double>(i, j) < mint)
//                                mint = src_image.at<double>(i, j);
//
//                dst_image.at<double>(row, col) = mint;   // 像素值赋最小值    
//            }
//        }
//    }
//}

void mul(Mat& A, Mat& B, Mat& dst)
{
    dst = Mat::zeros(A.size(), A.type());
    for (int row = 0; row < A.rows; row++)
    {
        for (int col = 0; col < A.cols; col++)
        {
            dst.at<double>(row, col) = A.at<double>(row, col) * B.at<double>(row, col);
        }
    }
}

void guidedFilter(Mat& I, Mat& p, Mat& q, Size kernel, double eps)
{
    //TODO:运算错误；I和p大小可能不一样!
    //Mat N = Mat::ones(I.size(), I.type());
    Mat mean_I, mean_p, mean_Ip, cov_Ip, mean_II, var_I, a, b, mean_a, mean_b, tmp;

    boxFilter(I,mean_I,-1,kernel);
    boxFilter(p,mean_p,-1,kernel);
    mul(I, p, tmp);
    boxFilter(tmp,mean_Ip,-1,kernel);
    multiply(mean_I, mean_p, tmp);
    cov_Ip = mean_Ip - tmp;

    mul(I, I, tmp);
    boxFilter(tmp, mean_II, -1, kernel);
    mul(mean_I, mean_I, tmp);
    var_I = mean_II - tmp;

    a = cov_Ip / (var_I + eps);
    mul(a, mean_I, tmp);
    b = mean_p - tmp;

    boxFilter(a, mean_a, -1, kernel);
    boxFilter(b, mean_b, -1, kernel);

    mul(I, mean_a, tmp);
    q = tmp + mean_b;
}

void AirlightEstimate(Mat& I, double A[])
{
    Mat im, im1, im2, im3, im4, img;
    Rect rect1, rect2, rect3, rect4;
    int w, h, max_index;
    double scores[4];
    double max_score;
    vector<Mat> mv;

    img = I.clone();
    cvtColor(img, im, COLOR_BGR2GRAY);
    img.convertTo(img, CV_64FC3);

    for (int times = 0; times <= 5; times++)
    {
        w = im.cols;
        h = im.rows;
        
        rect1 = Rect(Point(0, 0), Point(w / 2, h / 2));
        rect2 = Rect(Point(w / 2, 0), Point(w, h / 2));
        rect3 = Rect(Point(0, h / 2), Point(w / 2, h));
        rect4 = Rect(Point(w / 2, h / 2), Point(w, h));
        im1 = im(rect1);
        im2 = im(rect2);
        im3 = im(rect3);
        im4 = im(rect4);
        scores[0] = mean(im1)[0];
        scores[1] = mean(im2)[0];
        scores[2] = mean(im3)[0];
        scores[3] = mean(im4)[0];
        max_score = scores[0];
        max_index = 0;
        for (int i = 1; i < 4; i++)
        {
            if (max_score < scores[i])
            {
                max_index = i;
                max_score = scores[i];
            }
        }
        if (max_index == 0)
        {
            im = im1;
            img = img(rect1);
        }
        else if (max_index == 1)
        {
            im = im2;
            img = img(rect2);
        }
        else if (max_index == 2)
        {
            im = im3;
            img = img(rect3);
        }
        else
        {
            im = im4;
            img = img(rect4);
        }
    }
    split(img, mv);
    A[0] = mean(mv[0])[0];
    A[1] = mean(mv[1])[0];
    A[2] = mean(mv[2])[0];
    cout << A[0] << ' ' << A[1] << ' ' << A[2];
}

int main()
{
    string path = "1.jpeg";
    Mat I = imread(path);
    Mat gray, hsv, chroma, value, dP, dds, d_la, d_ref, dst;
    vector<Mat> mv, result;
    double A[3];
    int w = I.cols;
    int h = I.rows;

    cvtColor(I, gray, COLOR_BGR2GRAY);
    cvtColor(I, hsv, COLOR_BGR2HSV);
    split(hsv, mv);
    chroma = mv[1];
    value = mv[2];
    chroma.convertTo(chroma, CV_64FC1);
    value.convertTo(value, CV_64FC1);
    addWeighted(chroma, -0.780245, value, 0.959710, 0.121779, dP);

    //MinFilter(dP, dds);
    dds = dP.clone();
    gray.convertTo(gray,CV_64FC1);
    gray /= 255.0;
    dds /= 255.0;
    guidedFilter(gray, dds, d_ref, Size(48, 48), 0.0001);
    for (int row = 0; row < d_ref.rows; row++)
    {
        for (int col = 0; col < d_ref.cols; col++)
        {
            d_ref.at<double>(row, col) = exp(-d_ref.at<double>(row, col));
            if (d_ref.at<double>(row, col) < 0.1)
                d_ref.at<double>(row, col) = 0.1;
            else if (d_ref.at<double>(row, col) > 1)
                d_ref.at<double>(row, col) = 1;
        }
    }

    AirlightEstimate(I, A);
    I.convertTo(I, CV_64FC3);
    split(I, mv);
    for (int i = 0; i < 3; i++)
    {
        result.push_back((mv[i] - A[i]) / d_ref + A[i]);
    }
    merge(result, dst);

    dst.convertTo(dst, CV_8UC3);
    namedWindow("result", WINDOW_AUTOSIZE);
    imshow("result", dst);
    //imwrite("result.jpeg", dst);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
