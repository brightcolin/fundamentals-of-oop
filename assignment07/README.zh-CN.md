[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 07 — 动态数组模板与整数排序

[首页](../README.zh-CN.md) · C++11

## 项目简介

本作业包含两个相关模块：仿照 `std::vector` 手写的动态数组模板，以及基于该容器实现的整数排序器；同时提供演示、测试和与 `std::vector` 的性能比较。

## `MyVector<T>` 接口

| 类别 | 操作 |
|---|---|
| 生命周期 | 默认、填充、复制构造与复制赋值 |
| 容量 | `size`、`capacity`、`empty`、`reserve`、`resize` |
| 访问 | `operator[]` 与带检查的 `at()` |
| 修改 | `push_back`、`pop_back`、`clear` |
| 迭代 | `begin`、`end`，支持范围 `for` |

容器遵循三法则，并在空间不足时将容量翻倍。模板定义放在 `MyVector.tpp` 中，由 `MyVector.h` 包含。

## 文件结构

```text
assignment07/
├── MyVector.h / MyVector.tpp
├── CP_IntSorter.h / CP_IntSorter.cpp / CP_IntSorterMain.cpp
├── CP_IntSorterTest.h / CP_IntSorterTest.cpp / CP_IntSorterTestMain.cpp
├── CP_MyVectorDemo.h / CP_MyVectorDemo.cpp / CP_MyVectorDemoMain.cpp
├── CP_MyVectorTest.h / CP_MyVectorTest.cpp / CP_MyVectorTestMain.cpp
├── CP_VectorBenchmark.h / CP_VectorBenchmark.cpp / CP_VectorBenchmarkMain.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
# MyVector 演示
g++ -std=c++11 -o myvector_demo.exe CP_MyVectorDemo.cpp CP_MyVectorDemoMain.cpp
.\myvector_demo.exe

# MyVector 测试
g++ -std=c++11 -o myvector_test.exe CP_MyVectorTest.cpp CP_MyVectorTestMain.cpp
.\myvector_test.exe

# 性能测试
g++ -std=c++11 -O2 -o benchmark.exe CP_VectorBenchmark.cpp CP_VectorBenchmarkMain.cpp
.\benchmark.exe

# IntSorter 及测试
g++ -std=c++11 -o sorter.exe CP_IntSorter.cpp CP_IntSorterMain.cpp
.\sorter.exe
g++ -std=c++11 -o sorter_test.exe CP_IntSorter.cpp CP_IntSorterTest.cpp CP_IntSorterTestMain.cpp
.\sorter_test.exe
```

性能测试建议使用 `-O2` 优化。

---

[上一项](../assignment06/README.zh-CN.md) · [下一项](../assignment08/README.zh-CN.md)
