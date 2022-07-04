#include <stdio.h>
#include <stdlib.h>
#include "dataStruct.h"     /* here you have implementation of the node and binary search tree data structures. */

#define isBigger(n1, n2) (n1->key > n2->key) /* is the key of n1 bigger than the key of n2 */
#define isSmaller(n1, n2) (n1->key < n2->key) /* is the key of n1 smaller than the key of n2 */
#define equalKey(n1, n2) (n1->key == n2->key) /* does the keys of n1 and n2 equal */
#define isLeaf(n) (!(n->left || n->right)) /* is n a leaf (no children) */
#define hasLeft(n) (n->left) /* does n have a left son */
#define hasRight(n) (n->right) /* does n have a right son */
#define isLeftChild(n) (n->p && n->p->left == n) /* n is the left child of his parent */
#define isRightChild(n) (n->p && n->p->right == n) /* n is the left child of his parent */

BST * subBST(node *);          /* returns a binary search tree which root is equal to n. used to refer to the subtree from n. */
node * createNode(double);  /* create a new node with key[n]=key */

node * search(BST *, double);   /* returns a node n in the binary search tree such that key[n] = key */
node * max(BST *);              /* returns a node n such that it key is the maximum key in the tree */
node * min(BST *);              /* returns a node n such that it key is the minimum key in the tree */
node * successor(node *);       /* returns the smallest node in the tree n is a part of such that it key is bigger than n */
node * predecessor(node *);     /* returns the biggest node in the tree n is a part of such that it key is smaller than n */

void preOrderBST(BST *b);       /* prints the pre-order of the tree */
void inOrderBST(BST *b);        /* prints the in-order of the tree */
void postOrderBST(BST *b);      /* prints the post-order of the tree */
void pre_order(node *b);        /* prints the pre-order of the subtree from n */
void in_order(node *b);         /* prints the in-order of the subtree from n */
void post_order(node *b);       /* prints the post-order of the subtree from n */

char state(node *n);            /* returns the state of n: 0 if n is a leaf, 1 if n has only a left child, 2 if n has only a right child, 3 is n has 2 children */



