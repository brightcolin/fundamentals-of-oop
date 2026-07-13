[English](README.md) | [简体中文](README.zh-CN.md)

# 作业 04 — 日历计算系统

[首页](../README.zh-CN.md) · C++11

## 项目简介

这是一个按任意天数向前或向后推算日期的程序，支持公元前与公元纪年，并能正确跨越不存在历史公元 0 年的纪年边界。

## 设计

```text
CP_Calendar（基类：公历日期与儒略日转换）
└── CP_CalendarEx（派生类：公元前/公元显示）
```

核心过程先将日期转换为儒略日数（JDN），加上 `n`，再转换回日期，因此运行时间不会随天数跨度增长。

| 用户年份 | 天文年份 |
|---:|---:|
| 公元 1 年 | 1 |
| 公元前 1 年 | 0 |
| 公元前 2 年 | -1 |

## 文件结构

```text
assignment04/
├── CP_Calendar.h / CP_Calendar.cpp
├── CP_CalendarEx.h / CP_CalendarEx.cpp
├── CP_CalendarMain.cpp
├── README.md
└── README.zh-CN.md
```

## 编译运行

```powershell
g++ -std=c++11 -o calendar.exe CP_CalendarMain.cpp CP_Calendar.cpp CP_CalendarEx.cpp
.\calendar.exe
```

公元年份输入正数，公元前年份输入负数；在年份提示处输入 `q` 退出。程序不接受年份 `0`。

## 参考资料

- Jean Meeus, *Astronomical Algorithms*, 第 2 版，第 7 章。
- Nachum Dershowitz 和 Edward M. Reingold，*Calendrical Calculations*，第 4 版。
- ISO 8601:2004，*Representation of dates and times*。

---

[上一项](../assignment03/README.zh-CN.md) · [下一项](../assignment05/README.zh-CN.md)
