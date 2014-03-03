// Location.cpp


#include "Location.h"

Location::Location() {
    //DO NOTHING
}
Location::Location(Latitude latitude, Longitude longitude, std::string new_locationName) {  
    this->latitude = latitude;
    this->longitude = longitude;
    this->nameOfLocation = new_locationName;
}

void Location::setLatitude(Latitude latitude) {
    this->latitude = latitude;
} 

void Location::setLongitude(Longitude longitude) {
    this->longitude = longitude;
}

void Location::setNameOfLocation(std::string nameOfLocation) {
    this->nameOfLocation = nameOfLocation;
}

Latitude Location::getLatitude() {
    return latitude;
}

Longitude Location::getLongitude(){
    return longitude;
}

std::string Location::getNameOfLocation() {
    return nameOfLocation;
}

std::string Location::toString() {
    return getLatitude().print() +" " + getLongitude().print() + getNameOfLocation();
}
