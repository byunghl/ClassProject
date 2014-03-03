// Longitude.cpp

#include <iostream>
#include "Longitude.h"

Longitude::Longitude() : Position() {
    // DO NOTHING
}

Longitude::Longitude(std::string coordinateStr, std::string direction) : Position(coordinateStr, direction) {
    this->coordinateStr = coordinateStr;
    if(direction[0] == 'W' || direction[0] == 'E')
        this->direction = direction;
    else
        std::cout << "Invalid direction! " << std::endl;
    setCoordinate(coordinateStr);
}
