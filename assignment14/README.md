# Assignment 14 — Union Double Hex (IEEE 754 Internals)

> IEEE 754 双精度浮点剖析 | 面向对象程序设计基础 第 14 次作业

---

## 📌 Description

Uses a `union` to overlay a `double`, an `unsigned long long`, and a `unsigned char[8]` in the same memory, making every bit of an IEEE 754 double-precision float directly inspectable. Visualises the sign bit, 11-bit exponent, and 52-bit mantissa for arbitrary doubles, and demonstrates special values (NaN, ±Inf).

---

## 📁 File Structure

```
assignment14/
├── CP_UnionDoubleHex.h          # Union definition + global function declarations
├── CP_UnionDoubleHex.cpp        # All gb_show* and gb_test* implementations
├── CP_UnionDoubleHexMain.cpp    # Entry point: interactive walkthrough
├── CP_UnionDoubleHexTest.h      # Test function declarations
├── CP_UnionDoubleHexTest.cpp    # gb_runAllTests / gb_printTestSummary
└── CP_UnionDoubleHexTestMain.cpp # Entry point: automated tests
```

---

## 🏗️ Union Design

```cpp
union U_DoubleHex {
    double             m_double;   // IEEE 754 double
    unsigned long long m_ull;      // same 8 bytes as a 64-bit integer
    unsigned char      m_bytes[8]; // same 8 bytes as individual octets
};
```

All three members share the same 8 bytes. Writing `m_double` and reading `m_ull` gives the raw bit pattern without any cast.

---

## 🔢 IEEE 754 Bit Layout (64-bit)

```
Bit 63     Bits 62–52        Bits 51–0
  │              │                │
Sign (1)   Exponent (11)   Mantissa (52)
```

| Value | Sign | Exponent (raw) | Mantissa |
|-------|------|----------------|----------|
| +0.0 | 0 | 0x000 | 0 |
| −0.0 | 1 | 0x000 | 0 |
| +∞ | 0 | 0x7FF | 0 |
| −∞ | 1 | 0x7FF | 0 |
| NaN | any | 0x7FF | non-zero |

---

## 🔧 Global Functions

| Function | Description |
|----------|-------------|
| `gb_showDoubleHexMemory(u)` | Prints all 8 bytes in hex, little-endian order |
| `gb_showDoubleDetail(u)` | Extracts and prints sign, exponent, mantissa fields |
| `gb_showNaN()` | Demonstrates NaN bit pattern and arithmetic rules |
| `gb_showPosInf()` | Demonstrates +∞ |
| `gb_showNegInf()` | Demonstrates −∞ |
| `gb_showArithmeticRules()` | Prints results of special-value arithmetic (0/0, 1/0, etc.) |
| `gb_testDoubleHex()` | Runs a set of known-value bit-pattern checks |

---

## 🚀 How to Compile & Run

```bash
# Interactive walkthrough
g++ -std=c++11 CP_UnionDoubleHexMain.cpp CP_UnionDoubleHex.cpp -o main
.\main.exe

# Automated tests
g++ -std=c++11 CP_UnionDoubleHexTestMain.cpp CP_UnionDoubleHex.cpp CP_UnionDoubleHexTest.cpp -o test
.\test.exe
```

> Output is platform-dependent for byte order. The code targets little-endian x86/x86-64 (Windows / Linux on Intel).
