#ifndef SATURN_H
#define SATURN_H

#include "Planet.h"

class Saturn : public Planet {
    bool hasRings;
    double mass; // in kg
public:
    Saturn(std::string _name, int _x, int _y, int _z, bool _hasRings, double _mass);
    bool getHasRings() const;
    double getMass() const;
    std::string getRingsInfo() const;
    std::string getMassInfo() const;
};

#endif // SATURN_H
