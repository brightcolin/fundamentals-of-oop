[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 13 — 对象池学生系统

[首页](../README.zh-CN.md) · C++11

## 项目简介

这是对作业 06 的重构，将节点、活动链表和分配策略分离。被删除的节点会归还给工厂管理的空闲链表，并在后续插入时复用。

## 设计

```text
CP_NodeDoubleLink
├── CP_StudentProduct   # 活动有序链表
└── CP_StudentFactory   # 空闲链表与节点复用
        ↑
CP_StudentSystem 同时持有并协调两者
```

| 方面 | 作业 06 | 作业 13 |
|---|---|---|
| 节点与链表设计 | 一个自引用类 | 节点与链表分离 |
| 分配 | 直接 `new` | `factory.mb_getNode()` |
| 释放 | 直接 `delete` | `factory.mb_returnNode()` |
| 复用 | 无 | 空闲链表复用 |

## 文件结构

```text
assignment13/
├── CP_Student.h                 # 仅头文件数据类
├── CP_NodeDoubleLink.h
├── CP_StudentFactory.h / CP_StudentFactory.cpp
├── CP_StudentProduct.h / CP_StudentProduct.cpp
├── CP_StudentSystem.h / CP_StudentSystem.cpp
├── CP_StudentSystemMain.cpp
├── CP_StudentSystemTest.h / CP_StudentSystemTest.cpp
├── CP_StudentSystemTestMain.cpp
├── CP_PerformanceTest.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
# 交互程序
g++ -std=c++11 -o run_main.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_StudentSystem.cpp CP_StudentSystemMain.cpp
.\run_main.exe

# 自动测试
g++ -std=c++11 -o run_test.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_StudentSystemTest.cpp CP_StudentSystemTestMain.cpp
.\run_test.exe

# 性能测试
g++ -std=c++11 -O2 -o run_perf.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_PerformanceTest.cpp
.\run_perf.exe
```

九组测试复用作业 06 的场景，并增加工厂回收与行为对比测试。`CP_Student` 仅在头文件中实现，因此无需单独的实现源文件。

---

[上一项](../assignment12/README.zh-CN.md) · [下一项](../assignment14/README.zh-CN.md)
