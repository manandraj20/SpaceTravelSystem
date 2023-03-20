#include <iostream>
#include <vector>
#include <cmath>
#include "Traveller.h"
#include "Planet.h"
#include "mars.h"
#include "earth.h"
#include "jupiter.h"
#include "Passenger.h"
#include "Astronaut.h"
#include "Commander.h"
#include "Ticket.h"
#include "SpaceTravel.h"
using namespace std;

int main()
{
   

    // Create some passengers, including astronauts and commanders
    vector<Traveller *> passengers;
    passengers.push_back(new Passenger("Alice Smith", 1));
    passengers.push_back(new Passenger("Bob Johnson", 2));
    passengers.push_back(new Astronaut("Carol Garcia", 3, 10, "SpaceX", "this is the space tarvel license issued by the US govt."));
    passengers.push_back(new Commander("Dave Lee", 4, 10, "NASA", "USA"));
    passengers.push_back(new Astronaut("Eve Brown", 5, 20, "Blue Origin"));
    passengers.push_back(new Commander("Frank Zhang", 6, 30, "Roscosmos", "France"));
    passengers.push_back(new Passenger("Grace Liu", 7));
    passengers.push_back(new Passenger("Harry Kim", 8));
    passengers.push_back(new Passenger("Isabel Chang", 9));
    passengers.push_back(new Passenger("Jack Wang", 10));
    passengers.push_back(new Passenger("Karen Chen", 11));
    passengers.push_back(new Passenger("Larry Li", 12));
    passengers.push_back(new Passenger("Megan Wu", 13));
    passengers.push_back(new Passenger("Nick Lin", 14));
    passengers.push_back(new Passenger("Olivia Chu", 15));
    vector<Ticket *> tickets;
    // Create some tickets and assign travellers to them
    for (int i = 0; i < tickets.size(); ++i)
    {
        Traveller *passenger = passengers[i]; // get the i-th passenger
        Planet source = earth;                // assign a source planet
        Planet dest = mars;                   // assign a destination planet
        int date = 2023 + i;                  // assign a date (just an example)

        tickets[i] = new Ticket(passenger, source, dest, date); // create a new ticket with the passenger
    }

    // Print out the tickets
    for (Ticket *t : tickets)
    {
        cout << (*t) << endl;
    }

    // Clean up memory
    for (Traveller *p : passengers)
    {
        delete p;
    }
    for (Ticket *t : tickets)
    {
        delete t;
    }

    return 0;
}
