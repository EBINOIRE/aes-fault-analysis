#include <systemc.h>

#ifndef __SBOX_H__
#define __SBOX_H__
using namespace sc_core;


// #ifndef SENSITIVITY(X, Y)
#define SENSITIVITY(X, Y) sensitive << X[Y]
// #endif

SC_MODULE( sbox ) {

    sc_in<sc_logic>  a[8];
    sc_out<sc_logic> c[8];

    sc_signal<sc_lv<8>> a_lv;
    sc_signal<sc_lv<8>> c_lv;

SC_CTOR( sbox ) {


    SC_METHOD(eval);
        dont_initialize();
        sensitive << a_lv;
    
    
    // convert w port (array of logic) to w_lv (logic_vector)
    SC_THREAD(c_assignment);
        sensitive << c_lv;

    // convert key port (array of logic) to c_lv (logic_vector)
    SC_THREAD(a_assignment);
        for(int i = 0; i < 8; i++){
				SENSITIVITY(a, i);
			}
    }

    void c_assignment(void){ 
        while(true) {
            for (int i = 0; i < 8; i++){
                c[i].write(c_lv.read()[i]);
            }
            wait(SC_ZERO_TIME);
            wait();
        }                
    }
    
    void a_assignment(void){ 
        while(true) {
            sc_lv<8> a_lv_temp;
            for (int i = 0; i < 8; i++){
                a_lv_temp[i] = a[i].read();
            }
            a_lv.write(a_lv_temp);
            wait(SC_ZERO_TIME);
            wait();
        }                
    }

    void eval(void){ 

        if (a_lv.read().to_uint()      == 0) 
            c_lv = 99;
        else if (a_lv.read().to_uint() == 1)
            c_lv = 124;
        else if (a_lv.read().to_uint() == 2)
            c_lv = 119;
        else if (a_lv.read().to_uint() == 3)
            c_lv = 123;
        else if (a_lv.read().to_uint() == 4)
            c_lv = 242;
        else if (a_lv.read().to_uint() == 5)
            c_lv = 107;
        else if (a_lv.read().to_uint() == 6)
            c_lv = 111;
        else if (a_lv.read().to_uint() == 7)
            c_lv = 197;
        else if (a_lv.read().to_uint() == 8)
            c_lv = 48;
        else if (a_lv.read().to_uint() == 9)
            c_lv = 1;
        else if (a_lv.read().to_uint() == 10)
            c_lv = 103;
        else if (a_lv.read().to_uint() == 11)
            c_lv = 43;
        else if (a_lv.read().to_uint() == 12)
            c_lv = 254;
        else if (a_lv.read().to_uint() == 13)
            c_lv = 215;
        else if (a_lv.read().to_uint() == 14)
            c_lv = 171;
        else if (a_lv.read().to_uint() == 15)
            c_lv = 118;
        else if (a_lv.read().to_uint() == 16)
            c_lv = 202;
        else if (a_lv.read().to_uint() == 17)
            c_lv = 130;
        else if (a_lv.read().to_uint() == 18)
            c_lv = 201;
        else if (a_lv.read().to_uint() == 19)
            c_lv = 125;
        else if (a_lv.read().to_uint() == 20)
            c_lv = 250;
        else if (a_lv.read().to_uint() == 21)
            c_lv = 89;
        else if (a_lv.read().to_uint() == 22)
            c_lv = 71;
        else if (a_lv.read().to_uint() == 23)
            c_lv = 240;
        else if (a_lv.read().to_uint() == 24)
            c_lv = 173;
        else if (a_lv.read().to_uint() == 25)
            c_lv = 212;
        else if (a_lv.read().to_uint() == 26)
            c_lv = 162;
        else if (a_lv.read().to_uint() == 27)
            c_lv = 175;
        else if (a_lv.read().to_uint() == 28)
            c_lv = 156;
        else if (a_lv.read().to_uint() == 29)
            c_lv = 164;
        else if (a_lv.read().to_uint() == 30)
            c_lv = 114;
        else if (a_lv.read().to_uint() == 31)
            c_lv = 192;
        else if (a_lv.read().to_uint() == 32)
            c_lv = 183;
        else if (a_lv.read().to_uint() == 33)
            c_lv = 253;
        else if (a_lv.read().to_uint() == 34)
            c_lv = 147;
        else if (a_lv.read().to_uint() == 35)
            c_lv = 38;
        else if (a_lv.read().to_uint() == 36)
            c_lv = 54;
        else if (a_lv.read().to_uint() == 37)
            c_lv = 63;
        else if (a_lv.read().to_uint() == 38)
            c_lv = 247;
        else if (a_lv.read().to_uint() == 39)
            c_lv = 204;
        else if (a_lv.read().to_uint() == 40)
            c_lv = 52;
        else if (a_lv.read().to_uint() == 41)
            c_lv = 165;
        else if (a_lv.read().to_uint() == 42)
            c_lv = 229;
        else if (a_lv.read().to_uint() == 43)
            c_lv = 241;
        else if (a_lv.read().to_uint() == 44)
            c_lv = 113;
        else if (a_lv.read().to_uint() == 45)
            c_lv = 216;
        else if (a_lv.read().to_uint() == 46)
            c_lv = 49;
        else if (a_lv.read().to_uint() == 47)
            c_lv = 21;
        else if (a_lv.read().to_uint() == 48)
            c_lv = 4;
        else if (a_lv.read().to_uint() == 49)
            c_lv = 199;
        else if (a_lv.read().to_uint() == 50)
            c_lv = 35;
        else if (a_lv.read().to_uint() == 51)
            c_lv = 195;
        else if (a_lv.read().to_uint() == 52)
            c_lv = 24;
        else if (a_lv.read().to_uint() == 53)
            c_lv = 150;
        else if (a_lv.read().to_uint() == 54)
            c_lv = 5;
        else if (a_lv.read().to_uint() == 55)
            c_lv = 154;
        else if (a_lv.read().to_uint() == 56)
            c_lv = 7;
        else if (a_lv.read().to_uint() == 57)
            c_lv = 18;
        else if (a_lv.read().to_uint() == 58)
            c_lv = 128;
        else if (a_lv.read().to_uint() == 59)
            c_lv = 226;
        else if (a_lv.read().to_uint() == 60)
            c_lv = 235;
        else if (a_lv.read().to_uint() == 61)
            c_lv = 39;
        else if (a_lv.read().to_uint() == 62)
            c_lv = 178;
        else if (a_lv.read().to_uint() == 63)
            c_lv = 117;
        else if (a_lv.read().to_uint() == 64)
            c_lv = 9;
        else if (a_lv.read().to_uint() == 65)
            c_lv = 131;
        else if (a_lv.read().to_uint() == 66)
            c_lv = 44;
        else if (a_lv.read().to_uint() == 67)
            c_lv = 26;
        else if (a_lv.read().to_uint() == 68)
            c_lv = 27;
        else if (a_lv.read().to_uint() == 69)
            c_lv = 110;
        else if (a_lv.read().to_uint() == 70)
            c_lv = 90;
        else if (a_lv.read().to_uint() == 71)
            c_lv = 160;
        else if (a_lv.read().to_uint() == 72)
            c_lv = 82;
        else if (a_lv.read().to_uint() == 73)
            c_lv = 59;
        else if (a_lv.read().to_uint() == 74)
            c_lv = 214;
        else if (a_lv.read().to_uint() == 75)
            c_lv = 179;
        else if (a_lv.read().to_uint() == 76)
            c_lv = 41;
        else if (a_lv.read().to_uint() == 77)
            c_lv = 227;
        else if (a_lv.read().to_uint() == 78)
            c_lv = 47;
        else if (a_lv.read().to_uint() == 79)
            c_lv = 132;
        else if (a_lv.read().to_uint() == 80)
            c_lv = 83;
        else if (a_lv.read().to_uint() == 81)
            c_lv = 209;
        else if (a_lv.read().to_uint() == 82)
            c_lv = 0;
        else if (a_lv.read().to_uint() == 83)
            c_lv = 237;
        else if (a_lv.read().to_uint() == 84)
            c_lv = 32;
        else if (a_lv.read().to_uint() == 85)
            c_lv = 252;
        else if (a_lv.read().to_uint() == 86)
            c_lv = 177;
        else if (a_lv.read().to_uint() == 87)
            c_lv = 91;
        else if (a_lv.read().to_uint() == 88)
            c_lv = 106;
        else if (a_lv.read().to_uint() == 89)
            c_lv = 203;
        else if (a_lv.read().to_uint() == 90)
            c_lv = 190;
        else if (a_lv.read().to_uint() == 91)
            c_lv = 57;
        else if (a_lv.read().to_uint() == 92)
            c_lv = 74;
        else if (a_lv.read().to_uint() == 93)
            c_lv = 76;
        else if (a_lv.read().to_uint() == 94)
            c_lv = 88;
        else if (a_lv.read().to_uint() == 95)
            c_lv = 207;
        else if (a_lv.read().to_uint() == 96)
            c_lv = 208;
        else if (a_lv.read().to_uint() == 97)
            c_lv = 239;
        else if (a_lv.read().to_uint() == 98)
            c_lv = 170;
        else if (a_lv.read().to_uint() == 99)
            c_lv = 251;
        else if (a_lv.read().to_uint() == 100)
            c_lv = 67;
        else if (a_lv.read().to_uint() == 101)
            c_lv = 77;
        else if (a_lv.read().to_uint() == 102)
            c_lv = 51;
        else if (a_lv.read().to_uint() == 103)
            c_lv = 133;
        else if (a_lv.read().to_uint() == 104)
            c_lv = 69;
        else if (a_lv.read().to_uint() == 105)
            c_lv = 249;
        else if (a_lv.read().to_uint() == 106)
            c_lv = 2;
        else if (a_lv.read().to_uint() == 107)
            c_lv = 127;
        else if (a_lv.read().to_uint() == 108)
            c_lv = 80;
        else if (a_lv.read().to_uint() == 109)
            c_lv = 60;
        else if (a_lv.read().to_uint() == 110)
            c_lv = 159;
        else if (a_lv.read().to_uint() == 111)
            c_lv = 168;
        else if (a_lv.read().to_uint() == 112)
            c_lv = 81;
        else if (a_lv.read().to_uint() == 113)
            c_lv = 163;
        else if (a_lv.read().to_uint() == 114)
            c_lv = 64;
        else if (a_lv.read().to_uint() == 115)
            c_lv = 143;
        else if (a_lv.read().to_uint() == 116)
            c_lv = 146;
        else if (a_lv.read().to_uint() == 117)
            c_lv = 157;
        else if (a_lv.read().to_uint() == 118)
            c_lv = 56;
        else if (a_lv.read().to_uint() == 119)
            c_lv = 245;
        else if (a_lv.read().to_uint() == 120)
            c_lv = 188;
        else if (a_lv.read().to_uint() == 121)
            c_lv = 182;
        else if (a_lv.read().to_uint() == 122)
            c_lv = 218;
        else if (a_lv.read().to_uint() == 123)
            c_lv = 33;
        else if (a_lv.read().to_uint() == 124)
            c_lv = 16;
        else if (a_lv.read().to_uint() == 125)
            c_lv = 255;
        else if (a_lv.read().to_uint() == 126)
            c_lv = 243;
        else if (a_lv.read().to_uint() == 127)
            c_lv = 210;
        else if (a_lv.read().to_uint() == 128)
            c_lv = 205;
        else if (a_lv.read().to_uint() == 129)
            c_lv = 12;
        else if (a_lv.read().to_uint() == 130)
            c_lv = 19;
        else if (a_lv.read().to_uint() == 131)
            c_lv = 236;
        else if (a_lv.read().to_uint() == 132)
            c_lv = 95;
        else if (a_lv.read().to_uint() == 133)
            c_lv = 151;
        else if (a_lv.read().to_uint() == 134)
            c_lv = 68;
        else if (a_lv.read().to_uint() == 135)
            c_lv = 23;
        else if (a_lv.read().to_uint() == 136)
            c_lv = 196;
        else if (a_lv.read().to_uint() == 137)
            c_lv = 167;
        else if (a_lv.read().to_uint() == 138)
            c_lv = 126;
        else if (a_lv.read().to_uint() == 139)
            c_lv = 61;
        else if (a_lv.read().to_uint() == 140)
            c_lv = 100;
        else if (a_lv.read().to_uint() == 141)
            c_lv = 93;
        else if (a_lv.read().to_uint() == 142)
            c_lv = 25;
        else if (a_lv.read().to_uint() == 143)
            c_lv = 115;
        else if (a_lv.read().to_uint() == 144)
            c_lv = 96;
        else if (a_lv.read().to_uint() == 145)
            c_lv = 129;
        else if (a_lv.read().to_uint() == 146)
            c_lv = 79;
        else if (a_lv.read().to_uint() == 147)
            c_lv = 220;
        else if (a_lv.read().to_uint() == 148)
            c_lv = 34;
        else if (a_lv.read().to_uint() == 149)
            c_lv = 42;
        else if (a_lv.read().to_uint() == 150)
            c_lv = 144;
        else if (a_lv.read().to_uint() == 151)
            c_lv = 136;
        else if (a_lv.read().to_uint() == 152)
            c_lv = 70;
        else if (a_lv.read().to_uint() == 153)
            c_lv = 238;
        else if (a_lv.read().to_uint() == 154)
            c_lv = 184;
        else if (a_lv.read().to_uint() == 155)
            c_lv = 20;
        else if (a_lv.read().to_uint() == 156)
            c_lv = 222;
        else if (a_lv.read().to_uint() == 157)
            c_lv = 94;
        else if (a_lv.read().to_uint() == 158)
            c_lv = 11;
        else if (a_lv.read().to_uint() == 159)
            c_lv = 219;
        else if (a_lv.read().to_uint() == 160)
            c_lv = 224;
        else if (a_lv.read().to_uint() == 161)
            c_lv = 50;
        else if (a_lv.read().to_uint() == 162)
            c_lv = 58;
        else if (a_lv.read().to_uint() == 163)
            c_lv = 10;
        else if (a_lv.read().to_uint() == 164)
            c_lv = 73;
        else if (a_lv.read().to_uint() == 165)
            c_lv = 6;
        else if (a_lv.read().to_uint() == 166)
            c_lv = 36;
        else if (a_lv.read().to_uint() == 167)
            c_lv = 92;
        else if (a_lv.read().to_uint() == 168)
            c_lv = 194;
        else if (a_lv.read().to_uint() == 169)
            c_lv = 211;
        else if (a_lv.read().to_uint() == 170)
            c_lv = 172;
        else if (a_lv.read().to_uint() == 171)
            c_lv = 98;
        else if (a_lv.read().to_uint() == 172)
            c_lv = 145;
        else if (a_lv.read().to_uint() == 173)
            c_lv = 149;
        else if (a_lv.read().to_uint() == 174)
            c_lv = 228;
        else if (a_lv.read().to_uint() == 175)
            c_lv = 121;
        else if (a_lv.read().to_uint() == 176)
            c_lv = 231;
        else if (a_lv.read().to_uint() == 177)
            c_lv = 200;
        else if (a_lv.read().to_uint() == 178)
            c_lv = 55;
        else if (a_lv.read().to_uint() == 179)
            c_lv = 109;
        else if (a_lv.read().to_uint() == 180)
            c_lv = 141;
        else if (a_lv.read().to_uint() == 181)
            c_lv = 213;
        else if (a_lv.read().to_uint() == 182)
            c_lv = 78;
        else if (a_lv.read().to_uint() == 183)
            c_lv = 169;
        else if (a_lv.read().to_uint() == 184)
            c_lv = 108;
        else if (a_lv.read().to_uint() == 185)
            c_lv = 86;
        else if (a_lv.read().to_uint() == 186)
            c_lv = 244;
        else if (a_lv.read().to_uint() == 187)
            c_lv = 234;
        else if (a_lv.read().to_uint() == 188)
            c_lv = 101;
        else if (a_lv.read().to_uint() == 189)
            c_lv = 122;
        else if (a_lv.read().to_uint() == 190)
            c_lv = 174;
        else if (a_lv.read().to_uint() == 191)
            c_lv = 8;
        else if (a_lv.read().to_uint() == 192)
            c_lv = 186;
        else if (a_lv.read().to_uint() == 193)
            c_lv = 120;
        else if (a_lv.read().to_uint() == 194)
            c_lv = 37;
        else if (a_lv.read().to_uint() == 195)
            c_lv = 46;
        else if (a_lv.read().to_uint() == 196)
            c_lv = 28;
        else if (a_lv.read().to_uint() == 197)
            c_lv = 166;
        else if (a_lv.read().to_uint() == 198)
            c_lv = 180;
        else if (a_lv.read().to_uint() == 199)
            c_lv = 198;
        else if (a_lv.read().to_uint() == 200)
            c_lv = 232;
        else if (a_lv.read().to_uint() == 201)
            c_lv = 221;
        else if (a_lv.read().to_uint() == 202)
            c_lv = 116;
        else if (a_lv.read().to_uint() == 203)
            c_lv = 31;
        else if (a_lv.read().to_uint() == 204)
            c_lv = 75;
        else if (a_lv.read().to_uint() == 205)
            c_lv = 189;
        else if (a_lv.read().to_uint() == 206)
            c_lv = 139;
        else if (a_lv.read().to_uint() == 207)
            c_lv = 138;
        else if (a_lv.read().to_uint() == 208)
            c_lv = 112;
        else if (a_lv.read().to_uint() == 209)
            c_lv = 62;
        else if (a_lv.read().to_uint() == 210)
            c_lv = 181;
        else if (a_lv.read().to_uint() == 211)
            c_lv = 102;
        else if (a_lv.read().to_uint() == 212)
            c_lv = 72;
        else if (a_lv.read().to_uint() == 213)
            c_lv = 3;
        else if (a_lv.read().to_uint() == 214)
            c_lv = 246;
        else if (a_lv.read().to_uint() == 215)
            c_lv = 14;
        else if (a_lv.read().to_uint() == 216)
            c_lv = 97;
        else if (a_lv.read().to_uint() == 217)
            c_lv = 53;
        else if (a_lv.read().to_uint() == 218)
            c_lv = 87;
        else if (a_lv.read().to_uint() == 219)
            c_lv = 185;
        else if (a_lv.read().to_uint() == 220)
            c_lv = 134;
        else if (a_lv.read().to_uint() == 221)
            c_lv = 193;
        else if (a_lv.read().to_uint() == 222)
            c_lv = 29;
        else if (a_lv.read().to_uint() == 223)
            c_lv = 158;
        else if (a_lv.read().to_uint() == 224)
            c_lv = 225;
        else if (a_lv.read().to_uint() == 225)
            c_lv = 248;
        else if (a_lv.read().to_uint() == 226)
            c_lv = 152;
        else if (a_lv.read().to_uint() == 227)
            c_lv = 17;
        else if (a_lv.read().to_uint() == 228)
            c_lv = 105;
        else if (a_lv.read().to_uint() == 229)
            c_lv = 217;
        else if (a_lv.read().to_uint() == 230)
            c_lv = 142;
        else if (a_lv.read().to_uint() == 231)
            c_lv = 148;
        else if (a_lv.read().to_uint() == 232)
            c_lv = 155;
        else if (a_lv.read().to_uint() == 233)
            c_lv = 30;
        else if (a_lv.read().to_uint() == 234)
            c_lv = 135;
        else if (a_lv.read().to_uint() == 235)
            c_lv = 233;
        else if (a_lv.read().to_uint() == 236)
            c_lv = 206;
        else if (a_lv.read().to_uint() == 237)
            c_lv = 85;
        else if (a_lv.read().to_uint() == 238)
            c_lv = 40;
        else if (a_lv.read().to_uint() == 239)
            c_lv = 223;
        else if (a_lv.read().to_uint() == 240)
            c_lv = 140;
        else if (a_lv.read().to_uint() == 241)
            c_lv = 161;
        else if (a_lv.read().to_uint() == 242)
            c_lv = 137;
        else if (a_lv.read().to_uint() == 243)
            c_lv = 13;
        else if (a_lv.read().to_uint() == 244)
            c_lv = 191;
        else if (a_lv.read().to_uint() == 245)
            c_lv = 230;
        else if (a_lv.read().to_uint() == 246)
            c_lv = 66;
        else if (a_lv.read().to_uint() == 247)
            c_lv = 104;
        else if (a_lv.read().to_uint() == 248)
            c_lv = 65;
        else if (a_lv.read().to_uint() == 249)
            c_lv = 153;
        else if (a_lv.read().to_uint() == 250)
            c_lv = 45;
        else if (a_lv.read().to_uint() == 251)
            c_lv = 15;
        else if (a_lv.read().to_uint() == 252)
            c_lv = 176;
        else if (a_lv.read().to_uint() == 253)
            c_lv = 84;
        else if (a_lv.read().to_uint() == 254)
            c_lv = 187;
        else if (a_lv.read().to_uint() == 255)
            c_lv = 22;
        else 
            c_lv = 0;

    }

};
#endif /* __SBOX_H__ */
