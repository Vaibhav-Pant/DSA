/*

In order to balance an AVL tree after insertion, apply the 
following rules:-

**We have to search for the imbalanced node first.


1) For a left-Left insertion --> Right rotate once w.r.t the
first imbalanced nodoe.

Example:-
-->Insert 4

             11                                                                     9
            /  \        Right_Rotate w.r.t to 11                                   / \
           9    18     (First imbalanced node = 11)                              5    11     (All nodes are balanced --> AVL tree)
         /  \     (start from 4 to all the way up and check)                    /    / \ 
        5    10   ----------------------------------------->                   4    10  18
       /
      4



2) For a Right-Right insertion --> Left rotate once w.r.t the
first imbalanced nodoe.

Example:-
-->Insert 19

        10                                                                         15
       / \                   First Imbalanced node = 10                           / \
      1   15                 Left rotate w.r.t 10                               10   17    (All nodes are balance --> AVL tree)
         /  \               --------------------------->                       / \    \  
        11  17                                                                1  11    19 
             \
             19              



3) For a left-Right insertion --> Left rotate once and then
Right rotate once.

Example:-
-->Insert 8

         10                                                   10                                                7
        / \     First inbalanced node = 10                   /  \                                              / \     (Balanced AVL tree)
       6   12   Left rotate w.r.t child of 10 (w.r.t 6)     7   12  Right rotate w.r.t imbalanced node(10)    6   10   
      / \      ---------------------------------------->   / \     --------------------------------------->  /   /  \
     4   7                                                6   8                                             4   8    12
          \                                              /    
           8                                            4    

4) For a Right-Left insertion --> Right rotate once w.r.t child of first  
imbalnced node and then Left rotate once w.r.t first imbanced node.

Example:-
-->Insert 16


        7                                                   7                                                     7               
       / \                                                 / \                                                   / \      
      1   10            First imbalanced node = 10        1   10                                                1   16   (Balance AVL tree)
           \    Right_Rotate w.r.t child of 10 (w.r.t 17)      \   Left_Rotate w.r.t first imbalanced node(10)      / \
            17  ---------------------------------------->      16  ------------------------------------------>     10  17
            /                                                   \   
           16                                                   17   


*/


#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
     int key;
     struct Node* left;
     struct Node* right;
     int height;
}node;

int getHeight(node * h)
{
     if(h == NULL)
          return 0;
     return h->height;
}

node *createNode(int value)
{
     node *root   = (node*)malloc(sizeof(node));
     root->key    = value;
     root->left   = NULL;
     root->right  = NULL;
     root->height = 1;
     
     return root;
}
 
int max(int n1, int n2)
{
     if(n1 > n2)
          return n1;
     return n2;
}


int getBalanceFactor(node *root)
{
     if((root->left == NULL && root->right == NULL) || root == NULL)
     {
          return 0;
     }
     return getHeight(root->left) - getHeight(root->right);
}


node * rightRotate(node * y)
{
     node *x   = y->left;
     node *T2  = x->right;
     x->right  = y; 
     y->left   = T2;

     y->height =  max(getHeight(y->right), getHeight(y->left)) + 1;
     x->height =  max(getHeight(x->right), getHeight(x->left)) + 1;

     return x;
}

node * leftRotate(node * y)
{
     node *x   = y->right;
     node *T1  = x->left;

     x->left   = y;
     y->right  = T1;

     y->height =  max(getHeight(y->right), getHeight(y->left)) + 1;
     x->height =  max(getHeight(x->right), getHeight(x->left)) + 1;

     return x;
}

node *insert(node *root, int key)
{
     if(root == NULL)
     {
          return(createNode(key));
     }
     if(key < root->key)
     {
          root->left = insert(root->left, key);
     }
     else if(key > root->key)
     {
          root->right = insert(root->right, key);
          // return root;
     }

     root->height = 1 + max(getHeight(root->left), getHeight(root->right));

     int bf = getBalanceFactor(root);

     // Left-Left insertion
     if(bf > 1 && key < root->left->key){
          return rightRotate(root);
     }

     // Right-Right insertion
     if(bf < -1 && key > root->right->key){
          return leftRotate(root);
     }

     // Left-Right insertion
     if(bf > 1 && key > root->left->key){
          root->left = leftRotate(root->left);
          return rightRotate(root);
     }

     //Right-Left insertion
     if(bf < -1 && key < root->right->key){
          root->right = rightRotate(root->right);
          return leftRotate(root);
     }

     return root;
}


void preOrder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main(){
     
     node * root = NULL;
     root = insert(root, 11);
     root = insert(root, 10);
     root = insert(root, 18);
     root = insert(root, 9);
     root = insert(root, 5);
     root = insert(root, 4);
     root = insert(root, 19);
     root = insert(root, 105);

     preOrder(root);

     return 0;
}