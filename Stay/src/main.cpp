// main.cpp

/*  Author: Byung Ho Lee
**  Stduent ID: #60626811
**
**  Project #1: Stay (Faraway, So Close!)
**  Due on Monday, January 27, 11:59pm
**
*/

#include "Project1Core.h"

int main() {

    // Program Start Here!
    Location startLocation = getFirstLineInput();
    int numberOfTargetLocation = getSecondLineInput();
    std::vector<Location> targetLocations = getThirdLineInput(numberOfTargetLocation);
    std::vector<Location> resultOfComputation = getComputedResult(startLocation, targetLocations);
    printResult(startLocation, resultOfComputation);
    // END OF PROGRAM

    return 0;
}
