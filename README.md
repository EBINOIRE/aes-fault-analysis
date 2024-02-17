# aes-fault-analysis
Fault injection and analysis of AES algorithm

I'm using fault-injection framework in systemc


Feb13:
    change the order of reading data in fault driver
     
    now the right value is preserved but still the signal is not write back into correct value 
    as a matter of fact it is not write back at all 
    or maybe the value that it is write back is equal to xored value of faulty bit 
    look at the fault driver for solution 
    maybe the req value should not be passed by value 