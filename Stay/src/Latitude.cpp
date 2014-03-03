// Latitude.cpp

#include <iostream>
#include "Latitude.h"

Latitude::Latitude() : Position() {
    // DO NOTHING
}

Latitude::Latitude(std::string coordinateStr, std::string direction) : Position(coordinateStr, direction) {
    this->coordinateStr = coordinateStr;
    if(direction[0] == 'N' || direction[0] == 'S')
        this->direction = direction;
    else
        std::cout << "Invalid direction! " << std::endl;
    setCoordinate(coordinateStr);
}
