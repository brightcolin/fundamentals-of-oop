# Assignment 05 — Complex Number Calculator / 复数计算系统

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

An implementation of `CP_Complex` with arithmetic, comparison, increment/decrement, compound-assignment, and stream operators. The code separates the class interface from three focused implementation files and includes an equivalence-class test suite.

本项目实现了 `CP_Complex` 复数类，支持算术、比较、自增自减、复合赋值和流运算符。类接口与三组职责明确的实现文件相分离，并配有等价类测试程序。

## Supported Operators / 支持的运算符

| Category / 类别 | Operators / 运算符 |
|---|---|
| Arithmetic / 算术 | `+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=` |
| Increment / 自增自减 | Prefix and postfix `++`, `--` / 前置与后置 `++`、`--` |
| Comparison / 比较 | `==`, `!=` |
| Stream I/O / 流输入输出 | `<<`, `>>` |

Division uses `(c²+d²)` as the denominator and throws `std::domain_error` when the divisor is zero.

除法以 `(c²+d²)` 为分母；除数为零时抛出 `std::domain_error`。

## Structure / 结构

```text
assignment05/
├── CP_Complex.h
├── CP_Complex_core.cpp       # Construction, access, stream I/O / 构造、访问、流
├── CP_Complex_arith.cpp      # Arithmetic / 算术
├── CP_Complex_incdec.cpp     # Increment and comparison / 自增自减与比较
├── CP_ComplexMain.cpp
├── CP_ComplexTest.h / CP_ComplexTest.cpp
├── CP_ComplexTest_arith.cpp
├── CP_ComplexTest_incdec.cpp
└── CP_ComplexTestMain.cpp
```

## Build and Run / 编译运行

```powershell
# Interactive program / 交互程序
g++ -std=c++11 -o complex.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexMain.cpp
.\complex.exe

# Automated tests / 自动测试
g++ -std=c++11 -o run_test.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp CP_ComplexTestMain.cpp
.\run_test.exe
```

Complex input uses `real imag`, for example `3 4` for `3+4i`. The test suite contains 53 checks covering general, real-only, imaginary-only, zero, negative, and zero-divisor cases.

复数按 `实部 虚部` 输入，例如 `3 4` 表示 `3+4i`。测试套件包含 53 项检查，覆盖一般复数、纯实数、纯虚数、零、负数和除零情况。

---

[Previous / 上一项](../assignment04/README.md) · [Next / 下一项](../assignment06/README.md)
