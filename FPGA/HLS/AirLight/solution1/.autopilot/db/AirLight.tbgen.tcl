set moduleName AirLight
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {AirLight}
set C_modelType { void 0 }
set C_modelArgList {
	{ src_V_data_V int 8 regular {axi_s 0 volatile  { src Data } }  }
	{ src_V_keep_V int 1 regular {axi_s 0 volatile  { src Keep } }  }
	{ src_V_strb_V int 1 regular {axi_s 0 volatile  { src Strb } }  }
	{ src_V_user_V int 1 regular {axi_s 0 volatile  { src User } }  }
	{ src_V_last_V int 1 regular {axi_s 0 volatile  { src Last } }  }
	{ src_V_id_V int 1 regular {axi_s 0 volatile  { src ID } }  }
	{ src_V_dest_V int 1 regular {axi_s 0 volatile  { src Dest } }  }
	{ B_A int 32 regular {pointer 1}  }
	{ G_A int 32 regular {pointer 1}  }
	{ R_A int 32 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "src_V_data_V", "interface" : "axis", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "src.V.data.V","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "src_V_keep_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "src.V.keep.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "src_V_strb_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "src.V.strb.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "src_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "src.V.user.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "src_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "src.V.last.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "src_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "src.V.id.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "src_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "src.V.dest.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "B_A", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "B_A","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "G_A", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "G_A","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "R_A", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "R_A","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 35
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ src_TDATA sc_in sc_lv 8 signal 0 } 
	{ src_TVALID sc_in sc_logic 1 invld 6 } 
	{ src_TREADY sc_out sc_logic 1 inacc 6 } 
	{ src_TKEEP sc_in sc_lv 1 signal 1 } 
	{ src_TSTRB sc_in sc_lv 1 signal 2 } 
	{ src_TUSER sc_in sc_lv 1 signal 3 } 
	{ src_TLAST sc_in sc_lv 1 signal 4 } 
	{ src_TID sc_in sc_lv 1 signal 5 } 
	{ src_TDEST sc_in sc_lv 1 signal 6 } 
	{ B_A sc_out sc_lv 32 signal 7 } 
	{ B_A_ap_vld sc_out sc_logic 1 outvld 7 } 
	{ G_A sc_out sc_lv 32 signal 8 } 
	{ G_A_ap_vld sc_out sc_logic 1 outvld 8 } 
	{ R_A sc_out sc_lv 32 signal 9 } 
	{ R_A_ap_vld sc_out sc_logic 1 outvld 9 } 
	{ s_axi_control_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_AWADDR sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_control_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_ARADDR sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_control_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_control_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_control_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "AWADDR" },"address":[{"name":"AirLight","role":"start","value":"0","valid_bit":"0"},{"name":"AirLight","role":"continue","value":"0","valid_bit":"4"},{"name":"AirLight","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWVALID" } },
	{ "name": "s_axi_control_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWREADY" } },
	{ "name": "s_axi_control_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WVALID" } },
	{ "name": "s_axi_control_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WREADY" } },
	{ "name": "s_axi_control_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "WDATA" } },
	{ "name": "s_axi_control_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "WSTRB" } },
	{ "name": "s_axi_control_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "ARADDR" },"address":[{"name":"AirLight","role":"start","value":"0","valid_bit":"0"},{"name":"AirLight","role":"done","value":"0","valid_bit":"1"},{"name":"AirLight","role":"idle","value":"0","valid_bit":"2"},{"name":"AirLight","role":"ready","value":"0","valid_bit":"3"},{"name":"AirLight","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARVALID" } },
	{ "name": "s_axi_control_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARREADY" } },
	{ "name": "s_axi_control_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RVALID" } },
	{ "name": "s_axi_control_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RREADY" } },
	{ "name": "s_axi_control_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "RDATA" } },
	{ "name": "s_axi_control_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "RRESP" } },
	{ "name": "s_axi_control_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BVALID" } },
	{ "name": "s_axi_control_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BREADY" } },
	{ "name": "s_axi_control_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "src_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "src_V_data_V", "role": "default" }} , 
 	{ "name": "src_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "src_V_dest_V", "role": "default" }} , 
 	{ "name": "src_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "src_V_dest_V", "role": "default" }} , 
 	{ "name": "src_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_keep_V", "role": "default" }} , 
 	{ "name": "src_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_strb_V", "role": "default" }} , 
 	{ "name": "src_TUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_user_V", "role": "default" }} , 
 	{ "name": "src_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_last_V", "role": "default" }} , 
 	{ "name": "src_TID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_id_V", "role": "default" }} , 
 	{ "name": "src_TDEST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_dest_V", "role": "default" }} , 
 	{ "name": "B_A", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_A", "role": "default" }} , 
 	{ "name": "B_A_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "B_A", "role": "ap_vld" }} , 
 	{ "name": "G_A", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "G_A", "role": "default" }} , 
 	{ "name": "G_A_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "G_A", "role": "ap_vld" }} , 
 	{ "name": "R_A", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "R_A", "role": "default" }} , 
 	{ "name": "R_A_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "R_A", "role": "ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19"],
		"CDFG" : "AirLight",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "src_V_data_V", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "src_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "src_V_user_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "src_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "src_V_id_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "src_V_dest_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "B_A", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "G_A", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "R_A", "Type" : "Vld", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.control_s_axi_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dictB_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dictG_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dictR_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dmul_64ns_64ns_64_7_max_dsp_1_U1", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.sitodp_32ns_64_6_no_dsp_1_U2", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_32s_32s_32_2_1_U3", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.sdiv_32ns_32ns_32_36_seq_1_U4", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_32s_32s_32_2_1_U5", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.sdiv_32ns_32ns_32_36_seq_1_U6", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_32s_32s_32_2_1_U7", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.sdiv_32ns_32ns_32_36_seq_1_U8", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_src_V_data_V_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_src_V_keep_V_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_src_V_strb_V_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_src_V_user_V_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_src_V_last_V_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_src_V_id_V_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_src_V_dest_V_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	AirLight {
		src_V_data_V {Type I LastRead 9 FirstWrite -1}
		src_V_keep_V {Type I LastRead 9 FirstWrite -1}
		src_V_strb_V {Type I LastRead 9 FirstWrite -1}
		src_V_user_V {Type I LastRead 9 FirstWrite -1}
		src_V_last_V {Type I LastRead 9 FirstWrite -1}
		src_V_id_V {Type I LastRead 9 FirstWrite -1}
		src_V_dest_V {Type I LastRead 9 FirstWrite -1}
		B_A {Type O LastRead -1 FirstWrite 67}
		G_A {Type O LastRead -1 FirstWrite 109}
		R_A {Type O LastRead -1 FirstWrite 151}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "5", "EnableSignal" : "ap_enable_pp5"}
	{"Pipeline" : "7", "EnableSignal" : "ap_enable_pp7"}
	{"Pipeline" : "9", "EnableSignal" : "ap_enable_pp9"}
]}

set Spec2ImplPortList { 
	src_V_data_V { axis {  { src_TDATA in_data 0 8 } } }
	src_V_keep_V { axis {  { src_TKEEP in_data 0 1 } } }
	src_V_strb_V { axis {  { src_TSTRB in_data 0 1 } } }
	src_V_user_V { axis {  { src_TUSER in_data 0 1 } } }
	src_V_last_V { axis {  { src_TLAST in_data 0 1 } } }
	src_V_id_V { axis {  { src_TID in_data 0 1 } } }
	src_V_dest_V { axis {  { src_TVALID in_vld 0 1 }  { src_TREADY in_acc 1 1 }  { src_TDEST in_data 0 1 } } }
	B_A { ap_vld {  { B_A out_data 1 32 }  { B_A_ap_vld out_vld 1 1 } } }
	G_A { ap_vld {  { G_A out_data 1 32 }  { G_A_ap_vld out_vld 1 1 } } }
	R_A { ap_vld {  { R_A out_data 1 32 }  { R_A_ap_vld out_vld 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
