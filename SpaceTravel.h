#pragma once

#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Astronaut.h"
#include "Commander.h"
#include "Planet.h"

class SpaceTravel {
private:
    static int nextId;  // Static variable to generate unique IDs
    int id;
    std::vector<Passenger*> passengers;
    Astronaut* astronaut;
    Commander* commander;
    Planet source, destination;
    Date travelDate;    

public:
    SpaceTravel(Planet _source, Planet _destination, Date _travelDate);
    void addPassenger(Passenger* passenger);
    void listPassengers() const;
    void printAstronaut() const;
    void printCommander() const;
    void setAstronaut(Astronaut* astronaut);
    void setCommander(Commander* commander);
    void updateAstronaut(Astronaut* newAstronaut);
    void updateCommander(Commander* newCommander);
    int getId() const;
    Planet getSource() const;
    Planet getDestination() const;
    Date getTravelDate() const;
    void setSource(const Planet& source);
    void setDestination(const Planet&dest );
    void setTravelDate(const Date& d);
    void Delete();
};
std::ostream &operator<<(std::ostream &os, const SpaceTravel &st);