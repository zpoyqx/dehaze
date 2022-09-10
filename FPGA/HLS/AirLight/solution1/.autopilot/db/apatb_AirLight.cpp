#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_src_V_data_V "../tv/cdatafile/c.AirLight.autotvin_src_V_data_V.dat"
#define AUTOTB_TVOUT_src_V_data_V "../tv/cdatafile/c.AirLight.autotvout_src_V_data_V.dat"
#define AUTOTB_TVIN_src_V_keep_V "../tv/cdatafile/c.AirLight.autotvin_src_V_keep_V.dat"
#define AUTOTB_TVOUT_src_V_keep_V "../tv/cdatafile/c.AirLight.autotvout_src_V_keep_V.dat"
#define AUTOTB_TVIN_src_V_strb_V "../tv/cdatafile/c.AirLight.autotvin_src_V_strb_V.dat"
#define AUTOTB_TVOUT_src_V_strb_V "../tv/cdatafile/c.AirLight.autotvout_src_V_strb_V.dat"
#define AUTOTB_TVIN_src_V_user_V "../tv/cdatafile/c.AirLight.autotvin_src_V_user_V.dat"
#define AUTOTB_TVOUT_src_V_user_V "../tv/cdatafile/c.AirLight.autotvout_src_V_user_V.dat"
#define AUTOTB_TVIN_src_V_last_V "../tv/cdatafile/c.AirLight.autotvin_src_V_last_V.dat"
#define AUTOTB_TVOUT_src_V_last_V "../tv/cdatafile/c.AirLight.autotvout_src_V_last_V.dat"
#define AUTOTB_TVIN_src_V_id_V "../tv/cdatafile/c.AirLight.autotvin_src_V_id_V.dat"
#define AUTOTB_TVOUT_src_V_id_V "../tv/cdatafile/c.AirLight.autotvout_src_V_id_V.dat"
#define AUTOTB_TVIN_src_V_dest_V "../tv/cdatafile/c.AirLight.autotvin_src_V_dest_V.dat"
#define AUTOTB_TVOUT_src_V_dest_V "../tv/cdatafile/c.AirLight.autotvout_src_V_dest_V.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_data_V "../tv/stream_size/stream_size_in_src_V_data_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_data_V "../tv/stream_size/stream_ingress_status_src_V_data_V.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_keep_V "../tv/stream_size/stream_size_in_src_V_keep_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_keep_V "../tv/stream_size/stream_ingress_status_src_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_strb_V "../tv/stream_size/stream_size_in_src_V_strb_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_strb_V "../tv/stream_size/stream_ingress_status_src_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_user_V "../tv/stream_size/stream_size_in_src_V_user_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_user_V "../tv/stream_size/stream_ingress_status_src_V_user_V.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_last_V "../tv/stream_size/stream_size_in_src_V_last_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_last_V "../tv/stream_size/stream_ingress_status_src_V_last_V.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_id_V "../tv/stream_size/stream_size_in_src_V_id_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_id_V "../tv/stream_size/stream_ingress_status_src_V_id_V.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_dest_V "../tv/stream_size/stream_size_in_src_V_dest_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_dest_V "../tv/stream_size/stream_ingress_status_src_V_dest_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_B_A "../tv/cdatafile/c.AirLight.autotvin_B_A.dat"
#define AUTOTB_TVOUT_B_A "../tv/cdatafile/c.AirLight.autotvout_B_A.dat"
// wrapc file define:
#define AUTOTB_TVIN_G_A "../tv/cdatafile/c.AirLight.autotvin_G_A.dat"
#define AUTOTB_TVOUT_G_A "../tv/cdatafile/c.AirLight.autotvout_G_A.dat"
// wrapc file define:
#define AUTOTB_TVIN_R_A "../tv/cdatafile/c.AirLight.autotvin_R_A.dat"
#define AUTOTB_TVOUT_R_A "../tv/cdatafile/c.AirLight.autotvout_R_A.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_src_V_data_V "../tv/rtldatafile/rtl.AirLight.autotvout_src_V_data_V.dat"
#define AUTOTB_TVOUT_PC_src_V_keep_V "../tv/rtldatafile/rtl.AirLight.autotvout_src_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_src_V_strb_V "../tv/rtldatafile/rtl.AirLight.autotvout_src_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_src_V_user_V "../tv/rtldatafile/rtl.AirLight.autotvout_src_V_user_V.dat"
#define AUTOTB_TVOUT_PC_src_V_last_V "../tv/rtldatafile/rtl.AirLight.autotvout_src_V_last_V.dat"
#define AUTOTB_TVOUT_PC_src_V_id_V "../tv/rtldatafile/rtl.AirLight.autotvout_src_V_id_V.dat"
#define AUTOTB_TVOUT_PC_src_V_dest_V "../tv/rtldatafile/rtl.AirLight.autotvout_src_V_dest_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_B_A "../tv/rtldatafile/rtl.AirLight.autotvout_B_A.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_G_A "../tv/rtldatafile/rtl.AirLight.autotvout_G_A.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_R_A "../tv/rtldatafile/rtl.AirLight.autotvout_R_A.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  src_V_data_V_depth = 0;
  src_V_keep_V_depth = 0;
  src_V_strb_V_depth = 0;
  src_V_user_V_depth = 0;
  src_V_last_V_depth = 0;
  src_V_id_V_depth = 0;
  src_V_dest_V_depth = 0;
  B_A_depth = 0;
  G_A_depth = 0;
  R_A_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{src_V_data_V " << src_V_data_V_depth << "}\n";
  total_list << "{src_V_keep_V " << src_V_keep_V_depth << "}\n";
  total_list << "{src_V_strb_V " << src_V_strb_V_depth << "}\n";
  total_list << "{src_V_user_V " << src_V_user_V_depth << "}\n";
  total_list << "{src_V_last_V " << src_V_last_V_depth << "}\n";
  total_list << "{src_V_id_V " << src_V_id_V_depth << "}\n";
  total_list << "{src_V_dest_V " << src_V_dest_V_depth << "}\n";
  total_list << "{B_A " << B_A_depth << "}\n";
  total_list << "{G_A " << G_A_depth << "}\n";
  total_list << "{R_A " << R_A_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int src_V_data_V_depth;
    int src_V_keep_V_depth;
    int src_V_strb_V_depth;
    int src_V_user_V_depth;
    int src_V_last_V_depth;
    int src_V_id_V_depth;
    int src_V_dest_V_depth;
    int B_A_depth;
    int G_A_depth;
    int R_A_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
