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

void postOrder(node *root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    //  Tree:
    
    //     4
    //    / \
    //   1   6
    //  / \
    // 5   2

    node *p = createNode(4);
    node *p1 = createNode(1);
    node *p2 = createNode(6);   
    node *p3 = createNode(5);
    node *p4 = createNode(2);


    p->left = p1;
    p->right = p2;
    
    p1->left = p3;
    p1->right = p4;

    postOrder(p);

    return 0;
}