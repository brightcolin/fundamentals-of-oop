[English](README.md) | [简体中文](README.zh-CN.md)

# Assignment 04 — Calendar Calculator

[Home](../README.md) · C++11

## Overview

A date calculator that moves forward or backward by an arbitrary number of days. It supports both B.C. and A.D. dates and crosses the era boundary without introducing a historical year zero.

## Design

```text
CP_Calendar (base class: Gregorian date and JDN conversion)
└── CP_CalendarEx (derived class: B.C./A.D. presentation)
```

The core converts a date to a Julian Day Number (JDN), adds `n`, and converts the result back. This makes date shifting constant-time with respect to `n`.

| User year | Astronomical year |
|---:|---:|
| A.D. 1 | 1 |
| B.C. 1 | 0 |
| B.C. 2 | -1 |

## Files

```text
assignment04/
├── CP_Calendar.h / CP_Calendar.cpp
├── CP_CalendarEx.h / CP_CalendarEx.cpp
├── CP_CalendarMain.cpp
├── README.md
└── README.zh-CN.md
```

## Build and Run

```powershell
g++ -std=c++11 -o calendar.exe CP_CalendarMain.cpp CP_Calendar.cpp CP_CalendarEx.cpp
.\calendar.exe
```

Enter a positive year for A.D., a negative year for B.C., and `q` at the year prompt to quit. Year `0` is rejected.

## References

- Jean Meeus, *Astronomical Algorithms*, 2nd ed., Chapter 7.
- Nachum Dershowitz and Edward M. Reingold, *Calendrical Calculations*, 4th ed.
- ISO 8601:2004, *Representation of dates and times*.

---

[Previous](../assignment03/README.md) · [Next](../assignment05/README.md)
