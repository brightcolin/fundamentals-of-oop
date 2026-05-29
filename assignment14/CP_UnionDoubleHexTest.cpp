#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

#include "CP_UnionDoubleHex.h"
#include "CP_UnionDoubleHexTest.h"

static int g_passed = 0;
static int g_failed = 0;

static string gb_toHex(double d)
{
    U_DoubleHex u(d);
    ostringstream oss;
    oss << "0x" << uppercase << hex
        << setw(16) << setfill('0') << u.m_ull;
    return oss.str();
}

static void gb_check(const char *name, bool ok)
{
    cout << "| " << (ok ? "[PASS] " : "[FAIL] ")
         << left << setw(52) << name << endl;
    if (ok) g_passed++;
    else    g_failed++;
}

static void gb_checkHex(const char *name, double d, const char *expected)
{
    string actual = gb_toHex(d);
    bool ok = (actual == expected);
    cout << "| " << (ok ? "[PASS] " : "[FAIL] ")
         << left << setw(40) << name;
    if (!ok) cout << "  got=" << actual << " exp=" << expected;
    cout << endl;
    if (ok) g_passed++;
    else    g_failed++;
}

static void gb_test1_NormalValues()
{
    cout << "\n-- T1: Normal values --" << endl;
    gb_checkHex("1.0", 1.0, "0x3FF0000000000000");
    gb_checkHex("-1.0",  -1.0, "0xBFF0000000000000");
    gb_checkHex("2.0", 2.0, "0x4000000000000000");
    gb_checkHex("0.5", 0.5, "0x3FE0000000000000");
    gb_checkHex("-0.5", -0.5, "0xBFE0000000000000");
    gb_checkHex("0.1", 0.1, "0x3FB999999999999A");
    gb_checkHex("100.0", 100.0, "0x4059000000000000");
}

static void gb_test2_Zeros()
{
    cout << "\n-- T2: Zeros --" << endl;
    gb_checkHex("+0.0", 0.0, "0x0000000000000000");
    gb_checkHex("-0.0", -0.0, "0x8000000000000000");
    gb_check("+0.0 == -0.0 (value equal)", 0.0 == -0.0);
    gb_check("+0.0 hex != -0.0 hex (memory differs)",
             gb_toHex(0.0) != gb_toHex(-0.0));
}

static void gb_test3_NaN()
{
    cout << "\n-- T3: NaN --" << endl;

    U_DoubleHex u(0.0);
    u.m_double = 0.0 / u.m_double;
    double nan = u.m_double;

    string nanHex = gb_toHex(nan);
    bool nanOk = (nanHex.substr(0, 5) == "0x7FF" ||
                  nanHex.substr(0, 5) == "0xFFF") &&
                  nanHex != "0x7FF0000000000000" &&
                  nanHex != "0xFFF0000000000000";
    gb_check("0.0/0.0 -> NaN (exp all 1, mant != 0)", nanOk);

    gb_check("NaN != NaN", !(nan == nan));
    gb_check("isnan(NaN) == true", isnan(nan) != 0);
    gb_check("isnan(1.0) == false", isnan(1.0) == 0);

    
    gb_check("NaN hex: exponent all 1s",
             nanHex.substr(0, 5) == "0x7FF" ||
             nanHex.substr(0, 5) == "0xFFF");
}

static void gb_test4_Infinity()
{
    cout << "\n-- T4: Infinity --" << endl;

    U_DoubleHex uZero(0.0);
    double posInf = 1.0 / uZero.m_double;
    double negInf = -1.0 / uZero.m_double;

    gb_checkHex("+Infinity",  posInf, "0x7FF0000000000000");
    gb_checkHex("-Infinity",  negInf, "0xFFF0000000000000");
    gb_check("isinf(+Inf) == true", isinf(posInf) != 0);
    gb_check("isinf(-Inf) == true", isinf(negInf) != 0);
    gb_check("+Inf > 1e308", posInf > 1e308);
    gb_check("-Inf < -1e308", negInf < -1e308);
    gb_check("1.0/0.0 == +Inf", posInf == (1.0 / uZero.m_double));
    gb_check("-1.0/0.0 == -Inf", negInf == (-1.0 / uZero.m_double));
}

static void gb_test5_SpecialValues()
{
    cout << "\n-- T5: Special values --" << endl;
    
    gb_checkHex("DBL_MIN (2.2e-308)", 2.2250738585072014e-308,
                "0x0010000000000000");
    
    gb_checkHex("DBL_MAX (1.8e+308)", 1.7976931348623157e+308,
                "0x7FEFFFFFFFFFFFFF");
    
    gb_checkHex("denorm_min (5e-324)", 5e-324,
                "0x0000000000000001");
}

static void gb_test6_ArithmeticRules()
{
    cout << "\n-- T6: Arithmetic rules --" << endl;

    U_DoubleHex uZero(0.0);
    double nan = 0.0 / uZero.m_double;        
    double posInf = 1.0 / uZero.m_double;        
    double negInf = -1.0 / uZero.m_double;       

    gb_check("NaN + 1.0 -> NaN", isnan(nan + 1.0) != 0);
    gb_check("NaN * 0.0 -> NaN", isnan(nan * 0.0) != 0);
    gb_check("NaN + Inf -> NaN", isnan(nan + posInf) != 0);
    gb_check("NaN / NaN -> NaN", isnan(nan / nan) != 0);

    gb_check("Inf + 1.0 -> Inf", isinf(posInf + 1.0) != 0);
    gb_check("Inf * 2.0 -> Inf", isinf(posInf * 2.0) != 0);
    gb_check("1.0 / Inf -> 0", (1.0 / posInf) == 0.0);
    gb_check("Inf + Inf -> Inf", (posInf + posInf) == posInf);
    gb_check("Inf * (-Inf) -> -Inf", (posInf * negInf) == negInf);

    gb_check("Inf - Inf -> NaN", isnan(posInf - posInf) != 0);
    gb_check("Inf / Inf -> NaN", isnan(posInf / posInf) != 0);
    gb_check("0.0 / 0.0 -> NaN", isnan(0.0 / uZero.m_double) != 0);
    gb_check("0.0 * Inf -> NaN", isnan(0.0 * posInf) != 0);
}

void gb_printTestSummary(int passed, int failed)
{
    cout << "\n====================================================\n"
         << "  Test Results:  "
         << passed << " passed,  "
         << failed << " failed,  "
         << (passed + failed) << " total\n";
    if (failed == 0)
        cout << "  All tests PASSED!\n";
    else
        cout << "  SOME TESTS FAILED.\n";
    cout << "====================================================\n";
}

int gb_runAllTests()
{
    g_passed = 0;
    g_failed = 0;

    gb_test1_NormalValues();
    gb_test2_Zeros();
    gb_test3_NaN();
    gb_test4_Infinity();
    gb_test5_SpecialValues();
    gb_test6_ArithmeticRules();

    gb_printTestSummary(g_passed, g_failed);
    return g_failed;
}
