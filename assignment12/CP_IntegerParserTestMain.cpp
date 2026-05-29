#include <iostream>
using namespace std;

#include "CP_IntegerParserTest.h"

int main()
{
    cout << "====================================================\n"
         << "   Integer Parser -- Automated Test Suite\n"
         << "   T1: Valid integers     T2: Empty string\n"
         << "   T3: Sign only          T4: Invalid character\n"
         << "   T5: Leading zeros      T6: Overflow\n"
         << "   T7: Extra/misplaced sign\n"
         << "====================================================\n";

    CP_IntegerParserTest tester;
    return tester.runAll() == 0 ? 0 : 1;
}
