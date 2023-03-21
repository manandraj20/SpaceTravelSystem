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
    void setName(std::string _name);
    //setter for x,y, z
    void setX(int _x);
    void setY(int _y);
    void setZ(int _z);
    
    double distanceTo(const Planet &other) const;
};

#endif // PLANET_H
