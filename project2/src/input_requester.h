// input_request.h

// Author : Byung Ho Lee

// All the fucntions in this file are for getting input from the user.

#ifndef INPUT_REQUEST_H
#define INPUT_REQUEST_H

#include "student_info.h"
#include "cutset.h"
#include "grade_artifact.h"

std::string getNumberOfElement(std::string& str);

student_info* requestStudentInfo(int length);

cutset* requestCutSetPoints(unsigned int length, unsigned int numberOfCusetRange, student_info* pStdInfo, unsigned int numberOfStudent);

void requestRawScores(int length, int numberOfGradeArtifact, student_info* pStdInfos );

grade_artifact* requestGradeArtifact(int length);

#endif