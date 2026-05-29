# Assignment 1 — Shape Puzzle System

> 图形拼图系统 | 面向对象程序设计基础 第 1 次作业

---

## 📌 Description

A console-based character canvas drawing program. Supports circles, rectangles, and isosceles triangles rendered on a 60×25 character grid. Multiple shapes can be layered — later-added shapes overwrite earlier ones.

---

## 📁 File Structure

```
assignment1/
├── CP_Shape.h           # Abstract base class
├── CP_Circle.h          # Circle class declaration
├── CP_Circle.cpp        # Circle: point-in-circle check (integer arithmetic)
├── CP_Rect.h            # Rectangle class declaration
├── CP_Rect.cpp          # Rectangle: axis-aligned bounding box check
├── CP_Triangle.h        # Triangle class declaration
├── CP_Triangle.cpp      # Isosceles triangle: integer linear interpolation
└── CP_ShapeMain.cpp     # Main program: input, scene management, canvas render
```

---

## 🏗️ Class Structure

```
CP_Shape  (abstract base class)
├── CP_Circle
├── CP_Rect
└── CP_Triangle
```

**CP_Shape** defines:
- Members: `m_x`, `m_y` (position), `m_char` (fill character) — access: `protected`
- Pure virtual: `mb_isIn(x, y)` — whether point (x,y) is inside the shape
- Pure virtual: `mb_show()` — print shape info

---

## 🔢 Shape Logic

| Shape | Key Parameters | Point-in-shape Condition |
|-------|----------------|--------------------------|
| CP_Circle | center `(m_x, m_y)`, radius `m_radius` | `(x−m_x)² + (y−m_y)² <= m_radius²` |
| CP_Rect | top-left `(m_x, m_y)`, `m_width`, `m_height` | `x >= m_x && x < m_x+m_width && y >= m_y && y < m_y+m_height` |
| CP_Triangle | apex `(m_x, m_y)`, `m_base`, `m_height` | `2 * |x−m_x| * m_height <= m_base * (y−m_y)` |

All checks use integer arithmetic to avoid floating-point errors.

---

## 🖼️ Example Outputs

**House** (triangle + rectangle):
```
         ^
        ^^^
       ^^^^^
      ^^^^^^^^^
     ^^^^^^^^^^^
   ^^^^^^^^^^^^^^^
  ^^^^^^^^^^^^^^^^^
 ^^^^^^^^^^^^^^^^^^^^^
 ############################
 ############################
```

**Smiley Face** (overlapping circles + rectangle):
```
 OOO*OOOOOOOOOOO*OOO
 OO*****OOOOOOO*****OO
 OO*******OOOOO*******OO
 OOOOOO-----------OOOOOO
```

---

## 🚀 How to Run

```bash
g++ -std=c++11 CP_ShapeMain.cpp CP_Circle.cpp CP_Rect.cpp CP_Triangle.cpp -o shapes
.\shapes.exe
```

> **Note:** `system("pause")` is Windows-only. On Linux/macOS, remove it or replace with `std::cin.get()`.
