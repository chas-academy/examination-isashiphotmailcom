#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 5
#define NUM_TESTS 13

struct Student {
    char name[50];
    int scores[NUM_TESTS];
    float average;
};

int main(){
    struct Student students[NUM_STUDENTS];
    
    // Alice score result
    strcpy(students[0].name, "Alice");
    int alice_scores[NUM_TESTS] = {8, 9, 7, 6, 10, 9, 8, 7, 10, 10, 9, 10, 8};
    memcpy(students[0].scores, alice_scores, sizeof(alice_scores));

    // Bob score result
    strcpy(students[1].name, "Bob");
    int bob_scores[NUM_TESTS] = {5, 5, 6, 4, 5, 6, 5, 5, 4, 6, 5, 5, 4};
    memcpy(students[1].scores, bob_scores, sizeof(bob_scores));

    // Charlie score result
    strcpy(students[2].name, "Charlie");
    int charlie_scores[NUM_TESTS] = {10, 9, 9, 10, 10, 9, 9, 10, 9, 10, 10, 9, 10};
    memcpy(students[2].scores, charlie_scores, sizeof(charlie_scores));

    // David score result
    strcpy(students[3].name, "David");
    int david_scores[NUM_TESTS] = {4, 3, 5, 4, 4, 5, 4, 5, 4, 3, 5, 4, 4};
    memcpy(students[3].scores, david_scores, sizeof(david_scores));

    // Eve score result
    strcpy(students[4].name, "Eve");
    int eve_scores[NUM_TESTS] = {7, 6, 7, 8, 7, 6, 7, 7, 6, 7, 8, 7, 6};
    memcpy(students[4].scores, eve_scores, sizeof(eve_scores));

    // Calculate average scores for all students
    for (int student = 0; student < NUM_STUDENTS; student++) {
        int sum = 0;
        for (int i = 0; i < NUM_TESTS; i++) {
            sum += students[student].scores[i];
        }
        students[student].average = (float)sum / NUM_TESTS;
    }

    // Calculate total average
    float total_average = 0;
    for (int student = 0; student < NUM_STUDENTS; student++) {
        total_average += students[student].average;
    }
    total_average /= NUM_STUDENTS;

    // Find student with highest average
    int highest_index = 0;
    for (int student = 1; student < NUM_STUDENTS; student++) {
        if (students[student].average > students[highest_index].average) {
            highest_index = student;
        }
    }

    // Print results
    printf("Student Average Scores:\n");
    printf("======================\n");
    for (int student = 0; student < NUM_STUDENTS; student++) {
        printf("%-10s: %.2f\n", students[student].name, students[student].average);
    }
    printf("======================\n");
    printf("\nStudent with highest average score: %s\n", students[highest_index].name);
    
    printf("\nTotal average score: %.2f\n", total_average);
    printf("\nStudents below average:\n");
    printf("======================\n");
    for (int student = 0; student < NUM_STUDENTS; student++) {
        if (students[student].average < total_average) {
            printf("%-10s: %.2f\n", students[student].name, students[student].average);
        }
    }
    printf("======================\n");

    return 0;
} 

