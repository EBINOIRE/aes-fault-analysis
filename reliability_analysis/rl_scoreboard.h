//----------------------------------------------------------------------
//   Copyright 2016 NXP B.V.
//   Copyright 2007-2010 Mentor Graphics Corporation
//   Copyright 2007-2010 Cadence Design Systems, Inc.
//   Copyright 2010 Synopsys, Inc.
//   All Rights Reserved Worldwide
//
//   Licensed under the Apache License, Version 2.0 (the
//   "License"); you may not use this file except in
//   compliance with the License.  You may obtain a copy of
//   the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in
//   writing, software distributed under the License is
//   distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
//   CONDITIONS OF ANY KIND, either express or implied.  See
//   the License for the specific language governing
//   permissions and limitations under the License.
//----------------------------------------------------------------------

#ifndef _RELIABILITY_SCOREBOARD_H_
#define _RELIABILITY_SCOREBOARD_H_

#include <systemc>
#include <uvm>

#include <map>
#include <sstream>

#include "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault-injection-framework/core/src/uvm_objects/fi.h"
#include "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault-injection-framework/core/src/utils/utility_functions.h"

// -----------------------------------------------------------
// *********************** class Declaration ***********************
// -----------------------------------------------------------

//------------------------------------------------------------------------------
// CLASS: rl_scoreboard
//------------------------------------------------------------------------------


class rl_scoreboard : public uvm::uvm_scoreboard
{
public:

  uvm::uvm_analysis_imp<genericDataItem, rl_scoreboard> item_collected_export_stim;
  uvm::uvm_analysis_imp<genericDataItem, rl_scoreboard> item_collected_export_fault;

  // Provide implementations of virtual methods such as get_type_name and create
  UVM_COMPONENT_UTILS(rl_scoreboard);

  // constructor
  rl_scoreboard(uvm::uvm_component_name name);

  virtual void write(const genericDataItem& trans);

  // report_phase
  virtual void report_phase(uvm::uvm_phase& phase);
  void build_phase(uvm::uvm_phase& phase);

protected:

  // reliability_analysis
  void reliability_analysis(const genericDataItem& trans);
  bool analyze_output(void);

  bool disable_scoreboard;

  std::map<std::string, std::string> input_list;
  std::map<std::string, std::string> goldenOutput_list;
  std::map<std::string, std::string> faultyOutput_list;
  std::map<std::string, std::string> fault_list;
  
  fault_registry* flt_reg;
  genericDataItem trans_collected;

  int benign;
  int sdc;
  int crash;
}; // class rl_scoreboard

// -----------------------------------------------------------
// *********************** class Declaration *****************
// -----------------------------------------------------------
//----------------------------------------------------------------------
//  Class: master_scoreboard_mono_port
//        constructor
//        member function: write (virtual)
//        member function: report_phase (virtual)
//        member function: reliability_analysis
//        member function: analyze_output
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// constructor
//----------------------------------------------------------------------


rl_scoreboard::rl_scoreboard(uvm::uvm_component_name name)
: uvm::uvm_scoreboard(name),
  item_collected_export_stim("item_collected_export_stim", this),
  item_collected_export_fault("item_collected_export_fault", this)
{
  disable_scoreboard = false;
  benign = 0;
  sdc = 0;
  crash = 0;
}


//----------------------------------------------------------------------
// member function: build_phase
//----------------------------------------------------------------------


void rl_scoreboard::build_phase(uvm::uvm_phase& phase)
{

  uvm::uvm_scoreboard::build_phase(phase);

  // if(!uvm::uvm_config_db<virtual_interface*>::get(this, "", "vif", vif))
  //   UVM_FATAL("NOVIF","virtual interface must be set for: " + get_full_name() + ".vif");

  // get fault database
  if(!uvm::uvm_config_db<fault_registry*>::get(NULL, "", "flt_reg", flt_reg))
    UVM_FATAL("NOVIF", "fault database must be set for: "
      + get_full_name() + ".flt_db");

}

//----------------------------------------------------------------------
// member function: write (virtual)
//----------------------------------------------------------------------


void rl_scoreboard::write(const genericDataItem& trans)
{
  if(!disable_scoreboard){
    reliability_analysis(trans);
  } 
}

//----------------------------------------------------------------------
// member function: report_phase (virtual)
//----------------------------------------------------------------------


void rl_scoreboard::report_phase(uvm::uvm_phase& phase)
{
  if(!disable_scoreboard)
    UVM_INFO(get_type_name(), "Reporting scoreboard information...\n" +
        this->sprint(), uvm::UVM_LOW);
}

//----------------------------------------------------------------------
// member function: reliability_analysis
//----------------------------------------------------------------------

