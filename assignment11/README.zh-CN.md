[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 11 — 向量运算

[首页](../README.zh-CN.md) · C++17

## 项目简介

本项目在 `std::vector<float>` 上实现标量乘法和点积，包含串行与并行版本、正确性测试和性能比较。

## 设计

```text
CP_VectorOp
├── m_n, m_s, m_v1, m_v2
├── mb_generate
├── mb_scalarMul / mb_scalarMulPar
└── mb_dotProduct / mb_dotProductPar
```

| 运算 | 串行 | 并行 |
|---|---|---|
| 标量乘法 | `m_s * m_v1[i]` | 并行 STL 变换 |
| 点积 | `Σ m_v1[i] * m_v2[i]` | 并行变换归约 |

`Par` 方法使用并行执行策略，因此要求 C++17。在文档采用的 MSYS2 UCRT64 环境中，需要安装 oneTBB，并通过 `-ltbb12` 链接。其他 GCC 发行版可能使用 `-ltbb`，必要时应检查软件包的 `pkg-config` 信息。是否真正并行执行取决于编译器和后端。

## 文件结构

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

## 编译运行

```powershell
# 交互程序
g++ -std=c++17 -o vecop.exe CP_VectorOp.cpp CP_VectorOpMain.cpp -ltbb12
.\vecop.exe

# 自动测试
g++ -std=c++17 -o test.exe CP_VectorOp.cpp CP_VectorOpTest.cpp CP_VectorOpTestMain.cpp -ltbb12
.\test.exe

# 性能测试
g++ -std=c++17 -O2 -o benchmark.exe CP_VectorOp.cpp CP_VectorOpBenchmark.cpp -ltbb12
.\benchmark.exe
```

测试使用浮点容差比较串行与并行结果，并覆盖空向量与单元素向量。

在 MSYS2 UCRT64 环境中，可使用 `pacman -S mingw-w64-ucrt-x86_64-tbb` 安装 oneTBB；若使用其他 MSYS2 配置，请选择与对应 MinGW 环境匹配的软件包。

---

[上一项](../assignment10/README.zh-CN.md) · [下一项](../assignment12/README.zh-CN.md)
