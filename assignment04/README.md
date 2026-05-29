# Assignment 4 — Calendar Calculator

> 日历计算系统 | 面向对象程序设计基础 第 4 次作业 · 第 1 题

---

## 📌 Description

A calendar date calculator that computes the date `n` days after (or before) any given date. Supports both **A.D. and B.C. years**, and correctly crosses the B.C./A.D. boundary.

**Core algorithm:** Julian Day Number (JDN) — an international standard used in astronomy. Converting a date to JDN and back takes O(1) time with no loops, regardless of how large `n` is.

---

## 📁 File Structure

```
assignment4/
├── CP_Calendar.h          # Base class declaration
├── CP_Calendar.cpp        # isLeapYear, daysInMonth, toJDN, fromJDN, addDays
├── CP_CalendarEx.h        # Derived class declaration (B.C. support)
├── CP_CalendarEx.cpp      # Year conversion, B.C. output, cross-era addDays
└── CP_CalendarMain.cpp    # Main program: loop input, [q] to quit
```

---

## 🏗️ Class Structure

```
Calendar     (base class — A.D. dates, JDN core)
└── CalendarEx  (derived class — adds B.C. year support)
```

**Calendar** stores `m_year`, `m_month`, `m_day` as `protected` members and provides:
- `toJDN()` / `fromJDN(jdn)` — convert between date and Julian Day Number
- `addDays(n)` — implemented as `fromJDN(toJDN() + n)`, O(1)
- `virtual print()` — overridden by CalendarEx to show A.D./B.C. prefix

**CalendarEx** adds:
- `toAstroYear(userYear)` — converts user year to astronomical year (B.C. 1 = year 0)
- `toUserYear(astroYear)` — converts back for display
- Overrides `print()` and `addDays()` to handle B.C. years transparently

---

## 📐 Algorithm: Julian Day Number (JDN)

JDN is a continuous integer count of days starting from 4713 BC Jan 1. Any date difference equals the difference of their JDNs.

**Date → JDN** (Meeus, 1998, Ch. 7):
```
if month <= 2: year -= 1, month += 12
A = year / 100
B = 2 - A + A/4   (Gregorian correction)
JDN = ⌊365.25(year+4716)⌋ + ⌊30.6001(month+1)⌋ + day + B - 1524
```

**B.C. year handling (Astronomical Year Numbering):**

| User Input | Astronomical Year | Notes |
|------------|-------------------|-------|
| 1 (A.D. 1) | 1 | unchanged |
| -1 (B.C. 1) | 0 | no year zero in history |
| -2 (B.C. 2) | -1 | |

---

## 🧪 Test Results

| Input Date | n | Output Date |
|------------|---|-------------|
| A.D. 2026-03-11 | +100 | A.D. 2026-06-19 |
| A.D. 2000-01-01 | +366 | A.D. 2001-01-02 *(2000 is a leap year)* |
| A.D. 2024-02-28 | +1 | A.D. 2024-02-29 *(Feb 29 exists in 2024)* |
| B.C. 0044-03-15 | -30 | B.C. 0044-02-13 |
| B.C. 0001-12-31 | +1 | **A.D. 0001-01-01** *(B.C./A.D. boundary)* |

---

## 🚀 How to Run

```bash
g++ -std=c++11 CP_CalendarMain.cpp CP_Calendar.cpp CP_CalendarEx.cpp -o calendar
.\calendar.exe
```

**Interaction:**
- Enter year (positive = A.D., negative = B.C., `0` is invalid)
- Enter month and day
- Enter `n` (positive = forward, negative = backward)
- Type **`q`** at the year prompt to quit

---

## 📚 References

| # | Source |
|---|--------|
| [1] | Meeus, J. (1998). *Astronomical Algorithms* (2nd ed.). Willmann-Bell. Ch. 7. ISBN 978-0-943396-61-3 |
| [2] | Dershowitz, N. & Reingold, E. M. (2018). *Calendrical Calculations* (4th ed.). Cambridge University Press. ISBN 978-1-107-68316-7 |
| [3] | ISO 8601:2004 — *Representation of dates and times*. ISO. |
