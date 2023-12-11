// A Circular Queue is an extended version of a normal queue where the last element of the queue is connected to the first element of the queue forming a circle.
// In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we can not insert the next element even if there is a space in front of queue.
// Time Complexity: 
// Enqueue: O(1) because no loop is involved for a single enqueue.
// Dequeue: O(1) because no loop is involved for one dequeue operation.




#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
    /* data */
};

void create(struct Queue *q, int size)
{
    q->size=size;
    q->front = q->rear = 0;
    q-> Q = (int *)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("The queue is full");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        printf("The queue is empty");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
        /* code */
    } while (i!=(q.rear+1)%q.size);
    
    printf("\n");
}

int main ()
{
    struct Queue q;
    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);

    Display(q);

    printf("%d", dequeue(&q));
return 0;
}