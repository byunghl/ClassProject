// Project1Core.h

#ifndef PROJECT1CORE_H
#define PROJECT1CORE_H

#include "Location.h"
#include <iostream>
#include <vector>

// Function Declaration
Location getFirstLineInput();
int getSecondLineInput();
std::vector<Location> getThirdLineInput(int numberOfTarget);

double getGreatCircleDistanceBetweenTwoLocations(Location startLocation, Location destinationLocation);
double convertDegreeToRadian(double operand);
std::vector<Location> getComputedResult(Location startLocation, std::vector<Location> locations) ;
void printResult(Location startLocation, std::vector<Location>& locations);

bool isValidLatitude(std::string str);
bool isValidLongitude(std::string str);
bool isValidCoordinate(std::string str);
bool isValidLatitudeCoordinate(std::string latitudeCoordinateStr);
bool isValidLongitudeCoordinate(std::string longitudeCooridnateStr);
bool isValidLatitudeDirection(std::string str);
bool isValidLongitudeDirection(std::string str);

Location createLocation(std::string rawData);
Latitude createLatitude(std::string latitudePart);
Longitude createLongitude(std::string longitudePart);

std::string findLatitudePart(std::string str);
std::string findLongitudePart(std::string str);
std::string findCoordinatePart(std::string str);
std::string findNameOfLocationPart(std::string str);
std::string findDirectionPart(std::string str);

bool isValidInput(std::string str);
bool isValidForm(std::string str);
bool isNumber(const char character);
int getBackSlashPosition(int start, std::string str);
int getEmptyCharPositionFromString(int start, std::string str);

#endif