#include<stdio.h>
#include<stdlib.h>

#ifndef MY_HEADER_H
# define MY_HEADER_H


struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
    /* data */
};

void create(struct Queue *q, int size)
{
    q->size=size;
    q->front = q->rear = 0;
    q-> Q = (Node **)malloc(q->size*sizeof(Node *));
}
void enqueue(struct Queue *q,Node * x)
{
    if((q->rear+1)%q->size==q->front){
        printf("The queue is full");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

Node * dequeue(struct Queue *q)
{
    Node * x=NULL;
    if(q->front==q->rear)
        printf("The queue is empty");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}


#endif

