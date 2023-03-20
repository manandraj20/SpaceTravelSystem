#include "Passenger.h"
#include <stdexcept>

Passenger::Passenger(std::string _name, int _id) : Traveller(_name, _id), validityPeriod(10), isInfinite(false) {}

void Passenger::invalidate()
{
    isValid = false;
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
void Passenger::removeTravel(int _id){
    // TODO
    int cnt = 0;
    for (auto ele: list_of_travel_IDs){
        if (ele == _id){
            break;
        }
        cnt++;
    }
    if(static_cast<std::vector<int>::size_type>(cnt)>  (list_of_travel_IDs.size()) ){
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
