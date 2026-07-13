# Assignment 10 — DynArray, RAII, and Move Semantics / 动态数组、RAII 与移动语义

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

This assignment explores ownership and resource lifetime through three components: a move-only RAII pointer wrapper, a raw-pointer doubly-linked list, and an equivalent smart-pointer list.

本作业通过三个模块研究所有权与资源生命周期：仅支持移动的 RAII 指针包装器、使用裸指针的双向链表，以及对应的智能指针链表。

## Components / 组成

| Component / 组件 | Purpose / 目的 |
|---|---|
| `CP_DynArray<T>` | Owns one `T*`; copy disabled, move enabled / 独占一个 `T*`，禁用复制并支持移动 |
| `CP_DListRaw<T>` | Doubly-linked list using `new` and `delete` / 使用 `new` 和 `delete` 的双向链表 |
| `CP_DListSmart<T>` | List using `shared_ptr` forward links and `weak_ptr` back links / 前向使用 `shared_ptr`、后向使用 `weak_ptr` |
| `CP_A` | Logs construction and destruction / 输出构造与析构过程 |

Using `weak_ptr` for back links prevents the reference cycle that two `shared_ptr` links would create.

后向链接使用 `weak_ptr`，避免双向都使用 `shared_ptr` 时产生引用环。

## Files / 文件结构

```text
assignment10/
├── CP_DynArray.h
├── CP_A.h
├── CP_DListRaw.h
├── CP_DListSmart.h
├── CP_DynArrayTest.h / CP_DynArrayTest.cpp
├── CP_DynArrayTestMain.cpp
└── CP_DynArrayBenchmark.cpp
```

## Build and Run / 编译运行

```powershell
# Automated tests / 自动测试
g++ -std=c++11 -o test.exe CP_DynArrayTest.cpp CP_DynArrayTestMain.cpp
.\test.exe

# Raw-pointer vs smart-pointer benchmark / 裸指针与智能指针性能比较
g++ -std=c++11 -O2 -o benchmark.exe CP_DynArrayBenchmark.cpp
.\benchmark.exe
```

The tests verify move construction and assignment, deleted-copy semantics, pointer access, swapping, destruction, and both list implementations.

测试验证移动构造与赋值、禁用复制、指针访问、交换、析构以及两种链表实现。

---

[Previous / 上一项](../assignment09/README.md) · [Next / 下一项](../assignment11/README.md)
