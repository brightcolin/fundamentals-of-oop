[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 02 — 最大公约数与最小公倍数

[首页](../README.zh-CN.md) · C++17

## 项目简介

这是一个面向对象的最大公约数与最小公倍数计算器。`CP_GCD` 使用移位和减法实现 Stein 二进制最大公约数算法；`CP_LCM` 通过组合复用 `CP_GCD`，并采用先除后乘的公式降低溢出风险。

## 设计

| 类 | 职责 |
|---|---|
| `CP_GCD` | 计算二进制最大公约数 |
| `CP_LCM` | 通过组合计算最小公倍数 |
| `CP_Test` | 覆盖正常、边界和异常测试 |

实现遵循单一职责原则：每个类只负责一项明确任务。

### Stein 算法

```text
1. 提取公共的 2 的幂。
2. 将第一个操作数化为奇数。
3. 反复消除 2 的因子，并用较大的奇数减去较小值。
4. 恢复公共的 2 的幂。
```

最小公倍数使用 `a / gcd(a, b) * b` 计算。

## 文件结构

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

## 编译运行

```powershell
# 交互程序
g++ -std=c++17 -o main.exe CP_Main.cpp CP_GCD.cpp CP_LCM.cpp
.\main.exe

# 自动测试
g++ -std=c++17 -o run_test.exe CP_TestMain.cpp CP_GCD.cpp CP_LCM.cpp CP_Test.cpp
.\run_test.exe
```

两个目标分别包含 `main()`，必须独立编译。

---

[上一项](../assignment01/README.zh-CN.md) · [下一项](../assignment03/README.zh-CN.md)
