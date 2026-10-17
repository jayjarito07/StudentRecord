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
struct Student *findStudent(struct Student *head, int id);
struct Student *deleteStudent(struct Student *head, int id);
void editStudent(struct Student *head, struct Student *student);

// File handling
int saveToFile(struct Student *head);
struct Student *loadFile(void);

// Functions for display purposes
void menu(void);
void displayStudents(struct Student *head);
void dots(void);
void saveReport(struct Student *head);
void loadReport(struct Student *head);


#endif