-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
-- Date        : Mon Sep  5 16:58:32 2022
-- Host        : zpoyqx running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               e:/Vivado/Project_Vivado/DoubleDMA/DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_AirLight_0_0/DoubleDMA_AirLight_0_0_stub.vhdl
-- Design      : DoubleDMA_AirLight_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity DoubleDMA_AirLight_0_0 is
  Port ( 
    B_A_ap_vld : out STD_LOGIC;
    G_A_ap_vld : out STD_LOGIC;
    R_A_ap_vld : out STD_LOGIC;
    s_axi_control_AWADDR : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_control_AWVALID : in STD_LOGIC;
    s_axi_control_AWREADY : out STD_LOGIC;
    s_axi_control_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_control_WVALID : in STD_LOGIC;
    s_axi_control_WREADY : out STD_LOGIC;
    s_axi_control_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_BVALID : out STD_LOGIC;
    s_axi_control_BREADY : in STD_LOGIC;
    s_axi_control_ARADDR : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_control_ARVALID : in STD_LOGIC;
    s_axi_control_ARREADY : out STD_LOGIC;
    s_axi_control_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_RVALID : out STD_LOGIC;
    s_axi_control_RREADY : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC;
    interrupt : out STD_LOGIC;
    src_TVALID : in STD_LOGIC;
    src_TREADY : out STD_LOGIC;
    src_TDATA : in STD_LOGIC_VECTOR ( 7 downto 0 );
    src_TDEST : in STD_LOGIC_VECTOR ( 0 to 0 );
    src_TKEEP : in STD_LOGIC_VECTOR ( 0 to 0 );
    src_TSTRB : in STD_LOGIC_VECTOR ( 0 to 0 );
    src_TUSER : in STD_LOGIC_VECTOR ( 0 to 0 );
    src_TLAST : in STD_LOGIC_VECTOR ( 0 to 0 );
    src_TID : in STD_LOGIC_VECTOR ( 0 to 0 );
    B_A : out STD_LOGIC_VECTOR ( 31 downto 0 );
    G_A : out STD_LOGIC_VECTOR ( 31 downto 0 );
    R_A : out STD_LOGIC_VECTOR ( 31 downto 0 )
  );

end DoubleDMA_AirLight_0_0;

architecture stub of DoubleDMA_AirLight_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "B_A_ap_vld,G_A_ap_vld,R_A_ap_vld,s_axi_control_AWADDR[3:0],s_axi_control_AWVALID,s_axi_control_AWREADY,s_axi_control_WDATA[31:0],s_axi_control_WSTRB[3:0],s_axi_control_WVALID,s_axi_control_WREADY,s_axi_control_BRESP[1:0],s_axi_control_BVALID,s_axi_control_BREADY,s_axi_control_ARADDR[3:0],s_axi_control_ARVALID,s_axi_control_ARREADY,s_axi_control_RDATA[31:0],s_axi_control_RRESP[1:0],s_axi_control_RVALID,s_axi_control_RREADY,ap_clk,ap_rst_n,interrupt,src_TVALID,src_TREADY,src_TDATA[7:0],src_TDEST[0:0],src_TKEEP[0:0],src_TSTRB[0:0],src_TUSER[0:0],src_TLAST[0:0],src_TID[0:0],B_A[31:0],G_A[31:0],R_A[31:0]";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "AirLight,Vivado 2020.2";
begin
end;
