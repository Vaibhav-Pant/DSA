#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
} queue;

int isEmpty(queue *q)
{
    if (q->rear < q->front)
    {
        return 1;
    }
    return 0;
}

int isFull(queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void inQueue(queue *q)
{
    if (isFull(q))
    {
        printf("Queue full.\n");
    }
    else
    {
        int val;
        printf("Enter element: ");
        scanf("%d",&val);
        q->rear++; 
        q->arr[q->rear] = val;
    }
}

void deQueue(queue *q)
{
    if(isEmpty(q))
    {
        printf("Empty queue\n");
    }
    else
    {
        printf("Element removed: %d\n",q->arr[q->front]);    
        q->front++;
    }
}

void count(queue *q)
{
    printf("Front: %d\n",q->front);
    printf("Rear : %d\n",q->rear);
    printf("Count: %d\n",q->rear - q->front + 1);
}

void display(queue *q)
{
    if(isEmpty(q))
    {
        printf("Empty queue\n");
    }
    else{
        printf("Queue:\n");
        for(int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}



int main()
{
    queue q;
    q.size = 100;
    q.front = 0;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));


    while(true)
    {
        int n;
        scanf("%d", &n);

        if(n == 1)
        {
            inQueue(&q);
        }
        else if(n == 2)
        {
            deQueue(&q);
        }

        else if(n == 3)
        {
            count(&q);
        }
        else if(n == 4)
        {
            display(&q);
        }
        else
        {
            break;
        }
    }
    return 0;
}
