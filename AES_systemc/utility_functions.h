#include <systemc.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring> 

#ifndef __UTILITY_FUNCTIONS_H__
#define __UTILITY_FUNCTIONS_H__
using namespace sc_core;

std::string zero_fill(int length){
    std::stringstream strstream;
    std::string str;

    // char arr[length];
    // for (int i = 0; i < length; i++)
    //     arr[i] = '0';
    strstream << std::setfill('0') << std::setw(length) << "0";
    strstream >> str;
    
    return str;
}

template <int size>
sc_lv<size> arraylogic_to_lv(sc_in<sc_logic> signal_array[]){	
    sc_lv<size> temp_lv = 0;

    for (int i = 0; i < size; i++){
        temp_lv[i] = signal_array[i]->read();
    }
    return temp_lv;
}
template <int size>
sc_lv<size> arraylogic_to_lv(sc_out<sc_logic> signal_array[]){	
    sc_lv<size> temp_lv = 0;

    for (int i = 0; i < size; i++){
        temp_lv[i] = signal_array[i]->read();
    }
    return temp_lv;
}

template <int size>
void lv_to_arraylogic(sc_out<sc_logic> signal_array[], sc_lv<size>& lv){	

    for (int i = 0; i < size; i++){
        signal_array[i]->write(lv[i]);
    }
}

// @define: templated function to convert string to vector of logic
//      @input type: string
//      @output type: sc_dt::sc_lv<width>
template <int size>
void str2logic_array(std::string str, sc_signal<sc_logic> logic_array[]){
    std::string::iterator it;
    int i = size - 1;
if (str.length() == size){
    for (it = str.begin(); it != str.end(); it++){
        if ((*it) == '1')
            logic_array[i].write(sc_dt::SC_LOGIC_1);
        else if ((*it) == '0')
            logic_array[i].write(sc_dt::SC_LOGIC_0);
        
        i = i - 1;
        }
    } else {
    std::cout << "length do not match" << std::endl;
    std::cout << "Length of the string: " << str.length() << std::endl;

    }
}

/////////// ----------- AES subroutins

sc_lv<32> rotword(sc_lv<32> sc_lv_input){
    sc_lv<32> sc_lv_temp = (sc_lv_input.range(31 - 8,31 - 31), sc_lv_input.range(31 - 0, 31 - 7));

    return sc_lv_temp;
}


sc_lv<32> rconx(sc_lv<32> sc_lv_input){
    sc_lv<32> sc_lv_temp;

    if (sc_lv_input.to_uint() == 1) 
        sc_lv_temp = 16777216;
    else if (sc_lv_input.to_uint() == 2)
        sc_lv_temp = 33554432;
    else if (sc_lv_input.to_uint() == 3)
        sc_lv_temp = 67108864;
    else if (sc_lv_input.to_uint() == 4)
        sc_lv_temp = 134217728;
    else if (sc_lv_input.to_uint() == 5)
        sc_lv_temp = 268435456;
    else if (sc_lv_input.to_uint() == 6)
        sc_lv_temp = 536870912;
    else if (sc_lv_input.to_uint() == 7)
        sc_lv_temp = 1073741824;
    else if (sc_lv_input.to_uint() == 8)
        sc_lv_temp = 2147483648;
    else if (sc_lv_input.to_uint() == 9)
        sc_lv_temp = 452984832;
    else if (sc_lv_input.to_uint() == 10)
        sc_lv_temp = 905969664;
    else 
        sc_lv_temp = 0;
    
    return sc_lv_temp;
}


