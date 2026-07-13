[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 09 — 成绩单管理系统

[首页](../README.zh-CN.md) · C++11

## 项目简介

这是一个支持纯文本持久化的控制台成绩管理程序。每条学生记录包含字符串 ID 和整数成绩，数据保存在 `std::vector` 中，并支持常见的增删改查操作。

## 设计

```text
CP_StudentRecord        # 数据记录
CP_GradeSheet           # 存储、增删改查和文件读写
└── CP_GradeSheetSystem # 交互菜单
```

| 操作 | 方法 |
|---|---|
| 添加、删除、修改和查询 | `mb_add`、`mb_remove`、`mb_modify`、`mb_query` |
| 清空与显示 | `mb_clear`、`mb_show` |
| 读取与保存 | `mb_readFile`、`mb_writeFile` |

`grades.txt` 使用连续的虚构编号作为演示数据，不包含真实学生信息。

## 文件结构

```text
assignment09/
├── CP_GradeSheet.h / CP_GradeSheet.cpp
├── CP_GradeSheetSystem.h / CP_GradeSheetSystem.cpp
├── CP_GradeSheetSystemMain.cpp
├── CP_GradeSheetTest.h / CP_GradeSheetTest.cpp
├── CP_GradeSheetTestMain.cpp
├── grades.txt
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
# 交互程序
g++ -std=c++11 -o gradesheet.exe CP_GradeSheet.cpp CP_GradeSheetSystem.cpp CP_GradeSheetSystemMain.cpp
.\gradesheet.exe

# 自动测试
g++ -std=c++11 -o test.exe CP_GradeSheet.cpp CP_GradeSheetTest.cpp CP_GradeSheetTestMain.cpp
.\test.exe
```

28 项检查覆盖全部增删改查操作、非法输入以及使用临时文件进行的写入/读取往返验证。

---

[上一项](../assignment08/README.zh-CN.md) · [下一项](../assignment10/README.zh-CN.md)
