vlib work
vlib activehdl

vlib activehdl/xilinx_vip
vlib activehdl/xpm
vlib activehdl/axi_infrastructure_v1_1_0
vlib activehdl/axi_vip_v1_1_8
vlib activehdl/processing_system7_vip_v1_0_10
vlib activehdl/xil_defaultlib
vlib activehdl/xbip_utils_v3_0_10
vlib activehdl/axi_utils_v2_0_6
vlib activehdl/xbip_pipe_v3_0_6
vlib activehdl/xbip_dsp48_wrapper_v3_0_4
vlib activehdl/xbip_dsp48_addsub_v3_0_6
vlib activehdl/xbip_dsp48_multadd_v3_0_6
vlib activehdl/xbip_bram18k_v3_0_6
vlib activehdl/mult_gen_v12_0_16
vlib activehdl/floating_point_v7_1_11
vlib activehdl/lib_pkg_v1_0_2
vlib activehdl/fifo_generator_v13_2_5
vlib activehdl/lib_fifo_v1_0_14
vlib activehdl/lib_srl_fifo_v1_0_2
vlib activehdl/lib_cdc_v1_0_2
vlib activehdl/axi_datamover_v5_1_24
vlib activehdl/axi_sg_v4_1_13
vlib activehdl/axi_dma_v7_1_23
vlib activehdl/generic_baseblocks_v2_1_0
vlib activehdl/axi_register_slice_v2_1_22
vlib activehdl/axi_data_fifo_v2_1_21
vlib activehdl/axi_crossbar_v2_1_23
vlib activehdl/axi_protocol_converter_v2_1_22
vlib activehdl/axi_clock_converter_v2_1_21
vlib activehdl/blk_mem_gen_v8_4_4
vlib activehdl/axi_dwidth_converter_v2_1_22
vlib activehdl/proc_sys_reset_v5_0_13

vmap xilinx_vip activehdl/xilinx_vip
vmap xpm activehdl/xpm
vmap axi_infrastructure_v1_1_0 activehdl/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_8 activehdl/axi_vip_v1_1_8
vmap processing_system7_vip_v1_0_10 activehdl/processing_system7_vip_v1_0_10
vmap xil_defaultlib activehdl/xil_defaultlib
vmap xbip_utils_v3_0_10 activehdl/xbip_utils_v3_0_10
vmap axi_utils_v2_0_6 activehdl/axi_utils_v2_0_6
vmap xbip_pipe_v3_0_6 activehdl/xbip_pipe_v3_0_6
vmap xbip_dsp48_wrapper_v3_0_4 activehdl/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_6 activehdl/xbip_dsp48_addsub_v3_0_6
vmap xbip_dsp48_multadd_v3_0_6 activehdl/xbip_dsp48_multadd_v3_0_6
vmap xbip_bram18k_v3_0_6 activehdl/xbip_bram18k_v3_0_6
vmap mult_gen_v12_0_16 activehdl/mult_gen_v12_0_16
vmap floating_point_v7_1_11 activehdl/floating_point_v7_1_11
vmap lib_pkg_v1_0_2 activehdl/lib_pkg_v1_0_2
vmap fifo_generator_v13_2_5 activehdl/fifo_generator_v13_2_5
vmap lib_fifo_v1_0_14 activehdl/lib_fifo_v1_0_14
vmap lib_srl_fifo_v1_0_2 activehdl/lib_srl_fifo_v1_0_2
vmap lib_cdc_v1_0_2 activehdl/lib_cdc_v1_0_2
vmap axi_datamover_v5_1_24 activehdl/axi_datamover_v5_1_24
vmap axi_sg_v4_1_13 activehdl/axi_sg_v4_1_13
vmap axi_dma_v7_1_23 activehdl/axi_dma_v7_1_23
vmap generic_baseblocks_v2_1_0 activehdl/generic_baseblocks_v2_1_0
vmap axi_register_slice_v2_1_22 activehdl/axi_register_slice_v2_1_22
vmap axi_data_fifo_v2_1_21 activehdl/axi_data_fifo_v2_1_21
vmap axi_crossbar_v2_1_23 activehdl/axi_crossbar_v2_1_23
vmap axi_protocol_converter_v2_1_22 activehdl/axi_protocol_converter_v2_1_22
vmap axi_clock_converter_v2_1_21 activehdl/axi_clock_converter_v2_1_21
vmap blk_mem_gen_v8_4_4 activehdl/blk_mem_gen_v8_4_4
vmap axi_dwidth_converter_v2_1_22 activehdl/axi_dwidth_converter_v2_1_22
vmap proc_sys_reset_v5_0_13 activehdl/proc_sys_reset_v5_0_13

