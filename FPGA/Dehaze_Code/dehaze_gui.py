import cv2 as cv
import numpy as np
import time
from PySide2.QtWidgets import *
from PySide2.QtUiTools import *
from PySide2.QtGui import *

class Dehaze():
    def __init__(self):
        self.ui = QUiLoader().load(r'haze.ui')
        self.ui.button_up.clicked.connect(self.s_up)
        self.ui.button_down.clicked.connect(self.s_down)
        self.ui.button_process.clicked.connect(self.main)
        self.imglist = ['1.jpeg','2.jpeg','3.jpeg','4.png','5.png']
        self.path = '..\\haze_image\\'
        self.index = 0
        self.A = []
        self.display()

    def s_up(self):
        if self.index == 0:
            self.index = len(self.imglist) - 1
        else:
            self.index -= 1
        self.display()

    def s_down(self):
        if self.index == len(self.imglist) - 1:
            self.index = 0
        else:
            self.index += 1
        self.display()

    def display(self):
        self.I = cv.imread(self.path + self.imglist[self.index])
        height, width = self.I.shape[0], self.I.shape[1]
        haze_image = QImage(self.I, width, height, QImage.Format_BGR888)
        pix_img = QPixmap.fromImage(haze_image)
        self.ui.haze.setPixmap(pix_img)
        tmp = np.zeros((height, width, 3), np.uint8)
        tmp.fill(255)
        white = QPixmap.fromImage(QImage(tmp, width, height, QImage.Format_BGR888))
        self.ui.dehaze.setPixmap(white)

    def AirlightEstimate(self,img):
        im = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
        imlist = [[],[]]
        for times in range(5):
            h,w = im.shape[0],im.shape[1]
            imlist[0].append(im[0:int(h / 2), 0:int(w / 2)])
            imlist[0].append(im[0:int(h / 2), int(w / 2):w])
            imlist[0].append(im[int(h / 2):h, 0:int(h / 2)])
            imlist[0].append(im[int(h / 2):h, int(w / 2):w])
            imlist[1].append(img[0:int(h / 2), 0:int(w / 2)])
            imlist[1].append(img[0:int(h / 2), int(w / 2):w])
            imlist[1].append(img[int(h / 2):h, 0:int(h / 2)])
            imlist[1].append(img[int(h / 2):h, int(w / 2):w])
            scorelist = [np.mean(i) for i in imlist[0]]
            max_index = np.argmax(scorelist)
            im,img = imlist[0][max_index],imlist[1][max_index]
            imlist = [[],[]]
        img_single_channel_list = cv.split(img)
        for channel in img_single_channel_list:
            self.A.append(np.mean(channel))

    def Guidedfilter(self,im,p,r,eps):
        start = time.time()
        mean_I = cv.boxFilter(im,cv.CV_64F,(r,r))
        mean_p = cv.boxFilter(p, cv.CV_64F,(r,r))
        mean_Ip = cv.boxFilter(im*p,cv.CV_64F,(r,r))
        cov_Ip = mean_Ip - mean_I*mean_p

        mean_II = cv.boxFilter(im*im,cv.CV_64F,(r,r))
        var_I   = mean_II - mean_I*mean_I

        a = cov_Ip/(var_I + eps)
        b = mean_p - a*mean_I

        mean_a = cv.boxFilter(a,cv.CV_64F,(r,r))
        mean_b = cv.boxFilter(b,cv.CV_64F,(r,r))

        q = mean_a*im + mean_b
        end = time.time()
        print("Guidedfilter运行时间：%.3f秒" % (end-start))
        return q

    def main(self):
        start = time.time()
        hsv = cv.cvtColor(self.I,cv.COLOR_BGR2HSV) # 创建HSV图
        h,chroma,value = cv.split(hsv)
        dP = 0.121779+0.959710*value-0.780245*chroma

        dP = dP / 255
        d_ref = np.exp(-dP)
        d_ref = np.clip(d_ref,0.1,1)
        self.AirlightEstimate(self.I)
        I_single_channel_list = cv.split(self.I)
        result = [(I_single_channel_list[i] - self.A[i]) / d_ref + self.A[i] for i in range(3)]
        dst = cv.merge((result[2],result[1],result[0]))
        dst /= 255
        dst = np.abs(dst)
        dst = np.clip(dst,0.1,1)
        dst *= 255
        dst = dst.astype(np.uint8)
        end = time.time()

        self.A = []
        self.ui.lineEdit.setText(str(round(end-start,3))+'s')
        height, width = self.I.shape[0], self.I.shape[1]
        dehaze_image = QImage(dst, width, height, QImage.Format_RGB888)
        pix_img = QPixmap.fromImage(dehaze_image)
        self.ui.dehaze.setPixmap(pix_img)

if __name__ == '__main__':
    time.sleep(1)
    app = QApplication([])
    dehaze = Dehaze()
    dehaze.ui.show()
    app.exec_()

