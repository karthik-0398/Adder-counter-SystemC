//////////////////////////////////////////////////////////////////////////////////
// Description: Testbench for adder
// Author: ks6n19
// Version: 1.0
// Date: 20/May/2020
//////////////////////////////////////////////////////////////////////////////////
#include "systemc.h" //Testbench.h
SC_MODULE(Testbench){
	sc_out<sc_logic> TA, TB, TCin; //changes made here
        sc_out<sc_logic>error;
        sc_out<sc_logic>TSum,TCout;  //changes made here

	void testprocess(){
                error.write(SC_LOGIC_0);

                //combination 000
		TA.write(SC_LOGIC_0);
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_0&&TCout.read()==SC_LOGIC_0)
                error.write(SC_LOGIC_0);
                else
                  error.write(SC_LOGIC_1);
                
                 //combination 001
		TA.write(SC_LOGIC_0);
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_1&&TCout.read()==SC_LOGIC_0)
                error.write(SC_LOGIC_0);
                else
                  error.write(SC_LOGIC_1);

                //combination 010
		TA.write(SC_LOGIC_0);
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_1&&TCout.read()==SC_LOGIC_0)
                error.write(SC_LOGIC_0);
                else
                  error.write(SC_LOGIC_1);

                //combination 011
		TA.write(SC_LOGIC_0);
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_0&&TCout.read()==SC_LOGIC_1)
                error.write(SC_LOGIC_0);
                else
                  error.write(SC_LOGIC_1);

                //combination 100
		TA.write(SC_LOGIC_1);
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_1&&TCout.read()==SC_LOGIC_0)
                error.write(SC_LOGIC_0);
                else
                  error.write(SC_LOGIC_1);


                //combination 101
		TA.write(SC_LOGIC_1);
		TB.write(SC_LOGIC_0);
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_0&&TCout.read()==SC_LOGIC_1)
                error.write(SC_LOGIC_0);
                else
                  error.write(SC_LOGIC_1);

                //combination 110
		TA.write(SC_LOGIC_1);
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_0&&TCout.read()==SC_LOGIC_1)
                error.write(SC_LOGIC_0);
                else
                  error.write(SC_LOGIC_1);


		//combination 111
		TA.write(SC_LOGIC_1);
		TB.write(SC_LOGIC_1);
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS);
                if(TSum.read()==SC_LOGIC_1&&TCout.read()==SC_LOGIC_1)
                error.write(SC_LOGIC_0);
                else
                  error.write(SC_LOGIC_1);
	}
	SC_CTOR(Testbench){
		SC_THREAD(testprocess);
	}
};