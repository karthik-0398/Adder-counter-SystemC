//////////////////////////////////////////////////////////////////////////////////
// Description: Testbench for integrated adder and counter
// Author: ks6n19
// Version: 1.0
// Date: 20/May/2020
//////////////////////////////////////////////////////////////////////////////////
#include "systemc.h" //Testbench.h
SC_MODULE(Testbench){
	sc_out<sc_logic> TA, TB, TCin; //changes made here
        sc_out<sc_logic>error;
        sc_out<sc_logic>TSum,TCout;  //changes made here
		 sc_out<bool>reset;  // make changes in CounterMain.cpp to instantate this instead of testbench 2
         sc_out<bool>enable;

	void testprocess(){
                error.write(SC_LOGIC_0);
	 enable.write(false);
     reset.write(false);
     wait(10,SC_NS);

     enable.write(true);
     reset.write(true);
     wait(10,SC_NS);

                //combination 000
		TA.write(SC_LOGIC_0);
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_0&&TCout.read()==SC_LOGIC_0)
                error.write(SC_LOGIC_0);
			    enable.write(false);       // counter does not run if error is 0 
			    reset.write(true);
                wait(10,SC_NS);
                else
                  error.write(SC_LOGIC_1);
			      enable.write(true);  // counter is reset  if error is 1 
				  reset.write(false);
                
                 //combination 001
		TA.write(SC_LOGIC_0);
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_1&&TCout.read()==SC_LOGIC_0)
                error.write(SC_LOGIC_0);
			    enable.write(false);       // counter does not run if error is 0 
			    reset.write(true);			
                else
                  error.write(SC_LOGIC_1);
			      enable.write(true);  // counter is reset if error is 1 
				  reset.write(false);

                //combination 010
		TA.write(SC_LOGIC_0);
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_1&&TCout.read()==SC_LOGIC_0)
                error.write(SC_LOGIC_0);
			    enable.write(false);       // counter does not run if error is 0 
			    reset.write(true);			
                else
                  error.write(SC_LOGIC_1);
			      enable.write(true);  // counter is reset if error is 1 
				  reset.write(false);

                //combination 011
		TA.write(SC_LOGIC_0);
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_0&&TCout.read()==SC_LOGIC_1)
                error.write(SC_LOGIC_0);
			    enable.write(false);       // counter does not  run if error is 0 
			    reset.write(true);			
 			
                else
                  error.write(SC_LOGIC_1);
			      enable.write(true);  // counter is reset if error is 1 
				  reset.write(false);

                //combination 100
		TA.write(SC_LOGIC_1);
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_1&&TCout.read()==SC_LOGIC_0)
                error.write(SC_LOGIC_0);
 			    enable.write(false);       // counter does not runs if error is 0 
			    reset.write(true);			
 
               else
                  error.write(SC_LOGIC_1);
			      enable.write(true);  // counter is reset if error is 1 
				  reset.write(false);


                //combination 101
		TA.write(SC_LOGIC_1);
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_0&&TCout.read()==SC_LOGIC_1)
                error.write(SC_LOGIC_0);
			    enable.write(false);       // counter does not run if error is 0 
			    reset.write(true);			
 			
                else
                  error.write(SC_LOGIC_1);
			      enable.write(true);  // counter is reset if error is 1 
				  reset.write(false);

                //combination 110
		TA.write(SC_LOGIC_1);
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_0&&TCout.read()==SC_LOGIC_1)
                error.write(SC_LOGIC_0);
			    enable.write(false);       // counter does not run if error is 0 
			    reset.write(true);			
 			
                else
                  error.write(SC_LOGIC_1);
			      enable.write(true);  // counter is reset if error is 1 
				  reset.write(false);


		//combination 111
		TA.write(SC_LOGIC_1);
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_1&&TCout.read()==SC_LOGIC_1)
                error.write(SC_LOGIC_0);
			    enable.write(false);       // counter does not run if error is 0 
			    reset.write(true);			
 			
                else
                  error.write(SC_LOGIC_1);
			      enable.write(true);  // counter is reset if error is 1 
				  reset.write(false);

	}
	SC_CTOR(Testbench){
		SC_THREAD(testprocess);
	}
};