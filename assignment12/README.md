[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 12 — Integer Parser

[Home](../README.md) · C++11

## Overview

A strict string-to-`int` parser that rejects malformed input, detects overflow, and reports an error code plus the position of the offending character through a custom exception type.

## Error Model

| Code | Meaning |
|---|---|
| `CE_EMPTY_STRING` | Empty input |
| `CE_SIGN_ONLY` | Only `+` or `-` |
| `CE_INVALID_CHAR` | Invalid non-digit character |
| `CE_LEADING_ZEROS` | Disallowed leading zeros |
| `CE_OVERFLOW` | Outside the `int` range |
| `CE_EXTRA_SIGN` | Sign after position zero |

```cpp
static int CP_IntegerParser::mbs_parse(const std::string &s);
```

The method returns the parsed value or throws `CP_IntegerException`, which stores the code, zero-based position, and a readable message.

## Files

```text
assignment12/
├── CP_IntegerException.h
├── CP_IntegerParser.h / CP_IntegerParser.cpp
├── CP_IntegerParserMain.cpp
├── CP_IntegerParserTest.h / CP_IntegerParserTest.cpp
├── CP_IntegerParserTestMain.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
# Interactive parser
g++ -std=c++11 -o main.exe CP_IntegerParser.cpp CP_IntegerParserMain.cpp
.\main.exe

# Automated tests
g++ -std=c++11 -o run_test.exe CP_IntegerParser.cpp CP_IntegerParserTest.cpp CP_IntegerParserTestMain.cpp
.\run_test.exe
```

The 34 checks cover valid signed values, empty input, signs, invalid characters, leading zeros, `INT_MIN`/`INT_MAX`, overflow, and extra signs.

---

[Previous](../assignment11/README.md) · [Next](../assignment13/README.md)
