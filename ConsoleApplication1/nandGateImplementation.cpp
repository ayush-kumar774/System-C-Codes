#include "nandGateDesign.h"

void nand_gate::nandBehavior()
{
	//output.write(!(input1.read() & input2.read()));
	if (input1.read() == true and input2.read() == true) {
		cout <<"Input 1 value " <<input1.read() << endl;
		cout <<"Input 2 value " <<input2.read() << endl;
		output.write(false);
	}
	else {
		cout << "Input 1 value " << input1.read() << endl;
		cout << "Input 2 value " << input2.read() << endl;
		output.write(true);
	}
}

nand_gate::nand_gate(sc_module_name name)
{
	SC_METHOD(nandBehavior);
	sensitive << input1 << input2;
	dont_initialize();
}