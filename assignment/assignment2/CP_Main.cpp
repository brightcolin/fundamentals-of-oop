#include <iostream>
#include <stdexcept>
#include "CP_GCD.h"
#include "CP_LCM.h"

int main() {
    long long a, b;
    std::cout << "Enter two positive integers: ";
    std::cin >> a >> b;

    try {
        GCD gcd(a, b);
        gcd.print();
    } catch (const std::invalid_argument& e) {
        std::cerr << "GCD Error: " << e.what() << std::endl;
    }

    try {
        LCM lcm(a, b);
        lcm.print();
    } catch (const std::invalid_argument& e) {
        std::cerr << "LCM Error: " << e.what() << std::endl;
    }

    return 0;
}