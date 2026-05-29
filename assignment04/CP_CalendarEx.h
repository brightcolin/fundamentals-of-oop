#ifndef CP_CALENDAR_EX_H
#define CP_CALENDAR_EX_H

#include "CP_Calendar.h"
#include <string>

class CalendarEx : public Calendar {
public:
    CalendarEx();
    CalendarEx(int year, int month, int day);

    void print() const override;

    CalendarEx addDays(int n) const;

    static int toAstroYear(int userYear);
    static int toUserYear(int astroYear);

};

#endif