// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc>
#include "mydesign.h"
#include "tester.h"

int sc_main(int argc, char* argv[])
{
	and_gate* dut = new and_gate("dut");
	tester* tt = new tester("tester");

	sc_signal<bool> taar1;
	sc_signal<bool> taar2;
	sc_signal<bool> taar3;

	//sc_trace_file file* = sc_create_vcd_trace_file("trace_file");

	//connecting dut
	dut->in1(taar1); //dut->in.bind(taar1);
	dut->in2(taar2);
	dut->o1(taar3);
	//dut now connected

	//connecting tester
	tt->dut_in1_driver(taar1);
	tt->dut_in2_driver(taar2);
	tt->dut_out_observer(taar3);
	//tester now connected

	//starting simulation
	//cout << sc_time_stamp();
	sc_core::sc_start();
	//cout << sc_time_stamp();

	delete tt;
	delete dut;
	//close_vcd_trace_file(file);
	return 0;
}
//// All systemc modules should include systemc.h header file
//
//#include "systemc.h"
//
//SC_MODULE(hello_world) {
//	SC_CTOR(hello_world) {
//		// Nothing in the constructor
//	}
//	void say_hello() {
//		// Print "Hello World" to the console
//		cout << "Hello World.\n";
//	}
//};
//
//SC_MODULE(and2) {
//    //sc_in <DT> a ; // DT --> Data Type
//    //sc_in <DT> b ; 
//    //sc_out <DT> f ;
//
//    sc_in < sc_uint<1> > a, b;
//    sc_out < sc_uint<1> > f;
//    sc_in <bool> clk;// clock
//
//    void func() {
//        f.write(a.read() & b.read());
//    }
//
//    SC_CTOR(and2) {
//        // Constructor   
//        SC_METHOD(func);
//        //sensitive << a << b ; // in systemC the left shift operator is overloaded to represent a list of sensitive signals or events 
//        //sensitive << clk.pos() ; // positive edge sensitive
//        sensitive << clk.neg(); // negative edge sensitive
//    }
//
//};
//
//SC_MODULE(fir) {
//    sc_in <bool> clk;
//    sc_in <bool> rst;
//    sc_in < sc_int<16> > inp;
//    sc_out < sc_int<16> > outp;
//
//    void fir_main();
//
//    SC_CTOR(fir) {
//        SC_CTHREAD(fir_main, clk.pos());
//        reset_signal_is(rst, true); // true means reset is asserted high while false means reset is asserted low.
//    }
//};
//
//const sc_uint<8> coef[5] = {
//    18,
//    77,
//    107,
//    87,
//    28
//};
//
//// FIR main thread
//void fir::fir_main(void) {
//    sc_int <16> taps[5];
//
//    //Reset code
//    // Reset internal variables
//    outp.write(0);
//    wait();
//
//    while (true) {
//        // read inputs
//        // algorithm codes
//        // write outputs
//
//        for (int i = 5 - 1; i > 0; i--)
//        {
//            taps[i] = taps[i - 1];
//        }
//        taps[0] = inp.read();
//
//        sc_int<16> val;
//        for (int i = 0; i < 5; i++)
//        {
//            val += coef[i] * taps[i];
//        }
//        outp.write(val);
//        wait();
//    }
//}
//
//int sc_main(int argc, char* argv[])
//{
//	hello_world hello("HELLO");
//	// Print the hello world
//	hello.say_hello();
//    /*and2 and_operation("");
//    and_operation.func();*/
//	return 0;
//}