#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "addRoundKey.h"
#include "mixColumns.h"
#include "shiftRows.h"
#include "subBytes.h"


#ifndef __ENCRYPTROUND_H__
#define __ENCRYPTROUND_H__
using namespace sc_core;

SC_MODULE( encryptRound ) {

    sc_in<sc_logic>  in[128];
    sc_in<sc_logic>  key[128];
    sc_out<sc_logic> out[128];
    
    sc_signal<sc_logic, SC_MANY_WRITERS> afterSubBytes[128];
    sc_signal<sc_logic, SC_MANY_WRITERS> afterShiftRows[128];
    sc_signal<sc_logic, SC_MANY_WRITERS> afterMixColumns[128];
    sc_signal<sc_logic, SC_MANY_WRITERS> afterAddroundKey[128];

    addRoundKey* b;
    mixColumns* m;
    shiftRows* r;
    subBytes* s;

SC_CTOR( encryptRound ) {

    s = new subBytes("s");
        for(int i = 0; i < 128; i++){
            s->in[i].bind(in[i]);
            s->out[i].bind(afterSubBytes[i]);
        }

    r = new shiftRows("r");
        for (int i = 0; i < 128; i++){
            r->in[127 - i].bind(afterSubBytes[i]);
            r->shifted[127 - i].bind(afterShiftRows[i]);
        }

    m = new mixColumns("m");
        for(int i = 0; i < 128; i++){
            m->state_in[i].bind(afterShiftRows[i]);
            m->state_out[i].bind(afterMixColumns[i]);
        }

    b = new addRoundKey("b");
        for(int i = 0; i < 128; i++){
            b->data[i].bind(afterMixColumns[i]);
            b->out[i].bind(out[i]);
            b->key[i].bind(key[i]);
        }

    }
};
#endif /* __ENCRYPTROUND_H__ */

