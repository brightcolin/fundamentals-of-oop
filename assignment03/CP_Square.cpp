#include "CP_Square.h"
#include <iostream>

Square::Square(double side)
    : RegularPolygon(4, side) {}

std::string Square::name() const {
    return "Square";
}

void Square::draw() const {
    int s = (int)m_side;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) std::cout << "* ";
        std::cout << std::endl;
    }
}