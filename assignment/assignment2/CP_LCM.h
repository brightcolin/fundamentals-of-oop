#ifndef LCM_H
#define LCM_H

#include "CP_GCD.h"

class LCM {
public:
    LCM(long long a, long long b);

    long long result() const;
    long long geta()   const;
    long long getb()   const;

    void print() const;

private:
    long long a_;
    long long b_;
    long long result_;
};

#endif