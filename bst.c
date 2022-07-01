#include "head.h"

node * search(BST *bst, double k) {
    node *ptr = bst->root;
    while(ptr) {
        if (ptr->key > k)
            ptr = ptr->left;
        else if (ptr->key < k)
            ptr = ptr->right;
        else
            return ptr;
    }
    return NULL;
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
}
void delete(BST *bst, node *n) {
    node *newSon;
    node *succ;
    switch(state(n)) {
        case 0: newSon = NULL; break;
        case 1: newSon = n->left; break;
        case 2: newSon = n->right; break;
        case 3:
            succ = successor(n);
            n->key = succ->key;
            delete(bst, succ);
            return;
    }
    if (isLeftChild(n))
        n->p->left = newSon;
    else
        n->p->right = newSon;
}

node * max(BST *bst) {
    node *ptr = bst->root;
    while(isLeaf(ptr)) {
        ptr = ptr->right;
    }
    return ptr;
}
node * min (BST *bst) {
    node *ptr = bst->root;
    while(hasLeft(ptr)) {
        ptr = ptr->left;
    }
    return ptr;
}
node * successor(node *n) {
    if (hasRight(n))
        return min(subBST(n->right));
    else {
        node *ptr = n;
        while(isRightChild(ptr)) {
            ptr = ptr->p;
        }
        return ptr->p;
    }
}
node * predecessor(node *n) {
    if (hasLeft(n))
        return max(subBST(n->left));
    else {
        node *ptr = n;
        while(isLeftChild(ptr)) {
            ptr = ptr->p;
        }
        return ptr->p;
    }
}
void preOrderBST(BST *b ) {
    pre_order(b->root);
}
void pre_order(node *n) {
    if (n) {
        printf("%f ", n->key);
        pre_order(n->left);
        pre_order(n->right);
    }
}
void inOrderBST(BST *b ) {
    in_order(b->root);
}
void in_order(node *n) {
    if (n) {
        in_order(n->left);
        printf("%f ", n->key);
        in_order(n->right);
    }
}
void postOrderBST(BST *b ) {
    post_order(b->root);
}
void post_order(node *n) {
    if (n) {
        post_order(n->left);
        post_order(n->right);
        printf("%f ", n->key);
    }
}

char state(node *n) {
    if (isLeaf(n))
        return 0;
    if (isLeftChild(n))
        return 1;
    if (isRightChild(n))
        return 2;
    return 3;
}

