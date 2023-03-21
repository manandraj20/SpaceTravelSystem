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

int main() {
    // Open the input file
    std::ifstream infile("travellerList.txt");
    if (!infile) {
        std::cerr << "Error: could not open input file" << std::endl;
        return 1;
    }

    // Create vectors to store the passengers, astronauts, and commanders
    std::vector<Passenger> passengers;

    // Read the lines from the input file and create the corresponding objects
    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string type;
        Passenger p;
        Date startDate;
        std::getline(ss, type, ','); // Extract the type (should be "P")
        
       
        if (type == "P") { // P stands for passenger
           
            ss >> p;
            passengers.push_back(p);
        }
        
        // } else if (type == "astronaut") {
        //     ss >> years >> flights >> company;
        //     std::getline(ss, license); // read the license text (may contain spaces)
        //     astronauts.push_back(new Astronaut(name, id, flights, company, license));
        // } else if (type == "commander") {
        //     ss >> years >> flights >> company >> country;
        //     commanders.push_back(new Commander(name, id, flights, company, country));
        // }
    }

    // Print the contents of the vectors for testing
    std::cout << "Passengers:" << std::endl;
    for (const auto passenger : passengers) {
        std::cout << passenger << std::endl;
    }
    return 0;
}
