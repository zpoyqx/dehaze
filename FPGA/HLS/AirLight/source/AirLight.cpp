#include "AirLight.h"

void AirLight(Stream& src, int& B_A, int& G_A, int& R_A){
#pragma HLS INTERFACE axis port=src register
#pragma HLS INTERFACE ap_vld port=B_A register
#pragma HLS INTERFACE ap_vld port=G_A register
#pragma HLS INTERFACE ap_vld port=R_A register
#pragma HLS INTERFACE s_axilite port=return

	Pixel pixIn, pixOut;
	int dictB[256] = {0};
	int dictG[256] = {0};
	int dictR[256] = {0};
	int totalB = 0, totalB_w = 0, totalG = 0, totalG_w = 0, totalR = 0, totalR_w = 0, size = 0;

	do {
#pragma HLS PIPELINE II=3
		size++;
		pixIn = src.read();
		dictB[pixIn.data]++;
		pixIn = src.read();
		dictG[pixIn.data]++;
		pixIn = src.read();
		dictR[pixIn.data]++;
	} while(pixIn.last == 0);

    int thresh = size * 0.05;

	for(int i = 255; i >= 0; i--)
	{
#pragma HLS PIPELINE II=3
		totalB += dictB[i];
		if (totalB > thresh){
			for (int j = i; j <= 255; j++)
				totalB_w += j * dictB[j];
			B_A = totalB_w / totalB;
			break;
		}
	}
	for(int i = 255; i >= 0; i--)
	{
#pragma HLS PIPELINE II=3
		totalG += dictG[i];
		if (totalG > thresh){
			for (int j = i; j <= 255; j++)
				totalG_w += j * dictG[j];
			G_A = totalG_w / totalG;
			break;
		}
	}
	for(int i = 255; i >= 0; i--)
	{
#pragma HLS PIPELINE II=3
		totalR += dictR[i];
		if (totalR > thresh){
			for (int j = i; j <= 255; j++)
				totalR_w += j * dictR[j];
			R_A = totalR_w / totalR;
			break;
		}
	}
}
