#include "Planet.h"
#include <cmath>

Planet::Planet(std::string _name, int _x, int _y, int _z) : name(_name), x(_x), y(_y), z(_z) {}

std::string Planet::getName() const { return name; }

int Planet::getX() const { return x; }

int Planet::getY() const { return y; }

int Planet::getZ() const { return z; }

void Planet::setName(std::string _name) { name = _name; }
//setter for x,y, z
void Planet::setX(int _x) { x = _x; }
void Planet::setY(int _y) { y = _y; }
void Planet::setZ(int _z) { z = _z; }

double Planet::distanceTo(const Planet &other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}
