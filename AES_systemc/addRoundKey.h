#include <systemc.h>

#ifndef __ADDROUNDKEY_H__
#define __ADDROUNDKEY_H__
using namespace sc_core;


// #ifndef SENSITIVITY(X, Y)
#define SENSITIVITY(X, Y) sensitive << X[Y]
// #endif


SC_MODULE( addRoundKey ) {

    sc_in<sc_logic> data[128];
    sc_in<sc_logic> key[128];
    sc_out<sc_logic> out[128];

    sc_signal<sc_lv<128>> data_lv;
    sc_signal<sc_lv<128>> key_lv;
    sc_signal<sc_lv<128>> out_lv;

SC_CTOR( addRoundKey ) {


    SC_METHOD(eval);
        dont_initialize();
        sensitive << key_lv << data_lv;
    
    
    // convert w port (array of logic) to w_lv (logic_vector)
    SC_THREAD(out_assignment);
        sensitive << out_lv;

    // convert key port (array of logic) to key_lv (logic_vector)
    SC_THREAD(key_assignment);
        for(int i = 0; i < 128; i++){
				SENSITIVITY(key, i);
			}
    // convert data port (array of logic) to data_lv (logic_vector)
    SC_THREAD(data_assignment);
        for(int i = 0; i < 128; i++){
				SENSITIVITY(data, i);
			}

    }

    void out_assignment(void){ 
        while(true) {
            for (int i = 0; i < 128; i++){
                out[i].write(out_lv.read()[i]);
            }
            wait(SC_ZERO_TIME);
            wait();
        }                
    }
    
    void key_assignment(void){ 
        while(true) {
            sc_lv<128> key_lv_temp;
            for (int i = 0; i < 128; i++){
                key_lv_temp[i] = key[i].read();
            }
            key_lv.write(key_lv_temp);
            wait(SC_ZERO_TIME);
            wait();
        }                
    }
    void data_assignment(void){ 
        while(true) {
            sc_lv<128> data_lv_temp;
            for (int i = 0; i < 128; i++){
                data_lv_temp[i] = data[i].read();
            }
            data_lv.write(data_lv_temp);
            wait(SC_ZERO_TIME);
            wait();
        }                
    }


    void eval(void){ 
        sc_lv<128> out_temp = key_lv.read() ^ data_lv.read();
        out_lv.write(out_temp);
    }

};
#endif /* __ADDROUNDKEY_H__ */

