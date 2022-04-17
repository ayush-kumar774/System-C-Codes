#include "mydesign.h"

void and_gate::behavior()
{
    //cout << "behavior starting" << endl;
    /*for (int i = 0; i < 1000000000; i++)
    {
    }*/

    o1.write(in1.read() & in2.read());
}

and_gate::and_gate(sc_module_name name)
{
    SC_METHOD(behavior);
    sensitive << in1 << in2;
    dont_initialize();
}