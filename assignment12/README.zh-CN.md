[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 12 — 整数字符串解析器

[首页](../README.zh-CN.md) · C++11

## 项目简介

这是一个严格的字符串到 `int` 解析器，能够拒绝格式错误的输入、检测溢出，并通过自定义异常报告错误码和出错字符位置。

## 错误模型

| 错误码 | 含义 |
|---|---|
| `CE_EMPTY_STRING` | 空字符串 |
| `CE_SIGN_ONLY` | 只有正负号 |
| `CE_INVALID_CHAR` | 非法非数字字符 |
| `CE_LEADING_ZEROS` | 不允许的前导零 |
| `CE_OVERFLOW` | 超出 `int` 范围 |
| `CE_EXTRA_SIGN` | 非首位符号 |

```cpp
static int CP_IntegerParser::mbs_parse(const std::string &s);
```

方法成功时返回整数，失败时抛出 `CP_IntegerException`；异常保存错误码、从零开始的位置和可读说明。

## 文件结构

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

## 编译运行

```powershell
# 交互解析器
g++ -std=c++11 -o main.exe CP_IntegerParser.cpp CP_IntegerParserMain.cpp
.\main.exe

# 自动测试
g++ -std=c++11 -o run_test.exe CP_IntegerParser.cpp CP_IntegerParserTest.cpp CP_IntegerParserTestMain.cpp
.\run_test.exe
```

34 项检查覆盖有效有符号整数、空输入、符号、非法字符、前导零、`INT_MIN`/`INT_MAX`、溢出和多余符号。

---

[上一项](../assignment11/README.zh-CN.md) · [下一项](../assignment13/README.zh-CN.md)
