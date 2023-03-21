#ifndef PLUTO_H
#define PLUTO_H

#include "Planet.h"

class Pluto : public Planet {
    bool isDwarf;
    double mass; // in kg
public:
    Pluto(std::string _name, int _x, int _y, int _z, bool _isDwarf, double _mass);
    bool getIsDwarf() const;
    double getMass() const;
    std::string getDwarfInfo() const;
    std::string getMassInfo() const;
};

#endif // PLUTO_H
