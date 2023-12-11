#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char data;
    struct Node *next;
    int top;
} *top =NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    
    if (t=NULL) {
        printf("Stack is full");}
    else
    {
        t->data =x;
        t->next=top;
        top=t;
    }
}

char pop()
{
    char x =-1;
    struct Node *t;
    if(top==NULL)
    {
        printf("Stack is emplty");
    }
    else
    {
        t=top;
        top= top->next;
        x= t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

char isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]='\0';i++)
    {
        if(exp[i]=='(')
            push (exp[i]);
        else if(exp[i]==')')
        {
            if(top=NULL)
                return 0;
            pop();
        }
    }
    if(top=NULL)
        return 1;
    else
        return 0;
}
int main ()
{	
    char *exp = "((a+b)*(c-d))";

    printf("%d", isBalanced(exp));
    printf("hello world");

return 0;
}