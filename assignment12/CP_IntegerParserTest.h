#ifndef CP_INTEGERPARSERTEST_H
#define CP_INTEGERPARSERTEST_H

#include "CP_IntegerParser.h"

class CP_IntegerParserTest
{
public:
    CP_IntegerParserTest();
    int  runAll();
    void printSummary() const;

private:
    int m_passed;
    int m_failed;

    void test1_ValidIntegers();
    void test2_EmptyString();
    void test3_SignOnly();
    void test4_InvalidChar();
    void test5_LeadingZeros();
    void test6_Overflow();
    void test7_ExtraSign();

    void checkOK(const char *name, const string &input, int expected);
    
    void checkFail(const char *name, const string &input,
                   CP_ErrorCode expectedCode);
    
    void checkFailPos(const char *name, const string &input,
                      CP_ErrorCode expectedCode, int expectedPos);

    void printHeader(const char *title) const;
};

#endif
