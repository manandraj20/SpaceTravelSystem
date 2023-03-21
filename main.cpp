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
 * the program includes a makefile. Use that to make main.o using `make main` and `make clean` to delete all the object files
 * use ./main in the same directory to run the main file then.
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
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
// find any space travel object from the vector of space class object given the id of the space travel object
SpaceTravel *findSpaceTravel(std::vector<SpaceTravel *> spaceTravels, int id)
{
    for (auto &spaceTravel : spaceTravels)
    {
        if (spaceTravel->getId() == id)
        {
            return spaceTravel;
        }
    }
    return nullptr;
}

// find any ticket object from the vector of ticket objects given the id of the ticket object
Ticket *findTicket(std::vector<Ticket> tickets, int id)
{
    for (auto &ticket : tickets)
    {
        if (ticket.getID() == id)
        {
            return &ticket;
        }
    }
    return nullptr;
}

int main()
{
    // make a text file any include all the passengers in that
    // read the file and create the passengers

    // Build the universe with at least 3 planets
    Earth earth("Earth", 149, 0, 0, .73);     // name, (x, y, z), waterCoverage
    Mars mars("Mars", 228, 0, 0, true, 1000); // name, (x, y, z), waterIsThereornot, mo of inhabitants
    Jupiter jupiter("Jupiter", 778, 0, 0, true, 1.898e27);

    // Date now;
    // create a traveller
    // validity for every passenger is 10 years by deafult
    // Open the input file
    std::ifstream infile("travellerList.txt");
    if (!infile)
    {
        std::cerr << "Error: could not open input file" << std::endl;
        return 1;
    }

    // Create vectors to store the passengers, astronauts, and commanders
    std::vector<Passenger> passengers;
    std::vector<Astronaut> astronauts;
    std::vector<Commander> commanders;
    // Read the lines from the input file and create the corresponding objects
    std::string line;
    while (std::getline(infile, line))
    {
        std::stringstream ss(line);
        std::string type;
        Passenger p;
        Date startDate;
        std::getline(ss, type, ','); // Extract the type (should be "P")

        if (type == "P")
        { // P stands for passenger

            ss >> p;
            // cout << p << endl;
            passengers.push_back(p);
        }
        else if (type == "astronaut")
        {

            Astronaut a;
            ss >> a;
            // cout << a << endl;
            astronauts.push_back(a);
        }
         else if (type == "commander") {
            Commander c;
            ss >> c;
            commanders.push_back(c);
        }
    }

    // close the file
    infile.close();

    // you can replace this instantiation if you wish
    std::string license = "this is the space tarvel license issued by the US govt.";
    Astronaut astronaut1("Carol Garcia", 3, 10, "SpaceX", license);
    Astronaut astronaut2("Eve Brown", 5, 20, "Blue Origin", license);
    Commander commander1("Frank Zhang", 6, 30, "Roscosmos", "France");
    Commander commander2("Dave Lee", 4, 10, "NASA", "USA");

    vector<Ticket> tickets;
    // create two tickets for Alice
    // check validity of Alice and then only book ticket
    if (passengers[0].checkValidity())
    {

        Ticket ticket1(earth, mars, Date(), 10);                 // initialise a ticket source=earth, des=mars, Date of travel=Date() which is today's date, validity period=10, by default validity period is 10
        passengers[0].setTravelerid(ticket1.getID());            //  create a traveller id for the passenger
        passengers[0].addTravel(passengers[0].getTravellerID()); // add ticket to the list of travels of the passengers
        ticket1.bookTicket(&passengers[0]);                      // book the ticket

        cout << ticket1 << std::endl;
        tickets.push_back(ticket1);

        // optional method to book return ticket
        Ticket ticket1R = ticket1.bookReturn(Date(2025, 12, 12));
        passengers[0].setTravelerid(ticket1.getID());
        tickets.push_back(ticket1R);
        cout << ticket1R << std::endl;
    }
    // create a ticket for Bob
    if (passengers[1].checkValidity())
    {
        passengers[1].setTravelerid(3);
        Ticket ticket2(jupiter, earth, Date(2024, 5, 10));
        ticket2.bookTicket(&passengers[1]);

        tickets.push_back(ticket2);
        cout << ticket2 << std::endl;
    }
    // create a ticket for Carol
    if (passengers[2].checkValidity())
    {
        passengers[2].setTravelerid(4);
        Ticket ticket3(earth, mars, Date(2024, 5, 10));
        ticket3.bookTicket(&passengers[2]);

        tickets.push_back(ticket3);
        cout << ticket3 << std::endl;
    }
    // create a ticket for Grace
    if (passengers[3].checkValidity())
    {
        passengers[3].setTravelerid(5);
        Ticket ticket4(earth, mars, Date(2024, 5, 10));
        ticket4.bookTicket(&passengers[3]);

        tickets.push_back(ticket4);
        cout << ticket4 << std::endl;
    }
    // create a ticket for Harry
    if (passengers[4].checkValidity())
    {
        passengers[4].setTravelerid(6);
        Ticket ticket5(earth, mars, Date(2024, 5, 10));
        ticket5.bookTicket(&passengers[4]);
        tickets.push_back(ticket5);
        cout << ticket5 << std::endl;
    }
    // create a ticket for Isabel

    if (passengers[5].checkValidity())
    {
        passengers[5].setTravelerid(7);
        Ticket ticket6(earth, mars, Date(2024, 5, 10));
        ticket6.bookTicket(&passengers[5]);
        tickets.push_back(ticket6);
        cout << ticket6 << std::endl;
    }
    // create a ticket for Jack
    if (passengers[6].checkValidity())
    {
        passengers[6].setTravelerid(8);
        Ticket ticket7(earth, mars, Date(2024, 5, 10));
        ticket7.bookTicket(&passengers[6]);
        tickets.push_back(ticket7);
        cout << ticket7 << std::endl;
    }

    vector<SpaceTravel *> st_list;

    // check if there are duplicate tickets for the same source, destination, and date
    if (checkDuplicateTickets(tickets, earth, mars, Date(2024, 5, 10)))
    {

        // create SpaceTravel object only if there are more than 2 passengers with the same source, destination, and date
        SpaceTravel st1(earth, mars, Date());

        st1.setAstronaut(&astronaut1);
        // the setCommander action will assign space travel object id to the commander object,
        // the commander can then use that to access the space travel object
        st1.setCommander(&commanders[0]);

        st1.addPassenger(&passengers[6]);

        st1.addPassenger(&passengers[5]);
        st1.addPassenger(&passengers[4]);
        st_list.push_back(&st1);

        // checking the travel details associated with the commander
        SpaceTravel *st_temp = findSpaceTravel(st_list, commanders[0].getTravellerID());

        std::cout << "Printing the space travel class: " << endl;
        std::cout << *st_temp << std::endl;
    }

    if (checkDuplicateTickets(tickets, earth, mars, Date(2025, 12, 12)))
    {
        // create SpaceTravel object only if there are more than 2 passengers with the same source, destination, and date
        SpaceTravel st2(mars, earth, Date(2025, 12, 12));
        st2.setAstronaut(&astronaut2);
        st2.setCommander(&commander2);
        st_list.push_back(&st2);
        std::cout << st2 << std::endl;
    }

    return 0;
}
