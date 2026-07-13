[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 10 — DynArray, RAII, and Move Semantics

[Home](../README.md) · C++11

## Overview

This assignment explores ownership and resource lifetime through three components: a move-only RAII pointer wrapper, a raw-pointer doubly-linked list, and an equivalent smart-pointer list.

## Components

| Component | Purpose |
|---|---|
| `CP_DynArray<T>` | Owns one `T*`; copy disabled, move enabled |
| `CP_DListRaw<T>` | Doubly-linked list using `new` and `delete` |
| `CP_DListSmart<T>` | List using `shared_ptr` forward links and `weak_ptr` back links |
| `CP_A` | Logs construction and destruction |

Using `weak_ptr` for back links prevents the reference cycle that two `shared_ptr` links would create.

## Files

```text
assignment10/
├── CP_DynArray.h
├── CP_A.h
├── CP_DListRaw.h
├── CP_DListSmart.h
├── CP_DynArrayTest.h / CP_DynArrayTest.cpp
├── CP_DynArrayTestMain.cpp
├── CP_DynArrayBenchmark.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Automated tests
g++ -std=c++11 -o test.exe CP_DynArrayTest.cpp CP_DynArrayTestMain.cpp
.\test.exe

# Raw-pointer vs smart-pointer benchmark
g++ -std=c++11 -O2 -o benchmark.exe CP_DynArrayBenchmark.cpp
.\benchmark.exe
```

The tests verify move construction and assignment, deleted-copy semantics, pointer access, swapping, destruction, and both list implementations.

---

[Previous](../assignment09/README.md) · [Next](../assignment11/README.md)
