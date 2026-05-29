#ifndef CP_COMPLEX_TEST_H
#define CP_COMPLEX_TEST_H

#include "CP_Complex.h"
#include <string>
#include <functional>

class CP_ComplexTest {
public:
    CP_ComplexTest();

    void testArith();    
    void testIncDec();   

    int  runAll();           
    void printSummary() const;

    int getPassed() const;
    int getFailed() const;
    int getTotal()  const;

    void check(const std::string& name,
               const CP_Complex& got, const CP_Complex& expected);
    void checkBool(const std::string& name, bool got, bool expected);
    void checkThrows(const std::string& name, std::function<void()> fn);
    void printHeader(const std::string& title) const;

private:
    int m_passed;
    int m_failed;
};

#endif 