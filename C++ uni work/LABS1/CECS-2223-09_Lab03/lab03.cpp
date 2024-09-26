/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 30, 2023
* Topic: Lab 3
* File name: lab03.cpp
* Brian Bonet Medina, 119461
*/
#include "Grades.h"

int main() {
    Grades students[5]; // Creating an array of Grades objects
    int num = 0;
    for (int i = 0; i < 5; i++) {
        int studentNumber = i + 1;
       
        students[i].getScores(studentNumber);
        students[i].printGrades(studentNumber);
    }
    
    printf("\n\n ***** Program developed by Brian Bonet Medina, ID#119461 *****\n");
    system("pause");
    return 0;
}
