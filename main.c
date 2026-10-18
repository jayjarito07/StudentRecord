#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "student.h"
#define BUFFER_SIZE 4096
#define NAME_SIZE 100

int main(void) {
    printf("Loading file");
    fflush(stdout);
    dots();
    struct Student *head = loadReport();
    int choice = 0;

    printf("====================================\n");
    printf("====== STUDENT RECORD MANAGER ======\n");
    printf("====================================\n\n");
    do {
        menu();
        do {
            choice = scanInt("Choice: ");
            if (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
                printf("Invalid Choice.\n");
                printf("------------------------------------\n");
            }
        } while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
    
        if (choice == 1) {
            int id, age;
            char name[NAME_SIZE];
            float gwa;

            printf("------------------------------------\n");
            id = scanInt("ID: ");
            do {
                if (id <= 0) {
                    printf("Not a valid ID. Try another.\n");
                    printf("------------------------------------\n");
                }
                if(findStudent(head, id) != NULL) {
                    printf("ID already exists. Try another.\n");
                    printf("------------------------------------\n");
                }
            } while (findStudent(head, id) != NULL || id <= 0);

            printf("Name: ");
            fgets(name, NAME_SIZE, stdin);
            printf("Age: ");
            scanf("%d", &age);
            printf("GWA: ");
            scanf("%f", &gwa);
            
            head = addStudent(head, id, name, age, gwa);
            printf("Student added.\n");
            saveReport(head);
        }

        else if (choice == 2) {
            printf("------------------------------------\n");
            displayStudents(head);
        }

        else if (choice == 3) {
            int id = 0;

            do {
                printf("------------------------------------\n");
                printf("Enter the Student ID: ");
                scanf("%d", &id);

                if (id <= 0) { printf("Invalid ID.\n"); }
            } while (id <= 0);
            
            struct Student *foundStudent = findStudent(head, id);
            printf("------------------------------------\n");
            printf("Searching for Student #%d", id);
            fflush(stdout);
            dots();
            if (foundStudent != NULL) {
                printf("Student found.\n\n");
                printf("ID: %d\n", foundStudent->id);
                printf("Name: %s\n", foundStudent->name);
                printf("Age: %d\n", foundStudent->age);
                printf("GWA: %.2f\n", foundStudent->gwa);
            }
            else {
                printf("Student not found.\n");
            }
        }

        else if (choice == 4) {
            int id = 0;

            do {
                printf("------------------------------------\n");
                printf("Enter the Student ID: ");
                scanf("%d", &id);

                if (id <= 0) { printf("Invalid ID.\n"); }
            } while (id <= 0);
            
            printf("Searching for student #%d", id);
            fflush(stdout);
            dots();
            if (findStudent(head, id) != NULL) {
                printf("Student #%d found.\n", id);
                Sleep(200);
                printf("Deleting student #%d", id);
                fflush(stdout);
                dots();

                head = deleteStudent(head, id);
                printf("Student #%d successfully deleted.\n", id);
                saveReport(head);
            } 
            else {
                printf("Student not found in the records.\n");
            }
        }

        else if (choice == 5) {
            int id = 0;
            struct Student *found = NULL;

            do {
                printf("------------------------------------\n");
                printf("Enter the student ID: ");
                scanf("%d", &id);

                if (id <= 0) { printf("Invalid ID.\n"); }
            } while (id <= 0);
            found = findStudent(head, id);

            printf("Searching for student #%d", id);
            fflush(stdout);
            dots();

            if (found != NULL) {
                printf("Student #%d found.\n\n", id);
                editStudent(head, found);
                saveReport(head);
            } 
            else {
                printf("Student #%d not found in the records.\n", id);
            }
        }

        printf("------------------------------------\n");
        if (choice != 0) {
            Sleep(2000);
        }
    } while (choice != 0);

    printf("Exiting Program");
    fflush(stdout);
    dots();
    printf("Exited Successfully.\n");

    freeAll(head);
    return 0;
}