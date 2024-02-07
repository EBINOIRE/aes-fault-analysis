//----------------------------------------------------------------------
//   Copyright 2016-2019 NXP B.V.
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

#include <systemc>
#include <uvm>
#include "testbench.h"
// placeholder for UVM Test file
#include "./reliability_analysis/rl_test.h"

int sc_main(int, char*[])
{
  testbench* generic_testbench = new testbench("generic_testbench");
  sc_report_handler::set_actions (SC_ID_VECTOR_CONTAINS_LOGIC_VALUE_,
                                  SC_DO_NOTHING);
  sc_report_handler::set_actions (SC_ID_LOGIC_X_TO_BOOL_,
                                  SC_DO_NOTHING);
  
  // Run test
  // placeholder for UVM Test module name
    uvm::run_test("rl_test");
  
  return 0;
}
