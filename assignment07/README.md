# Assignment 07 — `MyVector<T>` and IntSorter / 动态数组模板与整数排序

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

This assignment contains two related components: a from-scratch dynamic-array template modeled after `std::vector`, and an integer sorter built on that container. It also includes demonstrations, tests, and a benchmark against `std::vector`.

本作业包含两个相关模块：仿照 `std::vector` 手写的动态数组模板，以及基于该容器实现的整数排序器；同时提供演示、测试和与 `std::vector` 的性能比较。

## `MyVector<T>` Interface / 接口

| Category / 类别 | Operations / 操作 |
|---|---|
| Lifetime / 生命周期 | Default, fill, copy construction; copy assignment / 默认、填充、复制构造与复制赋值 |
| Capacity / 容量 | `size`, `capacity`, `empty`, `reserve`, `resize` |
| Access / 访问 | `operator[]`, checked `at()` / `operator[]` 与带检查的 `at()` |
| Modifiers / 修改 | `push_back`, `pop_back`, `clear` |
| Iteration / 迭代 | `begin`, `end`, range-for support / 支持范围 `for` |

The container follows the rule of three and doubles capacity when additional storage is needed. Template definitions live in `MyVector.tpp`, which is included by `MyVector.h`.

容器遵循三法则，并在空间不足时将容量翻倍。模板定义放在 `MyVector.tpp` 中，由 `MyVector.h` 包含。

## Files / 文件结构

```text
assignment07/
├── MyVector.h / MyVector.tpp
├── CP_IntSorter.h / CP_IntSorter.cpp / CP_IntSorterMain.cpp
├── CP_IntSorterTest.h / CP_IntSorterTest.cpp / CP_IntSorterTestMain.cpp
├── CP_MyVectorDemo.h / CP_MyVectorDemo.cpp / CP_MyVectorDemoMain.cpp
├── CP_MyVectorTest.h / CP_MyVectorTest.cpp / CP_MyVectorTestMain.cpp
└── CP_VectorBenchmark.h / CP_VectorBenchmark.cpp / CP_VectorBenchmarkMain.cpp
```

## Build and Run / 编译运行

```powershell
# MyVector demo / MyVector 演示
g++ -std=c++11 -o myvector_demo.exe CP_MyVectorDemo.cpp CP_MyVectorDemoMain.cpp
.\myvector_demo.exe

# MyVector tests / MyVector 测试
g++ -std=c++11 -o myvector_test.exe CP_MyVectorTest.cpp CP_MyVectorTestMain.cpp
.\myvector_test.exe

# Benchmark / 性能测试
g++ -std=c++11 -O2 -o benchmark.exe CP_VectorBenchmark.cpp CP_VectorBenchmarkMain.cpp
.\benchmark.exe

# IntSorter and tests / 排序程序及测试
g++ -std=c++11 -o sorter.exe CP_IntSorter.cpp CP_IntSorterMain.cpp
.\sorter.exe
g++ -std=c++11 -o sorter_test.exe CP_IntSorter.cpp CP_IntSorterTest.cpp CP_IntSorterTestMain.cpp
.\sorter_test.exe
```

Use `-O2` for meaningful benchmark results. / 性能测试建议使用 `-O2` 优化。

---

[Previous / 上一项](../assignment06/README.md) · [Next / 下一项](../assignment08/README.md)
