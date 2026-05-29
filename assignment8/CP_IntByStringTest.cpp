#include <iostream>
using namespace std;
#include "CP_IntByStringTest.h"

// ======================== Interactive mode ========================
void CP_IntByStringTest::mb_run()
{
    char bufA[200],bufB[200],bufOp[10];
    int running=1;

    cout<<"=========================================="<<endl;
    cout<<"   CP_IntByString Interactive Calculator"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"  Supports: +  -  *  /"<<endl;
    cout<<"  Enter 'q' to quit."<<endl;
    cout<<"=========================================="<<endl;

    while(running)
    {
        cout<<"\nEnter the first integer: ";
        cin.getline(bufA,200);
        if(bufA[0]=='q'||bufA[0]=='Q') break;

        cout<<"Enter operator (+, -, *, /): ";
        cin.getline(bufOp,10);
        if(bufOp[0]=='q'||bufOp[0]=='Q') break;

        cout<<"Enter the second integer: ";
        cin.getline(bufB,200);
        if(bufB[0]=='q'||bufB[0]=='Q') break;

        CP_IntByString a(bufA);
        CP_IntByString b(bufB);
        CP_IntByString result;

        switch(bufOp[0])
        {
            case '+': result=a+b; break;
            case '-': result=a-b; break;
            case '*': result=a*b; break;
            case '/': result=a/b; break;
            default:
                cout<<"  Unknown operator!"<<endl;
                continue;
        }

        cout<<"\n  ";
        a.mb_show("");
        cout<<" "<<bufOp[0]<<" ";
        b.mb_show("");
        cout<<" = ";
        result.mb_show("");
        cout<<endl;
    }
    cout<<"\nGoodbye!"<<endl;
}

// ======================== Automated check ========================
void CP_IntByStringTest::mb_check(const string &testName,
                                   const CP_IntByString &result,
                                   const string &expected)
{
    m_totalTests++;
    string actual=result.mb_toString();
    if(actual==expected)
    {
        m_passedTests++;
        cout<<"  [PASS] "<<testName
            <<" => "<<actual<<endl;
    }
    else
    {
        cout<<"  [FAIL] "<<testName
            <<" => got "<<actual
            <<", expected "<<expected<<endl;
    }
}

// ======================== Addition: 7 cases ========================
void CP_IntByStringTest::mb_testAdd()
{
    cout<<"\n===== Addition Tests ====="<<endl;

    {
        CP_IntByString a("12345");
        CP_IntByString b("67890");
        mb_check("pos+pos: 12345+67890", a+b, "80235");
    }
    {
        CP_IntByString a("0");
        CP_IntByString b("0");
        mb_check("zero+zero: 0+0", a+b, "0");
    }
    {
        CP_IntByString a("1000");
        CP_IntByString b("300",-1);
        mb_check("pos+neg(res>0): 1000+(-300)", a+b, "700");
    }
    {
        CP_IntByString a("200");
        CP_IntByString b("500",-1);
        mb_check("pos+neg(res<0): 200+(-500)", a+b, "-300");
    }
    {
        CP_IntByString a("999",-1);
        CP_IntByString b("1",-1);
        mb_check("neg+neg: (-999)+(-1)", a+b, "-1000");
    }
    {
        CP_IntByString a("99999999999999999999");
        CP_IntByString b("1");
        mb_check("big: 99..9(20)+1", a+b,
                 "100000000000000000000");
    }
    {
        CP_IntByString a("12345");
        CP_IntByString b("12345",-1);
        mb_check("opposite: 12345+(-12345)", a+b, "0");
    }
}

