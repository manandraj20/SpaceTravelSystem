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
    //setter for year
    void setYear(int _year);

private:
    static std::tm tmFromYMD(int year, int month, int day);
    static int daysInMonth(int month, int year);
    static bool isLeapYear(int year);
};


std::ostream &operator<<(std::ostream &os, const Date &d);
//implement a overloaded >> operator for date
std::istream &operator>>(std::istream &is, Date &d);
#endif // DATE_H
// string year, month, day;
//     std::getline(is, year, '-');
//     std::getline(is, month, '-');
//     std::getline(is, day,',');
//     cout << year << month << day<<endl;
//     d=Date(std::stoi(year),std::stoi(month),std::stoi(day));
//     return is;