struct __cosim_s7__ { char data[7]; };
extern "C" void AirLight_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_AirLight_hw(volatile void * __xlx_apatb_param_src, volatile void * __xlx_apatb_param_B_A, volatile void * __xlx_apatb_param_G_A, volatile void * __xlx_apatb_param_R_A) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;long __xlx_apatb_param_src_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_data_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_stream_buf_final_size; ++i)((hls::stream<__cosim_s7__>*)__xlx_apatb_param_src)->read();
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_B_A);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > B_A_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "B_A");
  
            // push token into output port buffer
            if (AESL_token != "") {
              B_A_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((int*)__xlx_apatb_param_B_A)[0] = B_A_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_G_A);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > G_A_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "G_A");
  
            // push token into output port buffer
            if (AESL_token != "") {
              G_A_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((int*)__xlx_apatb_param_G_A)[0] = G_A_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_R_A);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > R_A_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "R_A");
  
            // push token into output port buffer
            if (AESL_token != "") {
              R_A_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((int*)__xlx_apatb_param_R_A)[0] = R_A_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//src
aesl_fh.touch(AUTOTB_TVIN_src_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_src_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_src_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_src_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_src_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_src_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_src_V_user_V);
aesl_fh.touch(AUTOTB_TVOUT_src_V_user_V);
aesl_fh.touch(AUTOTB_TVIN_src_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_src_V_last_V);
aesl_fh.touch(AUTOTB_TVIN_src_V_id_V);
aesl_fh.touch(AUTOTB_TVOUT_src_V_id_V);
aesl_fh.touch(AUTOTB_TVIN_src_V_dest_V);
aesl_fh.touch(AUTOTB_TVOUT_src_V_dest_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_data_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_user_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_user_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_last_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_id_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_id_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_dest_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_dest_V);
//B_A
aesl_fh.touch(AUTOTB_TVIN_B_A);
aesl_fh.touch(AUTOTB_TVOUT_B_A);
//G_A
aesl_fh.touch(AUTOTB_TVIN_G_A);
aesl_fh.touch(AUTOTB_TVOUT_G_A);
//R_A
aesl_fh.touch(AUTOTB_TVIN_R_A);
aesl_fh.touch(AUTOTB_TVOUT_R_A);
CodeState = DUMP_INPUTS;
std::vector<__cosim_s7__> __xlx_apatb_param_src_stream_buf;
{
  while (!((hls::stream<__cosim_s7__>*)__xlx_apatb_param_src)->empty())
    __xlx_apatb_param_src_stream_buf.push_back(((hls::stream<__cosim_s7__>*)__xlx_apatb_param_src)->read());
  for (int i = 0; i < __xlx_apatb_param_src_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s7__>*)__xlx_apatb_param_src)->write(__xlx_apatb_param_src_stream_buf[i]);
  }
