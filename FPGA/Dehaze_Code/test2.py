import cv2 as cv
import numpy as np

def Guidedfilter(im,p,r,eps):
    mean_I = cv.boxFilter(im,cv.CV_64F,(r,r));
    mean_p = cv.boxFilter(p, cv.CV_64F,(r,r));
    mean_Ip = cv.boxFilter(im*p,cv.CV_64F,(r,r));
    cov_Ip = mean_Ip - mean_I*mean_p;

    mean_II = cv.boxFilter(im*im,cv.CV_64F,(r,r));
    var_I   = mean_II - mean_I*mean_I;

    a = cov_Ip/(var_I + eps);
    b = mean_p - a*mean_I;

    mean_a = cv.boxFilter(a,cv.CV_64F,(r,r));
    mean_b = cv.boxFilter(b,cv.CV_64F,(r,r));

    q = mean_a*im + mean_b;
    return q;
