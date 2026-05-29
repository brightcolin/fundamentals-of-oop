#include <iostream>
using namespace std;

#include "CP_StudentSystemTest.h"

int main()
{
    cout << "====================================================\n"
         << "   Student Management System (Factory Method)\n"
         << "   Automated Test Suite -- 9 test scenarios:\n"
         << "     1. Sorted insert      2. Delete by ID\n"
         << "     3. Delete by score    4. Query score by ID\n"
         << "     5. Query IDs by score 6. Duplicate ID rejected\n"
         << "     7. Mixed operations   8. Factory node recycling\n"
         << "     9. Compare with HW6\n"
         << "====================================================\n";

    CP_StudentSystemTest tester;
    return tester.runAll() == 0 ? 0 : 1;
}
