#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    // struct Node *parent;
} node;

node *createNode(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    // ptr->parent = NULL;
    return ptr;
}

// IOPred is rightmost element of left subtree
// IOSucc is leftmpst  element of right subtree
node *inOrderPredecessor(node *root, int value)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// node *inOrderSuccecessor(node *root)
// {
//     if(root->left == NULL && root->right == NULL)
//     {
//         node *ptr = root->parent;
//         while(ptr != NULL && root == ptr->right)
//         {
//             root = ptr;
//             ptr = ptr->parent;
//         }
//         return ptr;
//     }

//     root = root->right;
//     while(root->left != NULL)
//     {
//         root = root->left;
//     }
//     return root;
// }

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

node *delete(node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->data == value)
    {
        free(root);
        return NULL;
    }
    if (root->data > value)
    {
        root->left = delete (root->left, value);
    }
    else if (root->data < value)
    {
        root->right = delete (root->right, value);
    }
    else
    {
        node *iPre = inOrderPredecessor(root, value);
        root->data = iPre->data;
        root->left = delete (root->left, iPre->data);
    }
    return root;
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
    node *l1 = createNode(6);
    node *r1 = createNode(15);
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
    // l1->parent = root;

    r1->left = r11;
    r1->right = r12;
    // r1->parent = root;

    r11->left = r111;
    r11->right = r112;
    // r11->parent = r1;

    // l11->parent = l1;
    // l12->parent = l1;

    // r111->parent = r11;
    // r112->parent = r11;

    inOrder(root);
    printf("\n");
    delete (root, 13);
    printf("\n");
    inOrder(root);
    printf("\n");
    printf("%d\n", root->data);

    // node *ptr= inOrderSuccecessor(root->right->right);
    // printf("data: %d\n",ptr->data);

    return 0;
}