import cv2 as cv
import numpy as np

def AirlightEstimate(img):
    im = cv.cvtColor(I,cv.COLOR_BGR2GRAY)
    imlist = [[],[]]
    for times in range(5):
        h,w = im.shape[0],im.shape[1]
        imlist[0].append(im[0:int(h/2),0:int(w/2)])
        imlist[0].append(im[0:int(h/2),int(w/2):w])
        imlist[0].append(im[int(h/2):h,0:int(h/2)])
        imlist[0].append(im[int(h/2):h,int(w/2):w])
        imlist[1].append(img[0:int(h/2),0:int(w/2)])
        imlist[1].append(img[0:int(h/2),int(w/2):w])
        imlist[1].append(img[int(h/2):h,0:int(h/2)])
        imlist[1].append(img[int(h/2):h,int(w/2):w])
        scorelist = [np.mean(i) for i in imlist[0]]
        print(scorelist)
        max_index = np.argmax(scorelist)
        im,img = imlist[0][max_index],imlist[1][max_index]
        imlist = [[],[]]
    img_single_channel_list = cv.split(img)
    for channel in img_single_channel_list:
        A.append(np.mean(channel))

I = cv.imread('..\\haze_image\\4.png')
A = []
##img = I[127:142,420:435]
##img_single_channel_list = cv.split(img)
##for channel in img_single_channel_list:
##    A.append(np.mean(channel))
AirlightEstimate(I)
print(A)
