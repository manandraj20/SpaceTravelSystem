#include "saturn.h"

Saturn::Saturn(std::string _name, int _x, int _y, int _z, bool _hasRings, double _mass)
    : Planet(_name, _x, _y, _z), hasRings(_hasRings), mass(_mass) {}

bool Saturn::getHasRings() const {
    return hasRings;
}

double Saturn::getMass() const {
    return mass;
}

std::string Saturn::getRingsInfo() const {
    return hasRings ? "Saturn has rings." : "Saturn does not have rings.";
}

std::string Saturn::getMassInfo() const {
    return "Saturn has a mass of " + std::to_string(mass) + " kg.";
}
