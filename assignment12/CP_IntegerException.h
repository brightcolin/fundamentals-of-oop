#ifndef CP_INTEGEREXCEPTION_H
#define CP_INTEGEREXCEPTION_H

#include <string>
using namespace std;

enum CP_ErrorCode
{
    CE_EMPTY_STRING    = 1,   
    CE_SIGN_ONLY       = 2,   
    CE_INVALID_CHAR    = 3,   
    CE_LEADING_ZEROS   = 4,   
    CE_OVERFLOW        = 5,   
    CE_EXTRA_SIGN      = 6    
};

class CP_IntegerException
{
public:
    CP_ErrorCode m_code;      
    int          m_position;  
    string       m_message;   

public:
    CP_IntegerException(CP_ErrorCode code, int pos, const string &msg)
        : m_code(code), m_position(pos), m_message(msg) {}

    
    string mb_codeName() const
    {
        switch (m_code)
        {
        case CE_EMPTY_STRING:  return "EMPTY_STRING";
        case CE_SIGN_ONLY:     return "SIGN_ONLY";
        case CE_INVALID_CHAR:  return "INVALID_CHAR";
        case CE_LEADING_ZEROS: return "LEADING_ZEROS";
        case CE_OVERFLOW:      return "OVERFLOW";
        case CE_EXTRA_SIGN:    return "EXTRA_SIGN";
        default:               return "UNKNOWN";
        }
    }
};

#endif