void rl_scoreboard::reliability_analysis(const genericDataItem& trans)
{ 
  if (trans.auxInfoInt == 0){ // sender is stim_monitor
    if (trans.auxInfoString == "OUTPUT_DATA"){
      // update signals variables
      goldenOutput_list[trans.id] = trans.to_string();
    } else if (trans.auxInfoString == "INPUT_DATA"){
      input_list[trans.id] = trans.to_string();
    } else if (trans.auxInfoString == "MONITOR_FLAG"){
      if (trans.id == "DATA_READY"){
        analyze_output();
        
        // clear all lists 
        // input_list.clear();
        // goldenOutput_list.clear();
        // faultyOutput_list.clear();
        // fault_list.clear();
      }
    }
  } else if (trans.auxInfoInt == 1){ // if transaction belongs to faulty output
    if (trans.auxInfoString == "OUTPUT_DATA_FAULTY"){
      // update signals variables
      faultyOutput_list[trans.id] = trans.to_string();
    } else if (trans.auxInfoString == "ACTIVE_FAULT"){
      fault_list[trans.id] = trans.to_string();
    }
  }
}

//----------------------------------------------------------------------
// member function: analyze_output
//----------------------------------------------------------------------

bool rl_scoreboard::analyze_output(void)
{ 
  bool detected = false;

  std::ostringstream req_msg;
  
  std::cout<< "-------------- SCB_REPORT START @" << sc_core::sc_time_stamp() << std::endl; 
  for (auto i = goldenOutput_list.begin(); i != goldenOutput_list.end(); i++) 
      cout << "Golden output: " << i->first << " \t of \t\t" << std::hex << i->second << endl;
  
  std::string goldenOutput_name = goldenOutput_list.begin()->first;
  std::string goldenOutput_value = goldenOutput_list.begin()->second;

  // for (auto i = fault_list.begin(); i != fault_list.end(); i++) {
  //     cout << "Fault list: " << "\n" << i->first << " \t\t\t" << std::hex << i->second << endl;

  // }

  for (auto i = faultyOutput_list.begin(); i != faultyOutput_list.end(); i++) {
    cout << "Output Name: " << "\n" << i->first << " \t of \t\t" << std::hex << i->second << endl;
    int diff_bit = 0;
    for (int k=0; k < 128; k++){
      if (goldenOutput_value[k] != i->second[k])
        diff_bit = diff_bit + 1;
    }

    if (diff_bit != 0){
      cout << "\t\t has the difference of : "<< std::dec << diff_bit << std::endl;
    }
  }
  // trans_collected = flt_reg->get_faultableGDI("generic_testbench.dut_ref.sayacInstructionModuleEmb.PCregister");
  // std::string pc_golden_value = (static_cast<sc_signal<sc_dt::sc_lv<16>, SC_MANY_WRITERS>*>(trans_collected.ptr))->read().to_string();
  // std::cout << "I am here ..............PCregister" << std::endl;
  

  // if (pc_golden_value != pc_faulty_value){
  //   std::cout<< "Golden PC: " << pc_golden_value << std::endl; 
  //   std::cout<< "Faulty PC: " << pc_faulty_value << std::endl; 
  //   crash += 1;
  //   std::cout<< "    " << "RESULT: CRASH" << std::endl;
  // }
  // else if ((addrBus_golden_value != addrBus_faulty_value) || (dataBus_golden_value != dataBus_faulty_value)){
  //   std::cout<< "Golden Data Bus   : " << dataBus_golden_value << std::endl; 
  //   std::cout<< "Faulty Data Bus   : " << dataBus_faulty_value << std::endl; 
  //   std::cout<< "Golden Address Bus: " << addrBus_golden_value << std::endl; 
  //   std::cout<< "Faulty Address Bus: " << addrBus_faulty_value << std::endl; 
  //   sdc += 1;
  //   std::cout<< "    " << "RESULT: SDC" << std::endl;
  // }
  // else {
  //   std::cout<< "PC         : " << pc_golden_value << std::endl; 
  //   std::cout<< "Data Bus   : " << dataBus_golden_value << std::endl; 
  //   std::cout<< "Address Bus: " << addrBus_golden_value << std::endl; 

  //   benign += 1;
  //   std::cout<< "    " << "RESULT: BENIGN" << std::endl;
  // }

  std::cout<< "-------------- SCB_REPORT END" << std::endl; 

  if (!(req_msg.str().empty())){ // if stream is not empty, print info
    UVM_INFO(get_type_name(), req_msg.str(), uvm::UVM_LOW);
  }
  return detected;
}

#endif /* _RELIABILITY_SCOREBOARD_H_ */
