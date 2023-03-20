#ifndef PLANET_H
#define PLANET_H

#include <string>

class Planet {
    std::string name;
    int x, y, z;
public:
    Planet(std::string _name, int _x, int _y, int _z);
    std::string getName() const;
    int getX() const;
    int getY() const;
    int getZ() const;
    double distanceTo(const Planet &other) const;
};

#endif // PLANET_H
