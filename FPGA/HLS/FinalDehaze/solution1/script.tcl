############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FinalDehaze
set_top FinalDehaze
add_files FinalDehaze/source/FinalDehaze.cpp
add_files FinalDehaze/source/FinalDehaze.h
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -output E:/Vivado/Project_Vitis_HLS/FinalDehaze/FinalDehaze.zip -rtl verilog
source "./FinalDehaze/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog -output E:/Vivado/Project_Vitis_HLS/FinalDehaze/FinalDehaze.zip
