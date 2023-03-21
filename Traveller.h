#ifndef TRAVELLER_H
#define TRAVELLER_H

#include <string>
#include <vector>
//class Ticket; // forward declaration of Ticket class

class Traveller
{
public:
    std::string name;
    int id;
    bool valid;
    
     // new flag to indicate infinite validity
    //std::vector<Ticket *> list_of_tickets;

private:
    int traveler_id = -1; // when the ticket or travel class has not been initialized

public:
    Traveller(std::string _name, int _id);
    Traveller();
    int getTravellerID() const;

    

    bool verifyid(int givenID);

    std::string getName() const; // getter for the name attribute

    void setName(std::string newName); // setter for the name attribute

    void setTravelerid(int id);

    int getTravelerid() const;

    int getId() const; // getter for the id attribute

    void setid(int newID);

    

   
};

#endif /* TRAVELLER_H */
