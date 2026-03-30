#include "CP_Complex.h"
#include <sstream>
#include <iomanip>
#include <cmath>

CP_Complex::CP_Complex()                         : m_real(0.0), m_imag(0.0) {}
CP_Complex::CP_Complex(double real, double imag) : m_real(real), m_imag(imag) {}
CP_Complex::CP_Complex(double real)              : m_real(real), m_imag(0.0) {}

double CP_Complex::getReal()  const { return m_real; }
double CP_Complex::getImag()  const { return m_imag; }
void   CP_Complex::setReal(double r) { m_real = r; }
void   CP_Complex::setImag(double i) { m_imag = i; }

std::string CP_Complex::toString() const {
    
    auto fmt = [](double v) -> std::string {
        std::ostringstream s;
        s << std::fixed << std::setprecision(4) << std::abs(v);
        std::string t = s.str();
        if (t.find('.') != std::string::npos) {
            t.erase(t.find_last_not_of('0') + 1);
            if (t.back() == '.') t.pop_back();
        }
        return t;
    };

    bool rz = std::abs(m_real) < EPS;
    bool iz = std::abs(m_imag) < EPS;

    if (rz && iz) return "0";
    if (rz) return (m_imag < 0 ? "-" : "") + fmt(m_imag) + "i";
    if (iz) return (m_real < 0 ? "-" : "") + fmt(m_real);
    return (m_real < 0 ? "-" : "")  + fmt(m_real)
         + (m_imag < 0 ? "-" : "+") + fmt(m_imag) + "i";
}

void CP_Complex::print() const { std::cout << toString(); }

std::ostream& operator<<(std::ostream& os, const CP_Complex& c) {
    os << c.toString();
    return os;
}

std::istream& operator>>(std::istream& is, CP_Complex& c) {
    is >> c.m_real >> c.m_imag;
    return is;
}