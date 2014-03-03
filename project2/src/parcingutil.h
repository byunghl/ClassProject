// parcingutil.h

// Author : Byung Ho Lee

// All the functions in this file related to parsing values which were inputed by user of this program.

#ifndef PARCINGUTIL_H
#define PARCINGUTIL_H

#include "student_info.h"
#include <string>

int stringToInteger(std::string str);
double stringToDouble(std::string str);
int* generalizedParser(int length, std::string str);
double* generalizedPaserForDouble(int numberOfGradeArtifact, std::string str);
student_info* studentInfoParser(std::string str);

#endif