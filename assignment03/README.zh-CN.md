[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 03 — 图形计算系统

[首页](../README.zh-CN.md) · C++11

## 项目简介

这是一个支持五种几何图形的周长与面积计算器。项目采用三层继承结构，使所有正多边形共享同一套周长和面积公式实现。

## 设计

```text
CP_Shape（抽象基类）
├── CP_RegularPolygon（共享实现）
│   ├── CP_EquilateralTriangle (n = 3)
│   ├── CP_Square              (n = 4)
│   ├── CP_RegularPentagon     (n = 5)
│   └── CP_RegularHexagon      (n = 6)
└── CP_Circle
```

对于边数为 `n`、边长为 `s` 的正多边形：

| 数值 | 公式 |
|---|---|
| 周长 | `C = n × s` |
| 面积 | `A = n × s² / (4 × tan(π/n))` |

`CP_ShapeMain.cpp` 通过 `CP_Shape*` 保存对象，演示运行时多态，并在用户输入 `0` 时输出汇总结果。

## 文件结构

```text
assignment03/
├── CP_Shape.h
├── CP_RegularPolygon.h / CP_RegularPolygon.cpp
├── CP_EquilateralTriangle.h / CP_EquilateralTriangle.cpp
├── CP_Square.h / CP_Square.cpp
├── CP_RegularPentagon.h / CP_RegularPentagon.cpp
├── CP_RegularHexagon.h / CP_RegularHexagon.cpp
├── CP_Circle.h / CP_Circle.cpp
├── CP_ShapeMain.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
g++ -std=c++11 -o shapes.exe CP_ShapeMain.cpp CP_RegularPolygon.cpp CP_EquilateralTriangle.cpp CP_Square.cpp CP_RegularPentagon.cpp CP_RegularHexagon.cpp CP_Circle.cpp
.\shapes.exe
```

---

[上一项](../assignment02/README.zh-CN.md) · [下一项](../assignment04/README.zh-CN.md)
