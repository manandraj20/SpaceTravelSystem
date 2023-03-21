#ifndef TICKET_H
#define TICKET_H

#include "Planet.h"
#include "Passenger.h"
#include "Date.h"

class Ticket
{
    static int nextId;  // Static variable to generate unique IDs
    double price;
public:
    int id;
    Passenger *passenger;
    Planet source, destination;
    Date date;
    int validityPeriod = 10;
    bool valid = false;
    

public:
    Ticket( Planet _source, Planet _destination, Date _date,int _validityPeriod=10);
    void bookTicket(Passenger *_passenger);
    double getPrice() const;
    std::string getName() const;
    int getID() const; // getter for Passenger id
    Ticket bookReturn(Date _date) const;
    void setPrice();
   //getter for passenger
    Passenger* getPassenger() const;
    //getter for source
    Planet getSource() const;
    //getter for destination
    Planet getDestination() const;
    bool isValid() const;

  

    void validate();

    void setValidityPeriod(int _validityPeriod);

    int getValidityPeriod() const;

    void update(Planet _source, Planet _destination, Date _date);

    Date getTravelDate() const;
    void Delete();

private:
    
    double distanceTo(const Planet &source, const Planet &destination) const;
};
// declare the operator function outside of the class definition
std::ostream &operator<<(std::ostream &os, const Ticket &t);

#endif // TICKET_H
