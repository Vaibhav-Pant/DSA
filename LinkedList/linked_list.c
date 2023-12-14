#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse_linked_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    free(ptr);
}

struct node *insertfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;
}

struct node *insertAfterNode(struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

struct node *deleteFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *ptr = head;

    int i = 0;
    while (i != index-1)
    {
        ptr = ptr->next;
        i++;
    }

    struct node *q = ptr->next;
    ptr->next = q->next;
    free(q);
}

struct node *deleteLastNode(struct node *head)
{
    struct node* p = head;
    struct node* q = p->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}

struct node *deleteNodeWithValue(struct node *head, int value)
{
    struct node* p = head;
    struct node* q = head;

    while(q->data != value && q->next != NULL)
    {
        p = q;
        q = q->next;
    }

    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Element not in list.\n");
    }
}


int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *insert;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = NULL;

    // print the linked list
    traverse_linked_list(head);
    printf("\n");

    // insert at first and print:

    // head = insertfirst(head, 89);
    // traverse_linked_list(head);
    // printf("\n");

    // insert at a given index and print:

    // insertAtIndex(head, 90, 2);
    // traverse_linked_list(head);
    // printf("\n");

    // insert at end and print:

    // insertAtEnd(head, 91);
    // traverse_linked_list(head);
    // printf("\n");

    // insert after a node and print:

    // insertAfterNode(second, 92);
    // traverse_linked_list(head);
    // printf("\n");

    // delete at first and print:

    // head = deleteFirst(head);
    // traverse_linked_list(head);

    // delete at given index a1d print:

    // deleteAtIndex(head, 2);
    // traverse_linked_list(head);


    // delete last node and print:
    // deleteLastNode(head);
    // traverse_linked_list(head);

    // delete node with given value:

    // deleteNodeWithValue(head, 7);
    // traverse_linked_list(head);
    // printf("\n");


    return 0;
}
