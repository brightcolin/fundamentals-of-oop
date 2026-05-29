#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#include "CP_RegularPolygon.h"
#include <cmath>

RegularPolygon::RegularPolygon(int n, double side)
    : m_n(n), m_side(side) {}

double RegularPolygon::perimeter() const {
    return m_n * m_side;
}

double RegularPolygon::area() const {
    return (m_n * m_side * m_side) / (4.0 * std::tan(M_PI / m_n));
}