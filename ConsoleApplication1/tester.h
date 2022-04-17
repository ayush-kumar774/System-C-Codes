#pragma once
#include <systemc>
using namespace std;
using namespace sc_core;

//SC_MODULE
//SC_CTOR --> SC_HAS_PROCESS
//SC_METHOD XXX
//SC_THREAD XXX


class tester : public sc_module
{
public:
    sc_out<bool> dut_in1_driver;
    sc_out<bool> dut_in2_driver;
    sc_in<bool> dut_out_observer;

    SC_HAS_PROCESS(tester);

    tester(sc_module_name name);

    inline void log_msg(const char* msg)
    {
        cout << "[" << msg << "] @ " << sc_time_stamp() << endl;
    }

    void resetDUT();
    void drive_test();
    void check_output_port();
};