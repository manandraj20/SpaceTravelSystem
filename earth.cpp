#include "Earth.h"

Earth::Earth(std::string _name, int _x, int _y, int _z, double _waterCoverage)
    : Planet(_name, _x, _y, _z), waterCoverage(_waterCoverage) {}

double Earth::getWaterCoverage() const {
    return waterCoverage;
}

std::string Earth::getWaterInfo() const {
    return "Water coverage of " + getName() + " is " + std::to_string(waterCoverage) + "%";
}
