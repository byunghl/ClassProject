// evaluation.cpp

// Author : Byung Ho Lee

#include "evaluation.h"

#include <iostream>


// This function calculates total score of student and save total score information into student_info dynamic array.
void setTotalScore(grade_artifact* pGradeArtifact, unsigned int numberOfGradeArtifact, 
	student_info* pStdInfo, unsigned int numberOfStudents) {
	
	double totalScore = 0.0;
	
	// access to each student's record
	for(unsigned int i = 0; i < numberOfStudents; i++) {
		
		int* tempRawScores = pStdInfo[i].rawScores; // holds a student's raw score info
		
		for(unsigned int scoreCounter = 0; scoreCounter < numberOfGradeArtifact; scoreCounter++) {
			
			int aScore = tempRawScores[scoreCounter];

			totalScore += getEachScaledScore(aScore, pGradeArtifact[scoreCounter]);

		}

		pStdInfo[i].totalScore = totalScore;
		totalScore = 0.0;
	}

}

// This function calculates scaled grade and return it.
double getEachScaledScore(int score, grade_artifact gradeArtifact) {
	
	return (double)score / (double)gradeArtifact.possibleScore * (double)gradeArtifact.weight;

}

// This function evaluation final course letter grade using student's total score and cutset, then return the final letter grade.
char letterGradeCalculator(double* pCutset, double totalScore) {
	char letterGrade = ' ';
	if(totalScore >= pCutset[0]) 
		letterGrade = 'A';
	else if(totalScore >= pCutset[1])
		letterGrade = 'B';
	else if(totalScore >= pCutset[2])
		letterGrade = 'C';
	else
		letterGrade = 'F';

	return letterGrade;
}

// This function saves final letter grade into student_info dynamic array.
void setFinalLetterGrade(double* pCutset, student_info* pStdInfo, unsigned int numberOfStudent) {

	for(int i = 0; i < numberOfStudent;i++) {	
		pStdInfo[i].finalLetterGrade = letterGradeCalculator(pCutset, pStdInfo[i].totalScore);
	}

}

