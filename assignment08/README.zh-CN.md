[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 08 — 字符串大整数

[首页](../README.zh-CN.md) · C++11

## 项目简介

`CP_IntByString` 使用十进制字符串实现有符号任意精度整数运算。加、减、乘和整数除法均通过字符串竖式算法完成，不依赖内置大整数类型。

## 设计

```text
CP_IntByString
├── m_flag : 符号
├── m_data : 规范化后的绝对值数字串
├── operator +, -, *, /, ==, !=
└── 比较、加、减、乘、除与规范化辅助函数
```

实现会移除前导零并统一零的符号；有符号运算先确定结果符号，再转化为无符号数字串运算。

## 文件结构

```text
assignment08/
├── CP_IntByString.h / CP_IntByString.cpp
├── CP_IntByStringMain.cpp
├── CP_IntByStringTest.h / CP_IntByStringTest.cpp
├── CP_IntByStringTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
# 交互计算器
g++ -std=c++11 -o calc.exe CP_IntByString.cpp CP_IntByStringTest.cpp CP_IntByStringMain.cpp
.\calc.exe

# 自动测试
g++ -std=c++11 -o test.exe CP_IntByString.cpp CP_IntByStringTest.cpp CP_IntByStringTestMain.cpp
.\test.exe
```

交互入口也会调用测试运行器，因此其目标需要链接 `CP_IntByStringTest.cpp`。测试覆盖正负号、零、不同长度、整除与截断除法以及大整数操作数。

---

[上一项](../assignment07/README.zh-CN.md) · [下一项](../assignment09/README.zh-CN.md)
