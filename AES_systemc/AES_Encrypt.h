#include <systemc.h>

#include "addRoundKey.h"
#include "keyExpansion.h"
#include "encryptRound.h"
#include "subBytes.h"
#include "shiftRows.h"


#ifndef __AES_ENCRYPT_H__
#define __AES_ENCRYPT_H__
using namespace sc_core;

// #ifndef SENSITIVITY(X, Y)
#define SENSITIVITY(X, Y) sensitive << X[Y]
// #endif

SC_MODULE( AES_Encrypt ) {

    sc_in<sc_logic> in[128];
    sc_in<sc_logic> key[128];
    sc_out<sc_logic> out[128];

    sc_signal<sc_logic, SC_MANY_WRITERS> fullkeys[128*11];
    sc_signal<sc_logic, SC_MANY_WRITERS> states[12][128];
    sc_signal<sc_logic, SC_MANY_WRITERS> afterSubBytes[128];
    sc_signal<sc_dt::sc_logic, SC_MANY_WRITERS> afterShiftRows[128];

    addRoundKey* addrk1;
    addRoundKey* addrk2;
    keyExpansion* ke;
    encryptRound* er[9];
    subBytes* sb;
    shiftRows* sr;

SC_CTOR( AES_Encrypt ) {

        ke = new keyExpansion("ke");
            for (int i = 0; i < 128; i++)
            {
                ke->key[127 - i].bind(key[i]);
            }
            for (int i = 0; i < 1408; i++)
            {
                ke->w[1407 - i].bind(fullkeys[i]);
            }
        
        addrk1 = new addRoundKey("addrk1");
            for (int i = 0; i < 128; i++)
            {
                addrk1->data[i].bind(in[i]);
                addrk1->key[i].bind(key[i]);
                addrk1->out[i].bind(states[0][i]);
            }

        addrk2 = new addRoundKey("addrk2");
            for (int i = 0; i < 128; i++)
            {
                addrk2->data[i].bind(afterShiftRows[i]);
                addrk2->key[i].bind(fullkeys[i]);
                addrk2->out[i].bind(states[10][i]);
            }

        sb = new subBytes("sb");
            for (int i = 0; i < 128; i++)
            {
                sb->in[i].bind(states[9][i]);
                sb->out[i].bind(afterSubBytes[i]);
            }

        sr = new shiftRows("sr");
            for (int i = 0; i < 128; i++)
            {
                sr->in[127 - i].bind(afterSubBytes[i]);
                sr->shifted[127 - i].bind(afterShiftRows[i]);
            }
        
        for (int j = 0; j < 9; j++)
        {
            er[j] = new encryptRound(("loop_er_"+std::to_string(static_cast<unsigned long long>(j))).c_str());
                for (int i = 0; i < 128; i++)
                {
                    er[j]->in[i].bind(states[j][i]);
                    er[j]->key[i].bind(fullkeys[(1408 - (128 * ((j+1)+1))) + i]);
                    er[j]->out[i].bind(states[j+1][i]);
                }
        }

        SC_THREAD(out_assignment);
            for(int i = 0; i < 128; i++){
				SENSITIVITY(states[10], i);
			}
    }

    void out_assignment(void){
        while(true) {
            sc_lv<128> states_10_lv_temp;
            for (int i = 0; i < 128; i++){
                out[i].write(states[10][i].read());
            }
            wait(SC_ZERO_TIME);
            wait();
        } 
    }
};
#endif /* __AES_ENCRYPT_H__ */

