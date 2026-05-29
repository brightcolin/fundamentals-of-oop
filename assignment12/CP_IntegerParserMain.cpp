#include <iostream>
#include <string>
using namespace std;

#include "CP_IntegerParser.h"

int main()
{
    string input;

    cout << "===== Integer Parser (Exception Handling) =====" << endl;
    cout << "Enter a string to parse as integer." << endl;
    cout << "Type 'q' to quit." << endl;

    while (true)
    {
        cout << "\n> ";
        getline(cin, input);

        if (cin.eof() || input == "q" || input == "quit")
            break;

        try
        {
            int result = CP_IntegerParser::mbs_parse(input);
            cout << "Valid integer: " << result << endl;
        }
        catch (CP_IntegerException &e)
        {
            cout << "Exception caught!" << endl;
            cout << "  Error code : " << e.m_code
                 << " (" << e.mb_codeName() << ")" << endl;
            cout << "  Position   : " << e.m_position << endl;
            cout << "  Detail     : " << e.m_message << endl;

            if (input.length() > 0)
            {
                cout << "  Input      : \"" << input << "\"" << endl;
                cout << "               ";
                for (int i = 0; i < e.m_position + 1; i++)
                    cout << " ";
                cout << "^" << endl;
            }
        }
    } 

    cout << "\nGoodbye!" << endl;
    return 0;
}