long __xlx_apatb_param_src_stream_buf_size = ((hls::stream<__cosim_s7__>*)__xlx_apatb_param_src)->size();
// print B_A Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_B_A, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_B_A);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_B_A, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.B_A_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_B_A, __xlx_sprintf_buffer.data());
}
// print G_A Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_G_A, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_G_A);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_G_A, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.G_A_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_G_A, __xlx_sprintf_buffer.data());
}
// print R_A Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_R_A, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_R_A);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_R_A, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.R_A_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_R_A, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
AirLight_hw_stub_wrapper(__xlx_apatb_param_src, __xlx_apatb_param_B_A, __xlx_apatb_param_G_A, __xlx_apatb_param_R_A);
CodeState = DUMP_OUTPUTS;
long __xlx_apatb_param_src_stream_buf_final_size = __xlx_apatb_param_src_stream_buf_size - ((hls::stream<__cosim_s7__>*)__xlx_apatb_param_src)->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_user_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_last_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_id_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_dest_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src_stream_buf_final_size; j != e; ++j) {
sc_bv<56> __xlx_tmp_lv = ((long long*)&__xlx_apatb_param_src_stream_buf[j])[0];
sc_bv<8> __xlx_tmp_0_lv = __xlx_tmp_lv.range(7, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(15, 8);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(23, 16);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_3_lv = __xlx_tmp_lv.range(31, 24);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_3_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_user_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(39, 32);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_last_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_5_lv = __xlx_tmp_lv.range(47, 40);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_5_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_id_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_6_lv = __xlx_tmp_lv.range(55, 48);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_6_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_dest_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src_stream_buf_final_size, &tcl_file.src_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_src_stream_buf_final_size, &tcl_file.src_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_src_stream_buf_final_size, &tcl_file.src_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_src_stream_buf_final_size, &tcl_file.src_V_user_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_user_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_src_stream_buf_final_size, &tcl_file.src_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_last_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_src_stream_buf_final_size, &tcl_file.src_V_id_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_id_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_src_stream_buf_final_size, &tcl_file.src_V_dest_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_dest_V, __xlx_sprintf_buffer.data());

// dump stream ingress status to file

// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_data_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_src_stream_buf_final_size > 0) {
  long src_V_data_V_stream_ingress_size = __xlx_apatb_param_src_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_data_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src_stream_buf_final_size; j != e; j++) {
    src_V_data_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_data_V, __xlx_sprintf_buffer.data());
  }
} else {
  long src_V_data_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_data_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_data_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_keep_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_src_stream_buf_final_size > 0) {
  long src_V_keep_V_stream_ingress_size = __xlx_apatb_param_src_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_keep_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src_stream_buf_final_size; j != e; j++) {
    src_V_keep_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_keep_V, __xlx_sprintf_buffer.data());
  }
} else {
  long src_V_keep_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_keep_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_keep_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_strb_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_src_stream_buf_final_size > 0) {
  long src_V_strb_V_stream_ingress_size = __xlx_apatb_param_src_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_strb_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src_stream_buf_final_size; j != e; j++) {
    src_V_strb_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_strb_V, __xlx_sprintf_buffer.data());
  }
} else {
  long src_V_strb_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_strb_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_strb_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_user_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_src_stream_buf_final_size > 0) {
  long src_V_user_V_stream_ingress_size = __xlx_apatb_param_src_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_user_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_user_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src_stream_buf_final_size; j != e; j++) {
    src_V_user_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_user_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_user_V, __xlx_sprintf_buffer.data());
  }
} else {
  long src_V_user_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_user_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_user_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_user_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_last_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_src_stream_buf_final_size > 0) {
  long src_V_last_V_stream_ingress_size = __xlx_apatb_param_src_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src_stream_buf_final_size; j != e; j++) {
    src_V_last_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_last_V, __xlx_sprintf_buffer.data());
  }
} else {
  long src_V_last_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_last_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_last_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_id_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_src_stream_buf_final_size > 0) {
  long src_V_id_V_stream_ingress_size = __xlx_apatb_param_src_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_id_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_id_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src_stream_buf_final_size; j != e; j++) {
    src_V_id_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_id_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_id_V, __xlx_sprintf_buffer.data());
  }
} else {
  long src_V_id_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_id_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_id_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_id_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_dest_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_src_stream_buf_final_size > 0) {
  long src_V_dest_V_stream_ingress_size = __xlx_apatb_param_src_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_dest_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_dest_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src_stream_buf_final_size; j != e; j++) {
    src_V_dest_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_dest_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_dest_V, __xlx_sprintf_buffer.data());
  }
} else {
  long src_V_dest_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", src_V_dest_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_dest_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_src_V_dest_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_user_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_user_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_user_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_last_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_id_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_id_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_id_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_dest_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_dest_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_dest_V, __xlx_sprintf_buffer.data());
}// print B_A Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_B_A, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_B_A);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_B_A, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.B_A_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_B_A, __xlx_sprintf_buffer.data());
}
// print G_A Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_G_A, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_G_A);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_G_A, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.G_A_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_G_A, __xlx_sprintf_buffer.data());
}
// print R_A Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_R_A, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_R_A);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_R_A, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.R_A_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_R_A, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
