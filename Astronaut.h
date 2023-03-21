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
    Astronaut(){}

    //setter for the yearsOfExperience
    void setYearsOfExperience(int _yearsOfExperience) { yearsOfExperience = _yearsOfExperience; }

    //setter of licenseid
    void setLicenseId(std::string _licenseId) { licenseId = _licenseId; }
    //setter of spacetravellicense
    void setSpaceTravelLicense(std::string _spaceTravelLicense) { spaceTravelLicense = _spaceTravelLicense; }

    std::string getLicenseId() const { return licenseId; }

    std::string getSpaceTravelLicense() const { return spaceTravelLicense; }

    //implement overloaded >> operator
    friend std::istream &operator>>(std::istream &in, Astronaut &astronaut) {
        std::string name;
        int id;
        int yearsOfExperience;
        std::string licenseId;
        std::string spaceTravelLicense;
        std::getline(in, name, ',');
        in >> id >> yearsOfExperience;
        std::getline(in, licenseId, ',');
        std::getline(in, spaceTravelLicense);
        // in >> name >> id >> yearsOfExperience >> licenseId >> spaceTravelLicense;
        astronaut = Astronaut(name, id, yearsOfExperience, licenseId, spaceTravelLicense);
        return in;
    }
    // implement a overloaded << operator
    friend std::ostream &operator<<(std::ostream &out, const Astronaut &astronaut) {
        out << astronaut.name << "," << astronaut.id << "," << astronaut.yearsOfExperience << "," << astronaut.licenseId << "," << astronaut.spaceTravelLicense;
        return out;
    }
};
