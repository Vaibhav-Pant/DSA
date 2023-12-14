// Breadth first search ALgorightm

/*
Algo BFS( G{V,E} and source node s in V)
{
    Mark all nodes v in V as unvisited;
    Mark source node s as visited;
    enQueue(Q,s) // Add s in queue;

    while(Q is not empty)
    {
        u = deQueue(Q);
        for each unvisited neighbour v of u
        {
                mark v as visited;
                enQueue(Q,v);
        }
    }
}
*/



//Code:

#include <stdio.h>
#include <stdlib.h>


// Queue Implementation

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

void enQueue(queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue full.\n");
    }
    else
    {
        q->rear++; 
        q->arr[q->rear] = val;
    }
}

int deQueue(queue *q)
{
    int a = 0;
    if(isEmpty(q))
    {
        printf("Empty queue\n");
    }
    else
    {
        a =  q->arr[q->front];
        q->front++;
        return a;
    }
}


int main()
{
    queue q;
    q.size = 100;
    q.front = 0;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));


    // BFS implementation 

    //         0 -- 1
    //         | \  |
    //         |  \ |
    //         2 -- 3
    //         \  /
    //          4   
    //         / \
    //        5   6

    int s = 2;
    int node;
    int visited[7] = {0,0,0,0,0,0,0};

    int a[7][7] = {
        
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("%d ",s);
    visited[s] = 1;
    enQueue(&q, s);

    while(!isEmpty(&q))
    {
        node = deQueue(&q);
        for(int i = 0; i < 7; i++)
        {
            if(a[node][i] == 1 && visited[i] == 0)
            {
                printf("%d ",i);
                visited[i] = 1;
                enQueue(&q,i);
            }
        }

    }



    return 0;
}
