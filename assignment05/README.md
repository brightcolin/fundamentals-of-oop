[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 05 — Complex Number Calculator

[Home](../README.md) · C++11

## Overview

An implementation of `CP_Complex` with arithmetic, comparison, increment/decrement, compound-assignment, and stream operators. The code separates the class interface from three focused implementation files and includes an equivalence-class test suite.

## Supported Operators

| Category | Operators |
|---|---|
| Arithmetic | `+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=` |
| Increment and decrement | Prefix and postfix `++`, `--` |
| Comparison | `==`, `!=` |
| Stream I/O | `<<`, `>>` |

Division uses `(c²+d²)` as the denominator and throws `std::domain_error` when the divisor is zero.

## Structure

```text
assignment05/
├── CP_Complex.h
├── CP_Complex_core.cpp       # Construction, access, and stream I/O
├── CP_Complex_arith.cpp      # Arithmetic
├── CP_Complex_incdec.cpp     # Increment, decrement, and comparison
├── CP_ComplexMain.cpp
├── CP_ComplexTest.h / CP_ComplexTest.cpp
├── CP_ComplexTest_arith.cpp
├── CP_ComplexTest_incdec.cpp
├── CP_ComplexTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive program
g++ -std=c++11 -o complex.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexMain.cpp
.\complex.exe

# Automated tests
g++ -std=c++11 -o run_test.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp CP_ComplexTestMain.cpp
.\run_test.exe
```

Complex input uses `real imag`, for example `3 4` for `3+4i`. The test suite contains 53 checks covering general, real-only, imaginary-only, zero, negative, and zero-divisor cases.

---

[Previous](../assignment04/README.md) · [Next](../assignment06/README.md)
