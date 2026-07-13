# Assignment 14 — IEEE 754 Double Inspector / IEEE 754 双精度浮点剖析

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

An educational inspection tool that overlays a `double`, a 64-bit unsigned integer, and eight bytes in a union. It displays the sign, exponent, fraction, raw hexadecimal representation, and special values such as NaN and infinity.

这是一个教学用浮点检查工具，通过联合体让 `double`、64 位无符号整数和八个字节共享同一段内存，并显示符号位、指数、尾数、原始十六进制表示以及 NaN、无穷等特殊值。

## Memory Layout / 内存布局

```cpp
union U_DoubleHex {
    double             m_double;
    unsigned long long m_ull;
    unsigned char      m_bytes[8];
};
```

```text
Bit 63       Bits 62–52       Bits 51–0
Sign (1)     Exponent (11)    Fraction (52)
符号位        指数位            小数部分
```

| Value / 数值 | Exponent / 指数 | Fraction / 小数部分 |
|---|---|---|
| `±0.0` | All zero / 全零 | All zero / 全零 |
| `±∞` | All one / 全一 | All zero / 全零 |
| NaN | All one / 全一 | Non-zero / 非零 |

## Files / 文件结构

```text
assignment14/
├── CP_UnionDoubleHex.h / CP_UnionDoubleHex.cpp
├── CP_UnionDoubleHexMain.cpp
├── CP_UnionDoubleHexTest.h / CP_UnionDoubleHexTest.cpp
└── CP_UnionDoubleHexTestMain.cpp
```

## Build and Run / 编译运行

```powershell
# Interactive walkthrough / 交互演示
g++ -std=c++11 -o main.exe CP_UnionDoubleHex.cpp CP_UnionDoubleHexMain.cpp
.\main.exe

# Automated tests / 自动测试
g++ -std=c++11 -o run_test.exe CP_UnionDoubleHex.cpp CP_UnionDoubleHexTest.cpp CP_UnionDoubleHexTestMain.cpp
.\run_test.exe
```

The byte order shown by the program is platform-dependent. This implementation targets little-endian x86/x86-64 environments. Reading a non-active union member for type inspection relies on compiler behavior commonly supported by GCC and is not fully portable ISO C++.

程序显示的字节顺序取决于平台，本实现面向小端序 x86/x86-64 环境。通过读取联合体的非活动成员进行类型观察依赖 GCC 常见扩展行为，并非完全可移植的 ISO C++ 写法。

---

[Previous / 上一项](../assignment13/README.md) · [Home / 首页](../README.md)
