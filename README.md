[English](README.md) | [简体中文](README.zh-CN.md)

# Fundamentals of Object-Oriented Programming

<p align="center">
  <strong>A collection of 14 C++ course assignments covering object-oriented design, generic programming, resource management, and testing.</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-11%20%7C%2017-00599C?logo=c%2B%2B&logoColor=white" alt="C++11 and C++17">
  <img src="https://img.shields.io/badge/assignments-14%2F14-2ea44f" alt="14 of 14 assignments completed">
  <img src="https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white" alt="Windows">
  <img src="https://img.shields.io/badge/compiler-g%2B%2B%20(MinGW--w64)-blue" alt="g++ MinGW-w64">
  <a href="LICENSE"><img src="https://img.shields.io/badge/license-MIT-yellow" alt="MIT License"></a>
</p>

## About

This repository preserves the complete coursework for *Fundamentals of Object-Oriented Programming*. Each assignment is an independent console project focused on a specific C++ or object-oriented programming concept. The implementations primarily use the C++ standard library and include small, self-contained test programs where applicable.

## Assignment Index

| # | Project | Main concepts | Standard |
|---:|---|---|:---:|
| 01 | [Shape Puzzle System](assignment01/README.md) | Abstract classes, inheritance, polymorphism | C++11 |
| 02 | [GCD & LCM Calculator](assignment02/README.md) | Single responsibility, composition, Stein algorithm | C++17 |
| 03 | [Shape Calculation System](assignment03/README.md) | Multi-level inheritance, shared formulas | C++11 |
| 04 | [Calendar Calculator](assignment04/README.md) | Inheritance, Julian Day Number, B.C./A.D. | C++11 |
| 05 | [Complex Number Calculator](assignment05/README.md) | Operator overloading, stream I/O | C++11 |
| 06 | [Student System: Linked List](assignment06/README.md) | Circular doubly-linked list, manual memory management | C++11 |
| 07 | [`MyVector<T>` & IntSorter](assignment07/README.md) | Templates, rule of three, iterators | C++11 |
| 08 | [Big Integer by String](assignment08/README.md) | Arbitrary-precision integer arithmetic | C++11 |
| 09 | [Grade Sheet System](assignment09/README.md) | File I/O, CRUD, class composition | C++11 |
| 10 | [DynArray](assignment10/README.md) | RAII, move semantics, smart pointers | C++11 |
| 11 | [Vector Operations](assignment11/README.md) | Scalar multiplication, dot product, parallel STL | C++17 |
| 12 | [Integer Parser](assignment12/README.md) | Parsing, custom exceptions, overflow checks | C++11 |
| 13 | [Student System: Object Pool](assignment13/README.md) | Factory, free list, node reuse | C++11 |
| 14 | [IEEE 754 Double Inspector](assignment14/README.md) | Union memory overlay, IEEE 754 | C++11 |

Each assignment directory contains separate English and Simplified Chinese READMEs with design notes, file layout, build commands, and test instructions.

## Repository Layout

```text
.
├── assignment01/ ... assignment14/  # Independent assignments
├── AGENTS.md                         # Codex project guidance
├── CLAUDE.md                         # Claude Code project guidance
├── LICENSE                           # MIT License
├── README.md                         # English project overview
└── README.zh-CN.md                   # Simplified Chinese project overview
```

## Getting Started

### Requirements

- Windows 10 or 11
- `g++` from MinGW-w64
- C++11 or C++17 support, depending on the assignment
- A Parallel STL backend such as oneTBB for Assignment 11

Each directory is compiled independently. Open PowerShell in the repository root, enter an assignment directory, and use the command documented in that directory's README.

```powershell
cd assignment05
g++ -std=c++11 -o test.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp CP_ComplexTestMain.cpp
.\test.exe
```

Interactive programs and test runners have separate `main()` functions and must not be linked into the same executable.

## Verification Status

All 30 documented targets were compiled successfully with MSYS2 UCRT64 `g++` 16.1.0. The 12 automated test executables completed 408 checks with no failures. Assignment 11 uses oneTBB 2023.0.0 as its Parallel STL backend and links against `tbb12`.

## Conventions

- Classes and project files use the `CP_` prefix.
- Member variables use `m_`; member functions use `mb_`.
- Global functions use `gb_`; static members use `s_` or `sb_`.
- Template implementations are placed in `.tpp` files when separated from headers.
- Generated `.exe` files are ignored by Git.

## Academic Integrity

This repository is published for learning, review, and portfolio purposes. If you are taking a similar course, follow your institution's academic integrity policy and do not submit this work, in whole or in part, as your own coursework.

## License

Copyright © 2026 brightcolin. Released under the [MIT License](LICENSE).
