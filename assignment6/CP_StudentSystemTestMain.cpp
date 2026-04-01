// ============================================================
// CP_StudentSystemTestMain.cpp  --  Automated test entry point
//
// Compile:
//   g++ -std=c++11 CP_StudentSystemTestMain.cpp
//       CP_Student.cpp CP_ChainDoubleLink.cpp
//       CP_StudentSystem.cpp CP_StudentSystemTest.cpp
//       -o run_test
//
// Run:
//   .\run_test.exe
// ============================================================

#include <iostream>
using namespace std;

#include "CP_StudentSystemTest.h"

int main()
{
    cout << "====================================================\n"
         << "   Student Management System -- Test Suite\n"
         << "   7 test situations:\n"
         << "     1. Sorted insert      2. Delete by ID\n"
         << "     3. Delete by score    4. Query score by ID\n"
         << "     5. Query IDs by score 6. Duplicate ID rejected\n"
         << "     7. Mixed operations\n"
         << "====================================================\n";

    CP_StudentSystemTest tester;
    return tester.runAll() == 0 ? 0 : 1;
}
