#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *createNode(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// void insert(node *root, int value)
// {
//     node *prev = NULL;
//     node *p = root;

//     while(p != NULL)
//     {
//         prev = p;
//         if(value == p->data)
//         {
//             printf("Value already exist in BST.\n");
//             return;
//         }
//         else if(value < p->data)
//         {
//             p = p->left;
//         }
//         else
//         {
//             p = p->right;
//         }
//     }

//     node *new = createNode(value);
//     if(value < prev->data)
//     {
//         prev->left = new;
//     }
//     else
//     {
//         prev->right = new;
//     }

// }


void insert(node *root, int key)
{
    // node *ptr = createNode(key);
    // ptr->left = NULL;
    // ptr->right = NULL;

    node *p = root;
    // node *prev = NULL;
    
    while(p != NULL)
    {   
        // prev = p;
        if(p->data == key)
        {
            printf("Value already exist.\n");
            return;
        }
        if(key < p->data )
        {
            if(p->left != NULL)
            {
                 p = p->left;
            }
            else
            {
                break;
            }
        }
        else if(key > p->data)
        {
            if(p->right != NULL)
            {
                p = p->right;
            }
            else
            {
                break;
            }
        }
    }

    node *ptr = createNode(key);
    if(key < p->data)
    {
        p->left= ptr;
    }
    else
    {
        p->right = ptr;
    }

}


int main()
{

    //          9
    //        /  \
    //      /     \
    //    /        \           This is a BInary tree. It satisfy all the conditions.
    //   6          15
    //  / \        / \
    // 4   8      13   16
    //           / \
               11   14

    node *root = createNode(9);
    node *l1   = createNode(6);
    node *r1   = createNode(15);
    node *l11 = createNode(4);
    node *l12 = createNode(8);
    node *r11 = createNode(13);
    node *r12 = createNode(16);
    node *r111 = createNode(11);
    node *r112 = createNode(14);

    // linking

    root->left = l1;
    root->right = r1;

    l1->left = l11;
    l1->right = l12;

    r1->left = r11;
    r1->right = r12;

    r11->left = r111;
    r11->right = r112;

    insert(root, 7);

    printf("hello: %d\n",root->left->right->left->data);

}