/**
 * @file main.cpp
 * @author Milan Anand Raj (manandraj20@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief
 * the program includes a makefile. USe that to make main.o using `make main` and `make clean` to delete all the object files
 * use ./main in the same directory to run the main file then.
 * 
 */




#include <iostream>
#include "Traveller.h"
#include "Planet.h"
#include "Ticket.h"
#include "Passenger.h"
#include "Date.h"
#include "SpaceTravel.h"
#include "Astronaut.h"
#include "Commander.h"
#include "earth.h"
#include "mars.h"
#include "jupiter.h"
#include "saturn.h"
#include "pluto.h"

using namespace std;
bool checkDuplicateTickets(std::vector<Ticket> tickets, const Planet &source, const Planet &destination, const Date &date)
{
    int count = 0;
    for (const auto &ticket : tickets)
    {
        if (ticket.source.getName() == source.getName() && ticket.destination.getName() == destination.getName() && ticket.getTravelDate() == date)
        {
            count++;
        }
        if (count >= 2)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Build the universe with at least 3 planets
    Earth earth("Earth", 149, 0, 0, .73);
    Mars mars("Mars", 228, 0, 0, true, false);
    Jupiter jupiter("Jupiter", 778, 0, 0, true, 1.898e27);
    std::vector<Passenger *> passengers;
    // Date now;
    // create a traveller
    // validity for every passenger is 10 years by deafult
    Passenger passenger1("Alice", 4);
    passenger1.setStartDate(Date(2020, 5, 12));
    passengers.push_back(&passenger1);
    Passenger passenger2("Bob", 5);
    passenger2.setStartDate(Date()); // ticket for Bob will not be booked as his validity for 10 years as compared to now is invalid
                                     // change 2010 to 2020 and it will be booked again
    // we can increase the validity of every passenger by calling increaseValidity
    passenger2.increaseValidity(10);
    passengers.push_back(&passenger2);
    // create two tickets for Alice
    Passenger passenger3("Carol", 6);
    passenger3.setStartDate(Date());
    passengers.push_back(&passenger3);
    // passenger3.increaseValidity(10);
    Passenger passenger4("Grace Liu", 7);
    passenger4.setStartDate(Date());
    passengers.push_back(&passenger4);
    // passenger4.increaseValidity(10);
    // instantiate 7 more such kind of passengers
    Passenger passenger5("Harry Kim", 8);
    passengers.push_back(&passenger5);
    passenger5.setStartDate(Date());
    // passenger5.increaseValidity(10);
    Passenger passenger6("Isabel Chang", 9);

    passenger6.setStartDate(Date());
    passengers.push_back(&passenger6);
    Passenger passenger7("Jack Wang", 10);
    passenger7.setStartDate(Date());
    passengers.push_back(&passenger7);
    Passenger passenger8("Karen Chen", 11);
    passenger8.setStartDate(Date());
    passengers.push_back(&passenger8);
    Passenger passenger9("Larry Li", 12);
    passenger9.setStartDate(Date());
    passengers.push_back(&passenger9);
    Passenger passenger10("Megan Wu", 13);
    passenger10.setStartDate(Date());
    passengers.push_back(&passenger10);
    Passenger passenger11("Nick Lin", 14);
    passenger11.setStartDate(Date());
    passengers.push_back(&passenger11);
    std::string license = "this is the space tarvel license issued by the US govt.";
    Astronaut astronaut1("Carol Garcia", 3, 10, "SpaceX", license);
    Astronaut astronaut2("Eve Brown", 5, 20, "Blue Origin", license);
    Commander commander1("Frank Zhang", 6, 30, "Roscosmos", "France");
    Commander commander2("Dave Lee", 4, 10, "NASA", "USA");
    vector<Ticket> tickets;
    // create two tickets for Alice
    // check validity of Alice and then only book ticket
    if (passenger1.checkValidity())
    {
        passenger1.setTravelerid(1);

        Ticket ticket1(earth, mars, Date());
        ticket1.bookTicket(&passenger1);
       
        cout << ticket1 << std::endl;
        tickets.push_back(ticket1);
        passenger1.setTravelerid(2);

        // optional method to book return ticket
        Ticket ticket1R = ticket1.bookReturn(Date(2025, 12, 12));
        
        tickets.push_back(ticket1R);
        cout << ticket1R << std::endl;
    }
    // create a ticket for Bob
    if (passenger2.checkValidity())
    {
        passenger2.setTravelerid(3);
        Ticket ticket2(jupiter, earth, Date(2024, 5, 10));
        ticket2.bookTicket(&passenger2);
        
        tickets.push_back(ticket2);
        cout << ticket2 << std::endl;
    }
    // create a ticket for Carol
    if (passenger3.checkValidity())
    {
        passenger3.setTravelerid(4);
        Ticket ticket3( earth, mars, Date(2024, 5, 10));
        ticket3.bookTicket(&passenger3);
        
        tickets.push_back(ticket3);
        cout << ticket3 << std::endl;
    }
    // create a ticket for Grace
    if (passenger4.checkValidity())
    {
        passenger4.setTravelerid(5);
        Ticket ticket4( earth, mars, Date(2024, 5, 10));
        ticket4.bookTicket(&passenger4);
       
        tickets.push_back(ticket4);
        cout << ticket4 << std::endl;
    }
    // create a ticket for Harry
    if (passenger5.checkValidity())
    {
        passenger5.setTravelerid(6);
        Ticket ticket5( earth, mars, Date(2024, 5, 10));
        ticket5.bookTicket(&passenger5);
        tickets.push_back(ticket5);
        cout << ticket5 << std::endl;
    }
    // create a ticket for Isabel

    if (passenger6.checkValidity())
    {
        passenger6.setTravelerid(7);
        Ticket ticket6( earth, mars, Date(2024, 5, 10));
        ticket6.bookTicket(&passenger6);
        tickets.push_back(ticket6);
        cout << ticket6 << std::endl;
    }
    // create a ticket for Jack
    if (passenger7.checkValidity())
    {
        passenger7.setTravelerid(8);
        Ticket ticket7( earth, mars, Date(2024, 5, 10));
        ticket7.bookTicket(&passenger7);
        tickets.push_back(ticket7);
        cout << ticket7 << std::endl;
    }

    // check if there are duplicate tickets for the same source, destination, and date
    if (checkDuplicateTickets(tickets, earth, mars, Date(2024, 5, 10)))
    {

        // create SpaceTravel object only if there are more than 2 passengers with the same source, destination, and date
        SpaceTravel st1(earth, mars, Date());
        st1.setAstronaut(&astronaut1);
        st1.setCommander(&commander1);

        st1.addPassenger(&passenger7);

        st1.addPassenger(&passenger6);
        st1.addPassenger(&passenger5);

        std::cout << "Printing the space travel class: " << endl;
        std::cout << st1 << std::endl;
    }

    if (checkDuplicateTickets(tickets, earth, mars, Date(2025, 12, 12)))
    {
        // create SpaceTravel object only if there are more than 2 passengers with the same source, destination, and date
        SpaceTravel st2(mars, earth, Date(2025, 12, 12));
        st2.setAstronaut(&astronaut2);
        st2.setCommander(&commander2);
        std::cout << st2 << std::endl;
    }

    return 0;
}
