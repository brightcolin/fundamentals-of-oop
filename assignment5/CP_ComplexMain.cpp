#include "CP_Complex.h"
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    std::cout
        << "====================================================\n"
        << "   CP_Complex  Interactive Mode\n"
        << "   Input format:  real imag  (e.g. \"3 4\" = 3+4i)\n"
        << "   Type [q] at the first prompt to quit\n"
        << "====================================================\n";

    while (true) {
        
        std::cout << "\nEnter a  (real imag) or [q]: ";
        std::string tok;
        std::cin >> tok;
        if (tok == "q" || tok == "Q") {
            std::cout << "Goodbye!\n";
            break;
        }

        double r1, i1, r2, i2;
        try {
            r1 = std::stod(tok);
        } catch (...) {
            std::cerr << "Invalid input. Please enter a number or [q].\n";
            continue;
        }
        std::cin >> i1;

        
        std::cout << "Enter b  (real imag): ";
        std::cin >> r2 >> i2;

        CP_Complex a(r1, i1), b(r2, i2);

        
        std::cout << "\n  a        = " << a
                  << "\n  b        = " << b
                  << "\n  a + b    = " << (a + b)
                  << "\n  a - b    = " << (a - b)
                  << "\n  a * b    = " << (a * b) << "\n";

        try {
            std::cout << "  a / b    = " << (a / b) << "\n";
        } catch (const std::domain_error& e) {
            std::cout << "  a / b    = Error: " << e.what() << "\n";
        }

        
        CP_Complex c = a;
        std::cout << "  ++a      = " << (++c) << "\n";
        c = a;
        std::cout << "  a++      = " << (c++) << "  (a after: " << c << ")\n";
        c = a;
        std::cout << "  --a      = " << (--c) << "\n";
        c = a;
        std::cout << "  a--      = " << (c--) << "  (a after: " << c << ")\n";

        
        std::cout << "  a == b?  " << (a == b ? "true" : "false") << "\n"
                  << "  a != b?  " << (a != b ? "true" : "false") << "\n";

        std::cout << "----------------------------------------------------\n";
    }

    return 0;
}