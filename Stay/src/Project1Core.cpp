// Project1Core.cpp

/*  Author: Byung Ho Lee
**  Stduent ID: #60626811
**
**  Project #1: Stay (Faraway, So Close!)
**  Due on Monday, January 27, 11:59pm
**
*/

#include "Project1Core.h"
#include <cmath>

// Function that gets first line of input and return start location.
Location getFirstLineInput() {
    bool isValid = false;
    std::string rawData = "";
    while(!isValid) {
        std::getline(std::cin, rawData);
        isValid = isValidInput(rawData);    // VALIDATION
    }

    return createLocation(rawData);
}

// Function that gets second line of input and return the inputed value.
int getSecondLineInput() {
    std::string str = "";
    bool isNotValidInput = true;    
    while(isNotValidInput){
        bool isValid = true;
        std::getline(std::cin, str);
        for(int i = 0; i < (int)str.length(); i++) {
            if(isNumber(str[i]) == false) {
                isValid = false; 
            }
        }
        if(isValid && (str.length() != 0)) 
            isNotValidInput = false;
        
    }
    return atoi(str.c_str());
}

// function that gets third line of input and save inputed value in vector then return the vector.
std::vector<Location> getThirdLineInput(int numberOfTarget) {
    bool isValid = false;
    std::string rawData = "";

    std::vector<Location> destinations(numberOfTarget);

    for(int i = 0; i < numberOfTarget; i++) {
        while(!isValid) {
            std::getline(std::cin, rawData);   
            isValid = isValidInput(rawData);
        }
        destinations[i] = createLocation(rawData);
        isValid = false;
    }

    return destinations;
}

// function that computes closest location and farthest location and save it in to vector. 
// index 0 in vector is closest one and index 1 in vector is farthest one. 
std::vector<Location> getComputedResult(Location startLocation, std::vector<Location> locations) {
    
    Location closestLocation = locations[0];
    double distanceOfClosestLocation = getGreatCircleDistanceBetweenTwoLocations(startLocation, locations[0]);
    Location farthestLocation = locations[0];
    double distanceOfFarthestLocation = getGreatCircleDistanceBetweenTwoLocations(startLocation, locations[0]);

    for(int i=1; i < (int)locations.size() ; i++) {
        double distance = getGreatCircleDistanceBetweenTwoLocations(startLocation, locations[i]);
        if(distance > distanceOfFarthestLocation) {
            distanceOfFarthestLocation = distance;
            farthestLocation = locations[i];
        }
        if(distance < distanceOfClosestLocation){
            distanceOfClosestLocation = distance;
            closestLocation = locations[i];
        }
    }

    std::vector<Location> result(2);
    result[0] = closestLocation;
    result[1] = farthestLocation;

    return result;
    
}

// function that prints final result of this program. 
void printResult(Location startLocation, std::vector<Location>& locations) {

    std::printf("Start Location: %s %s (%s)\n", 
        startLocation.getLatitude().print().c_str(),
        startLocation.getLongitude().print().c_str(), 
        startLocation.getNameOfLocation().c_str());

    std::printf("Closest Location: %s %s (%s) (%f miles)\n",
        locations[0].getLatitude().print().c_str(), 
        locations[0].getLongitude().print().c_str(), 
        locations[0].getNameOfLocation().c_str(), 
        getGreatCircleDistanceBetweenTwoLocations(startLocation, locations[0]));
    std::printf("Farthest Location: %s %s (%s) (%f miles)\n", 
        locations[1].getLatitude().print().c_str(), locations[1].getLongitude().print().c_str(), 
        locations[1].getNameOfLocation().c_str(), getGreatCircleDistanceBetweenTwoLocations(startLocation, locations[1]));
    
}

