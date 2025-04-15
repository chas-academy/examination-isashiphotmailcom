#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_STUDENTS 5
#define NUM_EXAMS 13
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float scores[NUM_EXAMS];
    float average;
} Student;

// Function to capitalize the first letter of a name
void capitalize(char* name) {
    if (name[0] != '\0') {
        name[0] = toupper(name[0]);
        for (int i = 1; name[i] != '\0'; i++) {
            name[i] = tolower(name[i]);
        }
    }
}

int main() {
    Student students[NUM_STUDENTS];
    float totalAverage = 0;
    int highestIndex = 0;
    
    
    // Student 1: Alice
    strcpy(students[0].name, "alice");
    float aliceScores[NUM_EXAMS] = {8, 9, 7, 6, 10, 9, 8, 7, 10, 10, 9, 10, 8};
    float aliceSum = 0;
    for (int j = 0; j < NUM_EXAMS; j++) {
        students[0].scores[j] = aliceScores[j];
        aliceSum += aliceScores[j];
    }
    students[0].average = aliceSum / NUM_EXAMS;
    
    // Student 2: Bob
    strcpy(students[1].name, "bob");
    float bobScores[NUM_EXAMS] = {5, 5, 6, 4, 5, 6, 5, 5, 4, 6, 5, 5, 4};
    float bobSum = 0;
    for (int j = 0; j < NUM_EXAMS; j++) {
        students[1].scores[j] = bobScores[j];
        bobSum += bobScores[j];
    }
    students[1].average = bobSum / NUM_EXAMS;
    
    // Student 3: Charlie
    strcpy(students[2].name, "charlie");
    float charlieScores[NUM_EXAMS] = {10, 9, 9, 10, 10, 9, 9, 10, 9, 10, 10, 9, 10};
    float charlieSum = 0;
    for (int j = 0; j < NUM_EXAMS; j++) {
        students[2].scores[j] = charlieScores[j];
        charlieSum += charlieScores[j];
    }
    students[2].average = charlieSum / NUM_EXAMS;
    
    // Student 4: David
    strcpy(students[3].name, "david");
    float davidScores[NUM_EXAMS] = {4, 3, 5, 4, 4, 5, 4, 5, 4, 3, 5, 4, 4};
    float davidSum = 0;
    for (int j = 0; j < NUM_EXAMS; j++) {
        students[3].scores[j] = davidScores[j];
        davidSum += davidScores[j];
    }
    students[3].average = davidSum / NUM_EXAMS;
    
    // Student 5: Eve
    strcpy(students[4].name, "eve");
    float eveScores[NUM_EXAMS] = {7, 6, 7, 8, 7, 6, 7, 7, 6, 7, 8, 7, 6};
    float eveSum = 0;
    for (int j = 0; j < NUM_EXAMS; j++) {
        students[4].scores[j] = eveScores[j];
        eveSum += eveScores[j];
    }
    students[4].average = eveSum / NUM_EXAMS;
    
    // Calculate total average and find highest index
    for (int i = 0; i < NUM_STUDENTS; i++) {
        totalAverage += students[i].average;
        
        if (students[i].average > students[highestIndex].average) {
            highestIndex = i;
        }
    }
    totalAverage /= NUM_STUDENTS;
    
    // 1. Print student with highest average score
    char highestName[MAX_NAME_LENGTH];
    strcpy(highestName, students[highestIndex].name);
    capitalize(highestName);
    printf("%s\n", highestName);
    
    // 2. Print students with below average scores in input order
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (students[i].average < totalAverage) {
            char name[MAX_NAME_LENGTH];
            strcpy(name, students[i].name);
            capitalize(name);
            printf("%s\n", name);
        }
    }
    
    return 0;
}