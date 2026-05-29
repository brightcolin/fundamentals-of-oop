#ifndef CP_COMPLEX_H
#define CP_COMPLEX_H

#include <iostream>
#include <string>

class CP_Complex {
public:

    CP_Complex();                          
    CP_Complex(double real, double imag);  
    explicit CP_Complex(double real);      

    double getReal() const;
    double getImag() const;
    void   setReal(double r);
    void   setImag(double i);
    void        print()    const;
    std::string toString() const;

    
    CP_Complex operator+(const CP_Complex& rhs) const;
    CP_Complex operator-(const CP_Complex& rhs) const;
    CP_Complex operator*(const CP_Complex& rhs) const;
    CP_Complex operator/(const CP_Complex& rhs) const;

    CP_Complex& operator+=(const CP_Complex& rhs);
    CP_Complex& operator-=(const CP_Complex& rhs);
    CP_Complex& operator*=(const CP_Complex& rhs);
    CP_Complex& operator/=(const CP_Complex& rhs);

    CP_Complex& operator++();     
    CP_Complex  operator++(int);  
    CP_Complex& operator--();     
    CP_Complex  operator--(int);  

    bool operator==(const CP_Complex& rhs) const;
    bool operator!=(const CP_Complex& rhs) const;
    
    friend std::ostream& operator<<(std::ostream& os, const CP_Complex& c);
    friend std::istream& operator>>(std::istream& is, CP_Complex& c);

private:
    double m_real;
    double m_imag;

    static constexpr double EPS = 1e-9;  
};

#endif 
