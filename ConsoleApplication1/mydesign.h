#pragma once

#include <systemc>
using namespace std;
using namespace sc_core;

//SC_MODULE
//SC_CTOR --> SC_HAS_PROCESS
//SC_METHOD XXX
//SC_THREAD XXX

class and_gate : public sc_module
{
public:
    sc_in<bool> in1;
    sc_in<bool> in2;
    sc_out<bool> o1;

    SC_HAS_PROCESS(and_gate);
    and_gate(sc_module_name name);
    void behavior();
};