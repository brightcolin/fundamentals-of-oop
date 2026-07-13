# Assignment 06 — Student System with a Doubly-Linked List / 双向链表学生系统

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

A console student-management system backed by a circular doubly-linked list. Records remain sorted by student ID and can be inserted, deleted, queried, or listed.

这是一个基于循环双向链表的控制台学生管理系统。学生记录始终按 ID 升序排列，支持插入、删除、查询和完整显示。

## Design / 设计

```text
CP_Student                 # ID and score / 学号与成绩
CP_ChainDoubleLink         # Node and circular-list controller / 节点兼链表控制器
└── CP_StudentSystem       # Interactive menu / 交互菜单
```

`CP_ChainDoubleLink` acts as both a node and the head sentinel. The last node points back to the head, and memory is managed explicitly with `new` and `delete`.

`CP_ChainDoubleLink` 同时承担节点与头哨兵角色。尾节点重新指向头节点，节点内存通过 `new` 和 `delete` 显式管理。

| Operation / 操作 | Behavior / 行为 |
|---|---|
| Insert / 插入 | Sorted by ID; duplicate IDs rejected / 按 ID 排序并拒绝重复值 |
| Delete / 删除 | By ID or all records matching a score / 按 ID 或成绩批量删除 |
| Query / 查询 | By ID or score / 按 ID 或成绩查询 |
| Display / 显示 | Print all records in ID order / 按 ID 顺序输出全部记录 |

## Files / 文件结构

```text
assignment06/
├── CP_Student.h / CP_Student.cpp
├── CP_ChainDoubleLink.h / CP_ChainDoubleLink.cpp
├── CP_StudentSystem.h / CP_StudentSystem.cpp
├── CP_StudentSystemMain.cpp
├── CP_StudentSystemTest.h / CP_StudentSystemTest.cpp
└── CP_StudentSystemTestMain.cpp
```

## Build and Run / 编译运行

```powershell
# Interactive program / 交互程序
g++ -std=c++11 -o main.exe CP_Student.cpp CP_ChainDoubleLink.cpp CP_StudentSystem.cpp CP_StudentSystemMain.cpp
.\main.exe

# Automated tests / 自动测试
g++ -std=c++11 -o run_test.exe CP_Student.cpp CP_ChainDoubleLink.cpp CP_StudentSystemTest.cpp CP_StudentSystemTestMain.cpp
.\run_test.exe
```

The seven test groups cover ordering, deletion positions, score matches, lookup, duplicate IDs, empty lists, and mixed operations.

七组测试覆盖排序、不同位置删除、成绩匹配、查询、重复 ID、空链表和混合操作。

---

[Previous / 上一项](../assignment05/README.md) · [Next / 下一项](../assignment07/README.md)
