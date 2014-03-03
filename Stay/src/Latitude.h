// Latitude.h

#ifndef LATITUDE_H
#define LATITUDE_H


#include "Position.h"

class Latitude : public Position {

public:
    Latitude();
    Latitude(std::string coordinateStr, std::string direction);

};

#endif