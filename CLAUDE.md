# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

C++ OOP course assignments (面向对象程序设计基础). Compiler: g++ (MinGW-w64) on Windows. Standards: C++11 or C++17 depending on the assignment.

## Build Commands

There is no Makefile. Each assignment is compiled manually. Each assignment folder contains independently compilable source files.

**Compile a main executable:**
```bash
g++ -std=c++17 -o main.exe *.cpp
```

**Compile only specific files (e.g., when there are multiple main files):**
```bash
g++ -std=c++17 -o main.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexMain.cpp
```

**Compile and run the test executable:**
```bash
g++ -std=c++17 -o test.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp CP_ComplexTestMain.cpp
./test.exe
```

Each assignment folder has two entry points: `CP_*Main.cpp` (interactive app) and `CP_*TestMain.cpp` (test runner). Compile them separately — they cannot be linked together.

## Assignment Progression & Architecture

| # | Topic | Key Pattern |
|---|-------|-------------|
| 1 | Shape puzzle (canvas rendering) | Abstract base `CP_Shape` → `CP_Circle`, `CP_Rect`, `CP_Triangle` |
| 2 | GCD & LCM calculator | Single-responsibility classes; Stein (binary GCD) algorithm |
| 3 | Shape calculation system | Multi-level inheritance: `CP_Shape` → `CP_RegularPolygon` → specific shapes |
| 4 | Calendar (B.C./A.D.) | Julian Day Number (JDN); `CP_Calendar` → `CP_CalendarEx` |
| 5 | Complex number class | Full operator overloading (arithmetic, stream I/O, increment/decrement) |
| 6 | Student system | Raw doubly-linked list (`CP_ChainDoubleLink`) managing `CP_Student` nodes |
| 7 | `MyVector<T>` | Manual dynamic array with `reserve`/`resize`, rule-of-three, benchmarks |
| 8 | `CP_IntByString` | Big-integer arithmetic stored as strings |
| 9 | Grade sheet system | File-backed student grades |
| 10 | `CP_DynArray<T>` | Move-only RAII wrapper (copy-deleted); teaches move semantics explicitly |
| 11 | `CP_VectorOp` | Scalar multiplication & dot product on `std::vector<float>`, with parallel variant |
| 12 | `CP_IntegerParser` | String-to-integer parsing with custom `CP_IntegerException` enum error codes |
| 13 | Student system (factory) | `CP_StudentFactory` (node pool/free-list) + `CP_StudentProduct` (active list) backed by `CP_NodeDoubleLink` |
| 14 | `U_DoubleHex` union | IEEE 754 double internals; union overlapping `double`/`unsigned long long`/`unsigned char[8]` |

## Naming Conventions

- **Files:** prefixed `CP_` (class/procedure), e.g. `CP_Complex.h` / `CP_Complex_core.cpp`
- **Classes:** prefixed `CP_`, e.g. `CP_Complex`
- **Member variables:** `m_` prefix (e.g. `m_real`, `m_size`)
- **Member functions:** `mb_` prefix (e.g. `mb_show`, `mb_isIn`)
- **Static members:** `sb_` prefix for static functions, `s_` for static variables
- **Global functions:** `gb_` prefix
- **Template implementation:** placed in `.tpp` files included at the bottom of the `.h` (see `MyVector.h` → `MyVector.tpp`)

## Testing Pattern

Each assignment rolls its own test framework — no external library. A `CP_*Test` class exposes `check()`, `checkBool()`, `checkThrows()` helpers that accumulate pass/fail counts, then `printSummary()` reports results. `CP_*TestMain.cpp` instantiates the test class and calls `runAll()`.
