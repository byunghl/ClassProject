// Position.cpp

#include "Position.h"
#include <iostream>


Position::Position() {
    // DO NOTHING
}

Position::Position(std::string coordinateStr, std::string direction) {
    this->coordinateStr = coordinateStr;
    this->direction = direction;
    setCoordinate(coordinateStr);
}

void Position::setCoordinateStr(std::string coordinateStr) {
    this->coordinateStr = coordinateStr;
}
void Position::setCoordinate(std::string coordinateStr) { 
    coordinate = atof(coordinateStr.c_str());
}

void Position::setDirection(std::string direction) {
    this->direction = direction;
}

std::string Position::getCoordinateStr() const {
    return coordinateStr;
}

double Position::getCoordinate() const {
    return coordinate;
}

std::string Position::getDirection() const {
    return direction;
}

std::string Position::print() const {
    return getCoordinateStr() + "/" + getDirection();
}