# Assignment 09 — Grade Sheet System / 成绩单管理系统

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

A console grade-management application with plain-text persistence. Student records contain a string ID and integer grade, are stored in a `std::vector`, and support common CRUD operations.

这是一个支持纯文本持久化的控制台成绩管理程序。每条学生记录包含字符串 ID 和整数成绩，数据保存在 `std::vector` 中，并支持常见的增删改查操作。

## Design / 设计

```text
CP_StudentRecord       # Data record / 数据记录
CP_GradeSheet          # Storage, CRUD, file I/O / 存储、增删改查、文件读写
└── CP_GradeSheetSystem # Interactive menu / 交互菜单
```

| Operation / 操作 | Method / 方法 |
|---|---|
| Add, remove, modify, query / 添加、删除、修改、查询 | `mb_add`, `mb_remove`, `mb_modify`, `mb_query` |
| Clear and display / 清空与显示 | `mb_clear`, `mb_show` |
| Load and save / 读取与保存 | `mb_readFile`, `mb_writeFile` |

`grades.txt` contains synthetic sequential identifiers for demonstration and is not real student data.

`grades.txt` 使用连续的虚构编号作为演示数据，不包含真实学生信息。

## Files / 文件结构

```text
assignment09/
├── CP_GradeSheet.h / CP_GradeSheet.cpp
├── CP_GradeSheetSystem.h / CP_GradeSheetSystem.cpp
├── CP_GradeSheetSystemMain.cpp
├── CP_GradeSheetTest.h / CP_GradeSheetTest.cpp
├── CP_GradeSheetTestMain.cpp
└── grades.txt
```

## Build and Run / 编译运行

```powershell
# Interactive program / 交互程序
g++ -std=c++11 -o gradesheet.exe CP_GradeSheet.cpp CP_GradeSheetSystem.cpp CP_GradeSheetSystemMain.cpp
.\gradesheet.exe

# Automated tests / 自动测试
g++ -std=c++11 -o test.exe CP_GradeSheet.cpp CP_GradeSheetTest.cpp CP_GradeSheetTestMain.cpp
.\test.exe
```

Tests cover all CRUD operations, invalid input, and a write/read round trip using a temporary file.

测试覆盖全部增删改查操作、非法输入以及使用临时文件进行的写入/读取往返验证。

---

[Previous / 上一项](../assignment08/README.md) · [Next / 下一项](../assignment10/README.md)
