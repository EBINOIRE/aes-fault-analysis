//----------------------------------------------------------------------
//   Copyright 2016-2019 NXP-2019 B.V.
//   Copyright 2007-2011 Mentor Graphics Corporation
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

#ifndef _RELIABILITY_ANALYSIS_TEST_LIB_H_
#define _RELIABILITY_ANALYSIS_TEST_LIB_H_

#include <systemc>
#include <uvm>

#include "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault-injection-framework/core/src/uvm_objects/fi.h"
#include "rl_environment.h"

//------------------------------------------------------------------------//
//--------------------- fault injection test -----------------------------//
//------------------------------------------------------------------------//

// Base Test
class rl_test : public uvm::uvm_test
{
public:

  UVM_COMPONENT_UTILS(rl_test);

  rl_environment* rl_env {nullptr};
  uvm::uvm_table_printer* printer {nullptr};
  bool test_pass;

  rl_test( uvm::uvm_component_name name = "rl_test")
  : uvm::uvm_test(name)
  {
    test_pass = true;
  }

  virtual void build_phase(uvm::uvm_phase& phase)
  {
    uvm::uvm_test::build_phase(phase);

    // Enable transaction recording for everything
    uvm::uvm_config_db<int>::set(this, "*", "recording_detail", uvm::UVM_FULL);

    // Create the test bench
    rl_env = rl_environment::type_id::create("rl_env", this);
    assert(rl_env);

    // Create a specific depth printer for printing the created topology
    printer = new uvm::uvm_table_printer();
    printer->knobs.depth = 3;


    uvm::uvm_config_db<uvm::uvm_object_wrapper*>::set(this,
      "rl_env.fault_env.vir_seqr.run_phase",
      "default_sequence", faultSimulation_sequence::type_id::get());
    
  }

  void end_of_elaboration_phase(uvm::uvm_phase& phase)
  {
    // // Set verbosity for the bus monitor for this demo
    //  if(rl_env->fault_env->bus_monitor != NULL)
    //    rl_env->fault_env->bus_monitor->set_report_verbosity_level(uvm::UVM_FULL);

    UVM_INFO(get_type_name(), "Printing the test topology :\n" +
      this->sprint(printer), uvm::UVM_LOW);
  }

  void run_phase(uvm::uvm_phase& phase)
  {
    //set a drain-time for the environment if desired
    sc_core::sc_time drain_time = sc_core::sc_time(130, sc_core::SC_NS);
    phase.get_objection()->set_drain_time(this, drain_time);

    SC_FORK
      sc_core::sc_spawn(sc_bind(&rl_test::caffeinate, this, 5000.0, &phase)),
    SC_JOIN
  }


  // A simple task that consumes some time to keep test awake.
  void caffeinate(double delay, uvm::uvm_phase* phase)
  {
    // Raise an objection before starting the activity
    phase->raise_objection(this);

    sc_core::wait(delay, sc_core::SC_NS);

    // Drop the objection when done
    phase->drop_objection(this);
  }

  void extract_phase(uvm::uvm_phase& phase)
  {}
  
  void report_phase(uvm::uvm_phase& phase)
  {
    if(test_pass)
    {
      UVM_INFO(get_type_name(), "** UVM TEST PASSED **", uvm::UVM_NONE);
    }
    else
    {
      UVM_ERROR(get_type_name(), "** UVM TEST FAIL **");
    }
  }

  void final_phase(uvm::uvm_phase& phase)
  {
    delete printer;
  }

}; // class rl_test


#endif /* _RELIABILITY_ANALYSIS_TEST_LIB_H_ */