// function that computes distance between two location and return it. 
double getGreatCircleDistanceBetweenTwoLocations(Location startLocation, Location destinationLocation) {

    // startLocation
    std::string latitudeDirectionOfStartLocation = startLocation.getLatitude().getDirection();
    std::string longitudeDirectionOfStartLocation = startLocation.getLongitude().getDirection();

    // IF direction is North, then 1 f direction is South, then -1
    double valueOfLatitudeDirection1 = (latitudeDirectionOfStartLocation == "N") ? 1.0 : -1.0;
    // If direction is East, then 1 ; If direction is West, then -1
    double valueOfLongitudeDirection1 = (longitudeDirectionOfStartLocation == "E") ? 1.0 : -1.0;

    double startLocationLatitude = startLocation.getLatitude().getCoordinate() * valueOfLatitudeDirection1;
    double startLocationLongitude = startLocation.getLongitude().getCoordinate() * valueOfLongitudeDirection1;

    // destinationLocation 
    std::string latitudeDirectionOfDestinationLocation = destinationLocation.getLatitude().getDirection();
    std::string longitudeDirectionOfDestinationLocation = destinationLocation.getLongitude().getDirection();

    // IF direction is North, then 1 ;  If direction is South, then -1
    double valueOfLatitudeDirection2 = (latitudeDirectionOfDestinationLocation == "N") ? 1.0 : -1.0;
    // If direction is East, then 1 ; If direction is West, then -1
    double valueOfLongitudeDirection2 = (longitudeDirectionOfDestinationLocation == "E") ? 1.0 : -1.0;

    double destinationLocationLatitude = destinationLocation.getLatitude().getCoordinate() * valueOfLatitudeDirection2;
    double destinationLocationLongitude = destinationLocation.getLongitude().getCoordinate()* valueOfLongitudeDirection2;

    // Loaction in Radian
    double startLocationLatitudeInRadian = convertDegreeToRadian(startLocationLatitude);
    double destinationLoactionLatitudeInRadian = convertDegreeToRadian(destinationLocationLatitude);
    double startLoactionLongitudeInRadian = convertDegreeToRadian(startLocationLongitude);
    double destinationLoactionLongitudeInRadian = convertDegreeToRadian(destinationLocationLongitude);

    double deltaLatInRadian = destinationLoactionLatitudeInRadian - startLocationLatitudeInRadian;
    double deltaLonInRadian = destinationLoactionLongitudeInRadian - startLoactionLongitudeInRadian;

    double a = std::pow(std::sin(deltaLatInRadian/2.0), 2.0) + 
        std::cos(startLocationLatitudeInRadian) * 
        std::cos(destinationLoactionLatitudeInRadian) * 
        std::pow(std::sin(deltaLonInRadian/2.0), 2.0);

    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));

    const double radiusOfEarthInMiles = 3959.9;
    
    return radiusOfEarthInMiles * c;
}


// Function that convert degree to radian and return the radian.
double convertDegreeToRadian(double operand) {
    const double PI = atan(1.0)*4.0; // 3.14159
    return operand * (PI / 180.0);
}


// Function that creates Object Location which contains location of one place and return the Object.
Location createLocation(std::string rawData) {
    std::string latitudePart = findLatitudePart(rawData);   //Latitude Part
    std::string longitudePart = findLongitudePart(rawData); //Longitude Part
    std::string nameOfLocationPart = findNameOfLocationPart(rawData); // Name of Place Part

    Location location(createLatitude(latitudePart), createLongitude(longitudePart), nameOfLocationPart); 
    
    return location;
}


// Function that creates Object Latitude which contains Latitude information of one place and return the Object.
Latitude createLatitude(std::string latitudePart) {
    std::string coordinatePartOfLatitude = findCoordinatePart(latitudePart);
    std::string directionPartOfLatitude = findDirectionPart(latitudePart);
    Latitude latitude(coordinatePartOfLatitude, directionPartOfLatitude);
    return latitude;
}

// Functions that creates Object Longitude which contains Longitude information of one place and return the Object
Longitude createLongitude(std::string longitudePart) {
    std::string coordinatePart = findCoordinatePart(longitudePart);
    std::string directionPart= findDirectionPart(longitudePart);
    Longitude longitude(coordinatePart, directionPart);
    return longitude;
}

// Varifies latitude part of string is valid or not. 
bool isValidLatitude(std::string str) {
    int firstBackSlashOffset = getBackSlashPosition(0, str);

    if(firstBackSlashOffset == -1) {// STEP1: does '/' exist?
        return false;
    }
    else {
        std::string coordinatePart = findCoordinatePart(str); // LEFT SIDE
        std::string directionPart = str.substr(firstBackSlashOffset+1); 
        if(isValidLatitudeCoordinate(coordinatePart) && isValidLatitudeDirection(directionPart) )
            return true;
        else {
            return false;
        }
    }
}

// Varifies longitude part of string is valid or not. 
bool isValidLongitude(std::string str) {
    
    int firstBackSlashOffset = getBackSlashPosition(0, str);

    if(firstBackSlashOffset == -1) { // STEP1: does '/' exist?
        return false;
    }
    else {
        std::string coordinatePart = findCoordinatePart(str); // LEFT SIDE
        std::string directionPart = str.substr(firstBackSlashOffset+1, 1); 
        //std::cout << "coordinatePart:" << coordinatePart << std::endl;
        //std::cout << "directionPart:" << directionPart << std::endl;
        if(isValidLongitudeCoordinate(coordinatePart) && isValidLongitudeDirection(directionPart) )
            return true;
        else {
            return false;
        }
    }
}
 
// Checks direction in Latitude is right or not. 
bool isValidLatitudeDirection(std::string str) {
    if(str.length() != 1) 
        return false;
    else {
        if( (str[0] == 'N') || (str[0] =='S') ) 
            return true;
        else
            return false;
        
    }
}

