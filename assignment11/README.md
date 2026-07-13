[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 11 — Vector Operations

[Home](../README.md) · C++17

## Overview

An implementation of scalar multiplication and dot product on `std::vector<float>`, with sequential and parallel variants, correctness tests, and a performance benchmark.

## Design

```text
CP_VectorOp
├── m_n, m_s, m_v1, m_v2
├── mb_generate
├── mb_scalarMul / mb_scalarMulPar
└── mb_dotProduct / mb_dotProductPar
```

| Operation | Sequential | Parallel |
|---|---|---|
| Scalar multiplication | `m_s * m_v1[i]` | Parallel STL transform |
| Dot product | `Σ m_v1[i] * m_v2[i]` | Parallel transform-reduce |

C++17 is required for the parallel execution policies used by the `Par` methods. With the documented MSYS2 UCRT64 environment, install oneTBB and link it with `-ltbb12`. Other GCC distributions may expose the library as `-ltbb`; check the package's `pkg-config` metadata when needed. Actual parallelism depends on the compiler and backend.

## Files

```text
assignment11/
├── CP_VectorOp.h / CP_VectorOp.cpp
├── CP_VectorOpMain.cpp
├── CP_VectorOpTest.h / CP_VectorOpTest.cpp
├── CP_VectorOpTestMain.cpp
├── CP_VectorOpBenchmark.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive program
g++ -std=c++17 -o vecop.exe CP_VectorOp.cpp CP_VectorOpMain.cpp -ltbb12
.\vecop.exe

# Automated tests
g++ -std=c++17 -o test.exe CP_VectorOp.cpp CP_VectorOpTest.cpp CP_VectorOpTestMain.cpp -ltbb12
.\test.exe

# Benchmark
g++ -std=c++17 -O2 -o benchmark.exe CP_VectorOp.cpp CP_VectorOpBenchmark.cpp -ltbb12
.\benchmark.exe
```

The tests compare sequential and parallel results with floating-point tolerance and include empty and single-element vectors.

For the MSYS2 UCRT64 toolchain, oneTBB can be installed with `pacman -S mingw-w64-ucrt-x86_64-tbb`. Use the package matching your MinGW environment when using another MSYS2 profile.

---

[Previous](../assignment10/README.md) · [Next](../assignment12/README.md)
