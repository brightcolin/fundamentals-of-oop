# Assignment 8 — Big Integer by String

> 字符串大整数 | 面向对象程序设计基础 第 8 次作业

---

## 📌 Description

Arbitrary-precision signed integer arithmetic stored as a decimal string. Supports `+`, `-`, `*`, `/` with full sign handling, implemented using string-based column arithmetic on the absolute-value digits.

---

## 📁 File Structure

```
assignment8/
├── CP_IntByString.h             # Class declaration + private static helpers
├── CP_IntByString.cpp           # All arithmetic and helper implementations
├── CP_IntByStringMain.cpp       # Entry point: interactive calculator
├── CP_IntByStringTest.h         # Test framework header
├── CP_IntByStringTest.cpp       # Test groups: add, sub, mul, div
└── CP_IntByStringTestMain.cpp   # Entry point: automated tests
```

---

## 🏗️ Class Structure

```
CP_IntByString
├── m_flag   : int      — sign: +1 or −1
├── m_data   : string   — absolute value digits, no leading zeros
│
├── operator+  operator-  operator*  operator/
├── operator== operator!=
│
└── private static helpers (unsigned string arithmetic)
    ├── sf_absAdd(a, b)    → string
    ├── sf_absSub(a, b)    → string   (requires |a| >= |b|)
    ├── sf_absMul(a, b)    → string
    ├── sf_absDiv(a, b)    → string   (quotient)
    ├── sf_absMod(a, b)    → string   (remainder)
    ├── sf_absCmp(a, b)    → int      (+1 / 0 / -1)
    └── sf_removeLeadingZeros(s) → string
```

---

## 🔢 Sign Logic

All four operators reduce to unsigned string operations after determining the result sign:

| Operation | Sign rule |
|-----------|-----------|
| `a + b` | Same sign → keep; opposite signs → subtract smaller from larger, take larger's sign |
| `a - b` | Equivalent to `a + (-b)` |
| `a * b` | `m_flag = flag_a * flag_b` |
| `a / b` | `m_flag = flag_a * flag_b`; division on absolute values |

---

## 🧪 Test Groups

| Group | Coverage |
|-------|----------|
| `mb_testAdd` | Positive + positive, negative + positive, negative + negative, zero |
| `mb_testSub` | Large − small, small − large, same value |
| `mb_testMul` | General, zero factor, negative × negative |
| `mb_testDiv` | Exact division, truncated, negative dividend/divisor |

---

## 🚀 How to Compile & Run

```bash
# Interactive calculator
g++ -std=c++11 CP_IntByStringMain.cpp CP_IntByString.cpp -o calc
.\calc.exe

# Automated tests
g++ -std=c++11 CP_IntByStringTestMain.cpp CP_IntByString.cpp CP_IntByStringTest.cpp -o test
.\test.exe
```
