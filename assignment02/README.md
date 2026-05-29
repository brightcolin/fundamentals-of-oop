# Assignment 2 — GCD & LCM Calculator

> 最大公约数与最小公倍数 | 面向对象程序设计基础 第 2 次作业 · 第 1 题

---

## 📌 Description

A GCD and LCM calculation system built with OOP. The GCD class implements the **Binary GCD (Stein) algorithm** — no division or modulo operations, only bit shifts and subtraction. The LCM class internally composes a GCD object to avoid code duplication.

---

## 📁 File Structure

```
assignment2/
├── CP_GCD.h             # GCD class declaration
├── CP_GCD.cpp           # Binary GCD (Stein algorithm) implementation
├── CP_LCM.h             # LCM class declaration
├── CP_LCM.cpp           # LCM: composes GCD; uses divide-first formula to prevent overflow
├── CP_Test.h            # Test class declaration
├── CP_Test.cpp          # Automated test framework (all-English output)
├── CP_TestMain.cpp      # Test entry point → compiles to run_test.exe
└── CP_Main.cpp          # Main program → compiles to main.exe
```

---

## 🏗️ Class Structure

```
CP_GCD    — encapsulates Binary GCD algorithm
CP_LCM    — composes CP_GCD internally; computes LCM via lcm = a / gcd(a,b) * b
CP_Test   — automated test runner covering normal, boundary, and exception cases
```

**Single Responsibility Principle:** each class handles exactly one operation. `CP_LCM` reuses `CP_GCD` via composition rather than copying logic.

---

## ⚙️ Algorithm: Binary GCD (Stein)

Uses only bit shifts (`>>`) and subtraction — no `%` or `/`:

```
Phase 1: Extract common power of 2 (shift)
Phase 2: Ensure a is odd
Phase 3: While b != 0: remove factors of 2 from b, keep a <= b, b = b - a
Phase 4: Restore common factor: return a << shift
```

**LCM overflow prevention:** compute `a / gcd * b` (divide first, then multiply).

---

## 🚀 How to Run

```bash
# Main program
g++ -std=c++17 CP_Main.cpp CP_GCD.cpp CP_LCM.cpp -o main
.\main.exe

# Automated tests
g++ -std=c++17 CP_TestMain.cpp CP_GCD.cpp CP_LCM.cpp CP_Test.cpp -o run_test
.\run_test.exe
```
