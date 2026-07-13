[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 02 — GCD & LCM Calculator

[Home](../README.md) · C++17

## Overview

An object-oriented GCD and LCM calculator. `CP_GCD` implements Stein's binary GCD algorithm using shifts and subtraction, while `CP_LCM` composes a `CP_GCD` object and uses a divide-first formula to reduce overflow risk.

## Design

| Class | Responsibility |
|---|---|
| `CP_GCD` | Binary GCD calculation |
| `CP_LCM` | LCM calculation through composition |
| `CP_Test` | Normal, boundary, and exceptional test cases |

The implementation follows the single-responsibility principle: each class owns one focused operation.

### Stein Algorithm

```text
1. Extract the common power of two.
2. Make the first operand odd.
3. Repeatedly remove powers of two and subtract the smaller odd value.
4. Restore the common power of two.
```

LCM is calculated as `a / gcd(a, b) * b`.

## Files

```text
assignment02/
├── CP_GCD.h / CP_GCD.cpp
├── CP_LCM.h / CP_LCM.cpp
├── CP_Test.h / CP_Test.cpp
├── CP_Main.cpp
├── CP_TestMain.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive program
g++ -std=c++17 -o main.exe CP_Main.cpp CP_GCD.cpp CP_LCM.cpp
.\main.exe

# Automated tests
g++ -std=c++17 -o run_test.exe CP_TestMain.cpp CP_GCD.cpp CP_LCM.cpp CP_Test.cpp
.\run_test.exe
```

The two targets contain separate `main()` functions and must be compiled independently.

---

[Previous](../assignment01/README.md) · [Next](../assignment03/README.md)
