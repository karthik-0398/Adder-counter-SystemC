//////////////////////////////////////////////////////////////////////////////////
// Description: Main file for Counter uncorrected
// Author: ks6n19
// Version: 1.0
// Date: 20/May/2020
//////////////////////////////////////////////////////////////////////////////////
#include "systemc.h"
#include "Counter8bit.h"
#include "TestBenchDesign2.h"

SC_MODULE(CounterMain){
      sc_clock clock;
      //sc_signal<bool> clock;
      sc_signal<bool> reset;
      sc_signal<bool> enable;
      sc_signal<sc_uint<8> >counter_out;

Counter8bit counter;
TestBenchDesign2 test1;

SC_CTOR(CounterMain): clock("SystemClock", 2, 0.5, true), counter("Counter1"),test1("Test1"){
         counter.reset(reset);
         counter.enable(enable);
         counter.clock(clock);
         counter.counter_out(counter_out);

         test1.reset(reset);
         test1.enable(enable);
        
}

};
SC_MODULE_EXPORT(CounterMain);

