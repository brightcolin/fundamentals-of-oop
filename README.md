# Fundamentals of Object-Oriented Programming

> 面向对象程序设计基础 | Language: C++ | IDE: VSCode | Compiler: g++ (MinGW-w64)

---

## 📁 Repository Structure

```
.
├── assignment1/        # Assignment 1 - Shape Puzzle System
├── assignment2/        # Assignment 2 - GCD & LCM Calculator
└── assignment3/        # Assignment 3 - Shape Calculation System
```

---

## 📝 Assignment 1 — Shape Puzzle System

A console-based character drawing program using OOP. Supports circles, rectangles, and isosceles triangles rendered on a 60×25 character canvas.

**Key Concepts:** Abstract base class, inheritance, polymorphism

| File | Description |
|------|-------------|
| `CP_Shape.h` | Abstract base class |
| `CP_Circle.h/.cpp` | Circle derived class |
| `CP_Rect.h/.cpp` | Rectangle derived class |
| `CP_Triangle.h/.cpp` | Triangle derived class |
| `CP_ShapeMain.cpp` | Main program |

**How to run:**
```bash
g++ -std=c++11 CP_ShapeMain.cpp CP_Circle.cpp CP_Rect.cpp CP_Triangle.cpp -o shapes
./shapes.exe
```

---

## 📝 Assignment 2 — GCD & LCM Calculator

A GCD and LCM calculation system using OOP. GCD is computed using the Binary GCD (Stein) algorithm with no division or modulo operations.

**Key Concepts:** Single responsibility principle, class composition, exception handling

| File | Description |
|------|-------------|
| `CP_GCD.h/.cpp` | GCD class (Binary GCD / Stein algorithm) |
| `CP_LCM.h/.cpp` | LCM class (composes GCD internally) |
| `CP_Test.h/.cpp` | Automated test framework |
| `CP_TestMain.cpp` | Test entry point |
| `CP_Main.cpp` | Main program |

**How to run:**
```bash
# Main program
g++ -std=c++17 CP_Main.cpp CP_GCD.cpp CP_LCM.cpp -o main
./main.exe

# Run tests
g++ -std=c++17 CP_TestMain.cpp CP_GCD.cpp CP_LCM.cpp CP_Test.cpp -o run_test
./run_test.exe
```

---

## 📝 Assignment 3 — Shape Calculation System

A shape perimeter and area calculator using a 3-layer inheritance structure. Supports 5 shapes: equilateral triangle, square, regular pentagon, regular hexagon, and circle.

**Key Concepts:** Multi-level inheritance, shared formula in intermediate base class, polymorphism

| File | Description |
|------|-------------|
| `Shape.h` | Abstract base class with `perimeter()`, `area()`, `name()` |
| `RegularPolygon.h/.cpp` | Intermediate base class with unified regular polygon formula |
| `EquilateralTriangle.h/.cpp` | Equilateral triangle (n=3) |
| `Square.h/.cpp` | Square (n=4) |
| `RegularPentagon.h/.cpp` | Regular pentagon (n=5) |
| `RegularHexagon.h/.cpp` | Regular hexagon (n=6) |
| `Circle.h/.cpp` | Circle, directly inherits Shape |
| `ShapeMain.cpp` | Main program |

**How to run:**
```bash
g++ -std=c++11 ShapeMain.cpp RegularPolygon.cpp EquilateralTriangle.cpp Square.cpp RegularPentagon.cpp RegularHexagon.cpp Circle.cpp -o hw3
./hw3.exe
```

---

## ⚙️ Environment

| Item | Details |
|------|---------|
| OS | Windows 10 / 11 |
| IDE | Visual Studio Code |
| Compiler | g++ (MinGW-w64), C++11/17 |

---

> 🔒 This repository is private. Course is currently in progress.
