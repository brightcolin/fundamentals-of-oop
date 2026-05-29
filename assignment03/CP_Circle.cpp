#include "CP_Circle.h"
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double radius) 
    : m_radius(radius) {}
double Circle::perimeter() const {
    return 2.0 * M_PI * m_radius;
}
double Circle::area() const {
    return M_PI * m_radius * m_radius;
}
std::string Circle::name() const {
    return "Circle";
}

void Circle::draw() const {
    int r = (int)m_radius;
    for (int y = -r; y <= r; y++) {
        for (int x = -r; x <= r; x++) {
            if (x * x + y * y <= r * r) std::cout << "* ";
            else std::cout << "  ";
        }
        std::cout << std::endl;
    }
}