sc_lv<8> c(sc_lv<8> sc_lv_input){
    sc_lv<8> sc_lv_temp;

    if (sc_lv_input.to_uint()      == 0) 
        sc_lv_temp = 99;
    else if (sc_lv_input.to_uint() == 1)
        sc_lv_temp = 124;
    else if (sc_lv_input.to_uint() == 2)
        sc_lv_temp = 119;
    else if (sc_lv_input.to_uint() == 3)
        sc_lv_temp = 123;
    else if (sc_lv_input.to_uint() == 4)
        sc_lv_temp = 242;
    else if (sc_lv_input.to_uint() == 5)
        sc_lv_temp = 107;
    else if (sc_lv_input.to_uint() == 6)
        sc_lv_temp = 111;
    else if (sc_lv_input.to_uint() == 7)
        sc_lv_temp = 197;
    else if (sc_lv_input.to_uint() == 8)
        sc_lv_temp = 48;
    else if (sc_lv_input.to_uint() == 9)
        sc_lv_temp = 1;
    else if (sc_lv_input.to_uint() == 10)
        sc_lv_temp = 103;
    else if (sc_lv_input.to_uint() == 11)
        sc_lv_temp = 43;
    else if (sc_lv_input.to_uint() == 12)
        sc_lv_temp = 254;
    else if (sc_lv_input.to_uint() == 13)
        sc_lv_temp = 215;
    else if (sc_lv_input.to_uint() == 14)
        sc_lv_temp = 171;
    else if (sc_lv_input.to_uint() == 15)
        sc_lv_temp = 118;
    else if (sc_lv_input.to_uint() == 16)
        sc_lv_temp = 202;
    else if (sc_lv_input.to_uint() == 17)
        sc_lv_temp = 130;
    else if (sc_lv_input.to_uint() == 18)
        sc_lv_temp = 201;
    else if (sc_lv_input.to_uint() == 19)
        sc_lv_temp = 125;
    else if (sc_lv_input.to_uint() == 20)
        sc_lv_temp = 250;
    else if (sc_lv_input.to_uint() == 21)
        sc_lv_temp = 89;
    else if (sc_lv_input.to_uint() == 22)
        sc_lv_temp = 71;
    else if (sc_lv_input.to_uint() == 23)
        sc_lv_temp = 240;
    else if (sc_lv_input.to_uint() == 24)
        sc_lv_temp = 173;
    else if (sc_lv_input.to_uint() == 25)
        sc_lv_temp = 212;
    else if (sc_lv_input.to_uint() == 26)
        sc_lv_temp = 162;
    else if (sc_lv_input.to_uint() == 27)
        sc_lv_temp = 175;
    else if (sc_lv_input.to_uint() == 28)
        sc_lv_temp = 156;
    else if (sc_lv_input.to_uint() == 29)
        sc_lv_temp = 164;
    else if (sc_lv_input.to_uint() == 30)
        sc_lv_temp = 114;
    else if (sc_lv_input.to_uint() == 31)
        sc_lv_temp = 192;
    else if (sc_lv_input.to_uint() == 32)
        sc_lv_temp = 183;
    else if (sc_lv_input.to_uint() == 33)
        sc_lv_temp = 253;
    else if (sc_lv_input.to_uint() == 34)
        sc_lv_temp = 147;
    else if (sc_lv_input.to_uint() == 35)
        sc_lv_temp = 38;
    else if (sc_lv_input.to_uint() == 36)
        sc_lv_temp = 54;
    else if (sc_lv_input.to_uint() == 37)
        sc_lv_temp = 63;
    else if (sc_lv_input.to_uint() == 38)
        sc_lv_temp = 247;
    else if (sc_lv_input.to_uint() == 39)
        sc_lv_temp = 204;
    else if (sc_lv_input.to_uint() == 40)
        sc_lv_temp = 52;
    else if (sc_lv_input.to_uint() == 41)
        sc_lv_temp = 165;
    else if (sc_lv_input.to_uint() == 42)
        sc_lv_temp = 229;
    else if (sc_lv_input.to_uint() == 43)
        sc_lv_temp = 241;
    else if (sc_lv_input.to_uint() == 44)
        sc_lv_temp = 113;
    else if (sc_lv_input.to_uint() == 45)
        sc_lv_temp = 216;
    else if (sc_lv_input.to_uint() == 46)
        sc_lv_temp = 49;
    else if (sc_lv_input.to_uint() == 47)
        sc_lv_temp = 21;
    else if (sc_lv_input.to_uint() == 48)
        sc_lv_temp = 4;
    else if (sc_lv_input.to_uint() == 49)
        sc_lv_temp = 199;
    else if (sc_lv_input.to_uint() == 50)
        sc_lv_temp = 35;
    else if (sc_lv_input.to_uint() == 51)
        sc_lv_temp = 195;
    else if (sc_lv_input.to_uint() == 52)
        sc_lv_temp = 24;
    else if (sc_lv_input.to_uint() == 53)
        sc_lv_temp = 150;
    else if (sc_lv_input.to_uint() == 54)
        sc_lv_temp = 5;
    else if (sc_lv_input.to_uint() == 55)
        sc_lv_temp = 154;
    else if (sc_lv_input.to_uint() == 56)
        sc_lv_temp = 7;
    else if (sc_lv_input.to_uint() == 57)
        sc_lv_temp = 18;
    else if (sc_lv_input.to_uint() == 58)
        sc_lv_temp = 128;
    else if (sc_lv_input.to_uint() == 59)
        sc_lv_temp = 226;
    else if (sc_lv_input.to_uint() == 60)
        sc_lv_temp = 235;
    else if (sc_lv_input.to_uint() == 61)
        sc_lv_temp = 39;
    else if (sc_lv_input.to_uint() == 62)
        sc_lv_temp = 178;
    else if (sc_lv_input.to_uint() == 63)
        sc_lv_temp = 117;
    else if (sc_lv_input.to_uint() == 64)
        sc_lv_temp = 9;
    else if (sc_lv_input.to_uint() == 65)
        sc_lv_temp = 131;
    else if (sc_lv_input.to_uint() == 66)
        sc_lv_temp = 44;
    else if (sc_lv_input.to_uint() == 67)
        sc_lv_temp = 26;
    else if (sc_lv_input.to_uint() == 68)
        sc_lv_temp = 27;
    else if (sc_lv_input.to_uint() == 69)
        sc_lv_temp = 110;
    else if (sc_lv_input.to_uint() == 70)
        sc_lv_temp = 90;
    else if (sc_lv_input.to_uint() == 71)
        sc_lv_temp = 160;
    else if (sc_lv_input.to_uint() == 72)
        sc_lv_temp = 82;
    else if (sc_lv_input.to_uint() == 73)
        sc_lv_temp = 59;
    else if (sc_lv_input.to_uint() == 74)
        sc_lv_temp = 214;
    else if (sc_lv_input.to_uint() == 75)
        sc_lv_temp = 179;
    else if (sc_lv_input.to_uint() == 76)
        sc_lv_temp = 41;
    else if (sc_lv_input.to_uint() == 77)
        sc_lv_temp = 227;
    else if (sc_lv_input.to_uint() == 78)
        sc_lv_temp = 47;
    else if (sc_lv_input.to_uint() == 79)
        sc_lv_temp = 132;
    else if (sc_lv_input.to_uint() == 80)
        sc_lv_temp = 83;
    else if (sc_lv_input.to_uint() == 81)
        sc_lv_temp = 209;
    else if (sc_lv_input.to_uint() == 82)
        sc_lv_temp = 0;
    else if (sc_lv_input.to_uint() == 83)
        sc_lv_temp = 237;
    else if (sc_lv_input.to_uint() == 84)
        sc_lv_temp = 32;
    else if (sc_lv_input.to_uint() == 85)
        sc_lv_temp = 252;
    else if (sc_lv_input.to_uint() == 86)
        sc_lv_temp = 177;
    else if (sc_lv_input.to_uint() == 87)
        sc_lv_temp = 91;
    else if (sc_lv_input.to_uint() == 88)
        sc_lv_temp = 106;
    else if (sc_lv_input.to_uint() == 89)
        sc_lv_temp = 203;
    else if (sc_lv_input.to_uint() == 90)
        sc_lv_temp = 190;
    else if (sc_lv_input.to_uint() == 91)
        sc_lv_temp = 57;
    else if (sc_lv_input.to_uint() == 92)
        sc_lv_temp = 74;
    else if (sc_lv_input.to_uint() == 93)
        sc_lv_temp = 76;
    else if (sc_lv_input.to_uint() == 94)
        sc_lv_temp = 88;
    else if (sc_lv_input.to_uint() == 95)
        sc_lv_temp = 207;
    else if (sc_lv_input.to_uint() == 96)
        sc_lv_temp = 208;
    else if (sc_lv_input.to_uint() == 97)
        sc_lv_temp = 239;
    else if (sc_lv_input.to_uint() == 98)
        sc_lv_temp = 170;
    else if (sc_lv_input.to_uint() == 99)
        sc_lv_temp = 251;
    else if (sc_lv_input.to_uint() == 100)
        sc_lv_temp = 67;
    else if (sc_lv_input.to_uint() == 101)
        sc_lv_temp = 77;
    else if (sc_lv_input.to_uint() == 102)
        sc_lv_temp = 51;
    else if (sc_lv_input.to_uint() == 103)
        sc_lv_temp = 133;
    else if (sc_lv_input.to_uint() == 104)
        sc_lv_temp = 69;
    else if (sc_lv_input.to_uint() == 105)
        sc_lv_temp = 249;
    else if (sc_lv_input.to_uint() == 106)
        sc_lv_temp = 2;
    else if (sc_lv_input.to_uint() == 107)
        sc_lv_temp = 127;
    else if (sc_lv_input.to_uint() == 108)
        sc_lv_temp = 80;
    else if (sc_lv_input.to_uint() == 109)
        sc_lv_temp = 60;
    else if (sc_lv_input.to_uint() == 110)
        sc_lv_temp = 159;
    else if (sc_lv_input.to_uint() == 111)
        sc_lv_temp = 168;
    else if (sc_lv_input.to_uint() == 112)
        sc_lv_temp = 81;
    else if (sc_lv_input.to_uint() == 113)
        sc_lv_temp = 163;
    else if (sc_lv_input.to_uint() == 114)
        sc_lv_temp = 64;
    else if (sc_lv_input.to_uint() == 115)
        sc_lv_temp = 143;
    else if (sc_lv_input.to_uint() == 116)
        sc_lv_temp = 146;
    else if (sc_lv_input.to_uint() == 117)
        sc_lv_temp = 157;
    else if (sc_lv_input.to_uint() == 118)
        sc_lv_temp = 56;
    else if (sc_lv_input.to_uint() == 119)
        sc_lv_temp = 245;
    else if (sc_lv_input.to_uint() == 120)
        sc_lv_temp = 188;
    else if (sc_lv_input.to_uint() == 121)
        sc_lv_temp = 182;
    else if (sc_lv_input.to_uint() == 122)
        sc_lv_temp = 218;
    else if (sc_lv_input.to_uint() == 123)
        sc_lv_temp = 33;
    else if (sc_lv_input.to_uint() == 124)
        sc_lv_temp = 16;
    else if (sc_lv_input.to_uint() == 125)
        sc_lv_temp = 255;
    else if (sc_lv_input.to_uint() == 126)
        sc_lv_temp = 243;
    else if (sc_lv_input.to_uint() == 127)
        sc_lv_temp = 210;
    else if (sc_lv_input.to_uint() == 128)
        sc_lv_temp = 205;
    else if (sc_lv_input.to_uint() == 129)
        sc_lv_temp = 12;
    else if (sc_lv_input.to_uint() == 130)
        sc_lv_temp = 19;
    else if (sc_lv_input.to_uint() == 131)
        sc_lv_temp = 236;
    else if (sc_lv_input.to_uint() == 132)
        sc_lv_temp = 95;
    else if (sc_lv_input.to_uint() == 133)
        sc_lv_temp = 151;
    else if (sc_lv_input.to_uint() == 134)
        sc_lv_temp = 68;
    else if (sc_lv_input.to_uint() == 135)
        sc_lv_temp = 23;
    else if (sc_lv_input.to_uint() == 136)
        sc_lv_temp = 196;
    else if (sc_lv_input.to_uint() == 137)
        sc_lv_temp = 167;
    else if (sc_lv_input.to_uint() == 138)
        sc_lv_temp = 126;
    else if (sc_lv_input.to_uint() == 139)
        sc_lv_temp = 61;
    else if (sc_lv_input.to_uint() == 140)
        sc_lv_temp = 100;
    else if (sc_lv_input.to_uint() == 141)
        sc_lv_temp = 93;
    else if (sc_lv_input.to_uint() == 142)
        sc_lv_temp = 25;
    else if (sc_lv_input.to_uint() == 143)
        sc_lv_temp = 115;
    else if (sc_lv_input.to_uint() == 144)
        sc_lv_temp = 96;
    else if (sc_lv_input.to_uint() == 145)
        sc_lv_temp = 129;
    else if (sc_lv_input.to_uint() == 146)
        sc_lv_temp = 79;
    else if (sc_lv_input.to_uint() == 147)
        sc_lv_temp = 220;
    else if (sc_lv_input.to_uint() == 148)
        sc_lv_temp = 34;
    else if (sc_lv_input.to_uint() == 149)
        sc_lv_temp = 42;
    else if (sc_lv_input.to_uint() == 150)
        sc_lv_temp = 144;
    else if (sc_lv_input.to_uint() == 151)
        sc_lv_temp = 136;
    else if (sc_lv_input.to_uint() == 152)
        sc_lv_temp = 70;
    else if (sc_lv_input.to_uint() == 153)
        sc_lv_temp = 238;
    else if (sc_lv_input.to_uint() == 154)
        sc_lv_temp = 184;
    else if (sc_lv_input.to_uint() == 155)
        sc_lv_temp = 20;
    else if (sc_lv_input.to_uint() == 156)
        sc_lv_temp = 222;
    else if (sc_lv_input.to_uint() == 157)
        sc_lv_temp = 94;
    else if (sc_lv_input.to_uint() == 158)
        sc_lv_temp = 11;
    else if (sc_lv_input.to_uint() == 159)
        sc_lv_temp = 219;
    else if (sc_lv_input.to_uint() == 160)
        sc_lv_temp = 224;
    else if (sc_lv_input.to_uint() == 161)
        sc_lv_temp = 50;
    else if (sc_lv_input.to_uint() == 162)
        sc_lv_temp = 58;
    else if (sc_lv_input.to_uint() == 163)
        sc_lv_temp = 10;
    else if (sc_lv_input.to_uint() == 164)
        sc_lv_temp = 73;
    else if (sc_lv_input.to_uint() == 165)
        sc_lv_temp = 6;
    else if (sc_lv_input.to_uint() == 166)
        sc_lv_temp = 36;
    else if (sc_lv_input.to_uint() == 167)
        sc_lv_temp = 92;
    else if (sc_lv_input.to_uint() == 168)
        sc_lv_temp = 194;
    else if (sc_lv_input.to_uint() == 169)
        sc_lv_temp = 211;
    else if (sc_lv_input.to_uint() == 170)
        sc_lv_temp = 172;
    else if (sc_lv_input.to_uint() == 171)
        sc_lv_temp = 98;
    else if (sc_lv_input.to_uint() == 172)
        sc_lv_temp = 145;
    else if (sc_lv_input.to_uint() == 173)
        sc_lv_temp = 149;
    else if (sc_lv_input.to_uint() == 174)
        sc_lv_temp = 228;
    else if (sc_lv_input.to_uint() == 175)
        sc_lv_temp = 121;
    else if (sc_lv_input.to_uint() == 176)
        sc_lv_temp = 231;
    else if (sc_lv_input.to_uint() == 177)
        sc_lv_temp = 200;
    else if (sc_lv_input.to_uint() == 178)
        sc_lv_temp = 55;
    else if (sc_lv_input.to_uint() == 179)
        sc_lv_temp = 109;
    else if (sc_lv_input.to_uint() == 180)
        sc_lv_temp = 141;
    else if (sc_lv_input.to_uint() == 181)
        sc_lv_temp = 213;
    else if (sc_lv_input.to_uint() == 182)
        sc_lv_temp = 78;
    else if (sc_lv_input.to_uint() == 183)
        sc_lv_temp = 169;
    else if (sc_lv_input.to_uint() == 184)
        sc_lv_temp = 108;
    else if (sc_lv_input.to_uint() == 185)
        sc_lv_temp = 86;
    else if (sc_lv_input.to_uint() == 186)
        sc_lv_temp = 244;
    else if (sc_lv_input.to_uint() == 187)
        sc_lv_temp = 234;
    else if (sc_lv_input.to_uint() == 188)
        sc_lv_temp = 101;
    else if (sc_lv_input.to_uint() == 189)
        sc_lv_temp = 122;
    else if (sc_lv_input.to_uint() == 190)
        sc_lv_temp = 174;
    else if (sc_lv_input.to_uint() == 191)
        sc_lv_temp = 8;
    else if (sc_lv_input.to_uint() == 192)
        sc_lv_temp = 186;
    else if (sc_lv_input.to_uint() == 193)
        sc_lv_temp = 120;
    else if (sc_lv_input.to_uint() == 194)
        sc_lv_temp = 37;
    else if (sc_lv_input.to_uint() == 195)
        sc_lv_temp = 46;
    else if (sc_lv_input.to_uint() == 196)
        sc_lv_temp = 28;
    else if (sc_lv_input.to_uint() == 197)
        sc_lv_temp = 166;
    else if (sc_lv_input.to_uint() == 198)
        sc_lv_temp = 180;
    else if (sc_lv_input.to_uint() == 199)
        sc_lv_temp = 198;
    else if (sc_lv_input.to_uint() == 200)
        sc_lv_temp = 232;
    else if (sc_lv_input.to_uint() == 201)
        sc_lv_temp = 221;
    else if (sc_lv_input.to_uint() == 202)
        sc_lv_temp = 116;
    else if (sc_lv_input.to_uint() == 203)
        sc_lv_temp = 31;
    else if (sc_lv_input.to_uint() == 204)
        sc_lv_temp = 75;
    else if (sc_lv_input.to_uint() == 205)
        sc_lv_temp = 189;
    else if (sc_lv_input.to_uint() == 206)
        sc_lv_temp = 139;
    else if (sc_lv_input.to_uint() == 207)
        sc_lv_temp = 138;
    else if (sc_lv_input.to_uint() == 208)
        sc_lv_temp = 112;
    else if (sc_lv_input.to_uint() == 209)
        sc_lv_temp = 62;
    else if (sc_lv_input.to_uint() == 210)
        sc_lv_temp = 181;
    else if (sc_lv_input.to_uint() == 211)
        sc_lv_temp = 102;
    else if (sc_lv_input.to_uint() == 212)
        sc_lv_temp = 72;
    else if (sc_lv_input.to_uint() == 213)
        sc_lv_temp = 3;
    else if (sc_lv_input.to_uint() == 214)
        sc_lv_temp = 246;
    else if (sc_lv_input.to_uint() == 215)
        sc_lv_temp = 14;
    else if (sc_lv_input.to_uint() == 216)
        sc_lv_temp = 97;
    else if (sc_lv_input.to_uint() == 217)
        sc_lv_temp = 53;
    else if (sc_lv_input.to_uint() == 218)
        sc_lv_temp = 87;
    else if (sc_lv_input.to_uint() == 219)
        sc_lv_temp = 185;
    else if (sc_lv_input.to_uint() == 220)
        sc_lv_temp = 134;
    else if (sc_lv_input.to_uint() == 221)
        sc_lv_temp = 193;
    else if (sc_lv_input.to_uint() == 222)
        sc_lv_temp = 29;
    else if (sc_lv_input.to_uint() == 223)
        sc_lv_temp = 158;
    else if (sc_lv_input.to_uint() == 224)
        sc_lv_temp = 225;
    else if (sc_lv_input.to_uint() == 225)
        sc_lv_temp = 248;
    else if (sc_lv_input.to_uint() == 226)
        sc_lv_temp = 152;
    else if (sc_lv_input.to_uint() == 227)
        sc_lv_temp = 17;
    else if (sc_lv_input.to_uint() == 228)
        sc_lv_temp = 105;
    else if (sc_lv_input.to_uint() == 229)
        sc_lv_temp = 217;
    else if (sc_lv_input.to_uint() == 230)
        sc_lv_temp = 142;
    else if (sc_lv_input.to_uint() == 231)
        sc_lv_temp = 148;
    else if (sc_lv_input.to_uint() == 232)
        sc_lv_temp = 155;
    else if (sc_lv_input.to_uint() == 233)
        sc_lv_temp = 30;
    else if (sc_lv_input.to_uint() == 234)
        sc_lv_temp = 135;
    else if (sc_lv_input.to_uint() == 235)
        sc_lv_temp = 233;
    else if (sc_lv_input.to_uint() == 236)
        sc_lv_temp = 206;
    else if (sc_lv_input.to_uint() == 237)
        sc_lv_temp = 85;
    else if (sc_lv_input.to_uint() == 238)
        sc_lv_temp = 40;
    else if (sc_lv_input.to_uint() == 239)
        sc_lv_temp = 223;
    else if (sc_lv_input.to_uint() == 240)
        sc_lv_temp = 140;
    else if (sc_lv_input.to_uint() == 241)
        sc_lv_temp = 161;
    else if (sc_lv_input.to_uint() == 242)
        sc_lv_temp = 137;
    else if (sc_lv_input.to_uint() == 243)
        sc_lv_temp = 13;
    else if (sc_lv_input.to_uint() == 244)
        sc_lv_temp = 191;
    else if (sc_lv_input.to_uint() == 245)
        sc_lv_temp = 230;
    else if (sc_lv_input.to_uint() == 246)
        sc_lv_temp = 66;
    else if (sc_lv_input.to_uint() == 247)
        sc_lv_temp = 104;
    else if (sc_lv_input.to_uint() == 248)
        sc_lv_temp = 65;
    else if (sc_lv_input.to_uint() == 249)
        sc_lv_temp = 153;
    else if (sc_lv_input.to_uint() == 250)
        sc_lv_temp = 45;
    else if (sc_lv_input.to_uint() == 251)
        sc_lv_temp = 15;
    else if (sc_lv_input.to_uint() == 252)
        sc_lv_temp = 176;
    else if (sc_lv_input.to_uint() == 253)
        sc_lv_temp = 84;
    else if (sc_lv_input.to_uint() == 254)
        sc_lv_temp = 187;
    else if (sc_lv_input.to_uint() == 255)
        sc_lv_temp = 22;
    else 
        sc_lv_temp = 0;

    return sc_lv_temp;
}

sc_lv<32> subwordx(sc_lv<32> sc_lv_input){

    sc_lv<32> sc_lv_temp = (c(sc_lv_input.range(31 - 0, 31- 7)), c(sc_lv_input.range(31 - 8, 31- 15)), c(sc_lv_input.range(31 - 16, 31- 23)), c(sc_lv_input.range(31 - 24, 31- 31)));
    
    return sc_lv_temp;
}


#endif /* __UTILITY_FUNCTIONS_H__ */
