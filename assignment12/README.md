# Assignment 12 — Integer Parser

> 整数字符串解析与异常处理 | 面向对象程序设计基础 第 12 次作业

---

## 📌 Description

A strict string-to-`int` parser that rejects malformed input and reports exactly what went wrong and where. Uses a custom exception class instead of the standard library exceptions.

---

## 📁 File Structure

```
assignment12/
├── CP_IntegerException.h        # Custom exception: error code enum + position + message
├── CP_IntegerParser.h           # CP_IntegerParser — single static method mbs_parse()
├── CP_IntegerParser.cpp         # Parsing logic with detailed error detection
├── CP_IntegerParserMain.cpp     # Entry point: interactive parser
├── CP_IntegerParserTest.h       # Test framework header (7 test groups)
├── CP_IntegerParserTest.cpp     # Test implementation
└── CP_IntegerParserTestMain.cpp # Entry point: automated tests
```

---

## 🏗️ Class Structure

### CP_IntegerException

```
CP_IntegerException
├── m_code     : CP_ErrorCode   — machine-readable error type
├── m_position : int            — 0-based index of the offending character
└── m_message  : string         — human-readable description
```

### Error Codes

| Code | Value | Meaning |
|------|-------|---------|
| `CE_EMPTY_STRING` | 1 | Input string is empty |
| `CE_SIGN_ONLY` | 2 | String contains only `+` or `-` |
| `CE_INVALID_CHAR` | 3 | Non-digit, non-sign character found |
| `CE_LEADING_ZEROS` | 4 | Number starts with `0` but is not `"0"` |
| `CE_OVERFLOW` | 5 | Value exceeds `INT_MAX` or `INT_MIN` |
| `CE_EXTRA_SIGN` | 6 | Sign character appears after the first position |

### CP_IntegerParser

```cpp
static int mbs_parse(const string &s);
// Returns parsed int on success.
// Throws CP_IntegerException on any error.
```

---

## 🧪 Test Groups (7)

| # | Group | Examples |
|---|-------|---------|
| 1 | Valid integers | `"0"`, `"42"`, `"-7"`, `"+100"`, `"2147483647"` |
| 2 | Empty string | `""` → `CE_EMPTY_STRING` |
| 3 | Sign only | `"+"`, `"-"` → `CE_SIGN_ONLY` |
| 4 | Invalid char | `"12a"`, `"1.5"` → `CE_INVALID_CHAR` |
| 5 | Leading zeros | `"007"`, `"-01"` → `CE_LEADING_ZEROS` |
| 6 | Overflow | `"2147483648"`, `"-2147483649"` → `CE_OVERFLOW` |
| 7 | Extra sign | `"1+2"`, `"--1"` → `CE_EXTRA_SIGN` |

---

## 🚀 How to Compile & Run

```bash
# Interactive parser
g++ -std=c++11 CP_IntegerParserMain.cpp CP_IntegerParser.cpp -o main
.\main.exe

# Automated tests
g++ -std=c++11 CP_IntegerParserTestMain.cpp CP_IntegerParser.cpp CP_IntegerParserTest.cpp -o test
.\test.exe
```
