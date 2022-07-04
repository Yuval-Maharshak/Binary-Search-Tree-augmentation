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
#define DELETE(funcs)       \
void delete(BST *bst, node *n) {    \
    node *newSon;   \
    node *succ;     \
    switch(state(n)) {      \
        case 0: newSon = NULL; break;       \
        case 1: newSon = n->left; break;    \
        case 2: newSon = n->right; break;   \
        case 3:     \
            succ = successor(n);    \
            n->key = succ->key;     \
            delete(bst, succ);      \
            return;     \
    }       \
    if (isLeftChild(n))     \
        n->p->left = newSon;    \
    else    \
        n->p->right = newSon;       \
    if (newSon)     \
        newSon->p = n->p;       \
    while(newSon) {     \
        for (int i = 0; i<NUM_OF_FIELDS; i++) { \
            newSon->fields[i] = (funcs)[i](newSon);              \
        }             \
        newSon = newSon->p;                  \
    }                       \
}


