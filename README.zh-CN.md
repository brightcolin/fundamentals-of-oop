[English](README.md) | [简体中文](README.zh-CN.md)

# 面向对象程序设计基础

<p align="center">
  <strong>面向对象程序设计基础课程作业集，包含 14 个循序渐进的 C++ 项目。</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-11%20%7C%2017-00599C?logo=c%2B%2B&logoColor=white" alt="C++11 与 C++17">
  <img src="https://img.shields.io/badge/assignments-14%2F14-2ea44f" alt="14 项作业全部完成">
  <img src="https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white" alt="Windows">
  <img src="https://img.shields.io/badge/compiler-g%2B%2B%20(MinGW--w64)-blue" alt="g++ MinGW-w64">
  <a href="LICENSE"><img src="https://img.shields.io/badge/license-MIT-yellow" alt="MIT 许可证"></a>
</p>

## 项目简介

本仓库收录《面向对象程序设计基础》课程的完整作业。每个作业都是相互独立的控制台项目，集中练习一组 C++ 或面向对象编程知识。项目主要使用 C++ 标准库，并在适用的作业中提供独立的测试程序。

## 作业索引

| 序号 | 项目 | 核心知识 | 标准 |
|---:|---|---|:---:|
| 01 | [图形拼图系统](assignment01/README.zh-CN.md) | 抽象类、继承、多态 | C++11 |
| 02 | [最大公约数与最小公倍数](assignment02/README.zh-CN.md) | 单一职责、组合、Stein 算法 | C++17 |
| 03 | [图形计算系统](assignment03/README.zh-CN.md) | 多层继承、公式复用 | C++11 |
| 04 | [日历计算系统](assignment04/README.zh-CN.md) | 继承、儒略日、跨公元纪年 | C++11 |
| 05 | [复数计算系统](assignment05/README.zh-CN.md) | 运算符重载、流输入输出 | C++11 |
| 06 | [学生系统：双向链表](assignment06/README.zh-CN.md) | 循环双向链表、手动内存管理 | C++11 |
| 07 | [`MyVector<T>` 与整数排序](assignment07/README.zh-CN.md) | 模板、三法则、迭代器 | C++11 |
| 08 | [字符串大整数](assignment08/README.zh-CN.md) | 任意精度整数运算 | C++11 |
| 09 | [成绩单管理系统](assignment09/README.zh-CN.md) | 文件读写、增删改查、类组合 | C++11 |
| 10 | [动态数组资源包装器](assignment10/README.zh-CN.md) | RAII、移动语义、智能指针 | C++11 |
| 11 | [向量运算](assignment11/README.zh-CN.md) | 标量乘法、点积、并行 STL | C++17 |
| 12 | [整数字符串解析器](assignment12/README.zh-CN.md) | 字符串解析、自定义异常、溢出检查 | C++11 |
| 13 | [学生系统：对象池](assignment13/README.zh-CN.md) | 工厂、空闲链表、节点复用 | C++11 |
| 14 | [IEEE 754 双精度浮点剖析](assignment14/README.zh-CN.md) | 联合体内存重叠、IEEE 754 | C++11 |

每个作业目录均提供独立的英文版和简体中文版 README，介绍设计思路、文件结构、编译命令和测试方式。

## 仓库结构

```text
.
├── assignment01/ ... assignment14/  # 独立作业
├── AGENTS.md                         # Codex 项目指引
├── CLAUDE.md                         # Claude Code 项目指引
├── LICENSE                           # MIT 许可证
├── README.md                         # 英文项目总览
└── README.zh-CN.md                   # 简体中文项目总览
```

## 快速开始

### 环境要求

- Windows 10 或 11
- MinGW-w64 提供的 `g++`
- 根据作业要求支持 C++11 或 C++17
- 作业 11 需要 oneTBB 等并行 STL 后端

每个目录均独立编译。在仓库根目录打开 PowerShell，进入目标作业目录，然后执行该目录 README 中的命令。

```powershell
cd assignment05
g++ -std=c++11 -o test.exe CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp CP_ComplexTestMain.cpp
.\test.exe
```

交互程序和测试程序各自包含 `main()`，不能链接到同一个可执行文件中。

## 验证状态

全部 30 个文档目标均已使用 MSYS2 UCRT64 `g++` 16.1.0 成功编译；12 个自动化测试程序共完成 408 项检查，且无失败项。作业 11 使用 oneTBB 2023.0.0 作为并行 STL 后端，并链接 `tbb12`。

## 代码约定

- 类和项目文件使用 `CP_` 前缀。
- 成员变量使用 `m_`，成员函数使用 `mb_`。
- 全局函数使用 `gb_`，静态成员使用 `s_` 或 `sb_`。
- 模板实现与头文件分离时放在 `.tpp` 文件中。
- Git 会忽略生成的 `.exe` 文件。

## 学术诚信

本仓库仅用于学习、交流与作品展示。如果你正在修读类似课程，请遵守所在学校的学术诚信规定，不要将本仓库的全部或部分内容作为自己的课程作业提交。

## 许可证

版权所有 © 2026 brightcolin。本项目采用 [MIT License](LICENSE) 开源。
