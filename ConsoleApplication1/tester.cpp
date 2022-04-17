#include "tester.h"

void tester::check_output_port()
{
    cout << (dut_out_observer.read() == 1 ? "HIGH" : "LOW") << endl;
}

void tester::drive_test()
{

    log_msg("Starting test");
    //------------------------
    // Testcase 1
    /*check_output_port();*/
    resetDUT();
    dut_in1_driver.write(1);
    dut_in2_driver.write(0);
    wait(5, SC_NS);
    log_msg("output port for testcase 1 (1, 0) ");
    check_output_port();

    // Testcase 2 
    //resetDUT();
    dut_in1_driver.write(0);
    dut_in2_driver.write(0);
    wait(5, SC_NS);
    log_msg("output port for testcase 2 (0, 0) ");
    check_output_port();

    //sc_stop();

    // Testcase 3 (0, 1 => 0)
    //resetDUT();
    dut_in1_driver.write(0);
    dut_in2_driver.write(1);
    wait(5, SC_NS);
    log_msg("output port for testcase 3 (0, 1) ");
    check_output_port();

    // Testcase 4 (1, 1 => 1)
    //resetDUT();
    dut_in1_driver.write(1);
    dut_in2_driver.write(1);
    wait(5, SC_NS);
    log_msg("output port for testcase 4 (1, 1) ");
    check_output_port();

    log_msg("Ending test");
    //-------------------------
}

void tester::resetDUT()
{
    dut_in1_driver.write(0);
    dut_in2_driver.write(0);
}

tester::tester(sc_module_name name)
{
    // SystemC kernel processes
    // process/method registration
    SC_THREAD(drive_test);
    //dont_initialize();
}