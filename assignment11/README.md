# Assignment 11 — Vector Operations (Scalar Multiply & Dot Product)

> 向量运算 | 面向对象程序设计基础 第 11 次作业

---

## 📌 Description

Demonstrates two fundamental vector operations — scalar multiplication and dot product — on `std::vector<float>`, with both sequential and parallel implementations. Includes correctness tests and a performance benchmark.

---

## 📁 File Structure

```
assignment11/
├── CP_VectorOp.h               # Class declaration
├── CP_VectorOp.cpp             # mb_generate, mb_scalarMul, mb_dotProduct (sequential)
│                               # mb_scalarMulPar, mb_dotProductPar (parallel)
├── CP_VectorOpMain.cpp         # Entry point: interactive program
├── CP_VectorOpTest.h           # Test framework header
├── CP_VectorOpTest.cpp         # 5 test groups
├── CP_VectorOpTestMain.cpp     # Entry point: automated tests
└── CP_VectorOpBenchmark.cpp    # Entry point: sequential vs parallel timing
```

---

## 🏗️ Class Structure

```
CP_VectorOp
├── m_n   : int              — vector length
├── m_s   : float            — scalar multiplier
├── m_v1  : vector<float>    — first operand vector
├── m_v2  : vector<float>    — second operand vector
│
├── mb_generate(n)           — fill m_v1, m_v2 with random floats; pick random m_s
│
├── mb_scalarMul()           → vector<float>   — sequential: m_s * m_v1[i]
├── mb_scalarMulPar()        → vector<float>   — parallel variant
│
├── mb_dotProduct()          → float           — sequential: Σ m_v1[i] * m_v2[i]
└── mb_dotProductPar()       → float           — parallel variant
```

---

## 🧪 Test Groups (5)

| Method | Coverage |
|--------|----------|
| `mb_testGenerate` | Correct size after generate; non-empty vectors |
| `mb_testScalarMul` | Each element = `m_s * m_v1[i]`; zero-vector case |
| `mb_testDotProduct` | Known values; zero vector; single-element |
| `mb_testParallelConsistency` | Sequential and parallel results match (float tolerance) |
| `mb_testEdgeCases` | n=1, n=0 boundary |

---

## 🚀 How to Compile & Run

```bash
# Interactive program
g++ -std=c++17 CP_VectorOpMain.cpp CP_VectorOp.cpp -o vecop
.\vecop.exe

# Automated tests
g++ -std=c++17 CP_VectorOpTestMain.cpp CP_VectorOp.cpp CP_VectorOpTest.cpp -o test
.\test.exe

# Sequential vs parallel benchmark
g++ -std=c++17 -O2 CP_VectorOpBenchmark.cpp CP_VectorOp.cpp -o benchmark
.\benchmark.exe
```

> C++17 is required for the parallel STL execution policies used in the `Par` variants.
