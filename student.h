#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int id;
    char name[50];
    int age;
    float gwa;
    struct Student *next;
};

// Functions for program features
struct Student *addStudent(struct Student *head, int id, const char *name, int age, float gwa);
void freeAll(struct Student *head);

// Functions for display purposes
void menu();


#endif