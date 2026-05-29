#ifndef CP_VECTOROPTEST_H
#define CP_VECTOROPTEST_H

#include "CP_VectorOp.h"

class CP_VectorOpTest
{
public:
    int m_totalTests;
    int m_passedTests;

public:
    void mb_check(const string &name,bool condition);

    void mb_testGenerate();
    void mb_testScalarMul();
    void mb_testDotProduct();
    void mb_testParallelConsistency();
    void mb_testEdgeCases();

    void mb_runAll();
};

#endif
