#include <stdio.h>
#include "student.h"
#include <string.h>
#include <windows.h>

int main(void) {
    struct Student *head = NULL;
    int choice;

    printf("\n====================================\n");
    printf("=======STUDENT RECORD MANAGER=======");
    printf("\n====================================\n");
    do {
        menu();
        printf("------------------------------------\n");
        printf("Choice: ");
        scanf("%d", &choice);
    
        if (choice == 1) {
            int id, age;
            char name[50];
            float gwa;

            printf("------------------------------------\n");
            printf("ID: ");
            scanf("%d", &id);
            printf("Name: ");
            scanf("%49s", name);
            printf("Age: ");
            scanf("%d", &age);
            printf("GWA: ");
            scanf("%f", &gwa);
            
            head = addStudent(head, id, name, age, gwa);
        }
        printf("------------------------------------\n");
    } while (choice != 0);
    printf("Exiting Program");
    fflush(stdout);

    for (int i = 0; i < 3; i++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }
    Sleep(500);
    printf("\nExited Successfully.\n");

    freeAll(head);
    return 0;
}