vlog -work xilinx_vip  -sv2k12 "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_if.sv" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/clk_vip_if.sv" \
"E:/Vivado/Vivado/2020.2/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm  -sv2k12 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"E:/Vivado/Vivado/2020.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"E:/Vivado/Vivado/2020.2/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"E:/Vivado/Vivado/2020.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -93 \
"E:/Vivado/Vivado/2020.2/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_8  -sv2k12 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/94c3/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_10  -sv2k12 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_processing_system7_0_0/sim/DoubleDMA_processing_system7_0_0.v" \

vcom -work xbip_utils_v3_0_10 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/d117/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_6 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_6 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_6 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_6 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_6 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_16 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ce84/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_11 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/b0c0/hdl/floating_point_v7_1_rfs.vhd" \

vlog -work floating_point_v7_1_11  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/b0c0/hdl/floating_point_v7_1_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/verilog/AirLight_control_s_axi.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/verilog/AirLight_dictB.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/verilog/AirLight_dmul_64ns_64ns_64_7_max_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/verilog/AirLight_mul_32s_32s_32_2_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/verilog/AirLight_regslice_both.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/verilog/AirLight_sdiv_32ns_32ns_32_36_seq_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/verilog/AirLight_sitodp_32ns_64_6_no_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/verilog/AirLight.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/ip/AirLight_ap_dmul_5_max_dsp_64.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/26e4/hdl/ip/AirLight_ap_sitodp_4_no_dsp_32.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_AirLight_0_0/sim/DoubleDMA_AirLight_0_0.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_control_s_axi.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_dadd_64ns_64ns_64_7_full_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_dadddsub_64ns_64ns_64_7_full_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_dcmp_64ns_64ns_1_2_no_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_ddiv_64ns_64ns_64_59_no_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_dexp_64ns_64ns_64_21_full_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_dmul_64ns_64ns_64_7_max_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_regslice_both.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_sitodp_32s_64_6_no_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_sitodp_64s_64_6_no_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze_uitodp_32ns_64_6_no_dsp_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/verilog/FinalDehaze.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_dadddsub_5_full_dsp_64.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_dadd_5_full_dsp_64.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_dcmp_0_no_dsp_64.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_ddiv_57_no_dsp_64.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_dexp_19_full_dsp_64.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_dmul_5_max_dsp_64.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_sitodp_4_no_dsp_32.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_sitodp_4_no_dsp_64.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/05a7/hdl/ip/FinalDehaze_ap_uitodp_4_no_dsp_32.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_FinalDehaze_0_0/sim/DoubleDMA_FinalDehaze_0_0.v" \

vcom -work lib_pkg_v1_0_2 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/0513/hdl/lib_pkg_v1_0_rfs.vhd" \

vlog -work fifo_generator_v13_2_5  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/276e/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_5 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/276e/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_5  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/276e/hdl/fifo_generator_v13_2_rfs.v" \

vcom -work lib_fifo_v1_0_14 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/a5cb/hdl/lib_fifo_v1_0_rfs.vhd" \

vcom -work lib_srl_fifo_v1_0_2 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/51ce/hdl/lib_srl_fifo_v1_0_rfs.vhd" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work axi_datamover_v5_1_24 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/4ab6/hdl/axi_datamover_v5_1_vh_rfs.vhd" \

vcom -work axi_sg_v4_1_13 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/4919/hdl/axi_sg_v4_1_rfs.vhd" \

vcom -work axi_dma_v7_1_23 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/89d8/hdl/axi_dma_v7_1_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_axi_dma_0/sim/DoubleDMA_axi_dma_0.vhd" \

vlog -work generic_baseblocks_v2_1_0  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_22  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/af2c/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work axi_data_fifo_v2_1_21  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/54c0/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_23  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/bc0a/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_xbar_0/sim/DoubleDMA_xbar_0.v" \

vlog -work axi_protocol_converter_v2_1_22  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/5cee/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work axi_clock_converter_v2_1_21  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/1304/hdl/axi_clock_converter_v2_1_vl_rfs.v" \

vlog -work blk_mem_gen_v8_4_4  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/2985/simulation/blk_mem_gen_v8_4.v" \

vlog -work axi_dwidth_converter_v2_1_22  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/2394/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_auto_us_0/sim/DoubleDMA_auto_us_0.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_auto_us_1/sim/DoubleDMA_auto_us_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_auto_us_2/sim/DoubleDMA_auto_us_2.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_auto_pc_0/sim/DoubleDMA_auto_pc_0.v" \

vcom -work proc_sys_reset_v5_0_13 -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_rst_ps7_0_100M_0/sim/DoubleDMA_rst_ps7_0_100M_0.vhd" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_axi_dma_0_0/sim/DoubleDMA_axi_dma_0_0.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/ec67/hdl" "+incdir+../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ipshared/34f8/hdl" "+incdir+E:/Vivado/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_xbar_1/sim/DoubleDMA_xbar_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/ip/DoubleDMA_auto_pc_1/sim/DoubleDMA_auto_pc_1.v" \
"../../../../DoubleDMA.gen/sources_1/bd/DoubleDMA/sim/DoubleDMA.v" \

vlog -work xil_defaultlib \
"glbl.v"

