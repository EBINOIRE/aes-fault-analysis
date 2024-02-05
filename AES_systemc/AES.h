#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "AES_Encrypt.h"
#include "AES_Decrypt.h"


#ifndef __AES_H__
#define __AES_H__
using namespace sc_core;

#define SENSITIVITY(X, Y) sensitive << X[Y]

SC_MODULE( AES ) {

    sc_in<sc_logic> enable;
    sc_in<sc_logic> in[128];
    sc_in<sc_logic> key128[128];
    sc_in<sc_logic> expected128[128];
    sc_out<sc_logic> decrypted128[128];
    sc_out<sc_logic> encrypted128[128];
    sc_out<sc_logic> e128;
    sc_out<sc_logic> d128;
    AES_Encrypt* a;
    AES_Decrypt* a2;

SC_CTOR( AES ) {

    a = new AES_Encrypt("a");
        for (int i = 0; i < 128; i++)
        {
            a->in[i].bind(in[i]);
            a->key[i].bind(key128[i]);
            a->out[i].bind(encrypted128[i]);
        }
    
    a2 = new AES_Decrypt("a2");
        for (int i = 0; i < 128; i++)
        {
            a2->in[i].bind(encrypted128[i]);
            a2->key[i].bind(key128[i]);
            a2->out[i].bind(decrypted128[i]);
        }



    SC_METHOD(validity_check);
        for(int i = 0; i < 128; i++){
            SENSITIVITY(in, i);
            SENSITIVITY(expected128, i);
            SENSITIVITY(decrypted128, i);
            SENSITIVITY(encrypted128, i);
        }


    }

    void validity_check(void){ 
        if (enable->read() == SC_LOGIC_1){
            e128.write(SC_LOGIC_1);
            d128.write(SC_LOGIC_1);
            for(int i = 0; i < 128; i++){
                if (expected128[i] != encrypted128[i])
                    e128.write(SC_LOGIC_0);
                if (decrypted128[i] != in[i])
                    d128.write(SC_LOGIC_0);
            }
        }
    }
};
#endif /* __AES_H__ */

