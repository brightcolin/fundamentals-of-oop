#include "CP_Test.h"
#include "CP_GCD.h"
#include "CP_LCM.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

Test::Test() : totalCases_(0), passedCases_(0) {}

// ── Normal test case ──────────────────────────────────────────
bool Test::runCase(const std::string& label,
                   long long a, long long b,
                   long long expectedGcd, long long expectedLcm)
{
    ++totalCases_;
    bool ok = true;
    std::string reason;

    try {
        GCD gcd(a, b);
        LCM lcm(a, b);

        if (gcd.result() != expectedGcd) {
            ok = false;
            reason += " GCD expected=" + std::to_string(expectedGcd)
                    + " got=" + std::to_string(gcd.result()) + ";";
        }
        if (lcm.result() != expectedLcm) {
            ok = false;
            reason += " LCM expected=" + std::to_string(expectedLcm)
                    + " got=" + std::to_string(lcm.result()) + ";";
        }
    } catch (const std::exception& e) {
        ok = false;
        reason = std::string(" unexpected exception: ") + e.what();
    }

    std::cout << std::left << std::setw(42) << label;
    if (ok) {
        std::cout << "[PASS]\n";
        ++passedCases_;
    } else {
        std::cout << "[FAIL]" << reason << "\n";
    }
    return ok;
}

// ── Exception test case ───────────────────────────────────────
bool Test::runExceptionCase(const std::string& label,
                             long long a, long long b)
{
    ++totalCases_;
    bool caughtGcd = false, caughtLcm = false;

    try { GCD gcd(a, b); }
    catch (const std::invalid_argument&) { caughtGcd = true; }

    try { LCM lcm(a, b); }
    catch (const std::invalid_argument&) { caughtLcm = true; }

    bool ok = caughtGcd || caughtLcm;

    std::cout << std::left << std::setw(42) << label;
    if (ok) {
        std::cout << "[PASS] exception caught correctly\n";
        ++passedCases_;
    } else {
        std::cout << "[FAIL] expected exception not thrown\n";
    }
    return ok;
}

// ── Summary ───────────────────────────────────────────────────
void Test::printSummary() const {
    std::cout << "\n";
    std::cout << "------------------------------------------\n";
    std::cout << "  Result: " << passedCases_ << " / " << totalCases_ << " passed\n";
    if (passedCases_ == totalCases_)
        std::cout << "  All tests passed.\n";
    else
        std::cout << "  " << (totalCases_ - passedCases_) << " test(s) failed.\n";
    std::cout << "------------------------------------------\n";
}

// ── All test cases ────────────────────────────────────────────
bool Test::runAll() {
    std::cout << "------------------------------------------\n";
    std::cout << "  Auto Test\n";
    std::cout << "------------------------------------------\n";

    runCase("[Basic ] GCD(12,8)=4,    LCM=24",       12,    8,    4,     24);
    runCase("[Basic ] GCD(48,36)=12,  LCM=144",       48,   36,   12,   144);
    runCase("[Basic ] GCD(100,75)=25, LCM=300",      100,   75,   25,   300);
    runCase("[Coprime] GCD(7,13)=1,   LCM=91",         7,   13,    1,    91);
    runCase("[Coprime] GCD(17,19)=1,  LCM=323",       17,   19,    1,   323);
    runCase("[Equal ] GCD(9,9)=9,     LCM=9",          9,    9,    9,     9);
    runCase("[Equal ] GCD(1,1)=1,     LCM=1",          1,    1,    1,     1);
    runCase("[One   ] GCD(1,100)=1,   LCM=100",        1,  100,    1,   100);
    runCase("[One   ] GCD(99,1)=1,    LCM=99",        99,    1,    1,    99);
    runCase("[Pow2  ] GCD(64,16)=16,  LCM=64",        64,   16,   16,    64);
    runCase("[Pow2  ] GCD(1024,256)=256, LCM=1024", 1024,  256,  256,  1024);
    runCase("[Large ] GCD(999999999,1000000000)=1",
            999999999LL, 1000000000LL, 1LL, 999999999000000000LL);
    runCase("[Large ] GCD(123456789,987654321)=9",
            123456789LL, 987654321LL,  9LL, 13548070123626141LL);
    runExceptionCase("[Except] negative: (-1, 5)",   -1,   5);
    runExceptionCase("[Except] negative: (3, -7)",    3,  -7);
    runExceptionCase("[Except] zero:     (0, 5)",     0,   5);

    printSummary();
    return (passedCases_ == totalCases_);
}