#include "nandGateDesign.h"

void nand_gate::nandBehavior()
{
	output.write(!(input1.read() & input2.read()));
}

nand_gate::nand_gate(sc_module_name name)
{
	SC_METHOD(nandBehavior);
	sensitive << input1 << input2;
	dont_initialize();
}