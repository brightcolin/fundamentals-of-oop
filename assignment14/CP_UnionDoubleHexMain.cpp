#include <iostream>
#include <string>
using namespace std;

#include "CP_UnionDoubleHex.h"

int main()
{
    
    gb_testDoubleHex();

    cout << "\n--- Enter a double (q to quit) ---" << endl;
    string input;
    while (true)
    {
        cout << "\n> ";
        getline(cin, input);
        if (input == "q" || cin.eof())
            break;

        double d;
        try { d = stod(input); }
        catch (...) { cout << "Invalid input." << endl; continue; }

        U_DoubleHex u(d);
        gb_showDoubleDetail(u);
    }

    cout << "\nGoodbye!" << endl;
    return 0;
}
