#include <stdio.h>
#include "head.h"



typedef struct Node node;
typedef struct BST bst;
struct Node {
    double key;
    node *p;
    node *left;
    node *right;

    int fields[];
};
struct BST {
    node root;
};


#define insert(length, funcs) \
void insert(bst *bst, node *n) {    \
        node *ptr = bst->root, *y;  \
        while(ptr) {                \
            y = ptr;                \
            if (isBigger(ptr,n))    \
                ptr = ptr->left;    \
            else                    \
                ptr = ptr->right;   \
        }                           \
        n->p = y;                   \
        if (y) {                    \
            if (isBigger(y, n))     \
                y->left = n;        \
            else                    \
                y->right = n;       \
        }                           \
        else                        \
        bst->root = n;\
        while(n != bst->root) {     \
            for(int i = 0; i<(length); i++) { \
                n->fields[i] = (funcs)[i] (n);\
                n = n->p;                        \
            }              \
        }                      \
}
