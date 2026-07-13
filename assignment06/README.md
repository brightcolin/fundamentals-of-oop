[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 06 — Student System with a Doubly-Linked List

[Home](../README.md) · C++11

## Overview

A console student-management system backed by a circular doubly-linked list. Records remain sorted by student ID and can be inserted, deleted, queried, or listed.

## Design

```text
CP_Student                 # ID and score
CP_ChainDoubleLink         # Node and circular-list controller
└── CP_StudentSystem       # Interactive menu
```

`CP_ChainDoubleLink` acts as both a node and the head sentinel. The last node points back to the head, and memory is managed explicitly with `new` and `delete`.

| Operation | Behavior |
|---|---|
| Insert | Keep records sorted by ID and reject duplicates |
| Delete | Remove by ID or all records matching a score |
| Query | Search by ID or score |
| Display | Print all records in ID order |

## Files

```text
assignment06/
├── CP_Student.h / CP_Student.cpp
├── CP_ChainDoubleLink.h / CP_ChainDoubleLink.cpp
├── CP_StudentSystem.h / CP_StudentSystem.cpp
├── CP_StudentSystemMain.cpp
├── CP_StudentSystemTest.h / CP_StudentSystemTest.cpp
├── CP_StudentSystemTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive program
g++ -std=c++11 -o main.exe CP_Student.cpp CP_ChainDoubleLink.cpp CP_StudentSystem.cpp CP_StudentSystemMain.cpp
.\main.exe

# Automated tests
g++ -std=c++11 -o run_test.exe CP_Student.cpp CP_ChainDoubleLink.cpp CP_StudentSystemTest.cpp CP_StudentSystemTestMain.cpp
.\run_test.exe
```

The seven test groups cover ordering, deletion positions, score matches, lookup, duplicate IDs, empty lists, and mixed operations.

---

[Previous](../assignment05/README.md) · [Next](../assignment07/README.md)
