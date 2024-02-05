#include <systemc.h>
#include "/Users/ebinouri/Documents/UNi/Master_Thesis/Enhancement/AES_systemc/utility_functions.h"

#ifndef __KEYEXPANSION_H__
#define __KEYEXPANSION_H__
using namespace sc_core;


// #ifndef SENSITIVITY(X, Y)
#define SENSITIVITY(X, Y) sensitive << X[Y]
// #endif


SC_MODULE( keyExpansion ) {

    sc_in<sc_logic> key[128];
    sc_out<sc_logic> w[1408];

    sc_signal<sc_lv<1408>> w_lv;
    sc_signal<sc_lv<128>> key_lv;

    sc_lv<32> temp;
    sc_lv<32> r;
    sc_lv<32> rot;
    sc_lv<32> x;
    sc_lv<32> rconv;
    sc_lv<32> new_k;

    sc_lv<1408> w_temp;

SC_CTOR( keyExpansion ) {


    SC_METHOD(eval);
        dont_initialize();
        sensitive << key_lv;
    // convert w port (array of logic) to w_lv (logic_vector)
    SC_THREAD(w_assignment);
        sensitive << w_lv;

    // convert key port (array of logic) to key_lv (logic_vector)
    SC_THREAD(key_assignment);
        // dont_initialize();
        for(int i = 0; i < 128; i++){
				SENSITIVITY(key, i);
			}

    }

    void w_assignment(void){ 
        while(true) {
            for (int i = 0; i < 1408; i++){
                w[1407 - i].write(w_lv.read()[i]);
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
            key_lv.write(key_lv_temp.range(0, 127));
            wait(SC_ZERO_TIME);
            wait();
        }                
    }


    void eval(void){ 
        const char* zeros = zero_fill(1408 - 128).c_str();

        w_temp = (zeros, key_lv.read());
                                        // std::cout << "key(): " << key_lv.read() << std::endl;
                                        
        for (int i = 4; i < 4*(10 + 1); i = i + 1) {
            temp = w_temp.range(1407 - (1407- (32 - 1)), 1407 - (1407));
            // temp = w_temp.range((128 * (10 + 1) - 32), (128 * (10 + 1) - 32) + (32 - 1));
                                        // std::cout << "R [" << i << "]" << std::endl;
                                        // std::cout << "Initial temp: " << temp << std::endl;
                                        // std::cout << "R [" << i << "]- w_temp.range(1407-32, 1407): " << w_temp.range(1407 - (1407- (32 - 1)), 1407 - (1407)) << std::endl;
            if ((i % 4) == 0){
                rot = rotword(temp); // A call to the function rotword() is done and the returned value is stored in rot.
                x = subwordx(rot);	//A call to the function subwordx() is done and the returned value is stored in x.
                rconv = rconx(i/4); //A call to the function rconx() is done and the returned value is stored in rconv.
                temp = x ^ rconv;
            } else if (i % 4 == 4){
                temp = subwordx(temp);
            }

            new_k = w_temp.range((1407 - (128*(10+1)-(4*32))), (1407 - ((128*(10+1)-(4*32))+(32-1)))) ^ temp;
            w_temp = w_temp << 32;
            // w_temp = (w_temp.range(1407 - 0, 1407 - ((128 * (10 + 1) - 32) - 1)), new_k);
            w_temp = (w_temp.range(1407 - 0, 1407 - ((128 * (10 + 1) - 32) - 1)), new_k);
                                        // std::cout << "!!!! "<< std::endl;
                                        // std::cout << "rot: " << rot << std::endl;
                                        // std::cout << "x: " << x << std::endl;
                                        // std::cout << "rconv: " << rconv << std::endl;
                                        // std::cout << "temp: " << temp << std::endl;
                                        // std::cout << "new_k: " << new_k << std::endl;
                                        // std::cout << "W-temp: " << w_temp << std::endl;
                                        // std::cout << "------------------- "<< std::endl;
        }

        w_lv.write(w_temp);
                                        // std::cout << "W : " << w_temp << std::endl;
        
        
    }

};
#endif /* __KEYEXPANSION_H__ */

