# Assignment 01 — Shape Puzzle System / 图形拼图系统

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

A console canvas renderer for circles, rectangles, and isosceles triangles. Shapes are drawn on a 60 × 25 character grid; later shapes overwrite earlier ones where they overlap.

这是一个控制台字符画布程序，支持绘制圆形、矩形和等腰三角形。所有图形显示在 60 × 25 的字符网格中，后加入的图形会覆盖重叠位置上的旧图形。

## Design / 设计

```text
CP_Shape (abstract base class / 抽象基类)
├── CP_Circle
├── CP_Rect
└── CP_Triangle
```

`CP_Shape` stores the position and fill character, and declares two pure virtual functions: `mb_isIn(x, y)` for point containment and `mb_show()` for displaying shape information.

`CP_Shape` 保存位置和填充字符，并声明两个纯虚函数：`mb_isIn(x, y)` 用于判断点是否在图形内，`mb_show()` 用于输出图形信息。

| Shape / 图形 | Parameters / 参数 | Containment rule / 判定规则 |
|---|---|---|
| `CP_Circle` | Center and radius / 圆心与半径 | `(x-m_x)² + (y-m_y)² <= m_radius²` |
| `CP_Rect` | Top-left, width, height / 左上角、宽和高 | Axis-aligned bounds / 轴对齐边界判断 |
| `CP_Triangle` | Apex, base, height / 顶点、底边和高 | Integer linear interpolation / 整数线性插值 |

All containment checks use integer arithmetic to avoid floating-point boundary errors.

所有包含关系判断均使用整数运算，以避免浮点边界误差。

## Files / 文件结构

```text
assignment01/
├── CP_Shape.h
├── CP_Circle.h / CP_Circle.cpp
├── CP_Rect.h / CP_Rect.cpp
├── CP_Triangle.h / CP_Triangle.cpp
└── CP_ShapeMain.cpp
```

## Build and Run / 编译运行

Run the following commands from this directory in PowerShell. / 在本目录的 PowerShell 中执行：

```powershell
g++ -std=c++11 -o shapes.exe CP_ShapeMain.cpp CP_Circle.cpp CP_Rect.cpp CP_Triangle.cpp
.\shapes.exe
```

The program uses `system("pause")`, which is Windows-specific. / 程序使用了 Windows 专用的 `system("pause")`。

---

[Next: Assignment 02 / 下一项：作业 02](../assignment02/README.md)
