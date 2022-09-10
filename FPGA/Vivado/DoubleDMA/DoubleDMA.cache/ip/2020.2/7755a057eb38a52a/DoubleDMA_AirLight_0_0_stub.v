// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Mon Sep  5 16:58:24 2022
// Host        : zpoyqx running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ DoubleDMA_AirLight_0_0_stub.v
// Design      : DoubleDMA_AirLight_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "AirLight,Vivado 2020.2" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(B_A_ap_vld, G_A_ap_vld, R_A_ap_vld, 
  s_axi_control_AWADDR, s_axi_control_AWVALID, s_axi_control_AWREADY, 
  s_axi_control_WDATA, s_axi_control_WSTRB, s_axi_control_WVALID, s_axi_control_WREADY, 
  s_axi_control_BRESP, s_axi_control_BVALID, s_axi_control_BREADY, s_axi_control_ARADDR, 
  s_axi_control_ARVALID, s_axi_control_ARREADY, s_axi_control_RDATA, s_axi_control_RRESP, 
  s_axi_control_RVALID, s_axi_control_RREADY, ap_clk, ap_rst_n, interrupt, src_TVALID, 
  src_TREADY, src_TDATA, src_TDEST, src_TKEEP, src_TSTRB, src_TUSER, src_TLAST, src_TID, B_A, G_A, R_A)
/* synthesis syn_black_box black_box_pad_pin="B_A_ap_vld,G_A_ap_vld,R_A_ap_vld,s_axi_control_AWADDR[3:0],s_axi_control_AWVALID,s_axi_control_AWREADY,s_axi_control_WDATA[31:0],s_axi_control_WSTRB[3:0],s_axi_control_WVALID,s_axi_control_WREADY,s_axi_control_BRESP[1:0],s_axi_control_BVALID,s_axi_control_BREADY,s_axi_control_ARADDR[3:0],s_axi_control_ARVALID,s_axi_control_ARREADY,s_axi_control_RDATA[31:0],s_axi_control_RRESP[1:0],s_axi_control_RVALID,s_axi_control_RREADY,ap_clk,ap_rst_n,interrupt,src_TVALID,src_TREADY,src_TDATA[7:0],src_TDEST[0:0],src_TKEEP[0:0],src_TSTRB[0:0],src_TUSER[0:0],src_TLAST[0:0],src_TID[0:0],B_A[31:0],G_A[31:0],R_A[31:0]" */;
  output B_A_ap_vld;
  output G_A_ap_vld;
  output R_A_ap_vld;
  input [3:0]s_axi_control_AWADDR;
  input s_axi_control_AWVALID;
  output s_axi_control_AWREADY;
  input [31:0]s_axi_control_WDATA;
  input [3:0]s_axi_control_WSTRB;
  input s_axi_control_WVALID;
  output s_axi_control_WREADY;
  output [1:0]s_axi_control_BRESP;
  output s_axi_control_BVALID;
  input s_axi_control_BREADY;
  input [3:0]s_axi_control_ARADDR;
  input s_axi_control_ARVALID;
  output s_axi_control_ARREADY;
  output [31:0]s_axi_control_RDATA;
  output [1:0]s_axi_control_RRESP;
  output s_axi_control_RVALID;
  input s_axi_control_RREADY;
  input ap_clk;
  input ap_rst_n;
  output interrupt;
  input src_TVALID;
  output src_TREADY;
  input [7:0]src_TDATA;
  input [0:0]src_TDEST;
  input [0:0]src_TKEEP;
  input [0:0]src_TSTRB;
  input [0:0]src_TUSER;
  input [0:0]src_TLAST;
  input [0:0]src_TID;
  output [31:0]B_A;
  output [31:0]G_A;
  output [31:0]R_A;
endmodule
