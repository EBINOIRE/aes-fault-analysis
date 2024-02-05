#include <systemc.h>

#ifndef __SHIFTROWS_H__
#define __SHIFTROWS_H__
using namespace sc_core;

// #ifndef SENSITIVITY(X, Y)
#define SENSITIVITY(X, Y) sensitive << X[Y]
// #endif

SC_MODULE( shiftRows ) {

    sc_in<sc_logic> in[128];
    sc_out<sc_logic> shifted[128];

    sc_signal<sc_lv<128>> in_lv;
    sc_signal<sc_dt::sc_lv<128>, SC_MANY_WRITERS> shifted_lv;

SC_CTOR( shiftRows ) {
    
    SC_METHOD(eval);
        dont_initialize();
        sensitive << in_lv;
    
    // convert w port (array of logic) to w_lv (logic_vector)
    SC_THREAD(shifted_assignment);
        sensitive << shifted_lv;

    // convert key port (array of logic) to shifted_lv (logic_vector)
    SC_THREAD(in_assignment);
        for(int i = 0; i < 128; i++){
				SENSITIVITY(in, i);
			}
    }

    void shifted_assignment(void){ 
        while(true) {
            for (int i = 0; i < 128; i++){
                shifted[i].write(shifted_lv.read()[i]);
            }
            wait(SC_ZERO_TIME);

            wait();
        }                
    }
    
    void in_assignment(void){ 
        while(true) {
            sc_lv<128> in_lv_temp;
            for (int i = 0; i < 128; i++){
                in_lv_temp[i] = in[i].read();
            }
            in_lv.write(in_lv_temp);
            wait(SC_ZERO_TIME);
            wait();
        }                
    }

    void eval(void){ 
        sc_lv<8> segment_0_7,   segment_8_15,  segment_16_23, segment_24_31;
        sc_lv<8> segment_32_39, segment_40_47, segment_48_55, segment_56_63;
        sc_lv<8> segment_64_71, segment_72_79, segment_80_87, segment_88_95;
        sc_lv<8> segment_96_103, segment_104_111, segment_112_119, segment_120_127;

        // First row (r = 0) is not shifted
        segment_0_7     = in_lv.read().range(7, 0);
        segment_32_39   = in_lv.read().range(39, 32);
        segment_64_71   = in_lv.read().range(71, 64);
        segment_96_103  = in_lv.read().range(103, 96);

        // Second row (r = 1) is cyclically left shifted by 1 offset
        segment_8_15    = in_lv.read().range(47, 40);
        segment_40_47   = in_lv.read().range(79, 72);
        segment_72_79   = in_lv.read().range(111, 104);
        segment_104_111 = in_lv.read().range(15, 8);

        // Third row (r = 2) is cyclically left shifted by 2 offsets
        segment_16_23   = in_lv.read().range(87, 80);
        segment_48_55   = in_lv.read().range(119, 112);
        segment_80_87   = in_lv.read().range(23, 16);
        segment_112_119 = in_lv.read().range(55, 48);

        // Fourth row (r = 3) is cyclically left shifted by 3 offsets
        segment_24_31   = in_lv.read().range(127, 120);
        segment_56_63   = in_lv.read().range(31, 24);
        segment_88_95   = in_lv.read().range(63, 56);
        segment_120_127 = in_lv.read().range(95, 88);

        shifted_lv = (segment_120_127, segment_112_119, segment_104_111, segment_96_103, segment_88_95, segment_80_87, segment_72_79, segment_64_71, segment_56_63, segment_48_55, segment_40_47, segment_32_39, segment_24_31, segment_16_23, segment_8_15, segment_0_7);
        // shifted_lv = (segment_0_7, segment_8_15, segment_16_23, segment_24_31, segment_32_39, segment_40_47, segment_48_55, segment_56_63, segment_64_71, segment_72_79, segment_80_87, segment_88_95, segment_96_103, segment_104_111, segment_112_119, segment_120_127);
    }
};
#endif /* __SHIFTROWS_H__ */

