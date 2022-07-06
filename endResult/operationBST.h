#include "queriesBST.h"
#define INSERT(funcs)       /* defines a function insert that maintain all the fields in node*/ \
void insert(BST *bst, node *n) {                                                                \
    /* insert the node like usual, finding where to insert it and then putting it there*/       \
    node *ptr = bst->root, *y;  \
    while(ptr) {    \
        y = ptr;    \
        if (isBigger(ptr,n))    \
            ptr = ptr->left;    \
        else    \
            ptr = ptr->right;   \
    }   \
    n->p = y;   \
    if (y) {    \
        if (isBigger(y, n)) \
            y->left = n;    \
        else    \
            y->right = n;   \
    }   \
    else    \
        bst->root = n;                                                                          \
    /* for all the parents from n to root we fix the inaccuracies using the funcs given(the entire tree is fixed using induction and blah blah) */       \
    while(n) {     \
        for (int i = 0; i<NUM_OF_FIELDS; i++) { \
            n->fields[i] = (funcs)[i](n);              \
        }             \
        n = n->p;                  \
    }                  \
}
#define DELETE(funcs)   \
void delete(BST *bst, node *n) {    \
    node *y, *x;        \
    if(n->left == NULL || n->right == NULL)     \
        y = n;      \
    else        \
        y = successor(n);       \
    if (y->left != NULL)        \
        x = y->left;        \
    else        \
        x = y->right;       \
    if (x != NULL)      \
        x->p = y->p;        \
    if (y->p == NULL)       \
        bst->root = x;      \
    else        \
        if (y == y->p->left)        \
            y->p->left = x;     \
        else        \
            y->p->right = x;        \
    if (y != n)     \
        n->key = y->key;        \
    while(y) {     \
        for (int i = 0; i<NUM_OF_FIELDS; i++) { \
            y->fields[i] = (funcs)[i](y);              \
        }             \
        y = y->p;                  \
    }                  \
}


