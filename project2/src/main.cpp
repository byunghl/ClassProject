// main.cpp

/*	Author: Byung Ho Lee
**  Student ID#: 60626811
**	University California Irvine, ICS45C
**
**	Project2: Letter Never Sent
**	Due: February 10, 2014
*/

#include <iostream>
#include <string>

#include "input_requester.h"
#include "parcingutil.h"
#include "evaluation.h"
#include "output.h"


int main() {

	// Part1: request grade artifacts from user.
	std::string numStr = "";
	numStr = getNumberOfElement(numStr);
	unsigned int numberOfGradeArtifactElement = 0;
	numberOfGradeArtifactElement = stringToInteger(numStr);
	grade_artifact* pGradeArtifacts = requestGradeArtifact(numberOfGradeArtifactElement);

	//Part2: request student's information from user.
	std::string numberOfStudentsStr = "";
	numberOfStudentsStr = getNumberOfElement(numberOfStudentsStr);
	unsigned int numberOfStudents = 0;
	numberOfStudents = stringToInteger(numberOfStudentsStr);
	student_info* pStudentInfos = requestStudentInfo(numberOfStudents);

	//Part3: request student's raw socre from user.
	std::string numberOfRawScoresStr = "";
	numberOfRawScoresStr = getNumberOfElement(numberOfRawScoresStr);
	unsigned int numberOfRawScores = stringToInteger(numberOfRawScoresStr);
	requestRawScores(numberOfRawScores, numberOfGradeArtifactElement, pStudentInfos);
	
	// Evaluate total score
	setTotalScore(pGradeArtifacts, numberOfGradeArtifactElement, pStudentInfos, numberOfStudents);
	
	// Print total score
	printTotalScore(pStudentInfos, numberOfStudents);
	
	//Part4 : request cutset point from user. 
	std::string numberOfCutPointStr = "";
	numberOfCutPointStr = getNumberOfElement(numberOfCutPointStr);
	unsigned int numberOfCutsetRange = 4;
	unsigned int numberOfCutPoint = (unsigned int)stringToInteger(numberOfCutPointStr);
	cutset* pCutsets = requestCutSetPoints(numberOfCutPoint, numberOfCutsetRange, pStudentInfos, numberOfStudents);
	

	// Clear Memory
	for(unsigned int i = 0; i < numberOfStudents; i++) {
		delete[] pStudentInfos[i].rawScores;
	}
	for(unsigned int i = 0; i < numberOfCutPoint; i++) {
		delete[] pCutsets[i].aCutsets;
	}

	delete[] pCutsets; 
	delete[] pGradeArtifacts;
	delete[] pStudentInfos;
	// END of Memory Clearing
	
	return 0;
}

