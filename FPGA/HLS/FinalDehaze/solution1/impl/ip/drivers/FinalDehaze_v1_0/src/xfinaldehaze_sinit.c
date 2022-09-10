// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xfinaldehaze.h"

extern XFinaldehaze_Config XFinaldehaze_ConfigTable[];

XFinaldehaze_Config *XFinaldehaze_LookupConfig(u16 DeviceId) {
	XFinaldehaze_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XFINALDEHAZE_NUM_INSTANCES; Index++) {
		if (XFinaldehaze_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XFinaldehaze_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XFinaldehaze_Initialize(XFinaldehaze *InstancePtr, u16 DeviceId) {
	XFinaldehaze_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XFinaldehaze_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XFinaldehaze_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

