#include "CP_LCM.h"
#include <iostream>
#include <stdexcept>

LCM::LCM(long long a, long long b) : a_(a), b_(b) {
    if (a <= 0 || b <= 0) {
        throw std::invalid_argument("Input numbers must be positive.");
    }
    GCD gcd(a, b);
    result_ = (a / gcd.result()) * b;
}

long long LCM::result() const { return result_; }
long long LCM::geta()   const { return a_; }
long long LCM::getb()   const { return b_; }

void LCM::print() const {
    std::cout << "LCM(" << a_ << ", " << b_ << ") = " << result_ << std::endl;
}