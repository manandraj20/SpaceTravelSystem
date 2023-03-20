#include "SpaceTravel.h"

int SpaceTravel::nextId = 0;

SpaceTravel::SpaceTravel(Planet _source, Planet _destination, Date _travelDate) : id(++nextId), astronaut(nullptr), commander(nullptr),source(_source), destination(_destination), travelDate(_travelDate){}

void SpaceTravel::addPassenger(Passenger* passenger) {
    if (passengers.size() < 10) {
        passengers.push_back(passenger);
    } else {
        std::cout << "Cannot add passenger, maximum capacity reached" << std::endl;
    }
}

void SpaceTravel::listPassengers() const{
    std::cout << "Passengers:" << std::endl;
    for (Passenger* p : passengers) {
        std::cout << "- " << p->getName() << std::endl;
    }
    // if (astronaut != nullptr) {
    //     std::cout << "Astronaut: " << astronaut->getName() << std::endl;
    // }
    // if (commander != nullptr) {
    //     std::cout << "Commander: " << commander->getName() << std::endl;
    // }
}
void SpaceTravel::printAstronaut() const{
    if (astronaut != nullptr) {
        std::cout << "Astronaut: " << astronaut->getName() << std::endl;
    }
}
Planet SpaceTravel::getSource() const{
    // std::cout << "Source: " << source.getName() << std::endl;
    return source;
}
Planet SpaceTravel::getDestination() const{
    // std::cout << "Destination: " << destination.getName() << std::endl;
    return destination;
}
Date SpaceTravel::getTravelDate() const{
    std::cout << "Travel Date: " << travelDate << std::endl;
    return travelDate;
}
void SpaceTravel::setSource(const Planet& source){
    this->source = source;
}
void SpaceTravel::setDestination(const Planet&dest ){
    this->destination = dest;
}
void SpaceTravel::setTravelDate(const Date& d){
    this->travelDate = d;
}

void SpaceTravel::printCommander() const{
    if (commander != nullptr) {
        std::cout << "Commander: " << commander->getName() << std::endl;
    }
}

void SpaceTravel::setAstronaut(Astronaut* astronaut) {
    this->astronaut = astronaut;
}

void SpaceTravel::setCommander(Commander* commander) {
    this->commander = commander;
}

void SpaceTravel::updateAstronaut(Astronaut* newAstronaut) {
    if (astronaut != nullptr) {
        astronaut = newAstronaut;
    } else {
        std::cout << "No astronaut assigned" << std::endl;
    }
}

void SpaceTravel::updateCommander(Commander* newCommander) {
    if (commander != nullptr) {
        commander = newCommander;
    } else {
        std::cout << "No commander assigned" << std::endl;
    }
}

int SpaceTravel::getId() const {
    return id;
}
std::ostream& operator<<(std::ostream& os, const SpaceTravel& st)
{
    os << "Space travel ID: " << st.getId() << std::endl;
    os << "Source planet: " << st.getSource().getName() << std::endl;
    os << "Destination planet: " << st.getDestination().getName() << std::endl;
    os << "Travel date: " << st.getTravelDate() << std::endl;

    st.listPassengers();

    st.printAstronaut();
    st.printCommander();

    return os;
}
