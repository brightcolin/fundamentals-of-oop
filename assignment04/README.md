# Assignment 04 — Calendar Calculator / 日历计算系统

[Home / 首页](../README.md) · C++11

## Overview / 项目简介

A date calculator that moves forward or backward by an arbitrary number of days. It supports both B.C. and A.D. dates and crosses the era boundary without introducing a historical year zero.

这是一个按任意天数向前或向后推算日期的程序，支持公元前与公元纪年，并能正确跨越不存在历史公元 0 年的纪年边界。

## Design / 设计

```text
CP_Calendar   (base class: Gregorian date and JDN conversion)
              （基类：公历日期与儒略日转换）
└── CP_CalendarEx (derived class: B.C./A.D. presentation)
                  （派生类：公元前/公元显示）
```

The core converts a date to a Julian Day Number (JDN), adds `n`, and converts the result back. This makes date shifting constant-time with respect to `n`.

核心过程先将日期转换为儒略日数（JDN），加上 `n`，再转换回日期，因此运行时间不会随天数跨度增长。

| User year / 用户年份 | Astronomical year / 天文年份 |
|---:|---:|
| A.D. 1 / 公元 1 年 | 1 |
| B.C. 1 / 公元前 1 年 | 0 |
| B.C. 2 / 公元前 2 年 | -1 |

## Files / 文件结构

```text
assignment04/
├── CP_Calendar.h / CP_Calendar.cpp
├── CP_CalendarEx.h / CP_CalendarEx.cpp
└── CP_CalendarMain.cpp
```

## Build and Run / 编译运行

```powershell
g++ -std=c++11 -o calendar.exe CP_CalendarMain.cpp CP_Calendar.cpp CP_CalendarEx.cpp
.\calendar.exe
```

Enter a positive year for A.D., a negative year for B.C., and `q` at the year prompt to quit. Year `0` is rejected.

公元年份输入正数，公元前年份输入负数；在年份提示处输入 `q` 退出。程序不接受年份 `0`。

## References / 参考资料

- Jean Meeus, *Astronomical Algorithms*, 2nd ed., Chapter 7.
- Nachum Dershowitz and Edward M. Reingold, *Calendrical Calculations*, 4th ed.
- ISO 8601:2004, *Representation of dates and times*.

---

[Previous / 上一项](../assignment03/README.md) · [Next / 下一项](../assignment05/README.md)
