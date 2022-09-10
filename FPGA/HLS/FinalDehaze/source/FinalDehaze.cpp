#include "FinalDehaze.h"

void FinalDehaze(Stream& src, int& B_A, int& G_A, int& R_A, Stream& dst){
#pragma HLS INTERFACE axis port=src register
#pragma HLS INTERFACE ap_none port=B_A register
#pragma HLS INTERFACE ap_none port=G_A register
#pragma HLS INTERFACE ap_none port=R_A register
#pragma HLS INTERFACE axis port=dst register
#pragma HLS INTERFACE s_axilite port=return

	double c_max,c_min,B,G,R,P;
	Pixel pixInB,pixInG,pixInR,pixOut;
	int num;
	do {
#pragma HLS PIPELINE II=3
		//read pixel b,g,r
		pixInB = src.read();
		B = pixInB.data / 255.0;
		pixInG = src.read();
		G = pixInG.data / 255.0;
		pixInR = src.read();
		R = pixInR.data / 255.0;
		//calculate d_ref--P
		c_max = B > G ? B : G;
		c_max = c_max > R ? c_max : R;
		c_min = B < G ? B : G;
		c_min = c_max < R ? c_max : R;
		P = 0.121779 + 0.959710 * c_max - 0.780245 * ((c_max - c_min) / c_max);
		P = hls::exp(-P);
		P = P > 0.1 ? P : 0.1;
		P = P < 1 ? P : 1;
		//calculate dehaze pixel b
		num = (pixInB.data - B_A) / P + B_A;
		num = num < 0 ? -num : num;
		num = num > 255 ? 255 : num;
		pixOut.data = (ap_uint<8>)(num);
		pixOut.keep = pixInB.keep;
		pixOut.strb = pixInB.strb;
		pixOut.user = pixInB.user;
		pixOut.dest = pixInB.dest;
		pixOut.last = pixInB.last;
		dst.write(pixOut);
		//calculate dehaze pixel g
		num = (pixInG.data - G_A) / P + G_A;
		num = num < 0 ? -num : num;
		num = num > 255 ? 255 : num;
		pixOut.data = (ap_uint<8>)(num);
		pixOut.keep = pixInG.keep;
		pixOut.strb = pixInG.strb;
		pixOut.user = pixInG.user;
		pixOut.dest = pixInG.dest;
		pixOut.last = pixInG.last;
		dst.write(pixOut);
		//calculate dehaze pixel r
		num = (pixInR.data - R_A) / P + R_A;
		num = num < 0 ? -num : num;
		num = num > 255 ? 255 : num;
		pixOut.data = (ap_uint<8>)(num);
		pixOut.keep = pixInR.keep;
		pixOut.strb = pixInR.strb;
		pixOut.user = pixInR.user;
		pixOut.dest = pixInR.dest;
		pixOut.last = pixInR.last;
		dst.write(pixOut);
	} while(pixInR.last == 0);
}
