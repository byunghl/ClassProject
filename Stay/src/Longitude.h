// Longitude.h
#ifndef LONGITUDE_H
#define LONGITUDE_H

#include "Position.h"

class Longitude : public Position {

public:
    Longitude();
    Longitude(std::string coordinateStr, std::string direction);

};

#endif