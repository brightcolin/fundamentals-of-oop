[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 10 — 动态数组、RAII 与移动语义

[首页](../README.zh-CN.md) · C++11

## 项目简介

本作业通过三个模块研究所有权与资源生命周期：仅支持移动的 RAII 指针包装器、使用裸指针的双向链表，以及对应的智能指针链表。

## 组成

| 组件 | 目的 |
|---|---|
| `CP_DynArray<T>` | 独占一个 `T*`，禁用复制并支持移动 |
| `CP_DListRaw<T>` | 使用 `new` 和 `delete` 的双向链表 |
| `CP_DListSmart<T>` | 前向使用 `shared_ptr`、后向使用 `weak_ptr` 的链表 |
| `CP_A` | 输出构造与析构过程 |

后向链接使用 `weak_ptr`，避免双向都使用 `shared_ptr` 时产生引用环。

## 文件结构

```text
assignment10/
├── CP_DynArray.h
├── CP_A.h
├── CP_DListRaw.h
├── CP_DListSmart.h
├── CP_DynArrayTest.h / CP_DynArrayTest.cpp
├── CP_DynArrayTestMain.cpp
├── CP_DynArrayBenchmark.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
# 自动测试
g++ -std=c++11 -o test.exe CP_DynArrayTest.cpp CP_DynArrayTestMain.cpp
.\test.exe

# 裸指针与智能指针性能比较
g++ -std=c++11 -O2 -o benchmark.exe CP_DynArrayBenchmark.cpp
.\benchmark.exe
```

测试验证移动构造与赋值、禁用复制、指针访问、交换、析构以及两种链表实现。

---

[上一项](../assignment09/README.zh-CN.md) · [下一项](../assignment11/README.zh-CN.md)
