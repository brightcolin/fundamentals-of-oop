#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "CP_UnionDoubleHex.h"

void gb_showDoubleHexMemory(const U_DoubleHex &u)
{
    cout << "  Value : " << u.m_double << endl;
    cout << "  Hex   : 0x"
         << hex << uppercase << setw(16) << setfill('0')
         << u.m_ull << dec << endl;
}

void gb_showDoubleDetail(const U_DoubleHex &u)
{
    unsigned long long sign     = (u.m_ull >> 63) & 0x1;
    unsigned long long exponent = (u.m_ull >> 52) & 0x7FF;
    unsigned long long mantissa = u.m_ull & 0x000FFFFFFFFFFFFFULL;

    gb_showDoubleHexMemory(u);

    cout << "  Bytes : ";
    for (int i = 0; i < 8; i++)
    {
        cout << hex << uppercase << setw(2) << setfill('0')
             << (int)u.m_bytes[i];
        if (i < 7) cout << " ";
    }
    cout << dec << "  (little-endian)" << endl;

    cout << "  Sign  : " << sign
         << (sign ? "  (negative)" : "  (positive)") << endl;
    cout << "  Exp   : 0x" << hex << uppercase << exponent
         << dec << "  (" << exponent << ")" << endl;
    cout << "  Mant  : 0x" << hex << uppercase
         << setw(13) << setfill('0') << mantissa << dec << endl;

    if (exponent == 0x7FF)
    {
        if (mantissa != 0)
            cout << "  Type  : NaN" << endl;
        else if (sign == 0)
            cout << "  Type  : +Infinity" << endl;
        else
            cout << "  Type  : -Infinity" << endl;
    }
    else if (exponent == 0 && mantissa == 0)
    {
        cout << "  Type  : " << (sign ? "-" : "+") << "Zero" << endl;
    }
    else if (exponent == 0)
    {
        cout << "  Type  : Denormalized" << endl;
    }
    else
    {
        cout << "  Type  : Normalized (bias = "
             << (int)exponent - 1023 << ")" << endl;
    }
}

void gb_showNaN()
{
    cout << "--- NaN ---" << endl;
    U_DoubleHex u(0.0);
    u.m_double = 0.0 / u.m_double;  
    gb_showDoubleDetail(u);
}

void gb_showPosInf()
{
    cout << "--- +Infinity ---" << endl;
    U_DoubleHex u(1.0);
    U_DoubleHex zero(0.0);
    u.m_double = u.m_double / zero.m_double;  
    gb_showDoubleDetail(u);
}

void gb_showNegInf()
{
    cout << "--- -Infinity ---" << endl;
    U_DoubleHex u(-1.0);
    U_DoubleHex zero(0.0);
    u.m_double = u.m_double / zero.m_double;  
    gb_showDoubleDetail(u);
}

void gb_showArithmeticRules()
{
    U_DoubleHex uNaN(0.0);
    uNaN.m_double = 0.0 / uNaN.m_double;          

    U_DoubleHex uPosInf(1.0);
    U_DoubleHex uZero(0.0);
    uPosInf.m_double = 1.0 / uZero.m_double;      

    U_DoubleHex uNegInf(-1.0);
    uNegInf.m_double = -1.0 / uZero.m_double;     

    double nan    = uNaN.m_double;
    double posInf = uPosInf.m_double;
    double negInf = uNegInf.m_double;
    double x      = 3.14;

    cout << "===== Arithmetic Rules =====" << endl;

    cout << "\n--- NaN rules ---" << endl;
    U_DoubleHex r1(nan + x);
    cout << "  NaN + 3.14       = " << r1.m_double << endl;
    U_DoubleHex r2(nan - x);
    cout << "  NaN - 3.14       = " << r2.m_double << endl;
    U_DoubleHex r3(nan * x);
    cout << "  NaN * 3.14       = " << r3.m_double << endl;
    U_DoubleHex r4(nan / x);
    cout << "  NaN / 3.14       = " << r4.m_double << endl;
    U_DoubleHex r5(x / nan);
    cout << "  3.14 / NaN       = " << r5.m_double << endl;
    U_DoubleHex r6(nan + nan);
    cout << "  NaN + NaN        = " << r6.m_double << endl;
    U_DoubleHex r7(nan * 0.0);
    cout << "  NaN * 0          = " << r7.m_double << endl;
    U_DoubleHex r8(nan + posInf);
    cout << "  NaN + Inf        = " << r8.m_double << endl;

    cout << "\n--- +Infinity rules ---" << endl;
    U_DoubleHex r9(posInf + x);
    cout << "  +Inf + 3.14      = " << r9.m_double << endl;
    U_DoubleHex r10(posInf * x);
    cout << "  +Inf * 3.14      = " << r10.m_double << endl;
    U_DoubleHex r11(x / posInf);
    cout << "  3.14 / +Inf      = " << r11.m_double << endl;
    U_DoubleHex r12(posInf + posInf);
    cout << "  +Inf + (+Inf)    = " << r12.m_double << endl;
    U_DoubleHex r13(posInf * negInf);
    cout << "  +Inf * (-Inf)    = " << r13.m_double << endl;
    U_DoubleHex r14(posInf - posInf);
    cout << "  +Inf - (+Inf)    = " << r14.m_double << endl;
    U_DoubleHex r15(posInf / posInf);
    cout << "  +Inf / (+Inf)    = " << r15.m_double << endl;

    cout << "\n--- Zero special cases ---" << endl;
    U_DoubleHex r16(0.0 / uZero.m_double);
    cout << "  0.0 / 0.0        = " << r16.m_double << endl;
    U_DoubleHex r17(0.0 * posInf);
    cout << "  0.0 * +Inf       = " << r17.m_double << endl;
}


void gb_testDoubleHex()
{
    cout << "===== Double Hex Memory Viewer =====" << endl;

    cout << "\n--- Normal values ---" << endl;
    U_DoubleHex u1(1.0);
    gb_showDoubleHexMemory(u1);

    U_DoubleHex u2(-1.0);
    gb_showDoubleHexMemory(u2);

    U_DoubleHex u3(3.14);
    gb_showDoubleHexMemory(u3);

    U_DoubleHex u4(0.1);
    gb_showDoubleHexMemory(u4);

    cout << "\n--- Special values ---" << endl;
    U_DoubleHex u5(0.0);
    gb_showDoubleHexMemory(u5);

    U_DoubleHex u6(-0.0);
    gb_showDoubleHexMemory(u6);

    cout << endl;
    gb_showNaN();
    cout << endl;
    gb_showPosInf();
    cout << endl;
    gb_showNegInf();
    cout << endl;
    gb_showArithmeticRules();
}
