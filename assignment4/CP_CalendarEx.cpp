#include "CP_CalendarEx.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>


int CalendarEx::toAstroYear(int userYear) {
    if (userYear == 0) {
        throw std::invalid_argument("Year 0 does not exist in the calendar.");
    }
    return (userYear > 0) ? userYear : (userYear + 1);
}

int CalendarEx::toUserYear(int astroYear) {
    return (astroYear > 0) ? astroYear : (astroYear - 1);
}

CalendarEx::CalendarEx() : Calendar() {}

CalendarEx::CalendarEx(int year, int month, int day){
    if (year == 0) {
        throw std::invalid_argument("Year 0 does not exist in the calendar.");
    }

    m_year = toAstroYear(year);
    m_month = month;
    m_day = day;

    validate();

}

void CalendarEx::print() const {
    int userY = toUserYear(m_year);
    if (userY > 0) {
        std::cout << "A.D. " 
            << std::setw(4) << std::setfill('0') << userY << "-"
            << std::setw(2) << std::setfill('0') << m_month << "-"
            << std::setw(2) << std::setfill('0') << m_day << std::endl;
    } else {
        std::cout << "B.C. "
            << std::setw(4) << std::setfill('0') << -userY << "-"
            << std::setw(2) << std::setfill('0') << m_month << "-"
            << std::setw(2) << std::setfill('0') << m_day << std::endl;
    }
}

CalendarEx CalendarEx::addDays(int n) const {
    Calendar base = Calendar::fromJDN(toJDN() + n);
    int userY = toUserYear(base.getYear());
    return CalendarEx(userY, base.getMonth(), base.getDay());

}