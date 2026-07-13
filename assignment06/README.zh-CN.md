[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 06 — 双向链表学生系统

[首页](../README.zh-CN.md) · C++11

## 项目简介

这是一个基于循环双向链表的控制台学生管理系统。学生记录始终按 ID 升序排列，支持插入、删除、查询和完整显示。

## 设计

```text
CP_Student                 # 学号与成绩
CP_ChainDoubleLink         # 节点兼循环链表控制器
└── CP_StudentSystem       # 交互菜单
```

`CP_ChainDoubleLink` 同时承担节点与头哨兵角色。尾节点重新指向头节点，节点内存通过 `new` 和 `delete` 显式管理。

| 操作 | 行为 |
|---|---|
| 插入 | 按 ID 排序并拒绝重复值 |
| 删除 | 按 ID 或成绩批量删除 |
| 查询 | 按 ID 或成绩查询 |
| 显示 | 按 ID 顺序输出全部记录 |

## 文件结构

```text
assignment06/
├── CP_Student.h / CP_Student.cpp
├── CP_ChainDoubleLink.h / CP_ChainDoubleLink.cpp
├── CP_StudentSystem.h / CP_StudentSystem.cpp
├── CP_StudentSystemMain.cpp
├── CP_StudentSystemTest.h / CP_StudentSystemTest.cpp
├── CP_StudentSystemTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
# 交互程序
g++ -std=c++11 -o main.exe CP_Student.cpp CP_ChainDoubleLink.cpp CP_StudentSystem.cpp CP_StudentSystemMain.cpp
.\main.exe

# 自动测试
g++ -std=c++11 -o run_test.exe CP_Student.cpp CP_ChainDoubleLink.cpp CP_StudentSystemTest.cpp CP_StudentSystemTestMain.cpp
.\run_test.exe
```

七组测试覆盖排序、不同位置删除、成绩匹配、查询、重复 ID、空链表和混合操作。

---

[上一项](../assignment05/README.zh-CN.md) · [下一项](../assignment07/README.zh-CN.md)
