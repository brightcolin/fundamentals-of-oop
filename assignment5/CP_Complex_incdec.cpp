#include "CP_Complex.h"
#include <cmath>

CP_Complex& CP_Complex::operator++() { ++m_real; return *this; }
CP_Complex& CP_Complex::operator--() { --m_real; return *this; }

CP_Complex CP_Complex::operator++(int) {
    CP_Complex tmp = *this;  
    ++m_real;                
    return tmp;              
}

CP_Complex CP_Complex::operator--(int) {
    CP_Complex tmp = *this;
    --m_real;
    return tmp;
}

bool CP_Complex::operator==(const CP_Complex& rhs) const {
    return std::abs(m_real - rhs.m_real) < EPS &&
           std::abs(m_imag - rhs.m_imag) < EPS;
}

bool CP_Complex::operator!=(const CP_Complex& rhs) const {
    return !(*this == rhs);
}