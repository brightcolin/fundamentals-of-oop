# Assignment 12 — Integer Parser / 整数字符串解析器

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

A strict string-to-`int` parser that rejects malformed input, detects overflow, and reports an error code plus the position of the offending character through a custom exception type.

这是一个严格的字符串到 `int` 解析器，能够拒绝格式错误的输入、检测溢出，并通过自定义异常报告错误码和出错字符位置。

## Error Model / 错误模型

| Code / 错误码 | Meaning / 含义 |
|---|---|
| `CE_EMPTY_STRING` | Empty input / 空字符串 |
| `CE_SIGN_ONLY` | Only `+` or `-` / 只有正负号 |
| `CE_INVALID_CHAR` | Invalid non-digit character / 非法非数字字符 |
| `CE_LEADING_ZEROS` | Disallowed leading zeros / 不允许的前导零 |
| `CE_OVERFLOW` | Outside the `int` range / 超出 `int` 范围 |
| `CE_EXTRA_SIGN` | Sign after position zero / 非首位符号 |

```cpp
static int CP_IntegerParser::mbs_parse(const std::string &s);
```

The method returns the parsed value or throws `CP_IntegerException`, which stores the code, zero-based position, and a readable message.

方法成功时返回整数，失败时抛出 `CP_IntegerException`；异常保存错误码、从零开始的位置和可读说明。

## Files / 文件结构

```text
assignment12/
├── CP_IntegerException.h
├── CP_IntegerParser.h / CP_IntegerParser.cpp
├── CP_IntegerParserMain.cpp
├── CP_IntegerParserTest.h / CP_IntegerParserTest.cpp
└── CP_IntegerParserTestMain.cpp
```

## Build and Run / 编译运行

```powershell
# Interactive parser / 交互解析器
g++ -std=c++11 -o main.exe CP_IntegerParser.cpp CP_IntegerParserMain.cpp
.\main.exe

# Automated tests / 自动测试
g++ -std=c++11 -o run_test.exe CP_IntegerParser.cpp CP_IntegerParserTest.cpp CP_IntegerParserTestMain.cpp
.\run_test.exe
```

Tests cover valid signed values, empty input, signs, invalid characters, leading zeros, `INT_MIN`/`INT_MAX`, overflow, and extra signs.

测试覆盖有效有符号整数、空输入、符号、非法字符、前导零、`INT_MIN`/`INT_MAX`、溢出和多余符号。

---

[Previous / 上一项](../assignment11/README.md) · [Next / 下一项](../assignment13/README.md)
