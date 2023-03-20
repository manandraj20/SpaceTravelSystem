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

    std::string getAuthority() const { return authority; }

    int getYearsOfExperience() const { return yearsOfExperience; }

    std::string getLicenseId() const { return licenseId; }
    void checkTravelDetails() const; // code to check upcoming travel details
};

#endif /* COMMANDER_H */
