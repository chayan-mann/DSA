// C CODE TO CONCAT AND MERGE LNK LIST


#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
} *first=NULL,*second=NULL,*third=NULL;

void create1(int A[], int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last=t;
    }
}
void create2(int A[], int n)
{
    int i;
    struct Node *t,*last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second -> data = A[0];
    second -> next = NULL;
    last = second;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last=t;
    }
}

void create3(int A[], int n)
{
    int i;
    struct Node *t,*last;
    third = (struct Node *)malloc(sizeof(struct Node));
    third -> data = A[0];
    third -> next = NULL;
    last = third;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p ->data);
        p=p->next;
    }
}
void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next!=NULL)
    {
        p = p->next;
        p ->next = q;
    }
}

int main ()
{	
int A[] = {3,5,7,10,15};
int B []= {20,30,40,50,60};
create1(A,5);
create2(B,5);
Concat(first,second);


printf("Third\n");
Display(third);
printf("\n\n"); 
return 0;
}