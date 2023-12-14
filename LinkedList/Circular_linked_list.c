#include<stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *front = NULL;
node *rear  = NULL;

void traverse()
{
    node *p = front;
    while(p->next !=  front)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}

void enQueue(int value)
{
    node *ptr = (node*) malloc(sizeof(node));
    if(ptr == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        ptr->data = value;
        if(front == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
        }
        rear = ptr;
        rear->next = front;
    }
}

void deQueue()
{
    node *p = front;
    if(front == NULL)
    {
        printf("Queue empty");
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(p);
    }
}


int main()
{

    enQueue(1);
    enQueue(2);
    enQueue(3);
    traverse();
    deQueue();
    traverse();
    enQueue(4);
    enQueue(5);
    traverse();
    deQueue();
    deQueue();
    traverse();

    return 0;
}