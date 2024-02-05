#include <systemc.h>

#ifndef __MIXCOLUMNS_H__
#define __MIXCOLUMNS_H__
using namespace sc_core;

// #ifndef SENSITIVITY(X, Y)
#define SENSITIVITY(X, Y) sensitive << X[Y]
// #endif

SC_MODULE( mixColumns ) {

    sc_in<sc_logic> state_in[128];
    sc_out<sc_logic> state_out[128];

    sc_signal<sc_lv<128>> state_in_lv;
    sc_signal<sc_lv<128>> state_out_lv;

    SC_CTOR( mixColumns ) {
    
        SC_METHOD(eval);
            dont_initialize();
            sensitive << state_in_lv;
        
        // convert w port (array of logic) to w_lv (logic_vector)
        SC_THREAD(state_out_assignment);
            sensitive << state_out_lv;

        // convert key port (array of logic) to state_out_lv (logic_vector)
        SC_THREAD(state_in_assignment);
            for(int i = 0; i < 128; i++){
                    SENSITIVITY(state_in, i);
                }
    }

    void state_out_assignment(void){ 
        while(true) {
            for (int i = 0; i < 128; i++){
                state_out[i].write(state_out_lv.read()[i]);
            }
            wait(SC_ZERO_TIME);
            wait();
        }                
    }
    
    void state_in_assignment(void){ 
        while(true) {
            sc_lv<128> state_in_lv_temp;
            for (int i = 0; i < 128; i++){
                state_in_lv_temp[i] = state_in[i].read();
            }
            state_in_lv.write(state_in_lv_temp);
            wait(SC_ZERO_TIME);
            wait();
        }                
    }

    /* multiply by 2 (Within the Finite Field GF(2^3))
        multiplication by 2 is shifting on bit to the left, 
        if the original 8 bits had a 1 @ MSB, we must use "irreducible Polynomial Theorem" 
        X^4 + X^3 + X + 1
		xor the result with {1b}*/
    sc_lv<8> mb2(sc_lv<8> x){
        sc_lv<8> temp = x << 1;
        sc_lv<8> IPT = "00011011"; // irreducible Polynomial Theorem

        if (x[7] == SC_LOGIC_1)
            temp = temp ^ IPT;
        
        return temp;
    }
    /* multiplication by 3 
	multiplication by 3 is done by:
		multiplication by {02} + xor the original x
		so that 2+1=3. where xor is the addition of elements in finite fields
    */
    sc_lv<8> mb3(sc_lv<8> x){
        sc_lv<8> temp = mb2(x);
        temp = temp ^ x;

        return temp;
    }

    void eval(void){ 
            sc_lv<8> temp_state_out[16];
            temp_state_out[0] = "11100111"; // E7
            temp_state_out[1] = "11010000"; // D0
            temp_state_out[2] = "11001010"; // CA
            temp_state_out[3] = "10111010"; // BA
            temp_state_out[4] = mb3(temp_state_out[3]) ^ temp_state_out[2] ^ temp_state_out[1] ^ mb2(temp_state_out[0]);

            // std::cout << "state_in[0:8]  : "       << state_in_lv.read().range(8 - 1, 0) << std::endl;
            // std::cout << "state_in[0:8]  : 11100111" << std::endl;
            // std::cout << "state_in[8:16] : "       << state_in_lv.read().range((0 + 8) + 8 - 1, 8) << std::endl;
            // std::cout << "state_in[8:16] : 11010000" << std::endl;
            // std::cout << "state_in[16:23]: "       << state_in_lv.read().range((0 + 16) + 8 - 1, 16) << std::endl;
            // std::cout << "state_in[16:23]: 11001010" << std::endl;
            // std::cout << "state_in[24:31]: "       << state_in_lv.read().range((0 + 24) + 8 - 1, 24) << std::endl;
            // std::cout << "state_in[24:31]: 10111010" << std::endl;
            // std::cout << "state_out[0:8] : "       << temp_state_out[4] << std::endl;

            for (int i = 0; i < 4; i++){
                sc_lv<8> temp_0_7   = state_in_lv.read().range(i*32 + 8 - 1, i*32);
                sc_lv<8> temp_8_15  = state_in_lv.read().range((i*32 + 8) + 8 - 1, (i*32 + 8));
                sc_lv<8> temp_16_23 = state_in_lv.read().range((i*32 + 16) + 8 - 1, (i*32 + 16));
                sc_lv<8> temp_24_31 = state_in_lv.read().range((i*32 + 24) + 8 - 1, (i*32 + 24));

                temp_state_out[i*4 + 3] = mb2(temp_24_31) ^ mb3(temp_16_23) ^     temp_8_15  ^     temp_0_7;
                temp_state_out[i*4 + 2] =     temp_24_31  ^ mb2(temp_16_23) ^ mb3(temp_8_15) ^     temp_0_7;
                temp_state_out[i*4 + 1] =     temp_24_31  ^     temp_16_23  ^ mb2(temp_8_15) ^ mb3(temp_0_7);
                temp_state_out[i*4]     = mb3(temp_24_31) ^     temp_16_23  ^     temp_8_15  ^ mb2(temp_0_7);
            }

            state_out_lv = (temp_state_out[15], temp_state_out[14], temp_state_out[13], temp_state_out[12], 
                            temp_state_out[11], temp_state_out[10], temp_state_out[9], temp_state_out[8], 
                            temp_state_out[7], temp_state_out[6], temp_state_out[5], temp_state_out[4], 
                            temp_state_out[3], temp_state_out[2], temp_state_out[1], temp_state_out[0]);

        }

};
#endif /* __MIXCOLUMNS_H__ */