// Checks direction in Longitude is right or not.
bool isValidLongitudeDirection(std::string str) {
    if(str.length() != 1) 
        return false;
    else {
        if( (str[0] == 'E') || (str[0] =='W') ) 
            return true;
        else 
            return false;
    }
}

// Checks name of place is inputed or not. If length of string is less than 0, it assumes that name of space is incorect.
bool isValidNameOfPlace(std::string str) {
    if(str.length() == 0)
        return false;
    else
        return true;
}

// checks number part of longitude or latitude is correct or not.
bool isValidCoordinate(std::string str) {   
    for(int i = 0; i < (int)str.length(); i++) {
        if( (isNumber(str[i]) || str[i] == '.' ) ) 
            continue;
        else 
            return false;
    }
    return true;
}


// checks range of latitude is right or not
bool isValidLatitudeCoordinate(std::string latitudeCoordinateStr) {
    
    if(isValidCoordinate(latitudeCoordinateStr)) {
        double coordinate = atoi(latitudeCoordinateStr.c_str());
        if(coordinate >= 0 && coordinate <=90)
            return true;
        else
            return false;
        
    } else 
        return false;
}

// checks range of longitude is right or not
bool isValidLongitudeCoordinate(std::string longitudeCooridnateStr) {
    if(isValidCoordinate(longitudeCooridnateStr)) {
        double coordinate = atoi(longitudeCooridnateStr.c_str());
        if(coordinate >= 0 && coordinate <=180)
            return true;
        else 
            return false;   
    } else 
        return false;
}

// Checks input is in valid form or not. 
bool isValidForm(std::string str) {
    // VALID FORM MUST HAVE TWO EMPTY CHARs which seperate latitude and longtitude.
    int firstEmptyCharOffset = -1;
    int secondEmptyCharOffset = -1;

    firstEmptyCharOffset = getEmptyCharPositionFromString(0, str);

    if(firstEmptyCharOffset != -1)
        secondEmptyCharOffset = getEmptyCharPositionFromString(firstEmptyCharOffset+1,str);
    
    if((firstEmptyCharOffset != -1) && ((secondEmptyCharOffset != -1) && (secondEmptyCharOffset != (str.length() - 1) ) ) )
        return true;
    else
        return false;
}

// returns index of empty char ' '
int getEmptyCharPositionFromString(int start, std::string str) {
    return str.find(" ", start);
}

// returns index of '/' in string. 
int getBackSlashPosition(int start, std::string str) {
    return str.find("/", start);
}

// checks given char is a number or not. 
bool isNumber(const char character) {
    return ( (character >= '0') && (character <= '9') );
}

// 
std::string findCoordinatePart(std::string str) {
    int backSlashOffset = getBackSlashPosition(0, str);
    return str.substr(0,backSlashOffset);
}

// Find Direction(N,W,S,E) and return it. 
std::string findDirectionPart(std::string str) {
    int backSlashOffset = getBackSlashPosition(0, str);
    return str.substr(backSlashOffset+1);
}

// Find latitude part from the input and return latitude string.
std::string findLatitudePart(std::string str) {
    int locationOfFirstEmptyChar = getEmptyCharPositionFromString(0, str);
    std::string latitudeStr = str.substr(0, locationOfFirstEmptyChar);
    return latitudeStr;
}

// Find longitude part from the input and return longitude string.
std::string findLongitudePart(std::string str) {
    int locationOfFirstEmptyChar = getEmptyCharPositionFromString(0, str);
    int locationOfSecondEmptyChar = getEmptyCharPositionFromString(locationOfFirstEmptyChar+1, str);
    int lengthOfLongitudePart = locationOfSecondEmptyChar - locationOfFirstEmptyChar - 1;
    std::string longtitudeStr = str.substr(locationOfFirstEmptyChar+1,lengthOfLongitudePart);
    
    return longtitudeStr;
}

// Find name of location from the input and return string of name of location.
std::string findNameOfLocationPart(std::string str) {
    int locationOfFirstEmptyChar = getEmptyCharPositionFromString(0, str);
    int locationOfSecondEmptyChar = getEmptyCharPositionFromString(locationOfFirstEmptyChar+1, str);
    
    return str.substr(locationOfSecondEmptyChar+1);
}

// Checks user typed input value is valid or not. 
bool isValidInput(std::string str) {
    if( isValidForm(str) ) {
        std::string part1 = findLatitudePart(str);  //Latitude Part
        std::string part2 = findLongitudePart(str); //Longitude Part
        std::string part3 = findNameOfLocationPart(str); // Name of Place Part
        
        if(isValidLatitude(part1) && isValidLongitude(part2) && isValidNameOfPlace(part3)) // IF it is true everthing is fine.
            return true;
        else 
            return false;
    } else 
        return false;
    
}
