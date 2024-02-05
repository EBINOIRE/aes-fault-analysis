//----------------------------------------------------------------------
//   Copyright 2016 NXP B.V.
//   Copyright 2007-2010 Mentor Graphics Corporation
//   Copyright 2007-2011 Cadence Design Systems, Inc.
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

#ifndef _RELIABILITY_ANALYSIS_ENV_H_
#define _RELIABILITY_ANALYSIS_ENV_H_

#include <systemc>
#include <uvm>

#include "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault-injection-framework/core/src/uvm_objects/uvm_components/fault_environment.h"
#include "rl_scoreboard.h"

//------------------------------------------------------------------------------
//
// CLASS: rl_environment
//
//------------------------------------------------------------------------------

class rl_environment : public uvm::uvm_env
{
public:

  UVM_COMPONENT_UTILS(rl_environment);

  // fi environment
  fault_environment* fault_env;

  // Scoreboard to check golden vs faulty value
  rl_scoreboard* rl_scrb;

  // constructor
  rl_environment( uvm::uvm_component_name name)
  : uvm::uvm_env(name),
    fault_env(0), rl_scrb(0)
  {}
  
  // build_phase
  virtual void build_phase(uvm::uvm_phase& phase)
  {
    uvm::uvm_env::build_phase(phase);

    fault_env = fault_environment::type_id::create("fault_env", this);
    assert(fault_env);

    rl_scrb = rl_scoreboard::type_id::create("rl_scrb", this);
    assert(rl_scrb);
  }

  void connect_phase(uvm::uvm_phase& phase)
  {
    // Connect monitor to scoreboard
    fault_env->stim_mntr->item_collected_port.connect(
      rl_scrb->item_collected_export_stim);
      
    fault_env->fault_agnt->fault_mntr->item_collected_port.connect(
      rl_scrb->item_collected_export_fault);
  }

  void end_of_elaboration_phase(uvm::uvm_phase& phase)
  {}

}; // class rl_environment

#endif /* _RELIABILITY_ANALYSIS_ENV_H_ */
