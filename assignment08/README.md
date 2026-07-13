[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 08 — Big Integer by String

[Home](../README.md) · C++11

## Overview

`CP_IntByString` implements signed arbitrary-precision integer arithmetic using decimal strings. Addition, subtraction, multiplication, and integer division are performed with string-based column algorithms rather than built-in wide integer types.

## Design

```text
CP_IntByString
├── m_flag : sign
├── m_data : normalized absolute digits
├── operator +, -, *, /, ==, !=
└── helpers for compare, add, subtract, multiply, divide, and normalize
```

Leading zeros are removed, zero has a normalized sign, and signed operations are reduced to unsigned digit operations after determining the result sign.

## Files

```text
assignment08/
├── CP_IntByString.h / CP_IntByString.cpp
├── CP_IntByStringMain.cpp
├── CP_IntByStringTest.h / CP_IntByStringTest.cpp
├── CP_IntByStringTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive calculator
g++ -std=c++11 -o calc.exe CP_IntByString.cpp CP_IntByStringTest.cpp CP_IntByStringMain.cpp
.\calc.exe

# Automated tests
g++ -std=c++11 -o test.exe CP_IntByString.cpp CP_IntByStringTest.cpp CP_IntByStringTestMain.cpp
.\test.exe
```

The interactive entry point also invokes the test runner, so its target links `CP_IntByStringTest.cpp`. The tests cover signs, zero, unequal lengths, exact and truncated division, and large operands.

---

[Previous](../assignment07/README.md) · [Next](../assignment09/README.md)
