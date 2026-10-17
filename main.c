#include <stdio.h>
#include "student.h"
#include <string.h>
#include <windows.h>

int main(void) {
    struct Student *head = NULL;
    int choice;

    printf("\n====================================\n");
    printf("====== STUDENT RECORD MANAGER ======");
    printf("\n====================================\n");
    do {
        menu();
        printf("\nChoice: ");
        scanf("%d", &choice);
    
        if (choice == 1) {
            int id, age;
            char name[50];
            float gwa;

            printf("------------------------------------\n");
            do {
                printf("ID: ");
                scanf("%d", &id);

                if (id <= 0) {
                    printf("Not a valid ID. Try another.\n"); 
                    printf("------------------------------------\n");
                }
                else if(findStudent(head, id) != NULL) {
                    printf("ID already exists. Try another.\n");
                    printf("------------------------------------\n");
                }
            } while (findStudent(head, id) != NULL || id <= 0);
            
            printf("Name: ");
            scanf("%49s", name);
            printf("Age: ");
            scanf("%d", &age);
            printf("GWA: ");
            scanf("%f", &gwa);
            
            head = addStudent(head, id, name, age, gwa);
            printf("Student added.\n");
        }

        if (choice == 2) {
            printf("------------------------------------\n");
            displayStudents(head);
        }

        if (choice == 3) {
            int id = 0;

            do {
                printf("------------------------------------\n");
                printf("Enter the Student ID: ");
                scanf("%d", &id);

                if (id <= 0) { printf("Invalid ID.\n"); }
            } while (id <= 0);
            
            struct Student *foundStudent = findStudent(head, id);
            printf("------------------------------------\n");
            printf("Finding student");
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