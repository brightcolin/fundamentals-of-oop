[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 14 — IEEE 754 Double Inspector

[Home](../README.md) · C++11

## Overview

An educational inspection tool that overlays a `double`, a 64-bit unsigned integer, and eight bytes in a union. It displays the sign, exponent, fraction, raw hexadecimal representation, and special values such as NaN and infinity.

## Memory Layout

```cpp
union U_DoubleHex {
    double             m_double;
    unsigned long long m_ull;
    unsigned char      m_bytes[8];
};
```

```text
Bit 63       Bits 62–52       Bits 51–0
Sign (1)     Exponent (11)    Fraction (52)
```

| Value | Exponent | Fraction |
|---|---|---|
| `±0.0` | All zero | All zero |
| `±∞` | All one | All zero |
| NaN | All one | Non-zero |

## Files

```text
assignment14/
├── CP_UnionDoubleHex.h / CP_UnionDoubleHex.cpp
├── CP_UnionDoubleHexMain.cpp
├── CP_UnionDoubleHexTest.h / CP_UnionDoubleHexTest.cpp
├── CP_UnionDoubleHexTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive walkthrough
g++ -std=c++11 -o main.exe CP_UnionDoubleHex.cpp CP_UnionDoubleHexMain.cpp
.\main.exe

# Automated tests
g++ -std=c++11 -o run_test.exe CP_UnionDoubleHex.cpp CP_UnionDoubleHexTest.cpp CP_UnionDoubleHexTestMain.cpp
.\run_test.exe
```

The byte order shown by the program is platform-dependent. This implementation targets little-endian x86/x86-64 environments. Reading a non-active union member for type inspection relies on compiler behavior commonly supported by GCC and is not fully portable ISO C++.

---

[Previous](../assignment13/README.md) · [Home](../README.md)
