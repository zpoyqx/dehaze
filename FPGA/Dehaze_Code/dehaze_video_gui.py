import PySide2.QtCore
import cv2 as cv
import numpy as np
import time
import PySide2
from PySide2.QtWidgets import *
from PySide2.QtUiTools import *
from PySide2.QtGui import *

class Display:
    def __init__(self):
        self.ui = QUiLoader().load(r'haze_video.ui')

    def update_haze(self,pix_haze):
        self.ui.haze.setPixmap(pix_haze)

    def update_dehaze(self,pix_dehaze):
        self.ui.dehaze.setPixmap(pix_dehaze)

class Dehaze:
    def __init__(self):
        self.ui = QUiLoader().load(r'haze_video.ui')
        self.flag = 1
        self.ui.button_start.clicked.connect(self.run)
        self.ui.button_continue.clicked.connect(self.video_continue)
        self.ui.button_pause.clicked.connect(self.video_pause)
        self.video = cv.VideoCapture('..\\haze_image\\haze.mp4')
        self.height, self.width = int(self.video.get(cv.CAP_PROP_FRAME_HEIGHT)), int(self.video.get(cv.CAP_PROP_FRAME_WIDTH))
        self.total_time = 0
        self.frame_num = 1
        self.A = []

        self.display = Display()
        self.display_haze_signal = PySide2.QtCore.Signal(QImage)
        self.display_haze_signal.
        self.display_dehaze_signal = PySide2.QtCore.Signal(QImage)
        self.display_dehaze_signal.connect(self.display.update_dehaze)

        # 一开始用空白填充
        tmp = np.zeros((self.height,self.width,3),np.uint8)
        tmp.fill(255)
        white = QPixmap.fromImage(QImage(tmp, self.width, self.height, QImage.Format_BGR888))
        self.ui.haze.setPixmap(white)
        self.ui.dehaze.setPixmap(white)

    def __del__(self):
        self.video.release()

    def video_pause(self):
        self.flag = 0

    def video_continue(self):
        self.flag = 1

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
        
    def main(self,I):
        start = time.time()
        hsv = cv.cvtColor(I,cv.COLOR_BGR2HSV) # 创建HSV图
        h,chroma,value = cv.split(hsv)
        dP = 0.121779+0.959710*value-0.780245*chroma

        dP = dP / 255
        d_ref = np.exp(-dP)
        d_ref = np.clip(d_ref,0.1,1)
        self.AirlightEstimate(I)
        I_single_channel_list = cv.split(I)
        result = [(I_single_channel_list[i] - self.A[i]) / d_ref + self.A[i] for i in range(3)]
        dst = cv.merge((result[2],result[1],result[0]))
        dst /= 255
        dst = np.abs(dst)
        dst = np.clip(dst,0.1,1)
        dst *= 255
        dst = dst.astype(np.uint8)
        end = time.time()

        self.total_time += round(end - start, 3)
        self.A = []

        haze_image = QImage(I, self.width, self.height, QImage.Format_BGR888)
        dehaze_image = QImage(dst, self.width, self.height, QImage.Format_RGB888)
        pix_haze = QPixmap.fromImage(haze_image)
        pix_dehaze = QPixmap.fromImage(dehaze_image)
        self.display_haze_signal.emit(pix_haze)
        self.display_dehaze_signal.emit(pix_dehaze)

    def run(self):
        try:
            bol,frame = self.video.read()
            while bol:
                if self.flag and bol:
                    self.main(frame)
                    self.ui.lineEdit.setText(str(round(self.frame_num/self.total_time,3)))
                    self.frame_num += 1
                    bol,frame = self.video.read()
        except Exception as reason:
            print(reason)
            self.ui.lineEdit.setText('error')
            self.video.release()

if __name__ == '__main__':
    app = QApplication([])
    dehaze = Dehaze()
    dehaze.ui.show()
    app.exec_()

