/*
* ******************************************************************************
*  This file includes the SystemC models of the Nangate 45 nm library cells    *                                             
*  Copyright (C) 2021 University of Teheran                                    *
*  This source file may be used and distributed without restriction provided   *
*  that this copyright statement is not removed from the file and that any     *
*  derivative work contains the original copyright notice and the associated   *
*  disclaimer.                                                                 *
*  Project: QFLOW                                                              *
*  Last Author : Katayoon                                                      *
* ******************************************************************************
*/


#include "systemc.h"

#ifndef __TBUF_H__
#define __TBUF_H__


/*******************************------------------TRI_BUF-----------------*******************************/
/////////////////////////////////////////////////////////////////////////////////////
//    __TBUF_
/*
__________
|A	EN	Z|
|L	L	L|
|H	L	H|
|-	H	Z|
|________|
*/
SC_MODULE(__TBUF_){

	sc_in< sc_logic> A;
	sc_in< sc_logic> E;
	sc_out< sc_logic> Y;

	SC_CTOR(__TBUF_){

		SC_METHOD(eval);
		sensitive << A << E;

	}

	void eval(void){
		if (E->read() == SC_LOGIC_1){
			Y->write(A->read());
		} else {
			Y->write(SC_LOGIC_Z);
		}
	};
};

#endif /* __TBUF_H__ */