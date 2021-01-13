//////////////////////////////////////////////////////////////////////////////////
// Description: Main for Adder 
// Author: ks6n19
// Version: 1.0
// Date: 20/May/2020
//////////////////////////////////////////////////////////////////////////////////
#include "Adder.h"
#include "Testbench.h"

SC_MODULE(AdderMain){
	//Declare signals to be tied to the modules
	sc_signal<sc_logic> A_s,B_s,CIN_s;
	sc_signal<sc_logic> SUM_s,COUT_s;
	
	Adder adder1;
	Testbench test1;
          
        sc_signal<sc_logic>error_s;

	//Instantiate Adder and Bind Ports
	SC_CTOR(AdderMain): adder1("Adder"), test1("TestBench"){
	  adder1.A(A_s);
	  adder1.B(B_s);
	  adder1.Cin(CIN_s);
	  adder1.sum(SUM_s);
	  adder1.Cout(COUT_s);
	  
	  //Instantiate Testbench And Bind Ports
	  test1.TA(A_s);
	  test1.TB(B_s);
	  test1.TCin(CIN_s);
          test1.TSum(SUM_s);
          test1.TCout(COUT_s);
          test1.error(error_s);
	}
};

SC_MODULE_EXPORT(AdderMain);
