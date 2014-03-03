// evalutation.h

// Author : Byung Ho Lee

#ifndef EVALUATION_H
#define EVALUATION_H

#include "grade_artifact.h"
#include "student_info.h"

// FUNCTION DECLARATIONS
void setTotalScore(grade_artifact* pGradeArtifact, unsigned int numberOfGradeArtifact, 
    student_info* pStdInfo, unsigned int numberOfStudents);
double getEachScaledScore(int score, grade_artifact gradeArtifact);
void setFinalLetterGrade(double* pCutset, student_info* pStdInfo, 
    unsigned int numberOfStudent);




#endif