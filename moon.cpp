#include "moon.h"

Moon::Moon(std::string _name, int _x, int _y, int _z, bool _atmosphere, bool _water)
    : Planet(_name, _x, _y, _z), atmosphere(_atmosphere), water(_water) {}

bool Moon::hasAtmosphere() const {
    return atmosphere;
}

bool Moon::hasWater() const {
    return water;
}
