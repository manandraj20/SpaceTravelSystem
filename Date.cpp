#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

Date::Date()
{
    std::time_t now = std::time(nullptr);
    std::tm *ptm = std::localtime(&now);
    year = ptm->tm_year + 1900;
    month = ptm->tm_mon + 1;
    day = ptm->tm_mday;
}
bool Date::operator==(const Date &other) const
{
    return year == other.year && month == other.month && day == other.day;
}
int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

int Date::differenceInDays(const Date &other) const
{
    // calculate the difference in days between two dates
    std::tm time1 = tmFromYMD(year, month, day);
    time_t time1_sec = std::mktime(&time1);
    std::tm time2 = tmFromYMD(other.year, other.month, other.day);
    time_t time2_sec = std::mktime(&time2);
    int difference = std::difftime(time1_sec, time2_sec) / (24 * 3600);
    return std::abs(difference);
}

Date Date::futureDate(int years, int months, int days) const
{
    // calculate a future date by adding a certain number of years, months, and days
    int futureYear = year + years;
    int futureMonth = month + months;
    int futureDay = day + days;
    // adjust the date if it goes beyond the end of the month or year
    while (futureMonth > 12)
    {
        futureMonth -= 12;
        futureYear += 1;
    }
    while (futureDay > daysInMonth(futureMonth, futureYear))
    {
        futureDay -= daysInMonth(futureMonth, futureYear);
        futureMonth += 1;
        if (futureMonth > 12)
        {
            futureMonth -= 12;
            futureYear += 1;
        }
    }
    return Date(futureYear, futureMonth, futureDay);
}

std::tm Date::tmFromYMD(int year, int month, int day)
{
    std::tm tm = {0};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    return tm;
}

int Date::daysInMonth(int month, int year)
{
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    return days[month - 1];
}

bool Date::isLeapYear(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
std::ostream &operator<<(std::ostream &os, const Date &d)
{
    os << "Year/month/day: " << d.getYear() << "/" << d.getMonth() << "/" << d.getDay() << std::endl;
    return os;
}

//setter for year
void Date::setYear(int y)
{
    year = y;
}

// std::istream &operator>>(std::istream &is, Date &d)
// {
//     int year, month, day;
//     is >> year >> month >> day;
//     d = Date(year, month, day);
//     return is;
// }




//implement the >> overloaded operator assuming the fact that the date is given in the format of year-month-day in istream
std::istream &operator>>(std::istream &is, Date &d)
{
    int year, month, day;
    char c1, c2;
    is >> year >> c1 >> month >> c2 >> day;
    if (c1 != '-' || c2 != '-')
    {
        is.setstate(std::ios::failbit);
        return is;
    }
    d.setYear(year);
    return is;
}

