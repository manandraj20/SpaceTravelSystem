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

    void setStartDate(Date _startDate);
    void increaseValidity(int noOfYears = 1);
    bool checkValidity();
    void setValidityPeriod(int _validityPeriod);
};

/* PASSENGER_H */
