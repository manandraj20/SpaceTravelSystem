#include "Ticket.h"
#include <ostream>

using namespace std;
int Ticket::nextId = 0;
Ticket::Ticket( Planet _source, Planet _destination, Date _date, int _validityPeriod)
    : id(++nextId),source(_source), destination(_destination), date(_date), validityPeriod(_validityPeriod)
{
    // price = (date + 1) * distanceTo(_source, _destination);
    // price = 4000;
}
//getter for source
Planet Ticket::getSource() const { return source; }
//getter for destination
Planet Ticket::getDestination() const { return destination; }
//getter for passenger
Passenger* Ticket::getPassenger() const { return passenger; }

Date Ticket::getTravelDate() const { return date; }
double Ticket::getPrice() const { return price; }
Ticket Ticket::bookReturn(Date _date) const {
    Ticket rTicket = Ticket(destination, source, _date);
    rTicket.bookTicket(passenger);
    return rTicket;
}
void Ticket::bookTicket(Passenger* _passenger){
    passenger = _passenger;
    passenger->setTravelerid(id);
    
    setPrice();
}

std::string Ticket::getName() const
{ // getter for the Passenger name
    return passenger->getName();
}
int Ticket::getID() const
{
    // return passenger->getTravellerID();
    return id;
}

void Ticket::setPrice()
{
    const int K = 100;
    Date now;
    double BasePrice = (double)K / (double)(date.differenceInDays(now) + 1);
    // cout << date << " " << now << endl;
    // cout << distanceTo(source, destination) << " " << BasePrice << endl;
    price = (BasePrice * distanceTo(source, destination));
}

bool Ticket::isValid() const { return passenger->isValid; }



void Ticket::validate() { valid = true; }

void Ticket::update(Planet _source, Planet _destination, Date _date)
{
    source = _source;
    destination = _destination;
    date = _date;
}

void Ticket::setValidityPeriod(int _validityPeriod) { validityPeriod = _validityPeriod; }

int Ticket::getValidityPeriod() const { return validityPeriod; }

double Ticket::distanceTo(const Planet &source, const Planet &destination) const
{
    return source.distanceTo(destination);
}
// define the operator function outside of the class definition
std::ostream &operator<<(std::ostream &os, const Ticket &t)
{
    os << "TicketID: " << (t.getID()) << std::endl;
    os << "Passenger: " << (t.passenger)->getName() << std::endl;
    os << "Source planet: " << (t.source).getName() << std::endl;
    os << "Destination planet: " << (t.destination).getName() << std::endl;
    os << "Travel date: " << t.date;
    os << "Ticket price: " << t.getPrice() << std::endl;
    return os;
}
//impelement the delete operation fo ticket class
void Ticket::Delete()
{
    delete this;
}
