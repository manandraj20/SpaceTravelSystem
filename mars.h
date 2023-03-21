#ifndef MARS_H
#define MARS_H

#include "Planet.h"

class Mars : public Planet {
    bool water;
    int inhabitants;
public:
    Mars(std::string _name, int _x, int _y, int _z, bool _water, int _inhabitants);
    bool hasWater() const;
    int getInhabitants() const;
    void setInhabitants(int newInhabitants);
    //setter for water
    void setWater(bool _water);
};

#endif // MARS_H
