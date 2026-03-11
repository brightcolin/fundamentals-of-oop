# Assignment 3 — Shape Calculation System

> 图形计算系统 | 面向对象程序设计基础 第 3 次作业

---

## 📌 Description

A perimeter and area calculator for 5 geometric shapes, built with a **3-layer inheritance structure**. Regular polygons share a single unified formula via an intermediate base class. The program loops until the user enters `0` to summarize and exit.

---

## 📁 File Structure

```
assignment3/
├── CP_Shape.h                    # Abstract base class: perimeter(), area(), name()
├── CP_RegularPolygon.h           # Intermediate base class declaration
├── CP_RegularPolygon.cpp         # Unified regular polygon formula (C = n×s, A = ns²/4tan(π/n))
├── CP_EquilateralTriangle.h      # Equilateral triangle (n = 3)
├── CP_EquilateralTriangle.cpp
├── CP_Square.h                   # Square (n = 4)
├── CP_Square.cpp
├── CP_RegularPentagon.h          # Regular pentagon (n = 5)
├── CP_RegularPentagon.cpp
├── CP_RegularHexagon.h           # Regular hexagon (n = 6)
├── CP_RegularHexagon.cpp
├── CP_Circle.h                   # Circle: directly inherits CP_Shape
├── CP_Circle.cpp                 # C = 2πr, A = πr²
└── CP_ShapeMain.cpp              # Main program: menu loop, vector<CP_Shape*>, summary on 0
```

---

## 🏗️ Class Structure

```
CP_Shape  (abstract base class)
├── CP_RegularPolygon  (intermediate base class — shared formula)
│   ├── CP_EquilateralTriangle  (n = 3)
│   ├── CP_Square               (n = 4)
│   ├── CP_RegularPentagon      (n = 5)
│   └── CP_RegularHexagon       (n = 6)
└── CP_Circle  (directly inherits CP_Shape)
```

---

## 📐 Formulas

**Regular Polygon (shared in CP_RegularPolygon):**

| | Formula |
|--|---------|
| Perimeter | `C = n × s` |
| Area | `A = (n × s²) / (4 × tan(π/n))` |

**Per-shape area results:**

| Shape | Area |
|-------|------|
| Equilateral Triangle | `(√3 / 4) s²` |
| Square | `s²` |
| Regular Pentagon | `≈ 1.7205 s²` |
| Regular Hexagon | `(3√3 / 2) s²` |
| Circle | `π r²` |

---

## 🧪 Test Results

| Command | Shape | Input | Perimeter | Area |
|---------|-------|-------|-----------|------|
| 1 | Equilateral Triangle | s = 6 | 18.0000 | 15.5885 |
| 2 | Square | s = 4 | 16.0000 | 16.0000 |
| 3 | Regular Pentagon | s = 5 | 25.0000 | 43.0119 |
| 4 | Regular Hexagon | s = 3 | 18.0000 | 23.3827 |
| 5 | Circle | r = 7 | 43.9823 | 153.9380 |
| **0** | **Summary** | — | **120.9823** | **251.9211** |

---

## 🚀 How to Run

```bash
g++ -std=c++11 CP_ShapeMain.cpp CP_RegularPolygon.cpp CP_EquilateralTriangle.cpp \
    CP_Square.cpp CP_RegularPentagon.cpp CP_RegularHexagon.cpp CP_Circle.cpp -o hw3
.\hw3.exe
```
