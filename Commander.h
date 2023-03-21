#ifndef COMMANDER_H
#define COMMANDER_H

#include "Traveller.h"


#include <string>

class Commander : public Traveller
{
    std::string authority;
    int yearsOfExperience;
    std::string licenseId;
    


public:
    Commander(std::string _name, int _id, int _yearsOfExperience, std::string _licenseId, std::string _authority)
        : Traveller(_name, _id), authority(_authority), yearsOfExperience(_yearsOfExperience), licenseId(_licenseId)
    {
      //
    }
    Commander(){}

    std::string getAuthority() const { return authority; }

    int getYearsOfExperience() const { return yearsOfExperience; }

    std::string getLicenseId() const { return licenseId; }
    void checkTravelDetails() const; // code to check upcoming travel details
    //setter for authority
    void setAuthority(std::string _authority) { authority = _authority; }
    //setter for yearsOfExperience
    void setYearsOfExperience(int _yearsOfExperience) { yearsOfExperience = _yearsOfExperience; }
    //setter for licenseId
    void setLicenseId(std::string _licenseId) { licenseId = _licenseId; }
    //implement overloaded >> operator
    friend std::istream &operator>>(std::istream &in, Commander &commander)
    {
        std::string name;
        int id;
        int yearsOfExperience;
        std::string licenseId;
        std::string authority;
        std::getline(in, name, ',');
        // in >> id >> yearsOfExperience;
    
         in  >> id >> yearsOfExperience >> licenseId >> authority;
        commander = Commander(name, id, yearsOfExperience, licenseId, authority);
        return in;
    }

};

#endif /* COMMANDER_H */
