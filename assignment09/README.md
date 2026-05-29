# Assignment 9 — Grade Sheet System

> 成绩单管理系统 | 面向对象程序设计基础 第 9 次作业

---

## 📌 Description

A console-based grade management system with file persistence. Student records (string ID + integer grade) are stored in memory in a `std::vector` and read/written to a plain-text file (`grades.txt`).

---

## 📁 File Structure

```
assignment9/
├── CP_GradeSheet.h              # CP_StudentRecord struct + CP_GradeSheet class
├── CP_GradeSheet.cpp            # CRUD operations + file I/O
├── CP_GradeSheetSystem.h        # Menu shell wrapping CP_GradeSheet
├── CP_GradeSheetSystem.cpp      # Interactive main loop
├── CP_GradeSheetTest.h          # Test framework header (7 test groups)
├── CP_GradeSheetTest.cpp        # Test implementation
├── CP_GradeSheetSystemMain.cpp  # Entry point: interactive app
├── CP_GradeSheetTestMain.cpp    # Entry point: automated tests
└── grades.txt                   # Default data file (plain text)
```

---

## 🏗️ Architecture

```
CP_StudentRecord      ← plain struct: m_id (string), m_grade (int)
CP_GradeSheet         ← owns vector<CP_StudentRecord>, handles file I/O
CP_GradeSheetSystem   ← menu shell, holds one CP_GradeSheet
```

---

## 🔧 Operations

| Method | Description |
|--------|-------------|
| `mb_add(id, grade)` | Appends; rejects duplicate ID |
| `mb_remove(id)` | Removes by ID |
| `mb_modify(id, grade)` | Updates grade for existing ID |
| `mb_query(id, grade)` | Looks up grade by ID |
| `mb_clear()` | Empties the list |
| `mb_readFile(filename)` | Loads records from text file |
| `mb_writeFile(filename)` | Saves records to text file |
| `mb_show()` | Prints all records to stdout |

---

## 🧪 Test Groups (7)

| # | Group |
|---|-------|
| 1 | `mb_testAdd` — normal add, duplicate rejection |
| 2 | `mb_testRemove` — found / not-found |
| 3 | `mb_testModify` — existing / non-existing ID |
| 4 | `mb_testQuery` — found / not-found |
| 5 | `mb_testClear` — list empties correctly |
| 6 | `mb_testFile` — write then read roundtrip |
| 7 | `mb_testInvalid` — boundary and invalid inputs |

---

## 🚀 How to Compile & Run

```bash
# Interactive app
g++ -std=c++11 CP_GradeSheetSystemMain.cpp CP_GradeSheet.cpp CP_GradeSheetSystem.cpp -o gradesheet
.\gradesheet.exe

# Automated tests
g++ -std=c++11 CP_GradeSheetTestMain.cpp CP_GradeSheet.cpp CP_GradeSheetTest.cpp -o test
.\test.exe
```

> The file I/O test writes a temporary file in the working directory and reads it back.
