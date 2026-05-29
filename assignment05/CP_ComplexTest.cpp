#include "CP_ComplexTest.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

CP_ComplexTest::CP_ComplexTest() : m_passed(0), m_failed(0) {}

void CP_ComplexTest::printHeader(const std::string& title) const {
    std::cout << "\n-- " << title << " --\n";
}

void CP_ComplexTest::check(const std::string& name,
                           const CP_Complex& got,
                           const CP_Complex& expected)
{
    bool ok = (got == expected);
    std::cout << (ok ? "| [PASS] " : "| [FAIL] ")
              << std::left << std::setw(46) << name
              << " got=" << std::setw(14) << got.toString()
              << " exp=" << expected.toString() << "\n";
    ok ? ++m_passed : ++m_failed;
}

void CP_ComplexTest::checkBool(const std::string& name,
                               bool got, bool expected)
{
    bool ok = (got == expected);
    std::cout << (ok ? "| [PASS] " : "| [FAIL] ")
              << std::left << std::setw(46) << name
              << " got=" << (got ? "true " : "false")
              << "  exp=" << (expected ? "true" : "false") << "\n";
    ok ? ++m_passed : ++m_failed;
}

void CP_ComplexTest::checkThrows(const std::string& name,
                                 std::function<void()> fn)
{
    try {
        fn();
        std::cout << "| [FAIL] " << name
                  << " (expected exception, none thrown)\n";
        ++m_failed;
    } catch (const std::domain_error&) {
        std::cout << "| [PASS] "
                  << std::left << std::setw(46) << name
                  << " exception correctly thrown\n";
        ++m_passed;
    }
}

int CP_ComplexTest::runAll() {
    testArith();
    testIncDec();
    printSummary();
    return m_failed;
}

void CP_ComplexTest::printSummary() const {
    std::cout << "\n====================================================\n"
              << "  Test Results:  "
              << m_passed << " passed,  "
              << m_failed << " failed,  "
              << (m_passed + m_failed) << " total\n"
              << (m_failed == 0 ? "  All tests PASSED!\n"
                                : "  SOME TESTS FAILED.\n")
              << "====================================================\n";
}

int CP_ComplexTest::getPassed() const { return m_passed; }
int CP_ComplexTest::getFailed() const { return m_failed; }
int CP_ComplexTest::getTotal()  const { return m_passed + m_failed; }