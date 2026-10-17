#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

// add student
struct Student *addStudent(struct Student *head, int id, const char *name, int age, float gwa) {

    // allocate memory for new student
    struct Student *newStudent = malloc(sizeof(struct Student));
    
    // fill in the values of your new student
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->gwa = gwa;
    newStudent->next = NULL;    // end of the record
    

    // if no student in record
    if (head == NULL) {
        return newStudent;
    }

    // loop in the list until the end and connect the newStudent in it
    struct Student *current = head;
    while (current->next != NULL) {     // while the next node isnt null
        current = current->next;        // move your current node up the list
    }                                   // end the loop if the next node is NULL
    current->next = newStudent;         // connect your new student to the tail node

    return head;    // return your updated record
}

// free memory
void freeAll(struct Student *head) {
    struct Student *current = head;     // a marker to walk through the record 
    struct Student *next = NULL;        // a node for storing the next node in the record
    while (current != NULL) {           // loop in the record
        next = current->next;           // store the next node so you dont lose it
        free(current);                  // free the current node
        current = next;                 // move on the next node
    }
}

// display menu
void menu() {
    printf("\t[1] Add Student\n");
    printf("\t[0] Exit\n");
};