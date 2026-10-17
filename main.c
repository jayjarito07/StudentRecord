#include <stdio.h>
#include "student.h"

int main(void) {
    struct Student *head = NULL;
    int choice;

    printf("\n==========================\n");
    printf("==STUDENT RECORD MANAGER==");
    printf("\n==========================\n");
    do {
        menu();
        printf("--------------------------\n");
        printf("Choice: ");
        scanf("%d", &choice);
    
        printf("\n--------------------------\n");
        if (choice == 1) {
            int id, age;
            char name[50];
            float gwa;

            printf("ID: ");
            scanf("%d", &id);
            printf("Name: ");
            scanf("%.49s", &name);
            printf("Age: ");
            scanf("%d", &age);
            printf("GWA: ");
            scanf("%f", &gwa);
            
            addStudent(head, id, name, age, gwa);
        }
    } while (choice != 0); printf("THANK YOU FOR USING STUDENT RECORD MANAGER!");
    return 0;
}