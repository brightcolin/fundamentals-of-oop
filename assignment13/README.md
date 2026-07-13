[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 13 — Student System with an Object Pool

[Home](../README.md) · C++11

## Overview

A refactoring of Assignment 06 that separates nodes, the active list, and allocation policy. Deleted nodes are returned to a factory-managed free list and reused by later insertions.

## Design

```text
CP_NodeDoubleLink
├── CP_StudentProduct   # Active sorted list
└── CP_StudentFactory   # Free list and node reuse
        ↑
CP_StudentSystem owns and coordinates both
```

| Aspect | Assignment 06 | Assignment 13 |
|---|---|---|
| Node/list design | One self-referential class | Separate node and list |
| Allocation | Direct `new` | `factory.mb_getNode()` |
| Deallocation | Direct `delete` | `factory.mb_returnNode()` |
| Reuse | None | Free-list reuse |

## Files

```text
assignment13/
├── CP_Student.h                 # Header-only data class
├── CP_NodeDoubleLink.h
├── CP_StudentFactory.h / CP_StudentFactory.cpp
├── CP_StudentProduct.h / CP_StudentProduct.cpp
├── CP_StudentSystem.h / CP_StudentSystem.cpp
├── CP_StudentSystemMain.cpp
├── CP_StudentSystemTest.h / CP_StudentSystemTest.cpp
├── CP_StudentSystemTestMain.cpp
├── CP_PerformanceTest.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive program
g++ -std=c++11 -o run_main.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_StudentSystem.cpp CP_StudentSystemMain.cpp
.\run_main.exe

# Automated tests
g++ -std=c++11 -o run_test.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_StudentSystemTest.cpp CP_StudentSystemTestMain.cpp
.\run_test.exe

# Performance benchmark
g++ -std=c++11 -O2 -o run_perf.exe CP_StudentFactory.cpp CP_StudentProduct.cpp CP_PerformanceTest.cpp
.\run_perf.exe
```

The nine test groups reuse Assignment 06 scenarios and add factory recycling plus behavioral comparison. `CP_Student` is header-only, so no separate implementation source is required.

---

[Previous](../assignment12/README.md) · [Next](../assignment14/README.md)
