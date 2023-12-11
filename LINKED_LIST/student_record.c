#include <stdio.h>
#include <stdlib.h>

struct student
{ char name[30];
  char dob[11]; 
  char fathername[30];
  char contactnumber[20];
  struct student *NEXT;
};

struct student *head = NULL;
struct student *tail = NULL;

void addStudent()
{
	struct student *temp = malloc(sizeof(struct student));

	getchar();
	printf("\nEnter name of the student : ");
	scanf("%[^\n]s", temp->name);
	getchar();
	printf("\nEnter DOB (MM/DD/YYYY) : ");
	scanf("%s", temp->dob);
	getchar();
	printf("\nEnter father name : ");
	scanf("%[^\n]s", temp->fathername);
	getchar();
	printf("\nEnter contact no : ");
	scanf("%s", temp->contactnumber);
	temp->NEXT = NULL;

	if(head == NULL)  /* it means linked list is empty: no record */
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->NEXT = temp;
		tail = temp;
		getchar();
	} }

void displayAllStudents()
{
struct student *temp = head;

if(head == NULL)
	printf("\nNo record: Linked list empty!!");
else
{
	while(temp!=NULL)
	{
		printf("\nName : %s", temp->name);
		printf("\nDOB : %s", temp->dob);
		printf("\nfather name : %s", temp->fathername);
		printf("\nContact no : %s", temp->contactnumber);
		temp = temp->NEXT;
                if(temp!=NULL){
			printf("\n-----------------------------------------");
			printf("\nPress enter key for the next record..");
			getchar();
		}
	} } }

int main()
{
int choice = 1;
while(choice !=0 ){
	printf("\n***** Main Menu *****");
	printf("\n\tPress 1 to add stdudent");
	printf("\n\tPress 2 to display add stduents");
	printf("\n\tPress 0 to exit..");
	printf("\nEnter you choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: addStudent(); break;
		case 2: displayAllStudents(); break;
		default : printf("\nInvalid choice..Please input a valid no");
			  getchar();
	}
}
return 0;
}