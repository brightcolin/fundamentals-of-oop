[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 01 — Shape Puzzle System

[Home](../README.md) · C++11

## Overview

A console canvas renderer for circles, rectangles, and isosceles triangles. Shapes are drawn on a 60 × 25 character grid; later shapes overwrite earlier ones where they overlap.

## Design

```text
CP_Shape (abstract base class)
├── CP_Circle
├── CP_Rect
└── CP_Triangle
```

`CP_Shape` stores the position and fill character, and declares two pure virtual functions: `mb_isIn(x, y)` for point containment and `mb_show()` for displaying shape information.

| Shape | Parameters | Containment rule |
|---|---|---|
| `CP_Circle` | Center and radius | `(x-m_x)² + (y-m_y)² <= m_radius²` |
| `CP_Rect` | Top-left, width, height | Axis-aligned bounds |
| `CP_Triangle` | Apex, base, height | Integer linear interpolation |

All containment checks use integer arithmetic to avoid floating-point boundary errors.

## Files

```text
assignment01/
├── CP_Shape.h
├── CP_Circle.h / CP_Circle.cpp
├── CP_Rect.h / CP_Rect.cpp
├── CP_Triangle.h / CP_Triangle.cpp
├── CP_ShapeMain.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

Run the following commands from this directory in PowerShell:

```powershell
g++ -std=c++11 -o shapes.exe CP_ShapeMain.cpp CP_Circle.cpp CP_Rect.cpp CP_Triangle.cpp
.\shapes.exe
```

The program uses `system("pause")`, which is Windows-specific.

---

[Next: Assignment 02](../assignment02/README.md)
