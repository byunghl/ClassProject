//student_info.h

// Author : Byung Ho Lee

#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>

// structure for student's information
struct student_info {
    unsigned int studentID;
    std::string nameOfStduent;
    int* rawScores;
    double totalScore;
    char finalLetterGrade;
};

#endif