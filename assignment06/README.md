# Assignment 6 — Student Management System (Doubly-Linked List)

> 学生管理系统（循环双向链表） | 面向对象程序设计基础 第 6 次作业

---

## 📌 Description

A console-based student management system backed by a **circular doubly-linked list**. Students are stored sorted by ID in ascending order. Supports insert, delete (by ID or by score), and two query modes.

---

## 📁 File Structure

```
assignment6/
├── CP_Student.h                 # Data class: m_ID, m_score
├── CP_Student.cpp               # gb_swapStudent helper
├── CP_ChainDoubleLink.h         # Node class + list operations
├── CP_ChainDoubleLink.cpp       # Sorted insert, delete, find, count
├── CP_StudentSystem.h           # Menu-driven application shell
├── CP_StudentSystem.cpp         # Interactive main loop (6 operations)
├── CP_StudentSystemTest.h       # Test framework header (7 scenarios)
├── CP_StudentSystemTest.cpp     # Test implementation
├── CP_StudentSystemMain.cpp     # Entry point: interactive app
└── CP_StudentSystemTestMain.cpp # Entry point: automated tests
```

---

## 🏗️ Architecture

```
CP_Student                      ← plain data (ID + score)
CP_ChainDoubleLink              ← node AND list controller (circular)
    └── used by CP_StudentSystem ← menu shell
```

`CP_ChainDoubleLink` serves as both the **node** and the **list head sentinel**. The list is circular: the last node's `m_next` points back to the head, enabling O(n) traversal without a separate header object.

---

## 🔧 Operations

| Menu | Operation | Detail |
|------|-----------|--------|
| 1 | Add students | Sorted insert by ID; rejects duplicate IDs |
| 2 | Delete by ID | Finds node, unlinks and frees it |
| 3 | Delete by score | Removes all nodes matching the score |
| 4 | Query by ID | Returns score or "not found" |
| 5 | Query by score | Lists all IDs with that score |
| 6 | Show all | Prints list in sorted order |

---

## 🧪 Test Scenarios (7)

| # | Scenario |
|---|----------|
| 1 | Sorted insert — out-of-order input produces ascending ID order |
| 2 | Delete by ID — head / middle / tail / not-found / only node |
| 3 | Delete by score — multi-match, no-match, clear all |
| 4 | Query by ID — found (head/mid/tail) / not-found |
| 5 | Query by score — multi / single / none / empty list |
| 6 | Duplicate ID — rejected; unique ID accepted |
| 7 | Mixed operations — insert + delete + query in sequence |

---

## 🚀 How to Compile & Run

```bash
# Interactive app
g++ -std=c++11 CP_StudentSystemMain.cpp CP_Student.cpp CP_ChainDoubleLink.cpp CP_StudentSystem.cpp -o main
.\main.exe

# Automated tests
g++ -std=c++11 CP_StudentSystemTestMain.cpp CP_Student.cpp CP_ChainDoubleLink.cpp CP_StudentSystemTest.cpp -o test
.\test.exe
```
