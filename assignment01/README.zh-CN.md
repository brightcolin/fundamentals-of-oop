[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 01 — 图形拼图系统

[首页](../README.zh-CN.md) · C++11

## 项目简介

这是一个控制台字符画布程序，支持绘制圆形、矩形和等腰三角形。所有图形显示在 60 × 25 的字符网格中，后加入的图形会覆盖重叠位置上的旧图形。

## 设计

```text
CP_Shape（抽象基类）
├── CP_Circle
├── CP_Rect
└── CP_Triangle
```

`CP_Shape` 保存位置和填充字符，并声明两个纯虚函数：`mb_isIn(x, y)` 用于判断点是否在图形内，`mb_show()` 用于输出图形信息。

| 图形 | 参数 | 判定规则 |
|---|---|---|
| `CP_Circle` | 圆心与半径 | `(x-m_x)² + (y-m_y)² <= m_radius²` |
| `CP_Rect` | 左上角、宽和高 | 轴对齐边界判断 |
| `CP_Triangle` | 顶点、底边和高 | 整数线性插值 |

所有包含关系判断均使用整数运算，以避免浮点边界误差。

## 文件结构

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

## 编译运行

在本目录的 PowerShell 中执行：

```powershell
g++ -std=c++11 -o shapes.exe CP_ShapeMain.cpp CP_Circle.cpp CP_Rect.cpp CP_Triangle.cpp
.\shapes.exe
```

程序使用了 Windows 专用的 `system("pause")`。

---

[下一项：作业 02](../assignment02/README.zh-CN.md)
