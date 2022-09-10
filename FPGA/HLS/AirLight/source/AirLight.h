#ifndef _AIRLIGHT_H_
#define _AIRLIGHT_H_

#include "ap_int.h"
#include "hls_video.h"
#include "hls_stream.h"

//typedef unsigned char uchar;
typedef ap_axiu<8,1,1,1> Pixel;
typedef hls::stream< ap_axiu<8,1,1,1> > Stream;

void AirLight(Stream& src, int& B_A, int& G_A, int& R_A);

#endif
