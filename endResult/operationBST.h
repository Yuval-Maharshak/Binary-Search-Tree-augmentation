#include "queriesBST.h"
#define Insert(funcs) \
void insert(BST *bst, node *n) {    \
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
        bst->root = n;\
    while(n) {     \
        for (int i = 0; i<NUM_OF_FIELDS; i++) { \
            n->fields[i] = (funcs)[i](n);              \
        }             \
        n = n->p;                  \
    }                  \
}

