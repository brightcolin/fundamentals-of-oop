#ifndef CP_CALENDAR_H
#define CP_CALENDAR_H

#include <string>

class Calendar {
public:
    Calendar();
    Calendar(int year, int month, int day);

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setDate(int year, int month, int day);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    virtual void print() const;

    Calendar addDays(int n) const;

    static bool isLeapYear(int year);
    static int daysInMonth(int year, int month);

    long long toJDN() const;
    static Calendar fromJDN(long long jdn);

protected:
    int m_year;
    int m_month;
    int m_day;

    void validate() const;

};

#endif