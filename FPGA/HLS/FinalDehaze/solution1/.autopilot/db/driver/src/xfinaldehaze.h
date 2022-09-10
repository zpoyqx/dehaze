// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XFINALDEHAZE_H
#define XFINALDEHAZE_H

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
#include "xfinaldehaze_hw.h"

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
} XFinaldehaze_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XFinaldehaze;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XFinaldehaze_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XFinaldehaze_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XFinaldehaze_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XFinaldehaze_ReadReg(BaseAddress, RegOffset) \
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
int XFinaldehaze_Initialize(XFinaldehaze *InstancePtr, u16 DeviceId);
XFinaldehaze_Config* XFinaldehaze_LookupConfig(u16 DeviceId);
int XFinaldehaze_CfgInitialize(XFinaldehaze *InstancePtr, XFinaldehaze_Config *ConfigPtr);
#else
int XFinaldehaze_Initialize(XFinaldehaze *InstancePtr, const char* InstanceName);
int XFinaldehaze_Release(XFinaldehaze *InstancePtr);
#endif

void XFinaldehaze_Start(XFinaldehaze *InstancePtr);
u32 XFinaldehaze_IsDone(XFinaldehaze *InstancePtr);
u32 XFinaldehaze_IsIdle(XFinaldehaze *InstancePtr);
u32 XFinaldehaze_IsReady(XFinaldehaze *InstancePtr);
void XFinaldehaze_EnableAutoRestart(XFinaldehaze *InstancePtr);
void XFinaldehaze_DisableAutoRestart(XFinaldehaze *InstancePtr);


void XFinaldehaze_InterruptGlobalEnable(XFinaldehaze *InstancePtr);
void XFinaldehaze_InterruptGlobalDisable(XFinaldehaze *InstancePtr);
void XFinaldehaze_InterruptEnable(XFinaldehaze *InstancePtr, u32 Mask);
void XFinaldehaze_InterruptDisable(XFinaldehaze *InstancePtr, u32 Mask);
void XFinaldehaze_InterruptClear(XFinaldehaze *InstancePtr, u32 Mask);
u32 XFinaldehaze_InterruptGetEnabled(XFinaldehaze *InstancePtr);
u32 XFinaldehaze_InterruptGetStatus(XFinaldehaze *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