// ======================== Subtraction: 7 cases ========================
void CP_IntByStringTest::mb_testSub()
{
    cout<<"\n===== Subtraction Tests ====="<<endl;

    {
        CP_IntByString a("67890");
        CP_IntByString b("12345");
        mb_check("big-small: 67890-12345", a-b, "55545");
    }
    {
        CP_IntByString a("9999");
        CP_IntByString b("9999");
        mb_check("equal: 9999-9999", a-b, "0");
    }
    {
        CP_IntByString a("100");
        CP_IntByString b("999");
        mb_check("small-big: 100-999", a-b, "-899");
    }
    {
        CP_IntByString a("0");
        CP_IntByString b("54321");
        mb_check("zero-pos: 0-54321", a-b, "-54321");
    }
    {
        CP_IntByString a("100",-1);
        CP_IntByString b("200");
        mb_check("neg-pos: (-100)-200", a-b, "-300");
    }
    {
        CP_IntByString a("500",-1);
        CP_IntByString b("800",-1);
        mb_check("neg-neg: (-500)-(-800)", a-b, "300");
    }
    {
        CP_IntByString a("100000000000000000000");
        CP_IntByString b("1");
        mb_check("big: 10^20-1", a-b,
                 "99999999999999999999");
    }
}

// ======================== Multiplication: 6 cases ========================
void CP_IntByStringTest::mb_testMul()
{
    cout<<"\n===== Multiplication Tests ====="<<endl;

    {
        CP_IntByString a("123");
        CP_IntByString b("456");
        mb_check("pos*pos: 123*456", a*b, "56088");
    }
    {
        CP_IntByString a("99999");
        CP_IntByString b("0");
        mb_check("mul_zero: 99999*0", a*b, "0");
    }
    {
        CP_IntByString a("12345");
        CP_IntByString b("1");
        mb_check("mul_one: 12345*1", a*b, "12345");
    }
    {
        CP_IntByString a("25");
        CP_IntByString b("4",-1);
        mb_check("pos*neg: 25*(-4)", a*b, "-100");
    }
    {
        CP_IntByString a("30",-1);
        CP_IntByString b("20",-1);
        mb_check("neg*neg: (-30)*(-20)", a*b, "600");
    }
    {
        CP_IntByString a("99999999999999999999");
        CP_IntByString b("2");
        mb_check("big: 99..9(20)*2", a*b,
                 "199999999999999999998");
    }
}

// ======================== Division: 7 cases ========================
void CP_IntByStringTest::mb_testDiv()
{
    cout<<"\n===== Division Tests ====="<<endl;

    {
        CP_IntByString a("100");
        CP_IntByString b("25");
        mb_check("exact: 100/25", a/b, "4");
    }
    {
        CP_IntByString a("10");
        CP_IntByString b("3");
        mb_check("truncate: 10/3", a/b, "3");
    }
    {
        CP_IntByString a("0");
        CP_IntByString b("12345");
        mb_check("zero_div: 0/12345", a/b, "0");
    }
    {
        CP_IntByString a("3");
        CP_IntByString b("100");
        mb_check("small/big: 3/100", a/b, "0");
    }
    {
        CP_IntByString a("100",-1);
        CP_IntByString b("7");
        mb_check("neg/pos: (-100)/7", a/b, "-14");
    }
    {
        CP_IntByString a("100000000000000000000");
        CP_IntByString b("10000000000");
        mb_check("big: 10^20/10^10", a/b,
                 "10000000000");
    }
    {
        CP_IntByString a("987654321");
        CP_IntByString b("1");
        mb_check("div_one: 987654321/1", a/b, "987654321");
    }
}

// ======================== Run all automated tests ========================
void CP_IntByStringTest::mb_runAll()
{
    m_totalTests=0;
    m_passedTests=0;

    cout<<"============================================"<<endl;
    cout<<"   CP_IntByString Automated Test Suite"<<endl;
    cout<<"============================================"<<endl;

    mb_testAdd();
    mb_testSub();
    mb_testMul();
    mb_testDiv();

    cout<<"\n============================================"<<endl;
    cout<<"  Total: "<<m_totalTests
        <<"  Passed: "<<m_passedTests
        <<"  Failed: "<<(m_totalTests-m_passedTests)<<endl;
    if(m_totalTests==m_passedTests)
    {
        cout<<"  ALL TESTS PASSED!"<<endl;
    }
    else
    {
        cout<<"  SOME TESTS FAILED!"<<endl;
    }
    cout<<"============================================"<<endl;
}
