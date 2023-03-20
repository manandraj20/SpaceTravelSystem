#ifndef MOON_H
#define MOON_H

#include "Planet.h"

class Moon : public Planet {
    bool atmosphere;
    bool water;
public:
    Moon(std::string _name, int _x, int _y, int _z, bool _atmosphere, bool _water);
    bool hasAtmosphere() const;
    bool hasWater() const;
};

#endif // MOON_H
