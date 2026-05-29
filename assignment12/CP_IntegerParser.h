#ifndef CP_INTEGERPARSER_H
#define CP_INTEGERPARSER_H

#include <string>
using namespace std;

#include "CP_IntegerException.h"

class CP_IntegerParser
{
public:
    
    static int mbs_parse(const string &s);
};

#endif
