//////////////////////////////////////////////////////////////////////////////////
// Description: Testbench for counter
// Author: ks6n19
// Version: 1.0
// Date: 20/May/2020
//////////////////////////////////////////////////////////////////////////////////
#include "systemc.h"

SC_MODULE(TestBenchDesign2){
         sc_out<bool>reset;
         sc_out<bool>enable;
         //sc_in<bool>clock;

void testprocess(){
     enable.write(false);
     reset.write(false);
     wait(10,SC_NS);

     enable.write(true);
     reset.write(true);
     wait(10,SC_NS);

     enable.write(true);
     reset.write(false);
     wait(10,SC_NS);

     enable.write(false);
     reset.write(true);
     wait(10,SC_NS);

     enable.write(false);
     reset.write(false);
     wait(10,SC_NS);
     }

SC_CTOR(TestBenchDesign2){ 
       SC_THREAD(testprocess);
       //sensitive << clock.pos();
       }
};
