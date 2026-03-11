#include "CP_CalendarEx.h"
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::cout << "===== Calendar Calculator =====" << std::endl;
    std::cout << "Year Rules:" << std::endl;
    std::cout << "  positive integer = A.D." << std::endl;
    std::cout << "  negative integer = B.C." << std::endl;
    std::cout << "  year 0 does not exist." << std::endl;
    std::cout << "Algorithm: Julian Day Number (JDN), O(1) Time Complexity" << std::endl;
    std::cout << "  Type [q] at the year prompt to quit." << std::endl;
    std::cout << "===============================" << std::endl;

    while (true) {
        std::cout << "\nEnter a year (A.D.: positive, B.C.: negative) or [q] to quit: ";
        std::string input;
        std::cin >> input;

        if (input == "q" || input == "Q") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        int year;
        std::istringstream iss(input);
        if (!(iss >> year) || year == 0) {
            std::cerr << "Invalid input. Please enter a non-zero integer." << std::endl;
            continue;
        }

        int month, day;
        std::cout << "Enter a month (1-12): ";
        std::cin >> month;
        std::cout << "Enter a day   (1-31): ";
        std::cin >> day;

        try {
            CalendarEx date(year, month, day);
            std::cout << "\nYou entered:  ";
            date.print();

            std::cout << "Enter number of days to add" << std::endl;
            std::cout << "  (positive = forward, negative = backward, 0 = no change): ";
            int n;
            std::cin >> n;

            CalendarEx result = date.addDays(n);
            std::cout << "New date after " << n << " days: ";
            result.print();

        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "-------------------------------" << std::endl;
        std::cout << "Enter next year to calculate again." << std::endl;
    }

    return 0;
}