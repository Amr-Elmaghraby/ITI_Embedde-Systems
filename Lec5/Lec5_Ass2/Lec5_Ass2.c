#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CLASSES 3
#define NUM_STUDENTS 10
#define PASSING_GRADE 50



// Function to calculate statistics
void Statistics(int grades[NUM_CLASSES][NUM_STUDENTS]) {
    int numPassed = 0, numFailed = 0;
    int highestGrade = 0, lowestGrade = 100;
    int totalGrade = 0;

    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_STUDENTS; j++) {
            int grade = grades[i][j];
            if (grade >= PASSING_GRADE) {
                numPassed++;
            } else {
                numFailed++;
            }

            if (grade > highestGrade) {
                highestGrade = grade;
            }

            if (grade < lowestGrade) {
                lowestGrade = grade;
            }

            totalGrade += grade;
        }
    }

    float averageGrade = (float)totalGrade / (NUM_CLASSES * NUM_STUDENTS);

    printf("Number of passed students: %d\n", numPassed);
    printf("Number of failed students: %d\n", numFailed);
    printf("Highest grade: %d\n", highestGrade);
    printf("Lowest grade: %d\n", lowestGrade);
    printf("Average grade: %1.2f\n", averageGrade);
}

int main() {
    int grades[NUM_CLASSES][NUM_STUDENTS];
	grades[0][0]=90;grades[0][1]=80;grades[0][2]=70;grades[0][3]=99;grades[0][4]=95;grades[0][5]=45;grades[0][6]=60;grades[0][7]=76;grades[0][8]=78;grades[0][9]=88;
	grades[1][0]=92;grades[1][1]=81;grades[1][2]=83;grades[1][3]=84;grades[1][4]=79;grades[1][5]=89;grades[1][6]=98;grades[1][7]=62;grades[1][8]=66;grades[1][9]=78;
	grades[2][0]=93;grades[2][1]=94;grades[2][2]=100;grades[2][3]=40;grades[2][4]=61;grades[2][5]=49;grades[2][6]=50;grades[2][7]=100;grades[2][8]=90;grades[2][9]=70;

    // Calculate and display statistics
    Statistics(grades);

    return 0;
}
