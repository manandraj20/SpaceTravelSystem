#ifndef JUPITER_H
#define JUPITER_H

#include "Planet.h"

class Jupiter : public Planet {
    bool hasRings;
    double mass; // in kg
public:
    Jupiter(std::string _name, int _x, int _y, int _z, bool _hasRings, double _mass);
    bool getHasRings() const;
    double getMass() const;
    std::string getRingsInfo() const;
    std::string getMassInfo() const;
};

#endif // JUPITER_H
