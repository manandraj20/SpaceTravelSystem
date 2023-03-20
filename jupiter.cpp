#include "jupiter.h"

Jupiter::Jupiter(std::string _name, int _x, int _y, int _z, bool _hasRings, double _mass)
    : Planet(_name, _x, _y, _z), hasRings(_hasRings), mass(_mass) {}

bool Jupiter::getHasRings() const {
    return hasRings;
}

double Jupiter::getMass() const {
    return mass;
}

std::string Jupiter::getRingsInfo() const {
    return hasRings ? "Jupiter has rings." : "Jupiter does not have rings.";
}

std::string Jupiter::getMassInfo() const {
    return "Jupiter has a mass of " + std::to_string(mass) + " kg.";
}
