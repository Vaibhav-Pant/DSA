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
    if (q->rear == q->front)
    {
        return 1;
    }
    return 0;
}

int isFull(queue *q)
{
    if(q->front == -1 && q->rear != -1)
    {
        if ((q->rear + 1) % q->size ==  0)
        {
            return 1;
        }
        return 0;
    }

    if ((q->rear + 1) % q->size ==  q->front)
    {
        return 1;
    }
    return 0;
}

void inQueue(queue *q)
{
    if (isFull(q))
    {
        printf("Circular Queue is full.\n");
        return;
    }
    int x;
    scanf("%d",&x);
    // if(q->rear == -1 && q->front == -1)
    // {
    //     q->rear  = 0;
    //     q->front = 0;
    //     q->arr[q->rear] = x;
    //     return;
    // }

    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = x;

}

void deQueue(queue *q)
{
    if(q->front == -1)
    {
        printf("Element removed: %d\n",q->arr[q->front+1]);    
        q->front = (q->front + 1) % q->size + 1;
        return;
    }
    if(isEmpty(q))
    {
        printf("Circular queue is empty.\n");
        return;
    }
    printf("Element removed: %d\n",q->arr[q->front]);    
    q->front = (q->front + 1) % q->size;
}

void count(queue *q)
{
    if(q->rear < q->front)
    {
        printf("Count: %d\n",q->size - q->front  + q->rear + 1);
    }
    else if( q->rear >= q->front)
    {
        printf("Count: %d\n",q->rear - q->front );
    }
}

void display(queue *q)
{
    if(isEmpty(q))
    {
        printf("Empty queue\n"); 
    }
    
    if(q->front == -1)
    {
        for(int i = 0; i <= q->rear; i++)
        {
            printf("%d ",q->arr[i]);
        }
        printf("\n");
    }

    else if(q->rear >= q->front)
    {
        for(int i = q->front; i <= q->rear; i++)
        {
            printf("%d ",q->arr[i]);
        }
        printf("\n");
    }

    else
    {
        for(int i = q->front; i < q->size; i++)
        {
            printf("%d ",q->arr[i]);
        }
        for(int i = 0; i <= q->rear; i++)
        {
            printf("%d ",q->arr[i]);
        }
        printf("\n");
    }
        
}

int main()
{
    queue q;
    q.size  =  3;
    q.front = -1;
    q.rear  = -1;
    q.arr   = (int *)malloc(q.size * sizeof(int));

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