# Assignment 02 — GCD & LCM Calculator / 最大公约数与最小公倍数

[Home / 首页](../README.md) · C++17

## Overview / 项目简介

An object-oriented GCD and LCM calculator. `CP_GCD` implements Stein's binary GCD algorithm using shifts and subtraction, while `CP_LCM` composes a `CP_GCD` object and uses a divide-first formula to reduce overflow risk.

这是一个面向对象的最大公约数与最小公倍数计算器。`CP_GCD` 使用移位和减法实现 Stein 二进制最大公约数算法；`CP_LCM` 通过组合复用 `CP_GCD`，并采用先除后乘的公式降低溢出风险。

## Design / 设计

| Class / 类 | Responsibility / 职责 |
|---|---|
| `CP_GCD` | Binary GCD calculation / 二进制最大公约数计算 |
| `CP_LCM` | LCM calculation through composition / 通过组合计算最小公倍数 |
| `CP_Test` | Normal, boundary, and exceptional test cases / 正常、边界和异常测试 |

The implementation follows the single-responsibility principle: each class owns one focused operation.

实现遵循单一职责原则：每个类只负责一项明确任务。

### Stein Algorithm / Stein 算法

```text
1. Extract the common power of two. / 提取公共的 2 的幂。
2. Make the first operand odd. / 将第一个操作数化为奇数。
3. Repeatedly remove powers of two and subtract the smaller odd value.
   反复消除 2 的因子，并用较大的奇数减去较小值。
4. Restore the common power of two. / 恢复公共的 2 的幂。
```

LCM is calculated as `a / gcd(a, b) * b`. / 最小公倍数使用 `a / gcd(a, b) * b` 计算。

## Files / 文件结构

```text
assignment02/
├── CP_GCD.h / CP_GCD.cpp
├── CP_LCM.h / CP_LCM.cpp
├── CP_Test.h / CP_Test.cpp
├── CP_Main.cpp
└── CP_TestMain.cpp
```

## Build and Run / 编译运行

```powershell
# Interactive program / 交互程序
g++ -std=c++17 -o main.exe CP_Main.cpp CP_GCD.cpp CP_LCM.cpp
.\main.exe

# Automated tests / 自动测试
g++ -std=c++17 -o run_test.exe CP_TestMain.cpp CP_GCD.cpp CP_LCM.cpp CP_Test.cpp
.\run_test.exe
```

The two targets contain separate `main()` functions and must be compiled independently. / 两个目标分别包含 `main()`，必须独立编译。

---

[Previous / 上一项](../assignment01/README.md) · [Next / 下一项](../assignment03/README.md)
