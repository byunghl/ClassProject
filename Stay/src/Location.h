// Location.h

#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "Longitude.h"
#include "Latitude.h"

class Location {

public:
    Location();
    Location(Latitude latitude, Longitude longitude, std::string new_locationName);
    void setLatitude(Latitude latitude);
    void setLongitude(Longitude longitude);
    void setNameOfLocation(std::string new_nameOfLocation);
    Latitude getLatitude();
    Longitude getLongitude();
    std::string getNameOfLocation();
    std::string toString();

private:
    Latitude latitude;
    Longitude longitude;
    std::string nameOfLocation;
};

#endif