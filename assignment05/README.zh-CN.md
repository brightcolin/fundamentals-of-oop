[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 05 — 复数计算系统

[首页](../README.zh-CN.md) · C++11

## 项目简介

本项目实现了 `CP_Complex` 复数类，支持算术、比较、自增自减、复合赋值和流运算符。类接口与三组职责明确的实现文件相分离，并配有等价类测试程序。

## 支持的运算符

| 类别 | 运算符 |
|---|---|
| 算术 | `+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=` |
| 自增自减 | 前置与后置 `++`、`--` |
| 比较 | `==`, `!=` |
| 流输入输出 | `<<`, `>>` |

除法以 `(c²+d²)` 为分母；除数为零时抛出 `std::domain_error`。

## 文件结构

```text
assignment05/
├── CP_Complex.h
├── CP_Complex_core.cpp       # 构造、访问和流输入输出
├── CP_Complex_arith.cpp      # 算术运算
├── CP_Complex_incdec.cpp     # 自增自减与比较
├── CP_ComplexMain.cpp
├── CP_ComplexTest.h / CP_ComplexTest.cpp
├── CP_ComplexTest_arith.cpp
├── CP_ComplexTest_incdec.cpp
├── CP_ComplexTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
# 交互程序
g++ -std=c++11 -o complex.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexMain.cpp
.\complex.exe

# 自动测试
g++ -std=c++11 -o run_test.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp CP_ComplexTestMain.cpp
.\run_test.exe
```

复数按 `实部 虚部` 输入，例如 `3 4` 表示 `3+4i`。测试套件包含 53 项检查，覆盖一般复数、纯实数、纯虚数、零、负数和除零情况。

---

[上一项](../assignment04/README.zh-CN.md) · [下一项](../assignment06/README.zh-CN.md)
