//////////////////////////////////////////////////////////////////////////////////
// Description: Header file for Counter
// Author: ks6n19
// Version: 1.0
// Date: 20/May/2020
//////////////////////////////////////////////////////////////////////////////////

#include "systemc.h"
SC_MODULE (Counter8bit) {

sc_in_clk clock; //maybe try sc_clock clock
sc_in<bool> reset;
sc_in<bool> enable;
sc_out<sc_uint<8> >counter_out; //8bit

sc_uint<8> count; //8bit

void incr_count(){ 
while (true){
     if (enable.read()) {
       if (reset.read()){
         count = 0;
         counter_out.write(count);
         } else {
               count= count+1;
               counter_out.write(count);
               }
       }
       wait();
     }
};
	

SC_CTOR(Counter8bit) {
      SC_THREAD(incr_count);
      sensitive << clock.pos();
      count = 0;
  } // End of Constructor

 
}; 