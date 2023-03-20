#ifndef TICKET_H
#define TICKET_H

#include "Planet.h"
#include "Passenger.h"
#include "Date.h"

class Ticket
{
    double price;
public:
    Passenger *passenger;
    Planet source, destination;
    Date date;
    int validityPeriod = 10;
    bool valid = false;

public:
    Ticket( Planet _source, Planet _destination, Date _date);
    void bookTicket(Passenger *_passenger);
    double getPrice() const;
    std::string getName() const;
    int getID() const; // getter for Passenger id
    Ticket bookReturn(Date _date) const;
    void setPrice();

    bool isValid() const;

    void Delete();

    void validate();

    void setValidityPeriod(int _validityPeriod);

    int getValidityPeriod() const;

    void update(Planet _source, Planet _destination, Date _date);

    Date getTravelDate() const;

private:
    
    double distanceTo(const Planet &source, const Planet &destination) const;
};
// declare the operator function outside of the class definition
std::ostream &operator<<(std::ostream &os, const Ticket &t);

#endif // TICKET_H
