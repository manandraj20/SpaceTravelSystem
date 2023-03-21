#ifndef EARTH_H
#define EARTH_H

#include "Planet.h"

class Earth : public Planet {
    double waterCoverage; // as a percentage
public:
    Earth(std::string _name, int _x, int _y, int _z, double _waterCoverage);
    double getWaterCoverage() const;
    std::string getWaterInfo() const;
    void setWaterCoverage(double _waterCoverage);
    
};

#endif // EARTH_H
