#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
} node;

node *createNode(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int main(){

    node *root = createNode(3);
    node *p = createNode(1);
    node *q = createNode(2);

    root->left = p;
    root->right = q;

    return 0;
}