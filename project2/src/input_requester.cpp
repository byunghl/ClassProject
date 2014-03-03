// input_requester.cpp

// Author : Byung Ho Lee

#include "input_requester.h"
#include "parcingutil.h"
#include "output.h"
#include <iostream>
#include <string>

// request user to input number of elements for each input part
std::string getNumberOfElement(std::string& str) {

	getline(std::cin, str);

	return str;

}

// request user to input student information without prompt.
student_info* requestStudentInfo(int length) {
	std::string studentInfo;
	student_info* arr = new student_info[length];

	for(int i = 0; i < length; i++) {
		std::getline(std::cin, studentInfo);
		student_info* aStudentInfo = studentInfoParser(studentInfo);
		arr[i].studentID = aStudentInfo->studentID;
		arr[i].nameOfStduent = aStudentInfo->nameOfStduent;
		delete aStudentInfo;
	}
	return arr;
}
// request user to input cutset information without prompt.
// Every time this program gets one cutset inforamtion, it prints out student's final grade information.
cutset* requestCutSetPoints(unsigned int length, unsigned int numberOfCusetRange, student_info* pStdInfo, unsigned int numberOfStudent) {

	std::string aCutSetPointsStr = "";
	cutset* arr = new cutset[length];
	
	for(unsigned int i = 0; i < length; i++) {
		std::getline(std::cin, aCutSetPointsStr);
		arr[i].aCutsets = generalizedPaserForDouble(numberOfCusetRange, aCutSetPointsStr);
		printCutpint(i+1, arr[i].aCutsets, pStdInfo, numberOfStudent ); // OUTPUT FUNCTION CALL
	}
	
	return arr;
}

// request user to input raw scores information without prompt.
void requestRawScores(int length, int numberOfGradeArtifact, student_info* pStdInfos ) {
	std::string inputedStr = "";
	int* pPointsArr = NULL;
	
	for(int i = 0; i < length; i++) {
		std::getline(std::cin, inputedStr); 
		int firstEmptyOffset = inputedStr.find(" ", 0); 
		std::string idPartStr = inputedStr.substr(0, firstEmptyOffset); 
		int idNo = stringToInteger(idPartStr);
		std::string pointsParts = inputedStr.substr(firstEmptyOffset+1); 
	
		pPointsArr = generalizedParser(numberOfGradeArtifact, pointsParts); 
		
		for(int j = 0; j < length; j++) {
			if(idNo == pStdInfos[j].studentID) { 
				pStdInfos[j].rawScores = new int[numberOfGradeArtifact]; 
				for(int index=0; index < numberOfGradeArtifact; index++)
				{
					pStdInfos[j].rawScores[index] = pPointsArr[index]; 
				}
			}
		}
		
		delete[] pPointsArr;
	}

}
// request user to input graded arttifacts information without prompt.
grade_artifact* requestGradeArtifact(int length) {
	std::string possibleScoreStr;
	std::getline(std::cin, possibleScoreStr);
	
	std::string weightStr;
	std::getline(std::cin, weightStr);

	grade_artifact* pArr = new grade_artifact[length];
	int* pPossibleGrades = generalizedParser(length, possibleScoreStr); 
	int* pWeights = generalizedParser(length, weightStr);

	for(int i = 0; i < length; i++) {
		pArr[i].possibleScore = pPossibleGrades[i];
		pArr[i].weight = pWeights[i];
	}

	delete[] pPossibleGrades;	// CLEAR MEMORY
	delete[] pWeights;			// CELAR MEMORY

	return pArr;

}