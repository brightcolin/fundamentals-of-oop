#ifndef CP_A_H
#define CP_A_H

#include <iostream>
using namespace std;

class CP_A
{
public:
    int m_n;
    CP_A(int n = 0) noexcept : m_n(n) { cout << "  CP_A ctor: m_n=" << m_n << ", addr=" << this << endl; }
    ~CP_A() noexcept { cout << "  CP_A dtor: m_n=" << m_n << ", addr=" << this << endl; }
    void mb_show() noexcept
    {
        cout << "  m_n=" << m_n << ", addr=" << this << endl;
    }
};

#endif
