#include "CP_EquilateralTriangle.h"
#include <iostream>

EquilateralTriangle::EquilateralTriangle(double side)
    : RegularPolygon(3, side) {}

std::string EquilateralTriangle::name() const {
    return "Regular Triangle";
}

void EquilateralTriangle::draw() const {
    int h = (int)m_side;
    for (int i = 1; i <= h; i++) {
        for (int j = i; j < h; j++) std::cout << " ";
        for (int j = 1; j <= (2 * i - 1); j++) std::cout << "*";
        std::cout << std::endl;
    }
}