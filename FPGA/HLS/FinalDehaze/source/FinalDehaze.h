#ifndef _FINALDEHAZE_H_
#define _FINALDEHAZE_H_

#include "ap_int.h"
#include "hls_video.h"
#include "hls_stream.h"

typedef ap_axiu<8,1,1,1> Pixel;
typedef hls::stream< ap_axiu<8,1,1,1> > Stream;

void FinalDehaze(Stream& src, int& B_A, int& G_A, int& R_A, Stream& dst);

#endif
