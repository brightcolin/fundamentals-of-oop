# AGENTS.md

This file provides guidance to Codex when working with code in this repository.

## Overview

C++ OOP course assignments (面向对象程序设计基础). Compiler: g++ (MinGW-w64) on Windows. Standards: C++11 or C++17 depending on the assignment.

## Build Commands

There is no repository-wide build system. Compile each assignment independently using the exact command in that assignment's `README.md`. Always list source files explicitly because several directories contain multiple entry points or support files that must not be linked together.

For example, Assignment 05 has separate interactive and test executables:

```bash
g++ -std=c++11 -o complex.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexMain.cpp
g++ -std=c++11 -o run_test.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp CP_ComplexTestMain.cpp
./run_test.exe
```

Program structure varies by assignment: some have only an interactive entry point, while others provide one or more test or benchmark entry points. Never link two source files that define `main()` into the same executable.

Assignment 11 requires a Parallel STL backend. With MSYS2 UCRT64 and `mingw-w64-ucrt-x86_64-tbb`, link against `tbb12`:

```bash
g++ -std=c++17 -o test.exe CP_VectorOp.cpp CP_VectorOpTest.cpp CP_VectorOpTestMain.cpp -ltbb12
```

Other GCC distributions may expose the library as `tbb`; check the local oneTBB package metadata when `-ltbb12` is unavailable.

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

Automated test executables are provided for Assignments 02 and 05–14; Assignment 07 has two independent test executables. The tests are self-contained and use no external testing framework, but their class names and helper functions vary by assignment. Use the build and run commands in each assignment's `README.md` instead of assuming a uniform test layout.

The documented commands were verified with MSYS2 UCRT64 `g++` 16.1.0: all 30 targets compile, and the 12 automated test executables complete 408 checks with no failures.
