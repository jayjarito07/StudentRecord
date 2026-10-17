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
            } 
            else {
                printf("Student #%d not found in the records.\n", id);
            }
        }

        else if(choice != 0) { 
            printf("------------------------------------\n");
            printf("INVALID CHOICE.\n"); 
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