#include "CP_Complex.h"
#include <cmath>
#include <stdexcept>

CP_Complex CP_Complex::operator+(const CP_Complex& rhs) const {
    return CP_Complex(m_real + rhs.m_real,
                      m_imag + rhs.m_imag);
}

CP_Complex CP_Complex::operator-(const CP_Complex& rhs) const {
    return CP_Complex(m_real - rhs.m_real,
                      m_imag - rhs.m_imag);
}

CP_Complex CP_Complex::operator*(const CP_Complex& rhs) const {
    double a = m_real,     b = m_imag;
    double c = rhs.m_real, d = rhs.m_imag;
    return CP_Complex(a*c - b*d,   
                      a*d + b*c);  
}

CP_Complex CP_Complex::operator/(const CP_Complex& rhs) const {
    double a = m_real,     b = m_imag;
    double c = rhs.m_real, d = rhs.m_imag;

    double denom = c*c + d*d;
    if (std::abs(denom) < EPS)
        throw std::domain_error("Division by zero");

    return CP_Complex((a*c + b*d) / denom,   
                      (b*c - a*d) / denom);  
}

CP_Complex& CP_Complex::operator+=(const CP_Complex& rhs) { *this = *this + rhs; return *this; }
CP_Complex& CP_Complex::operator-=(const CP_Complex& rhs) { *this = *this - rhs; return *this; }
CP_Complex& CP_Complex::operator*=(const CP_Complex& rhs) { *this = *this * rhs; return *this; }
CP_Complex& CP_Complex::operator/=(const CP_Complex& rhs) { *this = *this / rhs; return *this; }