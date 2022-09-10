############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project AirLight
set_top AirLight
add_files AirLight/source/AirLight.cpp
add_files AirLight/source/AirLight.h
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -output E:/Vivado/Project_Vitis_HLS/AirLight/AirLight.zip -rtl verilog
source "./AirLight/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog -output E:/Vivado/Project_Vitis_HLS/AirLight/AirLight.zip
