#ifndef CP_DYNARRAYTEST_H
#define CP_DYNARRAYTEST_H

#include <string>
using namespace std;

class CP_DynArrayTest
{
public:
    int m_totalTests;
    int m_passedTests;

public:
    void mb_check(const string &name, bool condition);

    void mb_testDefaultCtor();
    void mb_testPtrCtor();
    void mb_testMoveCtor();
    void mb_testMoveAssign();
    void mb_testGet();
    void mb_testSwap();
    void mb_testWithCPA();
    
    void mb_testDListRaw();
    void mb_testDListSmart();

    void mb_runAll();
};

#endif
