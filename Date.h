#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>

class Date
{
private:
    int year, month, day;

public:
    Date(int y, int m, int d);
    Date();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int differenceInDays(const Date &other) const;
    Date futureDate(int years, int months, int days) const;
    bool operator==(const Date &other) const;

private:
    static std::tm tmFromYMD(int year, int month, int day);
    static int daysInMonth(int month, int year);
    static bool isLeapYear(int year);
};


std::ostream &operator<<(std::ostream &os, const Date &d);
#endif // DATE_H
