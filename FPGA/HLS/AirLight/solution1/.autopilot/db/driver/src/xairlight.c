// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xairlight.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XAirlight_CfgInitialize(XAirlight *InstancePtr, XAirlight_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XAirlight_Start(XAirlight *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAirlight_ReadReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_AP_CTRL) & 0x80;
    XAirlight_WriteReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XAirlight_IsDone(XAirlight *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAirlight_ReadReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XAirlight_IsIdle(XAirlight *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAirlight_ReadReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XAirlight_IsReady(XAirlight *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAirlight_ReadReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XAirlight_EnableAutoRestart(XAirlight *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAirlight_WriteReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XAirlight_DisableAutoRestart(XAirlight *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAirlight_WriteReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_AP_CTRL, 0);
}

void XAirlight_InterruptGlobalEnable(XAirlight *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAirlight_WriteReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_GIE, 1);
}

void XAirlight_InterruptGlobalDisable(XAirlight *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAirlight_WriteReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_GIE, 0);
}

void XAirlight_InterruptEnable(XAirlight *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAirlight_ReadReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_IER);
    XAirlight_WriteReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_IER, Register | Mask);
}

void XAirlight_InterruptDisable(XAirlight *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAirlight_ReadReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_IER);
    XAirlight_WriteReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_IER, Register & (~Mask));
}

void XAirlight_InterruptClear(XAirlight *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAirlight_WriteReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_ISR, Mask);
}

u32 XAirlight_InterruptGetEnabled(XAirlight *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAirlight_ReadReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_IER);
}

u32 XAirlight_InterruptGetStatus(XAirlight *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAirlight_ReadReg(InstancePtr->Control_BaseAddress, XAIRLIGHT_CONTROL_ADDR_ISR);
}

