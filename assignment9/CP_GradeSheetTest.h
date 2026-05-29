#ifndef CP_GRADESHEETTEST_H
#define CP_GRADESHEETTEST_H

#include "CP_GradeSheet.h"

class CP_GradeSheetTest
{
public:
    int m_totalTests;
    int m_passedTests;

public:
    void mb_check(const string &name,bool condition);

    void mb_testAdd();
    void mb_testRemove();
    void mb_testModify();
    void mb_testQuery();
    void mb_testClear();
    void mb_testFile();
    void mb_testInvalid();

    void mb_runAll();
};

#endif
