// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xfinaldehaze.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XFinaldehaze_CfgInitialize(XFinaldehaze *InstancePtr, XFinaldehaze_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XFinaldehaze_Start(XFinaldehaze *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFinaldehaze_ReadReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XFinaldehaze_WriteReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XFinaldehaze_IsDone(XFinaldehaze *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFinaldehaze_ReadReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XFinaldehaze_IsIdle(XFinaldehaze *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFinaldehaze_ReadReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XFinaldehaze_IsReady(XFinaldehaze *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFinaldehaze_ReadReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XFinaldehaze_EnableAutoRestart(XFinaldehaze *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFinaldehaze_WriteReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XFinaldehaze_DisableAutoRestart(XFinaldehaze *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFinaldehaze_WriteReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_AP_CTRL, 0);
}

void XFinaldehaze_InterruptGlobalEnable(XFinaldehaze *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFinaldehaze_WriteReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_GIE, 1);
}

void XFinaldehaze_InterruptGlobalDisable(XFinaldehaze *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFinaldehaze_WriteReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_GIE, 0);
}

void XFinaldehaze_InterruptEnable(XFinaldehaze *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XFinaldehaze_ReadReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_IER);
    XFinaldehaze_WriteReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_IER, Register | Mask);
}

void XFinaldehaze_InterruptDisable(XFinaldehaze *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XFinaldehaze_ReadReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_IER);
    XFinaldehaze_WriteReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_IER, Register & (~Mask));
}

void XFinaldehaze_InterruptClear(XFinaldehaze *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFinaldehaze_WriteReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_ISR, Mask);
}

u32 XFinaldehaze_InterruptGetEnabled(XFinaldehaze *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XFinaldehaze_ReadReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_IER);
}

u32 XFinaldehaze_InterruptGetStatus(XFinaldehaze *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XFinaldehaze_ReadReg(InstancePtr->Control_BaseAddress, XFINALDEHAZE_CONTROL_ADDR_ISR);
}

