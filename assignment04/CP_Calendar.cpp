#include "CP_Calendar.h"

#include <iostream>
#include<iomanip>
#include <stdexcept>

bool Calendar::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int Calendar::daysInMonth(int year, int month){
    static const int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2 && isLeapYear(year)){
        return 29;
    }
    return days[month];
}

long long Calendar::toJDN() const {
    int y= m_year;
    int m= m_month;
    int d= m_day;

    if(m<=2){
        y--;
        m+=12;
    }

    int A= y/100;
    int B= 2 - A + A/4;

    return (long long)(365.25*(y+4716)) 
        + (long long)(30.6001*(m+1)) 
        + d + B - 1524;
    
}

Calendar Calendar::fromJDN(long long jdn) {
    long long Z = jdn;
    long long A= Z;

    long long alpha = (long long)((Z-1867216.25)/36524.25);
    A += 1 + alpha - alpha/4;

    long long B = A + 1524;
    long long C = (long long)((B-122.1)/365.25);
    long long D = (long long)(365.25*C);
    long long E = (long long)((B-D)/30.6001);

    int day = (int)(B - D - (long long)(30.6001*E));
    int month = (int)(E < 14 ? E - 1 : E - 13);
    int year = (int)(month > 2 ? C - 4716 : C - 4715);

    return Calendar(year, month, day);
}

Calendar::Calendar() : m_year(2000), m_month(1), m_day(1) {}

Calendar::Calendar(int year, int month, int day) 
    : m_year(year), m_month(month), m_day(day) {
    validate();
}

void Calendar::setYear(int year) {
    m_year = year;
    validate();
}

void Calendar::setMonth(int month) {
    m_month = month;
    validate();
}

void Calendar::setDay(int day) {
    m_day = day;
    validate();
}

void Calendar::setDate(int year, int month, int day) {
    m_year = year;
    m_month = month;
    m_day = day;
    validate();
}

int Calendar::getYear() const {
    return m_year;
}

int Calendar::getMonth() const {
    return m_month;
}

int Calendar::getDay() const {
    return m_day;
}

void Calendar::print() const {
    std::cout << std::setw(4) << std::setfill('0') << m_year << "-"
              << std::setw(2) << std::setfill('0') << m_month << "-"
              << std::setw(2) << std::setfill('0') << m_day << std::endl;
}

Calendar Calendar::addDays(int n) const {
    return fromJDN(toJDN() + n);
}

void Calendar::validate() const {
    if (m_month < 1 || m_month > 12) {
        throw std::invalid_argument("Invalid month");
    }
    if (m_day < 1 || m_day > daysInMonth(m_year, m_month)) {
        throw std::invalid_argument("Invalid day");
    }
}