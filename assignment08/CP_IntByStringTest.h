#ifndef CP_INDBYSTRINGTEST_H
#define CP_INDBYSTRINGTEST_H

#include "CP_IntByString.h"

class CP_IntByStringTest
{
public:
    string m_input;
    CP_IntByString m_int;

    int m_totalTests;
    int m_passedTests;

public:
    // Interactive mode
    void mb_run();

    // Automated check helper
    void mb_check(const string &testName,
                  const CP_IntByString &result,
                  const string &expected);

    // Test groups
    void mb_testAdd();
    void mb_testSub();
    void mb_testMul();
    void mb_testDiv();

    // Run all automated tests
    void mb_runAll();
};

#endif
