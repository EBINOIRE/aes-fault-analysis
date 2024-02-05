#include <systemc.h>
#include "sbox.h"


#ifndef __SUBBYTES_H__
#define __SUBBYTES_H__
using namespace sc_core;

SC_MODULE( subBytes ) {

    sc_in<sc_logic> in[128];
    sc_out<sc_logic> out[128];

    sbox* sub_Bytes_0;
    sbox* sub_Bytes_1;
    sbox* sub_Bytes_2;
    sbox* sub_Bytes_3;
    sbox* sub_Bytes_4;
    sbox* sub_Bytes_5;
    sbox* sub_Bytes_6;
    sbox* sub_Bytes_7;
    sbox* sub_Bytes_8;
    sbox* sub_Bytes_9;
    sbox* sub_Bytes_10;
    sbox* sub_Bytes_11;
    sbox* sub_Bytes_12;
    sbox* sub_Bytes_13;
    sbox* sub_Bytes_14;
    sbox* sub_Bytes_15;

SC_CTOR( subBytes ) {

    sub_Bytes_0 = new sbox("sub_Bytes_0");
        sub_Bytes_0->a[0](in[0]);
        sub_Bytes_0->a[1](in[1]);
        sub_Bytes_0->a[2](in[2]);
        sub_Bytes_0->a[3](in[3]);
        sub_Bytes_0->a[4](in[4]);
        sub_Bytes_0->a[5](in[5]);
        sub_Bytes_0->a[6](in[6]);
        sub_Bytes_0->a[7](in[7]);
        sub_Bytes_0->c[0](out[0]);
        sub_Bytes_0->c[1](out[1]);
        sub_Bytes_0->c[2](out[2]);
        sub_Bytes_0->c[3](out[3]);
        sub_Bytes_0->c[4](out[4]);
        sub_Bytes_0->c[5](out[5]);
        sub_Bytes_0->c[6](out[6]);
        sub_Bytes_0->c[7](out[7]);


    sub_Bytes_14 = new sbox("sub_Bytes_14");
        sub_Bytes_14->a[0](in[8]);
        sub_Bytes_14->a[1](in[9]);
        sub_Bytes_14->a[2](in[10]);
        sub_Bytes_14->a[3](in[11]);
        sub_Bytes_14->a[4](in[12]);
        sub_Bytes_14->a[5](in[13]);
        sub_Bytes_14->a[6](in[14]);
        sub_Bytes_14->a[7](in[15]);
        sub_Bytes_14->c[0](out[8]);
        sub_Bytes_14->c[1](out[9]);
        sub_Bytes_14->c[2](out[10]);
        sub_Bytes_14->c[3](out[11]);
        sub_Bytes_14->c[4](out[12]);
        sub_Bytes_14->c[5](out[13]);
        sub_Bytes_14->c[6](out[14]);
        sub_Bytes_14->c[7](out[15]);

    sub_Bytes_4 = new sbox("sub_Bytes_4");
        sub_Bytes_4->a[0](in[16]);
        sub_Bytes_4->a[1](in[17]);
        sub_Bytes_4->a[2](in[18]);
        sub_Bytes_4->a[3](in[19]);
        sub_Bytes_4->a[4](in[20]);
        sub_Bytes_4->a[5](in[21]);
        sub_Bytes_4->a[6](in[22]);
        sub_Bytes_4->a[7](in[23]);
        sub_Bytes_4->c[0](out[16]);
        sub_Bytes_4->c[1](out[17]);
        sub_Bytes_4->c[2](out[18]);
        sub_Bytes_4->c[3](out[19]);
        sub_Bytes_4->c[4](out[20]);
        sub_Bytes_4->c[5](out[21]);
        sub_Bytes_4->c[6](out[22]);
        sub_Bytes_4->c[7](out[23]);

    sub_Bytes_5 = new sbox("sub_Bytes_5");
        sub_Bytes_5->a[0](in[24]);
        sub_Bytes_5->a[1](in[25]);
        sub_Bytes_5->a[2](in[26]);
        sub_Bytes_5->a[3](in[27]);
        sub_Bytes_5->a[4](in[28]);
        sub_Bytes_5->a[5](in[29]);
        sub_Bytes_5->a[6](in[30]);
        sub_Bytes_5->a[7](in[31]);
        sub_Bytes_5->c[0](out[24]);
        sub_Bytes_5->c[1](out[25]);
        sub_Bytes_5->c[2](out[26]);
        sub_Bytes_5->c[3](out[27]);
        sub_Bytes_5->c[4](out[28]);
        sub_Bytes_5->c[5](out[29]);
        sub_Bytes_5->c[6](out[30]);
        sub_Bytes_5->c[7](out[31]);

    sub_Bytes_6 = new sbox("sub_Bytes_6");
        sub_Bytes_6->a[0](in[32]);
        sub_Bytes_6->a[1](in[33]);
        sub_Bytes_6->a[2](in[34]);
        sub_Bytes_6->a[3](in[35]);
        sub_Bytes_6->a[4](in[36]);
        sub_Bytes_6->a[5](in[37]);
        sub_Bytes_6->a[6](in[38]);
        sub_Bytes_6->a[7](in[39]);
        sub_Bytes_6->c[0](out[32]);
        sub_Bytes_6->c[1](out[33]);
        sub_Bytes_6->c[2](out[34]);
        sub_Bytes_6->c[3](out[35]);
        sub_Bytes_6->c[4](out[36]);
        sub_Bytes_6->c[5](out[37]);
        sub_Bytes_6->c[6](out[38]);
        sub_Bytes_6->c[7](out[39]);

    sub_Bytes_7 = new sbox("sub_Bytes_7");
        sub_Bytes_7->a[0](in[40]);
        sub_Bytes_7->a[1](in[41]);
        sub_Bytes_7->a[2](in[42]);
        sub_Bytes_7->a[3](in[43]);
        sub_Bytes_7->a[4](in[44]);
        sub_Bytes_7->a[5](in[45]);
        sub_Bytes_7->a[6](in[46]);
        sub_Bytes_7->a[7](in[47]);
        sub_Bytes_7->c[0](out[40]);
        sub_Bytes_7->c[1](out[41]);
        sub_Bytes_7->c[2](out[42]);
        sub_Bytes_7->c[3](out[43]);
        sub_Bytes_7->c[4](out[44]);
        sub_Bytes_7->c[5](out[45]);
        sub_Bytes_7->c[6](out[46]);
        sub_Bytes_7->c[7](out[47]);

    sub_Bytes_8 = new sbox("sub_Bytes_8");
        sub_Bytes_8->a[0](in[48]);
        sub_Bytes_8->a[1](in[49]);
        sub_Bytes_8->a[2](in[50]);
        sub_Bytes_8->a[3](in[51]);
        sub_Bytes_8->a[4](in[52]);
        sub_Bytes_8->a[5](in[53]);
        sub_Bytes_8->a[6](in[54]);
        sub_Bytes_8->a[7](in[55]);
        sub_Bytes_8->c[0](out[48]);
        sub_Bytes_8->c[1](out[49]);
        sub_Bytes_8->c[2](out[50]);
        sub_Bytes_8->c[3](out[51]);
        sub_Bytes_8->c[4](out[52]);
        sub_Bytes_8->c[5](out[53]);
        sub_Bytes_8->c[6](out[54]);
        sub_Bytes_8->c[7](out[55]);

    sub_Bytes_9 = new sbox("sub_Bytes_9");
        sub_Bytes_9->a[0](in[56]);
        sub_Bytes_9->a[1](in[57]);
        sub_Bytes_9->a[2](in[58]);
        sub_Bytes_9->a[3](in[59]);
        sub_Bytes_9->a[4](in[60]);
        sub_Bytes_9->a[5](in[61]);
        sub_Bytes_9->a[6](in[62]);
        sub_Bytes_9->a[7](in[63]);
        sub_Bytes_9->c[0](out[56]);
        sub_Bytes_9->c[1](out[57]);
        sub_Bytes_9->c[2](out[58]);
        sub_Bytes_9->c[3](out[59]);
        sub_Bytes_9->c[4](out[60]);
        sub_Bytes_9->c[5](out[61]);
        sub_Bytes_9->c[6](out[62]);
        sub_Bytes_9->c[7](out[63]);

    sub_Bytes_10 = new sbox("sub_Bytes_10");
        sub_Bytes_10->a[0](in[64]);
        sub_Bytes_10->a[1](in[65]);
        sub_Bytes_10->a[2](in[66]);
        sub_Bytes_10->a[3](in[67]);
        sub_Bytes_10->a[4](in[68]);
        sub_Bytes_10->a[5](in[69]);
        sub_Bytes_10->a[6](in[70]);
        sub_Bytes_10->a[7](in[71]);
        sub_Bytes_10->c[0](out[64]);
        sub_Bytes_10->c[1](out[65]);
        sub_Bytes_10->c[2](out[66]);
        sub_Bytes_10->c[3](out[67]);
        sub_Bytes_10->c[4](out[68]);
        sub_Bytes_10->c[5](out[69]);
        sub_Bytes_10->c[6](out[70]);
        sub_Bytes_10->c[7](out[71]);

    sub_Bytes_11 = new sbox("sub_Bytes_11");
        sub_Bytes_11->a[0](in[72]);
        sub_Bytes_11->a[1](in[73]);
        sub_Bytes_11->a[2](in[74]);
        sub_Bytes_11->a[3](in[75]);
        sub_Bytes_11->a[4](in[76]);
        sub_Bytes_11->a[5](in[77]);
        sub_Bytes_11->a[6](in[78]);
        sub_Bytes_11->a[7](in[79]);
        sub_Bytes_11->c[0](out[72]);
        sub_Bytes_11->c[1](out[73]);
        sub_Bytes_11->c[2](out[74]);
        sub_Bytes_11->c[3](out[75]);
        sub_Bytes_11->c[4](out[76]);
        sub_Bytes_11->c[5](out[77]);
        sub_Bytes_11->c[6](out[78]);
        sub_Bytes_11->c[7](out[79]);

    sub_Bytes_12 = new sbox("sub_Bytes_12");
        sub_Bytes_12->a[0](in[80]);
        sub_Bytes_12->a[1](in[81]);
        sub_Bytes_12->a[2](in[82]);
        sub_Bytes_12->a[3](in[83]);
        sub_Bytes_12->a[4](in[84]);
        sub_Bytes_12->a[5](in[85]);
        sub_Bytes_12->a[6](in[86]);
        sub_Bytes_12->a[7](in[87]);
        sub_Bytes_12->c[0](out[80]);
        sub_Bytes_12->c[1](out[81]);
        sub_Bytes_12->c[2](out[82]);
        sub_Bytes_12->c[3](out[83]);
        sub_Bytes_12->c[4](out[84]);
        sub_Bytes_12->c[5](out[85]);
        sub_Bytes_12->c[6](out[86]);
        sub_Bytes_12->c[7](out[87]);

    sub_Bytes_13 = new sbox("sub_Bytes_13");
        sub_Bytes_13->a[0](in[88]);
        sub_Bytes_13->a[1](in[89]);
        sub_Bytes_13->a[2](in[90]);
        sub_Bytes_13->a[3](in[91]);
        sub_Bytes_13->a[4](in[92]);
        sub_Bytes_13->a[5](in[93]);
        sub_Bytes_13->a[6](in[94]);
        sub_Bytes_13->a[7](in[95]);
        sub_Bytes_13->c[0](out[88]);
        sub_Bytes_13->c[1](out[89]);
        sub_Bytes_13->c[2](out[90]);
        sub_Bytes_13->c[3](out[91]);
        sub_Bytes_13->c[4](out[92]);
        sub_Bytes_13->c[5](out[93]);
        sub_Bytes_13->c[6](out[94]);
        sub_Bytes_13->c[7](out[95]);

    sub_Bytes_15 = new sbox("sub_Bytes_15");
        sub_Bytes_15->a[0](in[96]);
        sub_Bytes_15->a[1](in[97]);
        sub_Bytes_15->a[2](in[98]);
        sub_Bytes_15->a[3](in[99]);
        sub_Bytes_15->a[4](in[100]);
        sub_Bytes_15->a[5](in[101]);
        sub_Bytes_15->a[6](in[102]);
        sub_Bytes_15->a[7](in[103]);
        sub_Bytes_15->c[0](out[96]);
        sub_Bytes_15->c[1](out[97]);
        sub_Bytes_15->c[2](out[98]);
        sub_Bytes_15->c[3](out[99]);
        sub_Bytes_15->c[4](out[100]);
        sub_Bytes_15->c[5](out[101]);
        sub_Bytes_15->c[6](out[102]);
        sub_Bytes_15->c[7](out[103]);


    sub_Bytes_1 = new sbox("sub_Bytes_1");
        sub_Bytes_1->a[0](in[104]);
        sub_Bytes_1->a[1](in[105]);
        sub_Bytes_1->a[2](in[106]);
        sub_Bytes_1->a[3](in[107]);
        sub_Bytes_1->a[4](in[108]);
        sub_Bytes_1->a[5](in[109]);
        sub_Bytes_1->a[6](in[110]);
        sub_Bytes_1->a[7](in[111]);
        sub_Bytes_1->c[0](out[104]);
        sub_Bytes_1->c[1](out[105]);
        sub_Bytes_1->c[2](out[106]);
        sub_Bytes_1->c[3](out[107]);
        sub_Bytes_1->c[4](out[108]);
        sub_Bytes_1->c[5](out[109]);
        sub_Bytes_1->c[6](out[110]);
        sub_Bytes_1->c[7](out[111]);

    sub_Bytes_2 = new sbox("sub_Bytes_2");
        sub_Bytes_2->a[0](in[112]);
        sub_Bytes_2->a[1](in[113]);
        sub_Bytes_2->a[2](in[114]);
        sub_Bytes_2->a[3](in[115]);
        sub_Bytes_2->a[4](in[116]);
        sub_Bytes_2->a[5](in[117]);
        sub_Bytes_2->a[6](in[118]);
        sub_Bytes_2->a[7](in[119]);
        sub_Bytes_2->c[0](out[112]);
        sub_Bytes_2->c[1](out[113]);
        sub_Bytes_2->c[2](out[114]);
        sub_Bytes_2->c[3](out[115]);
        sub_Bytes_2->c[4](out[116]);
        sub_Bytes_2->c[5](out[117]);
        sub_Bytes_2->c[6](out[118]);
        sub_Bytes_2->c[7](out[119]);

    sub_Bytes_3 = new sbox("sub_Bytes_3");
        sub_Bytes_3->a[0](in[120]);
        sub_Bytes_3->a[1](in[121]);
        sub_Bytes_3->a[2](in[122]);
        sub_Bytes_3->a[3](in[123]);
        sub_Bytes_3->a[4](in[124]);
        sub_Bytes_3->a[5](in[125]);
        sub_Bytes_3->a[6](in[126]);
        sub_Bytes_3->a[7](in[127]);
        sub_Bytes_3->c[0](out[120]);
        sub_Bytes_3->c[1](out[121]);
        sub_Bytes_3->c[2](out[122]);
        sub_Bytes_3->c[3](out[123]);
        sub_Bytes_3->c[4](out[124]);
        sub_Bytes_3->c[5](out[125]);
        sub_Bytes_3->c[6](out[126]);
        sub_Bytes_3->c[7](out[127]);

    }

};
#endif /* __SUBBYTES_H__ */

