#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
// Global declaration 
int count = 0; 
  
// Structure declaration 
struct node { 
    struct node* prev; 
    int ssn; 
    long int phno; 
    float sal; 
    char name[20], dept[10], desg[20]; 
    struct node* next; 
} * h, *temp, *temp1, *temp2, *temp4; 
  
// Function to create node 
void create() 
{ 
    int ssn; 
    long int phno; 
    float sal; 
    char name[20], dept[10], desg[20]; 
    temp = (struct node*)malloc(sizeof(struct node)); 
    temp->prev = NULL; 
    temp->next = NULL; 
    printf("\n enter ssn, name, depart"
           "ment, designation, salary "
           "and phno of employee:\n"); 
    scanf("%d %s %s %s %f %ld", 
          &ssn, name, dept, desg, 
          &sal, &phno); 
    temp->ssn = ssn; 
    strcpy(temp->name, name); 
    strcpy(temp->dept, dept); 
    strcpy(temp->desg, desg); 
    temp->sal = sal; 
    temp->phno = phno; 
    count++; 
} 
  
// Function to insert at beginning 
void insertbeg() 
{ 
    // If DLL is empty 
    if (h == NULL) { 
        create(); 
        h = temp; 
        temp1 = h; 
    } 
  
    // Else create a new node and 
    // update the links 
    else { 
        create(); 
        temp->next = h; 
        h->prev = temp; 
        h = temp; 
    } 
} 
// Function to delete at end 
int deleteend() 
{ 
    struct node* temp; 
    temp = h; 
    if (temp == NULL) { 
        printf("list is empty\n"); 
        return 0; 
    } 
    if (temp->next == NULL) { 
        printf("%d %s %s %s %f %ld\n", 
               temp->ssn, temp->name, 
               temp->dept, temp->desg, 
               temp->sal, temp->phno); 
        free(temp); 
        h = NULL; 
    } 
    else { 
        temp = temp1; 
        temp2 = temp1->prev; 
        temp2->next = NULL; 
        printf("%d %s %s %s %f %ld\n", 
               temp->ssn, temp->name, 
               temp->dept, temp->desg, 
               temp->sal, temp->phno); 
        free(temp); 
        temp1 = temp2; 
    } 
    count--; 
    return 0; 
} 
void employerDetails() 
{ 
    int ch, n, i; 
    h = NULL; 
    temp = temp1 = NULL; 
    
    