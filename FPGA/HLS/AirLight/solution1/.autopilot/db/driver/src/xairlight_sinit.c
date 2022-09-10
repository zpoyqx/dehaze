// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xairlight.h"

extern XAirlight_Config XAirlight_ConfigTable[];

XAirlight_Config *XAirlight_LookupConfig(u16 DeviceId) {
	XAirlight_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XAIRLIGHT_NUM_INSTANCES; Index++) {
		if (XAirlight_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XAirlight_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XAirlight_Initialize(XAirlight *InstancePtr, u16 DeviceId) {
	XAirlight_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XAirlight_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XAirlight_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

