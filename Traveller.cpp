#include "Traveller.h"

Traveller::Traveller(std::string _name, int _id) : name(_name), id(_id), valid(true), traveler_id(_id) {}

int Traveller::getTravellerID() const
{ // getter function for the traveller_id
    return traveler_id;
}
std::string Traveller::getName() const
{
    return name;
}

int Traveller::getId() const
{
    return id;
}

void Traveller::setTravelerid(int id)
{
    traveler_id = id;
}



int Traveller::getTravelerid() const
{
    return traveler_id;
}






void Traveller::setName(std::string newName)
{
    name = newName;
}

void Traveller::setid(int newID)
{
    id = newID;
}
bool Traveller::verifyid(int givenID)
{
    return givenID == this->id;
}





