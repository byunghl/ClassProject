// Position.h

#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position {

    protected:
        std::string coordinateStr;
        std::string direction;
        double coordinate;
    public:
        Position();
        Position(std::string coordinateStr, std::string direction); 
        void setCoordinateStr(std::string coordinateStr);
        void setCoordinate(std::string coordinateStr);
        void setDirection(std::string direction);
        std::string getCoordinateStr() const;
        double getCoordinate() const;
        std::string getDirection() const;
        std::string print() const;
};

#endif