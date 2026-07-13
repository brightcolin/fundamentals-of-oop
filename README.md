# Fundamentals of Object-Oriented Programming

<p align="center">
  <strong>A collection of 14 C++ course assignments covering object-oriented design, generic programming, resource management, and testing.</strong><br>
  <strong>面向对象程序设计基础课程作业集，包含 14 个循序渐进的 C++ 项目。</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-11%20%7C%2017-00599C?logo=c%2B%2B&logoColor=white" alt="C++11 and C++17">
  <img src="https://img.shields.io/badge/assignments-14%2F14-2ea44f" alt="14 of 14 assignments completed">
  <img src="https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white" alt="Windows">
  <img src="https://img.shields.io/badge/compiler-g%2B%2B%20(MinGW--w64)-blue" alt="g++ MinGW-w64">
  <a href="LICENSE"><img src="https://img.shields.io/badge/license-MIT-yellow" alt="MIT License"></a>
</p>

## About / 项目简介

This repository preserves the complete coursework for *Fundamentals of Object-Oriented Programming*. Each assignment is an independent console project and focuses on a specific C++ or object-oriented programming concept. The implementations primarily use the C++ standard library and include small, self-contained test programs where applicable.

本仓库收录《面向对象程序设计基础》课程的完整作业。每个作业都是相互独立的控制台项目，集中练习一组 C++ 或面向对象编程知识。项目主要使用 C++ 标准库，并在适用的作业中提供独立的测试程序。

## Assignment Index / 作业索引

| # | Project / 项目 | Main concepts / 核心知识 | Standard |
|---:|---|---|:---:|
| 01 | [Shape Puzzle System / 图形拼图系统](assignment01/) | Abstract classes, inheritance, polymorphism / 抽象类、继承、多态 | C++11 |
| 02 | [GCD & LCM Calculator / 最大公约数与最小公倍数](assignment02/) | Single responsibility, composition, Stein algorithm / 单一职责、组合、Stein 算法 | C++17 |
| 03 | [Shape Calculation System / 图形计算系统](assignment03/) | Multi-level inheritance, shared formulas / 多层继承、公式复用 | C++11 |
| 04 | [Calendar Calculator / 日历计算系统](assignment04/) | Inheritance, Julian Day Number, B.C./A.D. / 继承、儒略日、跨公元纪年 | C++11 |
| 05 | [Complex Number Calculator / 复数计算系统](assignment05/) | Operator overloading, stream I/O / 运算符重载、流输入输出 | C++11 |
| 06 | [Student System: Linked List / 学生系统：双向链表](assignment06/) | Circular doubly-linked list, manual memory / 循环双向链表、手动内存管理 | C++11 |
| 07 | [`MyVector<T>` & IntSorter / 动态数组模板与排序](assignment07/) | Templates, rule of three, iterators / 模板、三法则、迭代器 | C++11 |
| 08 | [Big Integer by String / 字符串大整数](assignment08/) | Arbitrary-precision integer arithmetic / 任意精度整数运算 | C++11 |
| 09 | [Grade Sheet System / 成绩单管理系统](assignment09/) | File I/O, CRUD, class composition / 文件读写、增删改查、类组合 | C++11 |
| 10 | [DynArray / 动态数组资源包装器](assignment10/) | RAII, move semantics, smart pointers / RAII、移动语义、智能指针 | C++11 |
| 11 | [Vector Operations / 向量运算](assignment11/) | Scalar multiplication, dot product, parallel STL / 标量乘法、点积、并行 STL | C++17 |
| 12 | [Integer Parser / 整数字符串解析器](assignment12/) | Parsing, custom exceptions, overflow checks / 字符串解析、自定义异常、溢出检查 | C++11 |
| 13 | [Student System: Object Pool / 学生系统：对象池](assignment13/) | Factory, free list, node reuse / 工厂、空闲链表、节点复用 | C++11 |
| 14 | [IEEE 754 Double Inspector / 双精度浮点剖析](assignment14/) | Union memory overlay, IEEE 754 / 联合体内存重叠、IEEE 754 | C++11 |

Every assignment directory contains a bilingual README with its design, file layout, build commands, and test instructions.

每个作业目录都包含一份双语 README，介绍设计思路、文件结构、编译命令和测试方式。

## Repository Layout / 仓库结构

```text
.
├── assignment01/ ... assignment14/  # Independent assignments / 独立作业
├── AGENTS.md                         # Codex project guidance / Codex 项目指引
├── CLAUDE.md                         # Claude Code guidance / Claude Code 项目指引
├── LICENSE                           # MIT License
└── README.md                         # Project overview / 项目总览
```

## Getting Started / 快速开始

### Requirements / 环境要求

- Windows 10 or 11 / Windows 10 或 11
- `g++` from MinGW-w64 / MinGW-w64 提供的 `g++`
- C++11 or C++17 support, depending on the assignment / 根据作业要求支持 C++11 或 C++17
- A Parallel STL backend such as oneTBB for Assignment 11 / 作业 11 需要 oneTBB 等并行 STL 后端

Each directory is compiled independently. Open PowerShell in the repository root, enter an assignment directory, and use the command documented in that directory's README.

每个目录均独立编译。在仓库根目录打开 PowerShell，进入目标作业目录，然后执行该目录 README 中的命令。

```powershell
cd assignment05
g++ -std=c++11 -o test.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp CP_ComplexTestMain.cpp
.\test.exe
```

Interactive programs and test runners have separate `main()` functions and must not be linked into the same executable.

交互程序和测试程序各自包含 `main()`，不能链接到同一个可执行文件中。

## Verification Status / 验证状态

All 30 documented targets were compiled successfully with MSYS2 UCRT64 `g++` 16.1.0. The 12 automated test executables completed 408 checks with no failures. Assignment 11 uses oneTBB 2023.0.0 as its Parallel STL backend and links against `tbb12`.

全部 30 个文档目标均已使用 MSYS2 UCRT64 `g++` 16.1.0 成功编译；12 个自动化测试程序共完成 408 项检查，且无失败项。作业 11 使用 oneTBB 2023.0.0 作为并行 STL 后端，并链接 `tbb12`。

## Conventions / 代码约定

- Classes and project files use the `CP_` prefix. / 类和项目文件使用 `CP_` 前缀。
- Member variables use `m_`; member functions use `mb_`. / 成员变量使用 `m_`，成员函数使用 `mb_`。
- Global functions use `gb_`; static members use `s_` or `sb_`. / 全局函数使用 `gb_`，静态成员使用 `s_` 或 `sb_`。
- Template implementations are placed in `.tpp` files when separated from headers. / 模板实现与头文件分离时放在 `.tpp` 文件中。
- Generated `.exe` files are ignored by Git. / Git 会忽略生成的 `.exe` 文件。

## Academic Integrity / 学术诚信

This repository is published for learning, review, and portfolio purposes. If you are taking a similar course, follow your institution's academic integrity policy and do not submit this work, in whole or in part, as your own coursework.

本仓库仅用于学习、交流与作品展示。如果你正在修读类似课程，请遵守所在学校的学术诚信规定，不要将本仓库的全部或部分内容作为自己的课程作业提交。

## License / 许可证

Copyright © 2026 brightcolin. Released under the [MIT License](LICENSE).

版权所有 © 2026 brightcolin。本项目采用 [MIT License](LICENSE) 开源。
