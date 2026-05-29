#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
using namespace std;

#include "CP_IntegerParserTest.h"

CP_IntegerParserTest::CP_IntegerParserTest()
    : m_passed(0), m_failed(0) {}

void CP_IntegerParserTest::printHeader(const char *title) const
{
    cout << "\n-- " << title << " --" << endl;
}

void CP_IntegerParserTest::checkOK(const char *name, const string &input, int expected)
{
    try
    {
        int result = CP_IntegerParser::mbs_parse(input);
        if (result == expected)
        {
            cout << "| [PASS] " << left << setw(52) << name << endl;
            ++m_passed;
        }
        else
        {
            cout << "| [FAIL] " << left << setw(52) << name
                 << "  got=" << result << " exp=" << expected << endl;
            ++m_failed;
        }
    }
    catch (CP_IntegerException &e)
    {
        cout << "| [FAIL] " << left << setw(52) << name
             << "  unexpected exception: " << e.mb_codeName() << endl;
        ++m_failed;
    }
}

void CP_IntegerParserTest::checkFail(const char *name, 
    const string &input, CP_ErrorCode expectedCode)
{
    try
    {
        int result = CP_IntegerParser::mbs_parse(input);
        cout << "| [FAIL] " << left << setw(52) << name
             << "  no exception, got=" << result << endl;
        ++m_failed;
    }
    catch (CP_IntegerException &e)
    {
        if (e.m_code == expectedCode)
        {
            cout << "| [PASS] " << left << setw(52) << name << endl;
            ++m_passed;
        }
        else
        {
            cout << "| [FAIL] " << left << setw(52) << name
                 << "  code=" << e.mb_codeName()
                 << " exp=" << expectedCode << endl;
            ++m_failed;
        }
    }
}

void CP_IntegerParserTest::checkFailPos(const char *name, 
    const string &input, CP_ErrorCode expectedCode, int expectedPos)
{
    try
    {
        int result = CP_IntegerParser::mbs_parse(input);
        cout << "| [FAIL] " << left << setw(52) << name
             << "  no exception, got=" << result << endl;
        ++m_failed;
    }
    catch (CP_IntegerException &e)
    {
        if (e.m_code == expectedCode && e.m_position == expectedPos)
        {
            cout << "| [PASS] " << left << setw(52) << name << endl;
            ++m_passed;
        }
        else
        {
            cout << "| [FAIL] " << left << setw(52) << name
                 << "  code=" << e.mb_codeName() << " pos=" << e.m_position
                 << " exp_code=" << expectedCode
                 << " exp_pos=" << expectedPos << endl;
            ++m_failed;
        }
    }
}

void CP_IntegerParserTest::test1_ValidIntegers()
{
    printHeader("T1: Valid integers");
    checkOK("\"0\" -> 0", "0", 0);
    checkOK("\"123\" -> 123", "123", 123);
    checkOK("\"-456\" -> -456", "-456", -456);
    checkOK("\"+789\" -> 789", "+789", 789);
    checkOK("\"1\" -> 1", "1", 1);
    checkOK("\"-1\" -> -1", "-1", -1);
    checkOK("\"+0\" -> 0", "+0", 0);
    checkOK("\"-0\" -> 0", "-0", 0);
    checkOK("\"2147483647\" (INT_MAX)", "2147483647", INT_MAX);
    checkOK("\"-2147483648\" (INT_MIN)", "-2147483648", INT_MIN);
}

void CP_IntegerParserTest::test2_EmptyString()
{
    printHeader("T2: Empty string -> CE_EMPTY_STRING");
    checkFail("\"\" -> EMPTY_STRING", "", CE_EMPTY_STRING);
}

void CP_IntegerParserTest::test3_SignOnly()
{
    printHeader("T3: Sign only -> CE_SIGN_ONLY");
    checkFail("\"+\" -> SIGN_ONLY", "+", CE_SIGN_ONLY);
    checkFail("\"-\" -> SIGN_ONLY", "-", CE_SIGN_ONLY);
}

void CP_IntegerParserTest::test4_InvalidChar()
{
    printHeader("T4: Invalid character -> CE_INVALID_CHAR");
    checkFailPos("\"12a3\" pos=2", "12a3", CE_INVALID_CHAR, 2);
    checkFailPos("\"abc\" pos=0", "abc", CE_INVALID_CHAR, 0);
    checkFailPos("\"12 3\" space pos=2", "12 3", CE_INVALID_CHAR, 2);
    checkFailPos("\"3.14\" decimal pos=1", "3.14", CE_INVALID_CHAR, 1);
    checkFailPos("\"12#4\" special pos=2", "12#4", CE_INVALID_CHAR, 2);
    checkFailPos("\"-12a\" pos=3", "-12a", CE_INVALID_CHAR, 3);
    checkFailPos("\" 123\" leading space pos=0", " 123", CE_INVALID_CHAR, 0);
}

void CP_IntegerParserTest::test5_LeadingZeros()
{
    printHeader("T5: Leading zeros -> CE_LEADING_ZEROS");
    checkFailPos("\"0123\" pos=0", "0123", CE_LEADING_ZEROS, 0);
    checkFailPos("\"-0123\" pos=1", "-0123", CE_LEADING_ZEROS, 1);
    checkFailPos("\"+0123\" pos=1", "+0123", CE_LEADING_ZEROS, 1);
    checkFailPos("\"00\" pos=0", "00", CE_LEADING_ZEROS, 0);
    checkFailPos("\"007\" pos=0", "007", CE_LEADING_ZEROS, 0);
}

void CP_IntegerParserTest::test6_Overflow()
{
    printHeader("T6: Overflow -> CE_OVERFLOW");
    checkFail("\"2147483648\" -> OVERFLOW", "2147483648", CE_OVERFLOW);
    checkFail("\"-2147483649\" -> OVERFLOW", "-2147483649", CE_OVERFLOW);
    checkFail("\"99999999999\" -> OVERFLOW", "99999999999", CE_OVERFLOW);
    checkFail("\"9999999999999999\" -> OVERFLOW",
              "9999999999999999", CE_OVERFLOW);
}

void CP_IntegerParserTest::test7_ExtraSign()
{
    printHeader("T7: Extra/misplaced sign -> CE_EXTRA_SIGN");
    checkFailPos("\"12+3\" pos=2", "12+3",   CE_EXTRA_SIGN, 2);
    checkFailPos("\"12-3\" pos=2", "12-3",   CE_EXTRA_SIGN, 2);
    checkFailPos("\"++123\" pos=1", "++123",  CE_EXTRA_SIGN, 1);
    checkFailPos("\"+-123\" pos=1", "+-123",  CE_EXTRA_SIGN, 1);
    checkFailPos("\"123+\" pos=3", "123+",   CE_EXTRA_SIGN, 3);
}

int CP_IntegerParserTest::runAll()
{
    test1_ValidIntegers();
    test2_EmptyString();
    test3_SignOnly();
    test4_InvalidChar();
    test5_LeadingZeros();
    test6_Overflow();
    test7_ExtraSign();
    printSummary();
    return m_failed;
}

void CP_IntegerParserTest::printSummary() const
{
    cout << "\n====================================================\n"
         << "  Test Results:  "
         << m_passed << " passed,  "
         << m_failed << " failed,  "
         << (m_passed + m_failed) << " total\n"
         << (m_failed == 0 ? "  All tests PASSED!\n"
                           : "  SOME TESTS FAILED.\n")
         << "====================================================\n";
}
