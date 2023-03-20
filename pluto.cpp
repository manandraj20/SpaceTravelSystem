#include "pluto.h"

Pluto::Pluto(std::string _name, int _x, int _y, int _z, bool _isDwarf, double _mass) : Planet(_name, _x, _y, _z) {
    isDwarf = _isDwarf;
    mass = _mass;
}

bool Pluto::getIsDwarf() const {
    return isDwarf;
}

double Pluto::getMass() const {
    return mass;
}

std::string Pluto::getDwarfInfo() const {
    if (isDwarf) {
        return "Pluto is a dwarf planet.";
    } else {
        return "Pluto is not a dwarf planet.";
    }
}

std::string Pluto::getMassInfo() const {
    return "Pluto's mass is " + std::to_string(mass) + " kg.";
}
