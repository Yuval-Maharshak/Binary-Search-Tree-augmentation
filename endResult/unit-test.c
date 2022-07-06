#include "queriesBST.h"
int size(node *n) {
    if (n->left && n->right)
        return n->left->fields[0] + n->right->fields[0] + 1;
    else if (n->right)
        return n->right->fields[0] + 1;
    else if (n->left)
        return n->left->fields[0] + 1;
    else
        return 1;
}
void insert(BST *bst, node *n) {
    node *ptr = bst->root, *y;
    while(ptr) {
        y = ptr;
        if (isBigger(ptr,n))
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    n->p = y;
    if (y) {
        if (isBigger(y, n))
            y->left = n;
        else
            y->right = n;
    }
    else
        bst->root = n;
    while(n) {
        for (int i = 0; i<NUM_OF_FIELDS; i++) {
            n->fields[i] = size(n);
        }
        n = n->p;
    }
}
void delete(BST *bst, node *n) {
    node *y, *x;
    if (n->left == NULL || n->right == NULL)
        y = n;
    else
        y = successor(n);
    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;
    if (x != NULL)
        x->p = y->p;
    if (y->p == NULL)
        bst->root = x;
    else    {
        if (y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
    }
    if (y != n)
        n->key = y->key;
    while(y) {
        for (int i = 0; i<NUM_OF_FIELDS; i++) {
            y->fields[i] = size(y);
        }
        y = y->p;
    }
}

int main() {
    BST bst = {createNode(5)};
    insert(&bst, createNode(4));
    insert(&bst, createNode(3));
    insert(&bst, createNode(6));
    insert(&bst, createNode(1));
    insert(&bst, createNode(4.5));
    insert(&bst, createNode(10));

    inOrderBST(&bst);
    printf("\n");
    delete(&bst, bst.root->left);
    inOrderBST(&bst);
    printf("\n%d\n", bst.root->fields[0]);
    delete(&bst, bst.root);
    inOrderBST(&bst);
    printf("\n%d", bst.root->fields[0]);
}
