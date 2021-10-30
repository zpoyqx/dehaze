clear;
path = "4.jpg";
I = imread(path);
gray = rgb2gray(I);
[h,w,~] = size(I);
%% CAP part
hsv = rgb2hsv(I);
chroma = hsv(:,:,2);
value = hsv(:,:,3);
sigmaMat = normrnd(0, 0.041337, h, w);
dP = 0.121779+0.959710*value-0.780245*chroma+sigmaMat;
%figure;imshow(dP)
hh = ceil(h/3);              % downsample window size 5 in original paper
ww = ceil(w/3);
dds = zeros(hh,ww);
for i=1:hh
    for j=1:ww
        dds(i,j) = min(min(dP(3*i-2:min(3*i,h),3*j-2:min(3*j,w))));
    end
end
% dr_ds = ordfilt2(dds,1,ones(3,3),'symmetric');             %minfilter in original paper
d_la = imresize(dds,[h w],'nearest');
% gray = imfilter(gray,fspecial('average',[10,10]));         %bigger window, better details
gray = double(gray);
d_ref_orig = guidedfilter(imresize(gray,[270 480],'bilinear')/255.0, imresize(d_la,[270 480],'nearest'), 6, 0.0001);
% d_ref_orig = guidedfilter(gray/255.0, d_la, 48, 0.0001);   %original paramtres
d_ref = imresize(d_ref_orig,[h w],'bilinear');
atmosphere = AirlightEstimate(imresize(double(I),[270 480],'nearest'));
trans_guided = min(max(exp(-double(d_ref)),0.1),1);
% figure;imshow(trans_guided);
I = double(I);
result(:,:,1) = (I(:,:,1) - atmosphere(1))./trans_guided + atmosphere(1);
result(:,:,2) = (I(:,:,2) - atmosphere(2))./trans_guided + atmosphere(2);
result(:,:,3) = (I(:,:,3) - atmosphere(3))./trans_guided + atmosphere(3);
subplot(211);imshow(path);
subplot(212);imshow(result/255);
% imwrite(result/255,"result1.jpeg","jpeg");