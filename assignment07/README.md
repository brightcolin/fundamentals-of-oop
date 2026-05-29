# Assignment 7 — MyVector\<T\> & IntSorter

> 手写动态数组模板 + 整数排序 | 面向对象程序设计基础 第 7 次作业

---

## 📌 Description

Two parts:

1. **`MyVector<T>`** — a from-scratch dynamic array template mirroring `std::vector`: rule-of-three, `reserve`/`resize`, iterators, and bounds-checked `at()`.
2. **`CP_IntSorter`** — reads integers from stdin, sorts them with and without deduplication using `MyVector<int>`.

---

## 📁 File Structure

```
assignment7/
├── MyVector.h                  # Template class declaration
├── MyVector.tpp                # Template implementation (included by MyVector.h)
│
├── CP_IntSorter.h              # gb_readInput / gb_sortNoDedup / gb_sortDedup / gb_run
├── CP_IntSorter.cpp            # Implementation
├── CP_IntSorterMain.cpp        # Entry point: interactive sort program
├── CP_IntSorterTest.h
├── CP_IntSorterTest.cpp        # IntSorter tests
├── CP_IntSorterTestMain.cpp    # Entry point: IntSorter tests
│
├── CP_MyVectorDemo.h
├── CP_MyVectorDemo.cpp         # gb_runDemo — walkthrough of MyVector API
├── CP_MyVectorDemoMain.cpp     # Entry point: demo
│
├── CP_MyVectorTest.h
├── CP_MyVectorTest.cpp         # gb_testMyVector — automated MyVector tests
├── CP_MyVectorTestMain.cpp     # Entry point: MyVector tests
│
├── CP_VectorBenchmark.h
├── CP_VectorBenchmark.cpp      # gb_runBenchmark — MyVector vs std::vector timing
└── CP_VectorBenchmarkMain.cpp  # Entry point: benchmark
```

---

## 🏗️ MyVector\<T\> Interface

| Category | Methods |
|----------|---------|
| Constructors | default, `(n, val)`, copy |
| Capacity | `size()`, `capacity()`, `empty()`, `reserve(n)`, `resize(n, val)` |
| Access | `operator[]`, `at()` (throws `std::out_of_range`) |
| Modifiers | `push_back()`, `pop_back()`, `clear()` |
| Iterators | `begin()`, `end()` (raw pointer, compatible with range-for) |

Growth strategy: doubles capacity when full (same as typical STL implementations).

---

## 🚀 How to Compile & Run

```bash
# MyVector demo
g++ -std=c++11 CP_MyVectorDemoMain.cpp CP_MyVectorDemo.cpp -o demo
.\demo.exe

# MyVector automated tests
g++ -std=c++11 CP_MyVectorTestMain.cpp CP_MyVectorTest.cpp -o test
.\test.exe

# MyVector vs std::vector benchmark
g++ -std=c++11 -O2 CP_VectorBenchmarkMain.cpp CP_VectorBenchmark.cpp -o benchmark
.\benchmark.exe

# IntSorter interactive program
g++ -std=c++11 CP_IntSorterMain.cpp CP_IntSorter.cpp -o sorter
.\sorter.exe

# IntSorter tests
g++ -std=c++11 CP_IntSorterTestMain.cpp CP_IntSorter.cpp CP_IntSorterTest.cpp -o test_sorter
.\test_sorter.exe
```

> Use `-O2` for the benchmark to get meaningful timing comparisons.
