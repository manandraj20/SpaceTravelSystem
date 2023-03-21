#pragma once

#include "Traveller.h"
#include "Date.h"
#include <vector>
#include<iostream>

class Passenger : public Traveller
{
private:
    Date startDate;
    int validityPeriod;
    bool isInfinite;
    std::vector<int> list_of_travel_IDs;

public:
    bool isValid;

    // methods to add travel to the list of travels of the traveller
    //  travel will be tickets in case of passenger
    void addTravel(int _id);
    void removeTravel(int _id);

    void invalidate();
    void validate();

    int getValidityPeriod() const;
    void setInfiniteValidity(bool value);
    bool isInfiniteValidity() const;

    Passenger(std::string _name, int _id);
    Passenger();
    void setStartDate(Date _startDate);
    void increaseValidity(int noOfYears = 1);
    bool checkValidity();
    void setValidityPeriod(int _validityPeriod);

    //getter for startDate
    Date getStartDate() const;
};

//implement a overloaded << operator
std::ostream &operator<<(std::ostream &os, const Passenger &p);

//implement a overloaded >> operator
std::istream &operator>>(std::istream &is, Passenger &p);

/* PASSENGER_H */
