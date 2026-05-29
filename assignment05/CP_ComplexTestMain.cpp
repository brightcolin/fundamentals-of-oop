#include "CP_ComplexTest.h"
#include <iostream>

int main() {
    std::cout
        << "====================================================\n"
        << "   CP_Complex  Automated Test Suite\n"
        << "----------------------------------------------------\n"
        << "   Equivalence class partition:\n"
        << "     Case 1  EC1  General complex  (a!=0, b!=0)\n"
        << "     Case 2  EC2  Pure imaginary   (a=0,  b!=0)\n"
        << "     Case 3  EC3  Pure real        (a!=0, b=0 )\n"
        << "     Case 4  EC4  Zero             (a=0,  b=0 )\n"
        << "     Case 5  EC5  Negative         (a<0  or b<0)\n"
        << "     Case 6  EC6  Divisor = 0      (operator/ only)\n"
        << "====================================================\n";

    CP_ComplexTest tester;
    return tester.runAll() == 0 ? 0 : 1;
}