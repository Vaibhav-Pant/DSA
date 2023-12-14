/*

Binary search tree:
 > It is a type of binary tree!

Properties:
1) All nodes of the left subtree is lesser.
2) All nodes of the rigt subtree is greater.
3) No duplicate nodes.
4) Left and right subtrees are also binary trees.
**5) Inorder traversal of a BST given an ascending order array.

ex.
        7
       / \          Not a binary tree.
      3   6         right subtree < 7,   i.e 6 < 7


        7
       / \          A binary tree.
      3   8         3 < 7 && 8 > 7

             9
           /  \
         /     \
       /        \           This is a BInary tree. It satisfy all the conditions.
      6          15
     / \        / \
    4   8      13   16
              / \
             11   14

*/

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

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(node *root)
{
    static node *prev = NULL;
    if(root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }

        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
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
    //          11   14

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

    r1->left = r11;
    r1->right = r12;

    r11->left = r111;
    r11->right = r112;

    // inOrder(root);
    // printf("%d \n",isBST(root));
}