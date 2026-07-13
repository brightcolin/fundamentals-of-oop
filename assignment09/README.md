[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 09 — Grade Sheet System

[Home](../README.md) · C++11

## Overview

A console grade-management application with plain-text persistence. Student records contain a string ID and integer grade, are stored in a `std::vector`, and support common CRUD operations.

## Design

```text
CP_StudentRecord        # Data record
CP_GradeSheet           # Storage, CRUD, and file I/O
└── CP_GradeSheetSystem # Interactive menu
```

| Operation | Method |
|---|---|
| Add, remove, modify, and query | `mb_add`, `mb_remove`, `mb_modify`, `mb_query` |
| Clear and display | `mb_clear`, `mb_show` |
| Load and save | `mb_readFile`, `mb_writeFile` |

`grades.txt` contains synthetic sequential identifiers for demonstration and is not real student data.

## Files

```text
assignment09/
├── CP_GradeSheet.h / CP_GradeSheet.cpp
├── CP_GradeSheetSystem.h / CP_GradeSheetSystem.cpp
├── CP_GradeSheetSystemMain.cpp
├── CP_GradeSheetTest.h / CP_GradeSheetTest.cpp
├── CP_GradeSheetTestMain.cpp
├── grades.txt
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive program
g++ -std=c++11 -o gradesheet.exe CP_GradeSheet.cpp CP_GradeSheetSystem.cpp CP_GradeSheetSystemMain.cpp
.\gradesheet.exe

# Automated tests
g++ -std=c++11 -o test.exe CP_GradeSheet.cpp CP_GradeSheetTest.cpp CP_GradeSheetTestMain.cpp
.\test.exe
```

The 28 checks cover all CRUD operations, invalid input, and a write/read round trip using a temporary file.

---

[Previous](../assignment08/README.md) · [Next](../assignment10/README.md)
