#include "Passenger.h"
#include <stdexcept>
#include <iostream>
#include <string>

Passenger::Passenger(std::string _name, int _id) : Traveller(_name, _id), validityPeriod(10), isInfinite(false) {}
Passenger::Passenger() {}
void Passenger::invalidate()
{
    isValid = false;
}

// getter for startDate
Date Passenger::getStartDate() const
{
    return startDate;
}

void Passenger::validate()
{
    isValid = true;
}

void Passenger::addTravel(int _id)
{
    // TODO
    list_of_travel_IDs.push_back(_id);
}
void Passenger::removeTravel(int _id)
{
    // TODO
    int cnt = 0;
    for (auto ele : list_of_travel_IDs)
    {
        if (ele == _id)
        {
            break;
        }
        cnt++;
    }
    if (static_cast<std::vector<int>::size_type>(cnt) > (list_of_travel_IDs.size()))
    {
        throw std::invalid_argument("Travel ID not found");
    }
    list_of_travel_IDs.erase(list_of_travel_IDs.begin() + cnt);
}

int Passenger::getValidityPeriod() const
{
    return validityPeriod;
}

void Passenger::setInfiniteValidity(bool value)
{
    isInfinite = value;
}

bool Passenger::isInfiniteValidity() const
{
    return isInfinite;
}

void Passenger::setStartDate(Date _startDate)
{
    startDate = _startDate;
}

void Passenger::increaseValidity(int noOfYears)
{
    validityPeriod += noOfYears;
}

bool Passenger::checkValidity()
{
    Date now;
    isValid = (now.differenceInDays(startDate) > validityPeriod * 365) ? false : true;
    return isValid;
}

void Passenger::setValidityPeriod(int _validityPeriod)
{
    validityPeriod = _validityPeriod;
}

// implement a overloaded << operator
std::ostream &operator<<(std::ostream &os, const Passenger &p)
{
    os << "Passenger ID: " << p.getId() << std::endl;
    os << "Passenger Name: " << p.getName() << std::endl;
    os << "Passenger start date: " << p.getStartDate();
    os << "Passenger Validity Period: " << p.getValidityPeriod() << std::endl;

    return os;
}

// implement a overloaded >> operator
std::istream &operator>>(std::istream &is, Passenger &p)
{
    std::string name;
    int id;
    Date startDate;
    int validityPeriod;
    std::getline(is, name, ',');
    // std::cout << name << std::endl;
    is >> id;
    // is >> ",";
    // std::cout << id << " ";
// std::string date;
//     std::getline(is, date, ',');
//     int year, month, day;
//     std::stringstream(date) >> year;
//     std::getline(std::stringstream(date.substr(5)), month, '-');
//     std::getline(std::stringstream(date.substr(8)), day, '-');


//     std::string year, month, day;
//     std::getline(is, year, '-');
//     std::getline(is, month, '-');
//     std::getline(is, day,',');
//     std::cout << year << month << day<<std::endl;
    // int num;
    // std::stringstream(year) >> num;
    // std::cout << num << std::endl;
    // startDate=Date(std::stoi(year),std::stoi(month),std::stoi(day));
    // return is;



    // is >> startDate;
    // std::cout << startDate << " ";
    int year, month, day;
    is >> year >> month >> day;
    // std::cout << year << month << day;
    startDate = Date(year, month, day);
    // std::cout << startDate << std::endl;
    startDate.setYear(year);
    is >> validityPeriod;
    // std::cout << validityPeriod << std::endl;
    p.setName(name);
    p.setid(id);
    p.setStartDate(startDate);
    p.setValidityPeriod(validityPeriod);
    return is;
}
