#include "CP_GCD.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

GCD::GCD(long long a, long long b) : a_(a), b_(b) {
    if (a < 0 || b < 0) {
        throw std::invalid_argument("Input numbers must be positive.");
    }
    result_ = compute(a, b);
}

long long GCD::result() const { return result_; }
long long GCD::geta()   const { return a_; }
long long GCD::getb()   const { return b_; }

void GCD::print() const {
    std::cout << "GCD(" << a_ << ", " << b_ << ") = "
              << result_ << std::endl;
}

long long GCD::compute(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int shift = 0;
    while (((a | b) & 1) == 0) {
        a >>= 1;
        b >>= 1;
        ++shift;
    }

    while ((a & 1) == 0)
        a >>= 1;

    while (b != 0) {

        while ((b & 1) == 0)
            b >>= 1;

        if (a > b)
            std::swap(a, b);

        b -= a;
    }

    return a << shift;
}