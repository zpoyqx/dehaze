import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
import time

def cv_imshow(img):
    cv.imshow('result',img)
    cv.waitKey(0)  # 按任意键继续执行，可以自定义设置时间，单位毫秒
    cv.destroyAllWindows()

def AirlightEstimate(img):
    im = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
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
        max_index = np.argmax(scorelist)
        im,img = imlist[0][max_index],imlist[1][max_index]
        imlist = [[],[]]
    img_single_channel_list = cv.split(img)
    for channel in img_single_channel_list:
        A.append(np.mean(channel))

start = time.time()
imglist = ['1.jpeg','2.jpeg','3.jpeg','4.jpg','5.png','6.png']
path = '..\\haze_image\\'+imglist[0]
A= []
I = cv.imread(path)
height,width = I.shape[0],I.shape[1]
thresh = height*width*0.05
# ---------------------
##hsv = cv.cvtColor(I,cv.COLOR_BGR2HSV) 
##h,chroma,value = cv.split(hsv)
##dP = 0.121779+0.959710*value-0.780245*chroma
##dP = dP / 255
##d_ref = np.exp(-dP)
##d_ref = np.clip(d_ref,0.1,1)
d_ref = np.zeros((height,width))
for w in range(width):
   for h in range(height):
       pixel = I[h,w]
       B,G,R = [pixel[0], pixel[1], pixel[2]]
       c_max = max(B, G, R) / 255.0
       c_min = min(B, G, R) / 255.0
       P = 0.121779 + 0.959710 * c_max - 0.780245 * ((c_max - c_min) / c_max)
       P = np.exp(-P)
       P = max(0.1,P)
       P = min(1,P)
       d_ref[h,w] = P
       
# ----------------------
##AirlightEstimate(I)
B,G,R = cv.split(I)
dict_B = {}
dict_G = {}
dict_R = {}
total,total_w = 0,0
for i in range(0,256):
    dict_B[i] = 0
    dict_G[i] = 0
    dict_R[i] = 0
for w in range(width):
   for h in range(height):
       dict_B[B[h,w]] += 1
       dict_G[G[h,w]] += 1
       dict_R[R[h,w]] += 1
for i in range(255,0,-1):
    total += dict_B[i]
    if total >= thresh:
        for pix in range(i,256):
            total_w += pix * dict_B[pix]
        A.append(int(total_w / total))
        total,total_w = 0,0
        break
for i in range(255,0,-1):
    total += dict_G[i]
    if total >= thresh:
        for pix in range(i,256):
            total_w += pix * dict_G[pix]
        A.append(int(total_w / total))
        total,total_w = 0,0
        break
for i in range(255,0,-1):
    total += dict_R[i]
    if total >= thresh:
        for pix in range(i,256):
            total_w += pix * dict_R[pix]
        A.append(int(total_w / total))
        break
# ----------------------
I = I.astype(np.int16)
I_single_channel_list = cv.split(I)
result = [(I_single_channel_list[i] - A[i]) / d_ref + A[i] for i in range(3)]
end = time.time()
print("总运行时间：%.3f秒" % (end-start))
dst = cv.merge((result[2],result[1],result[0]))
dst /= 255
plt.imshow(dst)
plt.show()
##cv_imshow(dst/255)
##cv.imwrite('result\\result_'+path,dst)

