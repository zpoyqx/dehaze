// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XAIRLIGHT_H
#define XAIRLIGHT_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xairlight_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XAirlight_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XAirlight;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XAirlight_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XAirlight_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XAirlight_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XAirlight_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XAirlight_Initialize(XAirlight *InstancePtr, u16 DeviceId);
XAirlight_Config* XAirlight_LookupConfig(u16 DeviceId);
int XAirlight_CfgInitialize(XAirlight *InstancePtr, XAirlight_Config *ConfigPtr);
#else
int XAirlight_Initialize(XAirlight *InstancePtr, const char* InstanceName);
int XAirlight_Release(XAirlight *InstancePtr);
#endif

void XAirlight_Start(XAirlight *InstancePtr);
u32 XAirlight_IsDone(XAirlight *InstancePtr);
u32 XAirlight_IsIdle(XAirlight *InstancePtr);
u32 XAirlight_IsReady(XAirlight *InstancePtr);
void XAirlight_EnableAutoRestart(XAirlight *InstancePtr);
void XAirlight_DisableAutoRestart(XAirlight *InstancePtr);


void XAirlight_InterruptGlobalEnable(XAirlight *InstancePtr);
void XAirlight_InterruptGlobalDisable(XAirlight *InstancePtr);
void XAirlight_InterruptEnable(XAirlight *InstancePtr, u32 Mask);
void XAirlight_InterruptDisable(XAirlight *InstancePtr, u32 Mask);
void XAirlight_InterruptClear(XAirlight *InstancePtr, u32 Mask);
u32 XAirlight_InterruptGetEnabled(XAirlight *InstancePtr);
u32 XAirlight_InterruptGetStatus(XAirlight *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
