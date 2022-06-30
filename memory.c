#include "head.h"

BST * subBST(node *n) {
    BST *b = malloc(sizeof(BST));
    b->root = n;
    return b;
}
node * createNode(double k) {
    node *n = malloc(sizeof(node));
    n->key = k;
    n->right = n->left = n->p = NULL;
    return n;
}