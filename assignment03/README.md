# Assignment 03 — Shape Calculation System / 图形计算系统

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

A perimeter and area calculator for five geometric shapes. It uses a three-level inheritance design so that all regular polygons share one implementation of their perimeter and area formulas.

这是一个支持五种几何图形的周长与面积计算器。项目采用三层继承结构，使所有正多边形共享同一套周长和面积公式实现。

## Design / 设计

```text
CP_Shape (abstract base / 抽象基类)
├── CP_RegularPolygon (shared implementation / 共享实现)
│   ├── CP_EquilateralTriangle (n = 3)
│   ├── CP_Square              (n = 4)
│   ├── CP_RegularPentagon     (n = 5)
│   └── CP_RegularHexagon      (n = 6)
└── CP_Circle
```

For a regular polygon with `n` sides of length `s`: / 对边数为 `n`、边长为 `s` 的正多边形：

| Measurement / 数值 | Formula / 公式 |
|---|---|
| Perimeter / 周长 | `C = n × s` |
| Area / 面积 | `A = n × s² / (4 × tan(π/n))` |

`CP_ShapeMain.cpp` stores objects through `CP_Shape*`, demonstrates runtime polymorphism, and prints a summary when the user enters `0`.

`CP_ShapeMain.cpp` 通过 `CP_Shape*` 保存对象，演示运行时多态，并在用户输入 `0` 时输出汇总结果。

## Files / 文件结构

```text
assignment03/
├── CP_Shape.h
├── CP_RegularPolygon.h / CP_RegularPolygon.cpp
├── CP_EquilateralTriangle.h / CP_EquilateralTriangle.cpp
├── CP_Square.h / CP_Square.cpp
├── CP_RegularPentagon.h / CP_RegularPentagon.cpp
├── CP_RegularHexagon.h / CP_RegularHexagon.cpp
├── CP_Circle.h / CP_Circle.cpp
└── CP_ShapeMain.cpp
```

## Build and Run / 编译运行

```powershell
g++ -std=c++11 -o shapes.exe CP_ShapeMain.cpp CP_RegularPolygon.cpp CP_EquilateralTriangle.cpp CP_Square.cpp CP_RegularPentagon.cpp CP_RegularHexagon.cpp CP_Circle.cpp
.\shapes.exe
```

---

[Previous / 上一项](../assignment02/README.md) · [Next / 下一项](../assignment04/README.md)
