// output.h

// Author : Byung Ho Lee

// All the functions in this file is for result output.

#ifndef OUTPUT_H
#define OUTPUT_H

#include "student_info.h"

void printTotalScore(student_info* pStdInfo, unsigned int numberOfStudent);
void printCutpint(int number, double* pCutset, student_info* pStdInfo, unsigned int numberOfStudent );

#endif