# Assignment 13 — Student System with an Object Pool / 对象池学生系统

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

A refactoring of Assignment 06 that separates nodes, the active list, and allocation policy. Deleted nodes are returned to a factory-managed free list and reused by later insertions.

这是对作业 06 的重构，将节点、活动链表和分配策略分离。被删除的节点会归还给工厂管理的空闲链表，并在后续插入时复用。

## Design / 设计

```text
CP_NodeDoubleLink
├── CP_StudentProduct   # Active sorted list / 活动有序链表
└── CP_StudentFactory   # Free list and node reuse / 空闲链表与节点复用
        ↑
CP_StudentSystem owns and coordinates both / 同时持有并协调两者
```

| Aspect / 方面 | Assignment 06 / 作业 06 | Assignment 13 / 作业 13 |
|---|---|---|
| Node/list design / 节点与链表 | One self-referential class / 一个自引用类 | Separate node and list / 节点与链表分离 |
| Allocation / 分配 | Direct `new` / 直接 `new` | `factory.mb_getNode()` |
| Deallocation / 释放 | Direct `delete` / 直接 `delete` | `factory.mb_returnNode()` |
| Reuse / 复用 | None / 无 | Free-list reuse / 空闲链表复用 |

## Files / 文件结构

```text
assignment13/
├── CP_Student.h                 # Header-only data class / 仅头文件数据类
├── CP_NodeDoubleLink.h
├── CP_StudentFactory.h / CP_StudentFactory.cpp
├── CP_StudentProduct.h / CP_StudentProduct.cpp
├── CP_StudentSystem.h / CP_StudentSystem.cpp
├── CP_StudentSystemMain.cpp
├── CP_StudentSystemTest.h / CP_StudentSystemTest.cpp
├── CP_StudentSystemTestMain.cpp
└── CP_PerformanceTest.cpp
```

## Build and Run / 编译运行

```powershell
# Interactive program / 交互程序
g++ -std=c++11 -o run_main.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_StudentSystem.cpp CP_StudentSystemMain.cpp
.\run_main.exe

# Automated tests / 自动测试
g++ -std=c++11 -o run_test.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_StudentSystemTest.cpp CP_StudentSystemTestMain.cpp
.\run_test.exe

# Performance benchmark / 性能测试
g++ -std=c++11 -O2 -o run_perf.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_PerformanceTest.cpp
.\run_perf.exe
```

The nine test groups reuse Assignment 06 scenarios and add factory recycling plus behavioral comparison. `CP_Student` is header-only, so no separate implementation source is required.

九组测试复用作业 06 的场景，并增加工厂回收与行为对比测试。`CP_Student` 仅在头文件中实现，因此无需单独的实现源文件。

---

[Previous / 上一项](../assignment12/README.md) · [Next / 下一项](../assignment14/README.md)
