#include <systemc>
#include <uvm>
#include <string>
#include <cstring>
#include "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault-injection-framework/core/src/uvm_objects/fi.h"
#include "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault-injection-framework/core/src/virtual_interface/virtual_interface.h"
#include "/Users/ebinouri/Documents/UNi/OpenSourceTools/fault-injection-framework/core/src/flt_registry/fault_registry.h"
// placeholder for design header file
#include "./AES_systemc/AES.h"

using namespace sc_core;

#define SENSITIVITY(X, Y) sensitive << X[Y]
#define NUMBER_OF_DUT_INSTANCES 9

SC_MODULE( testbench ) {

    // placeholder for DUT pointer definition
    AES* dut_ref;
    AES* dut__f[NUMBER_OF_DUT_INSTANCES];
    
    // Input Ports
    sc_signal<sc_logic, SC_MANY_WRITERS> enable;
    sc_signal<sc_logic, SC_MANY_WRITERS> in128[128];
    sc_signal<sc_logic, SC_MANY_WRITERS> key128[128];
    sc_signal<sc_logic, SC_MANY_WRITERS> expected128[128];
    
    // Output Ports
    sc_signal<sc_logic, SC_MANY_WRITERS> e128;
    sc_signal<sc_logic, SC_MANY_WRITERS> d128;
    sc_signal<sc_logic, SC_MANY_WRITERS> decrypted128[128];
    sc_signal<sc_logic, SC_MANY_WRITERS> encrypted128[128];
    
    sc_signal<sc_logic, SC_MANY_WRITERS> e128_f[NUMBER_OF_DUT_INSTANCES];
    sc_signal<sc_logic, SC_MANY_WRITERS> d128_f[NUMBER_OF_DUT_INSTANCES];
    sc_signal<sc_logic, SC_MANY_WRITERS> decrypted128_f[NUMBER_OF_DUT_INSTANCES][128];
    sc_signal<sc_logic, SC_MANY_WRITERS> encrypted128_f[NUMBER_OF_DUT_INSTANCES][128];
    
    // Intermediate Signals
    sc_core::sc_signal<sc_dt::sc_lv<128>, sc_core::SC_MANY_WRITERS> encrypted_lv;
    sc_core::sc_signal<sc_dt::sc_lv<128>, sc_core::SC_MANY_WRITERS> encrypted_lv_f[NUMBER_OF_DUT_INSTANCES];

    virtual_interface* vif;
    std::string test_spec_file = "./test_spec.json";
    fault_registry* flt_reg;

    sc_core::sc_event start_analysis;
    sc_core::sc_event start_analysis_flt_mntr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        // Interface instantiation
        vif = new virtual_interface("vif");
          assert(vif);

        // Add interface to configuration database
        uvm::uvm_config_db<virtual_interface*>::set(uvm::uvm_root::get(), "*", "vif", vif);
        
        // Set test_spec_file 
        uvm::uvm_config_db<std::string>::set(uvm::uvm_root::get(), "*", "test_spec_file", test_spec_file);
        
        // Instantiate the DUT and bind ports to interface
        // placeholder for design instantiation and binding
        dut_ref = new AES("dut_ref");
            dut_ref->enable(enable);
            dut_ref->e128(e128);
            dut_ref->d128(d128);

            for (int i = 0; i < 128; i++){
              dut_ref->in[i].bind(in128[i]);
            }
            for (int i = 0; i < 128; i++){
              dut_ref->key128[i].bind(key128[i]);
            }
            for (int i = 0; i < 128; i++){
              dut_ref->expected128[i].bind(expected128[i]);
            }
            for (int i = 0; i < 128; i++){
              dut_ref->decrypted128[i].bind(decrypted128[i]);
            }
            for (int i = 0; i < 128; i++){
              dut_ref->encrypted128[i].bind(encrypted128[i]);
            }

        for (int j = 0; j < NUMBER_OF_DUT_INSTANCES; j++){

          dut__f[j] = new AES(("dut__f"+std::to_string(static_cast<unsigned long long>(j))).c_str());
              dut__f[j]->enable(enable);
              dut__f[j]->e128(e128_f[j]);
              dut__f[j]->d128(d128_f[j]);

              for (int i = 0; i < 128; i++){
                dut__f[j]->in[i].bind(in128[i]);
              }
              for (int i = 0; i < 128; i++){
                dut__f[j]->key128[i].bind(key128[i]);
              }
              for (int i = 0; i < 128; i++){
                dut__f[j]->expected128[i].bind(expected128[i]);
              }
              for (int i = 0; i < 128; i++){
                dut__f[j]->decrypted128[i].bind(decrypted128_f[j][i]);
              }
              for (int i = 0; i < 128; i++){
                dut__f[j]->encrypted128[i].bind(encrypted128_f[j][i]);
              }


        }


        // creating fault registration module
        flt_reg = new fault_registry();
            // placeholder for registration of signal in fault registry
            
        vif->set_reference_to_signal<sc_core::sc_signal<sc_dt::sc_lv<128>, sc_core::SC_MANY_WRITERS>>("encrypted", encrypted_lv);
        
        for (int j = 0; j < NUMBER_OF_DUT_INSTANCES; j++){
          vif->set_reference_to_signal<sc_core::sc_signal<sc_dt::sc_lv<128>, sc_core::SC_MANY_WRITERS>>(("encrypted_f"+std::to_string(static_cast<unsigned long long>(j))).c_str(), encrypted_lv_f[j]);
        }

        for (int j = 0; j < NUMBER_OF_DUT_INSTANCES; j++){
          flt_reg->add_faultableGDI<sc_signal<sc_dt::sc_logic, SC_MANY_WRITERS>>(dut__f[j]->a->er[j]->afterShiftRows[NUMBER_OF_DUT_INSTANCES], ("sbox_5_dut_"+std::to_string(static_cast<unsigned long long>(j))+"_").c_str());
        }
        
        // group signals  
        // placeholder for categorizing signals
        // vif->mark_as_input("ci");
        vif->mark_as_goldenOutput("encrypted");
        //********
        for (int j = 0; j < NUMBER_OF_DUT_INSTANCES; j++){
          vif->mark_as_faultyOutput(("encrypted_f"+std::to_string(static_cast<unsigned long long>(j))).c_str());
        }

        
        
        // Add interface to configuration database
        uvm::uvm_config_db<fault_registry*>::set(
          uvm::uvm_root::get(), "*", "flt_reg", flt_reg);
        // Add sc_event to configuration database
        uvm::uvm_config_db<sc_core::sc_event*>::set(
          uvm::uvm_root::get(), "*", "start_analysis_event", &(start_analysis));
        uvm::uvm_config_db<sc_core::sc_event*>::set(
          uvm::uvm_root::get(), "*", "start_analysis_event_fault_mntr", &(start_analysis_flt_mntr));

        SC_THREAD(signaling); 

        // convert key port (array of logic) to encrypted_lv (logic_vector)
        SC_THREAD(encrypted_assignment);
            // dont_initialize();
            for(int i = 0; i < 128; i++){
            SENSITIVITY(encrypted128, i);
          }

        SC_THREAD(encrypted_f1_assignment);
            // dont_initialize();
            for (int j = 0; j < NUMBER_OF_DUT_INSTANCES; j++){
              for(int i = 0; i < 128; i++){
                SENSITIVITY(encrypted128_f[j], i);
              }
            }

        // SC_THREAD(w_assignment);
        //     sensitive << w_lv;

        SC_THREAD(notify_starting_an_event); 
          sensitive << encrypted_lv;
        SC_THREAD(notify_starting_flt_mntr); 
          //********
          for(int i = 0; i < NUMBER_OF_DUT_INSTANCES; i++){
            SENSITIVITY(encrypted_lv_f, i);
          }
          // sensitive <<  dut__f[0]->a->loop_9__er->in[5]
          //           <<  dut__f[1]->a->loop_1__er->in[5]
          //           <<  dut__f[2]->a->loop_2__er->in[5]
          //           <<  dut__f[3]->a->loop_3__er->in[5]
          //           <<  dut__f[4]->a->loop_4__er->in[5]
          //           <<  dut__f[5]->a->loop_5__er->in[5]
          //           <<  dut__f[6]->a->loop_6__er->in[5]
          //           <<  dut__f[7]->a->loop_7__er->in[5]
          //           <<  dut__f[8]->a->loop_8__er->in[5];
          // sensitive <<  dut__f[0]->a->loop_9__er->in[5]

       
    }

    void notify_starting_flt_mntr(void){
      while (true)
      {
        start_analysis_flt_mntr.notify();
        wait();
      }
      
      // sc_core::wait(20, SC_NS);
    }
    void notify_starting_an_event(void){
      // placeholder for adding start_analysis event notification
      while (true)
      {
        wait(20, SC_NS);

        start_analysis.notify();
        wait();
      }
    }

    void encrypted_assignment(void){ 
        while(true) {
            sc_lv<128> encrypted_lv_temp;
            for (int i = 0; i < 128; i++){
                encrypted_lv_temp[i] = encrypted128[i].read();
            }
            encrypted_lv.write(encrypted_lv_temp);
            wait(SC_ZERO_TIME);
            wait();
        }                
    }
    void encrypted_f1_assignment(void){ 
        while(true) {
            sc_lv<128> encrypted_lv_f_temp;
            for (int j = 0; j < NUMBER_OF_DUT_INSTANCES; j++){
              for (int i = 0; i < 128; i++){
                  encrypted_lv_f_temp[i] = encrypted128_f[j][i].read();
              }
              encrypted_lv_f[j].write(encrypted_lv_f_temp);
            }
            wait(SC_ZERO_TIME);
            wait();
        }                
    }

  // @define: templated function to convert string to vector of logic
  //      @input type: string
  //      @output type: sc_dt::sc_lv<width>
  void str2logic_array(std::string str, sc_signal<sc_logic, SC_MANY_WRITERS> logic_array[128]){
      std::string::iterator it;
      std::vector<sc_dt::sc_logic> logic_vector;
      int i = 127;
    if (str.length() == 128){
      for (it = str.begin(); it != str.end(); it++){
          if ((*it) == '1')
              logic_array[i].write(sc_dt::SC_LOGIC_1);
          else if ((*it) == '0')
              logic_array[i].write(sc_dt::SC_LOGIC_0);
          
          i = i - 1;
          }
      } else {
        std::cout << "length do not match" << std::endl;
        std::cout << "Length of the string: " << str.length() << std::endl;

      }
  }

    void signaling(void){
      enable.write(SC_LOGIC_0);
      sc_core::wait(10, SC_NS);

      str2logic_array("00000000000100010010001000110011010001000101010101100110011101111000100010011001101010101011101111001100110111011110111011111111", in128);
      str2logic_array("00000000000000010000001000000011000001000000010100000110000001110000100000001001000010100000101100001100000011010000111000001111", key128);
      str2logic_array("01101001110001001110000011011000011010100111101100000100001100001101100011001101101101111000000001110000101101001100010101011010", expected128);
      sc_core::wait(10, SC_NS);
      enable.write(SC_LOGIC_1);
      sc_core::wait(10, SC_NS);
      enable.write(SC_LOGIC_0);
      sc_core::wait(10, SC_NS);
    }
};
