#include <iostream>
using namespace std;

#include "CP_UnionDoubleHexTest.h"

int main()
{
    cout << "====================================================\n"
         << "   Double Hex Viewer -- Automated Test\n"
         << "====================================================\n";

    int failed = gb_runAllTests();
    return (failed == 0) ? 0 : 1;
}
