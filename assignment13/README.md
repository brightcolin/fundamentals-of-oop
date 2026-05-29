# Assignment 13 — Student Management System (Factory / Object Pool)

> 学生管理系统（工厂模式 / 对象池） | 面向对象程序设计基础 第 13 次作业

---

## 📌 Description

A refactoring of Assignment 6's student management system that introduces a **factory / free-list pattern**: instead of calling `new`/`delete` directly, nodes are borrowed from `CP_StudentFactory` and returned when deleted. This avoids repeated heap allocation and keeps deallocation predictable.

---

## 📁 File Structure

```
assignment13/
├── CP_Student.h                 # Data class: m_ID, m_score
├── CP_NodeDoubleLink.h          # Plain node: m_data, m_previous, m_next
├── CP_StudentFactory.h          # Free-list (object pool) — header
├── CP_StudentFactory.cpp        # mb_getNode / mb_returnNode / mb_deleteAll
├── CP_StudentProduct.h          # Active list — header
├── CP_StudentProduct.cpp        # Sorted insert, delete, find; borrows/returns from factory
├── CP_StudentSystem.h           # Orchestrator — holds one product + one factory
├── CP_StudentSystem.cpp         # Interactive menu loop
├── CP_StudentSystemMain.cpp     # Entry point: interactive app
├── CP_StudentSystemTest.h       # Test framework header (9 scenarios)
├── CP_StudentSystemTest.cpp     # Test implementation
├── CP_StudentSystemTestMain.cpp # Entry point: automated tests
└── CP_PerformanceTest.cpp       # Entry point: insert/delete throughput benchmark
```

---

## 🏗️ Architecture

```
CP_NodeDoubleLink        ← plain node (m_data + two pointers)
        │
        ├── CP_StudentFactory    ← free-list: spare nodes linked via m_next
        │       mb_getNode()     ← pop from free-list (or new if empty)
        │       mb_returnNode()  ← push back onto free-list
        │
        └── CP_StudentProduct    ← active sorted list
                mb_insertSorted(s, factory)  ← borrows node from factory
                mb_deleteById(id, factory)   ← returns node to factory
                mb_deleteByScore(score, factory)
```

`CP_StudentSystem` owns both a `CP_StudentProduct` and a `CP_StudentFactory`, passing the factory into every product operation.

---

## 🔄 Comparison with Assignment 6

| Aspect | Assignment 6 | Assignment 13 |
|--------|-------------|---------------|
| Node allocation | `new CP_ChainDoubleLink` in place | `factory.mb_getNode()` |
| Node deallocation | `delete` in place | `factory.mb_returnNode(p)` |
| List structure | Self-referential node (node = list head) | Separate node + separate list class |
| Test 9 | — | `test9_CompareWithHW6` verifies identical behaviour |

---

## 🧪 Test Scenarios (9)

| # | Scenario |
|---|----------|
| 1–7 | Same as Assignment 6 (sorted insert, delete by ID/score, query, duplicates, mixed) |
| 8 | Factory recycling — returned nodes are reused on next insert |
| 9 | Comparison with HW6 — same inputs produce identical list state |

---

## 🚀 How to Compile & Run

```bash
# Interactive app
g++ -std=c++11 CP_StudentSystemMain.cpp CP_Student.cpp CP_StudentFactory.cpp CP_StudentProduct.cpp CP_StudentSystem.cpp -o run_main
.\run_main.exe

# Automated tests
g++ -std=c++11 CP_StudentSystemTestMain.cpp CP_Student.cpp CP_StudentFactory.cpp CP_StudentProduct.cpp CP_StudentSystemTest.cpp -o run_test
.\run_test.exe

# Performance benchmark
g++ -std=c++11 -O2 CP_PerformanceTest.cpp CP_Student.cpp CP_StudentFactory.cpp CP_StudentProduct.cpp -o run_perf
.\run_perf.exe
```
