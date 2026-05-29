#include <iostream>
#include <string>
#include <climits>
using namespace std;

#include "CP_IntegerParser.h"

int CP_IntegerParser::mbs_parse(const string &s)
{
    int len = (int)s.length();

    if (len == 0)
    {
        throw CP_IntegerException(
            CE_EMPTY_STRING, 0,
            "The input string is empty.");
    }
    int  idx  = 0;    
    bool neg  = false; 

    if (s[0] == '+' || s[0] == '-')
    {
        neg = (s[0] == '-');
        idx = 1; 
        if (idx >= len)
        {
            throw CP_IntegerException(
                CE_SIGN_ONLY, 0,
                "Only a sign character '" + string(1, s[0])
                + "' with no digits following.");
        }
    }
    int digitStart = idx; 

    for (int i = idx; i < len; i++)
    {
        char ch = s[i];

        
        if (ch == '+' || ch == '-')
        {
            throw CP_IntegerException(
                CE_EXTRA_SIGN, i,
                "Unexpected sign character '" + string(1, ch)
                + "' at position " + to_string(i)
                + ". Sign is only allowed at position 0.");
        }
        if (ch < '0' || ch > '9')
        {
            string desc = "Invalid character '";
            desc += ch;
            desc += "' at position " + to_string(i) + ".";
            if (ch == ' ')
                desc += " (space)";
            else if (ch == '.')
                desc += " (decimal point; only integers are allowed)";

            throw CP_IntegerException(CE_INVALID_CHAR, i, desc);
        }
    }
    
    int digitLen = len - digitStart;
    if (digitLen > 1 && s[digitStart] == '0')
    {
        throw CP_IntegerException(
            CE_LEADING_ZEROS, digitStart,
            "Leading zero at position " + to_string(digitStart)
            + ". The digit sequence '" + s.substr(digitStart)
            + "' has unnecessary leading zeros.");
    }

    long long value = 0;
    for (int i = digitStart; i < len; i++)
    {
        value = value * 10 + (s[i] - '0');
        if (!neg && value > (long long)INT_MAX)
        {
            throw CP_IntegerException(
                CE_OVERFLOW, i,
                "Positive overflow at position " + to_string(i)
                + ". Value exceeds INT_MAX (" + to_string(INT_MAX) + ").");
        }
        if (neg && value > (long long)INT_MAX + 1)
        {
            throw CP_IntegerException(
                CE_OVERFLOW, i,
                "Negative overflow at position " + to_string(i)
                + ". Value exceeds INT_MIN (" + to_string(INT_MIN) + ").");
        }
    }

    if (neg)
        value = -value;

    return (int)value;
}
