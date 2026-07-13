[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 14 — IEEE 754 双精度浮点剖析

[首页](../README.zh-CN.md) · C++11

## 项目简介

这是一个教学用浮点检查工具，通过联合体让 `double`、64 位无符号整数和八个字节共享同一段内存，并显示符号位、指数、尾数、原始十六进制表示以及 NaN、无穷等特殊值。

## 内存布局

```cpp
union U_DoubleHex {
    double             m_double;
    unsigned long long m_ull;
    unsigned char      m_bytes[8];
};
```

```text
第 63 位     第 62–52 位     第 51–0 位
符号位（1）   指数位（11）     小数部分（52）
```

| 数值 | 指数 | 小数部分 |
|---|---|---|
| `±0.0` | 全零 | 全零 |
| `±∞` | 全一 | 全零 |
| NaN | 全一 | 非零 |

## 文件结构

```text
assignment14/
├── CP_UnionDoubleHex.h / CP_UnionDoubleHex.cpp
├── CP_UnionDoubleHexMain.cpp
├── CP_UnionDoubleHexTest.h / CP_UnionDoubleHexTest.cpp
├── CP_UnionDoubleHexTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
# 交互演示
g++ -std=c++11 -o main.exe CP_UnionDoubleHex.cpp CP_UnionDoubleHexMain.cpp
.\main.exe

# 自动测试
g++ -std=c++11 -o run_test.exe CP_UnionDoubleHex.cpp CP_UnionDoubleHexTest.cpp CP_UnionDoubleHexTestMain.cpp
.\run_test.exe
```

程序显示的字节顺序取决于平台，本实现面向小端序 x86/x86-64 环境。通过读取联合体的非活动成员进行类型观察依赖 GCC 常见扩展行为，并非完全可移植的 ISO C++ 写法。

---

[上一项](../assignment13/README.zh-CN.md) · [首页](../README.zh-CN.md)
