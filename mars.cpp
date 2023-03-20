#include "mars.h"

Mars::Mars(std::string _name, int _x, int _y, int _z, bool _water, int _inhabitants)
    : Planet(_name, _x, _y, _z), water(_water), inhabitants(_inhabitants) {}

bool Mars::hasWater() const {
    return water;
}

int Mars::getInhabitants() const {
    return inhabitants;
}

void Mars::setInhabitants(int newInhabitants) {
    inhabitants = newInhabitants;
}
