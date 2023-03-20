#pragma once

#include "Traveller.h"

class Astronaut : public Traveller {
    int yearsOfExperience;
    std::string licenseId;
    std::string spaceTravelLicense;
public:
    Astronaut(std::string _name, int _id, int _yearsOfExperience, std::string _licenseId, std::string _spaceTravelLicense)
            : Traveller(_name, _id), yearsOfExperience(_yearsOfExperience), licenseId(_licenseId), spaceTravelLicense(_spaceTravelLicense) { }

    int getYearsOfExperience() const { return yearsOfExperience; }

    std::string getLicenseId() const { return licenseId; }

    std::string getSpaceTravelLicense() const { return spaceTravelLicense; }
};
