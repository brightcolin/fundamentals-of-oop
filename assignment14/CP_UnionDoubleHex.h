#ifndef CP_UNIONDOUBLEHEX_H
#define CP_UNIONDOUBLEHEX_H

union U_DoubleHex
{
    double m_double;
    unsigned long long m_ull;
    unsigned char m_bytes[8];

    U_DoubleHex(double d = 0.0) : m_double(d) {}
    U_DoubleHex(const U_DoubleHex &u) : m_ull(u.m_ull) {}
    ~U_DoubleHex() {}
};

extern void gb_showDoubleHexMemory(const U_DoubleHex &u);
extern void gb_showDoubleDetail(const U_DoubleHex &u);
extern void gb_showNaN();
extern void gb_showPosInf();
extern void gb_showNegInf();
extern void gb_showArithmeticRules();
extern void gb_testDoubleHex();

#endif
