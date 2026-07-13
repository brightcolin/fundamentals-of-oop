# Assignment 11 — Vector Operations / 向量运算

[Home / 首页](../README.md) · C++17

## Overview / 项目简介

An implementation of scalar multiplication and dot product on `std::vector<float>`, with sequential and parallel variants, correctness tests, and a performance benchmark.

本项目在 `std::vector<float>` 上实现标量乘法和点积，包含串行与并行版本、正确性测试和性能比较。

## Design / 设计

```text
CP_VectorOp
├── m_n, m_s, m_v1, m_v2
├── mb_generate
├── mb_scalarMul / mb_scalarMulPar
└── mb_dotProduct / mb_dotProductPar
```

| Operation / 运算 | Sequential / 串行 | Parallel / 并行 |
|---|---|---|
| Scalar multiplication / 标量乘法 | `m_s * m_v1[i]` | Parallel STL transform / 并行 STL 变换 |
| Dot product / 点积 | `Σ m_v1[i] * m_v2[i]` | Parallel transform-reduce / 并行变换归约 |

C++17 is required for the parallel execution policies used by the `Par` methods. With the documented MSYS2 UCRT64 environment, install oneTBB and link it with `-ltbb12`. Other GCC distributions may expose the library as `-ltbb`; check the package's `pkg-config` metadata when needed. Actual parallelism depends on the compiler and backend.

`Par` 方法使用并行执行策略，因此要求 C++17。在文档采用的 MSYS2 UCRT64 环境中，需要安装 oneTBB，并通过 `-ltbb12` 链接。其他 GCC 发行版可能使用 `-ltbb`，必要时应检查软件包的 `pkg-config` 信息。是否真正并行执行取决于编译器和后端。

## Files / 文件结构

```text
assignment11/
├── CP_VectorOp.h / CP_VectorOp.cpp
├── CP_VectorOpMain.cpp
├── CP_VectorOpTest.h / CP_VectorOpTest.cpp
├── CP_VectorOpTestMain.cpp
└── CP_VectorOpBenchmark.cpp
```

## Build and Run / 编译运行

```powershell
# Interactive program / 交互程序
g++ -std=c++17 -o vecop.exe CP_VectorOp.cpp CP_VectorOpMain.cpp -ltbb12
.\vecop.exe

# Automated tests / 自动测试
g++ -std=c++17 -o test.exe CP_VectorOp.cpp CP_VectorOpTest.cpp CP_VectorOpTestMain.cpp -ltbb12
.\test.exe

# Benchmark / 性能测试
g++ -std=c++17 -O2 -o benchmark.exe CP_VectorOp.cpp CP_VectorOpBenchmark.cpp -ltbb12
.\benchmark.exe
```

The tests compare sequential and parallel results with floating-point tolerance and include empty and single-element vectors.

测试使用浮点容差比较串行与并行结果，并覆盖空向量与单元素向量。

For the MSYS2 UCRT64 toolchain, oneTBB can be installed with `pacman -S mingw-w64-ucrt-x86_64-tbb`. Use the package matching your MinGW environment when using another MSYS2 profile.

在 MSYS2 UCRT64 环境中，可使用 `pacman -S mingw-w64-ucrt-x86_64-tbb` 安装 oneTBB；若使用其他 MSYS2 配置，请选择与对应 MinGW 环境匹配的软件包。

---

[Previous / 上一项](../assignment10/README.md) · [Next / 下一项](../assignment12/README.md)
