# Assignment 5 — Complex Number Calculator

> 复数计算系统 | 面向对象程序设计基础 第 5 次作业 · 第 1 题

---

## 📌 Problem Description

Implement a complex number class `CP_Complex` with the following operator overloads:

- Arithmetic: `+`  `-`  `*`  `/`
- Prefix / postfix: `++`  `--`
- Comparison: `==`  `!=`
- Stream: `<<`  `>>`

Advanced (optional): equivalence class partition + automated verification program.

---

## 📁 File Structure

```
assignment5/
├── CP_Complex.h                 # Unified header — all declarations
├── CP_Complex_core.cpp          # Constructor / Getter·Setter / toString / stream
├── CP_Complex_arith.cpp         # +  -  *  /  and compound assignment
├── CP_Complex_incdec.cpp        # ++  --  (prefix & postfix)  ==  !=
│
├── CP_ComplexMain.cpp           # Interactive main program
│
├── CP_ComplexTest.h             # Test framework header
├── CP_ComplexTest.cpp           # Assertion helpers / runAll / summary
├── CP_ComplexTest_arith.cpp     # Equivalence-class tests: +  -  *  /
├── CP_ComplexTest_incdec.cpp    # Equivalence-class tests: ++  --  ==  !=
├── CP_ComplexTestMain.cpp       # Automated test entry point
│
└── 复数计算系统文档_v4.docx      # Assignment report (Word)
    复数计算系统文档_v4.pdf       # Assignment report (PDF)
```

---

## ⚙️ Environment

| Item | Details |
|------|---------|
| OS | Windows 10 / 11 |
| IDE | Visual Studio Code |
| Compiler | g++ (MinGW-w64) |
| Standard | C++11 |

---

## 🚀 How to Compile & Run

### Interactive Program

```bash
g++ -std=c++11 CP_ComplexMain.cpp \
    CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp \
    -o complex

.\complex.exe
```

Enter two complex numbers at the prompts (format: `real imag`, e.g. `3 4` means `3+4i`).  
Type `q` at the first prompt to quit.

### Automated Test Program (Advanced)

```bash
g++ -std=c++11 CP_ComplexTestMain.cpp \
    CP_Complex_core.cpp CP_Complex_arith.cpp CP_Complex_incdec.cpp \
    CP_ComplexTest.cpp CP_ComplexTest_arith.cpp CP_ComplexTest_incdec.cpp \
    -o run_test

.\run_test.exe
```

Expected output: **53 passed, 0 failed, 53 total**

---

## 🏗️ Architecture

The project uses a **single header + multiple implementation files** design.  
Each `.cpp` file is responsible for exactly one category of functionality.  
To add new features (e.g. polar form), create a new `.cpp` and add declarations to the header — no existing file needs to change.

```
CP_Complex.h        ← declare everything here
    │
    ├── CP_Complex_core.cpp      § constructors, output
    ├── CP_Complex_arith.cpp     § +  -  *  /
    └── CP_Complex_incdec.cpp    § ++  --  ==  !=
```

---

## 📐 Key Formulas

| Operator | Formula |
|----------|---------|
| `+` | `(a+c) + (b+d)i` |
| `-` | `(a-c) + (b-d)i` |
| `*` | `(ac-bd) + (ad+bc)i` |
| `/` | `[(ac+bd) + (bc-ad)i] / (c²+d²)` — throws `domain_error` when divisor is 0 |
| `++`/`--` | Real part ±1 only; imaginary part unchanged |

---

## 🧪 Test Results

| Test file | Cases | Passed |
|-----------|-------|--------|
| `CP_ComplexTest_arith.cpp` | 21 | 21 ✅ |
| `CP_ComplexTest_incdec.cpp` | 32 | 32 ✅ |
| **Total** | **53** | **53** ✅ |

Tests cover 5 equivalence classes per operator: general complex / pure imaginary / pure real / zero / negative.  
Division additionally tests EC6: divisor = 0 (must throw `std::domain_error`).
