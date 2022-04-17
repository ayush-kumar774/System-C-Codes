#pragma once

#include <systemc>
using namespace std;
using namespace sc_core;

class nand_gate : public sc_module {
public:
	sc_in <bool> input1;
	sc_in <bool> input2;
	sc_out <bool> output;

	SC_HAS_PROCESS(nand_gate);
	nand_gate(sc_module_name name);
	void nandBehavior();
};