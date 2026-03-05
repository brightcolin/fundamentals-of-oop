# Fundamentals of Object-Oriented Programming

> 面向对象程序设计基础 | Language: C++ | IDE: VSCode | Compiler: g++ (MinGW-w64)

---

## 📁 Repository Structure

```
.
├── assignment1/        # Assignment 1 - Shape Puzzle System
└── assignment2/        # Assignment 2 - GCD & LCM Calculator
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

## ⚙️ Environment

| Item | Details |
|------|---------|
| OS | Windows 10 / 11 |
| IDE | Visual Studio Code |
| Compiler | g++ (MinGW-w64), C++11/17 |

---

> 🔒 This repository is private. Course is currently in progress.
