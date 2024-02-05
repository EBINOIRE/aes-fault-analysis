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
    encryptRound* loop_1__er;
    encryptRound* loop_2__er;
    encryptRound* loop_3__er;
    encryptRound* loop_4__er;
    encryptRound* loop_5__er;
    encryptRound* loop_6__er;
    encryptRound* loop_7__er;
    encryptRound* loop_8__er;
    encryptRound* loop_9__er;
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
        // er[0] = new encryptRound("loop_1__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         er[0]->in[i].bind(states[1 - 1][i]);
        //         er[0]->key[i].bind(fullkeys[(1408 - (128 * (1+1))) + i]);
        //         er[0]->out[i].bind(states[1][i]);
        //     }
            
        // er[1] = new encryptRound("loop_2__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         er[1]->in[i].bind(states[2 - 1][i]);
        //         er[1]->key[i].bind(fullkeys[(1408 - (128 * (2+1))) + i]);
        //         er[1]->out[i].bind(states[2][i]);
        //     }
        // loop_3__er = new encryptRound("loop_3__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         loop_3__er->in[i].bind(states[3 - 1][i]);
        //         loop_3__er->key[i].bind(fullkeys[(1408 - (128 * (3+1))) + i]);
        //         loop_3__er->out[i].bind(states[3][i]);
        //     }
        // loop_4__er = new encryptRound("loop_4__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         loop_4__er->in[i].bind(states[4 - 1][i]);
        //         loop_4__er->key[i].bind(fullkeys[(1408 - (128 * (4+1))) + i]);
        //         loop_4__er->out[i].bind(states[4][i]);
        //     }
        // loop_5__er = new encryptRound("loop_5__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         loop_5__er->in[i].bind(states[5 - 1][i]);
        //         loop_5__er->key[i].bind(fullkeys[(1408 - (128 * (5+1))) + i]);
        //         loop_5__er->out[i].bind(states[5][i]);
        //     }
        // loop_6__er = new encryptRound("loop_6__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         loop_6__er->in[i].bind(states[6 - 1][i]);
        //         loop_6__er->key[i].bind(fullkeys[(1408 - (128 * (6+1))) + i]);
        //         loop_6__er->out[i].bind(states[6][i]);
        //     }
        // loop_7__er = new encryptRound("loop_7__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         loop_7__er->in[i].bind(states[7 - 1][i]);
        //         loop_7__er->key[i].bind(fullkeys[(1408 - (128 * (7+1))) + i]);
        //         loop_7__er->out[i].bind(states[7][i]);
        //     }
        // loop_8__er = new encryptRound("loop_8__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         loop_8__er->in[i].bind(states[8 - 1][i]);
        //         loop_8__er->key[i].bind(fullkeys[(1408 - (128 * (8+1))) + i]);
        //         loop_8__er->out[i].bind(states[8][i]);
        //     }
        // loop_9__er = new encryptRound("loop_9__er");
        //     for (int i = 0; i < 128; i++)
        //     {
        //         loop_9__er->in[i].bind(states[9 - 1][i]);
        //         loop_9__er->key[i].bind(fullkeys[(1408 - (128 * (9+1))) + i]);
        //         loop_9__er->out[i].bind(states[9][i]);
        //     }

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

