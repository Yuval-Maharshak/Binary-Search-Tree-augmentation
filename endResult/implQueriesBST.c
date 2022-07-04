#include "queriesBST.h"

node * search(BST *bst, double k) {
    node *ptr = bst->root;
    while(ptr) {
        /* if the key of ptr is bigger than k then if k is in the subtree from ptr it's left to ptr. same for if it's smaller. */
        if (ptr->key > k)
            ptr = ptr->left;
        else if (ptr->key < k)
            ptr = ptr->right;
        else        /* if we found a node such that its key is equal to k */
            return ptr;
    }
    return NULL;
}

node * max(BST *bst) {
    /* the max node in bst is just the rightest node in the tree */
    node *ptr = bst->root;
    while(isLeaf(ptr)) {
        ptr = ptr->right;
    }
    return ptr;
}
node * min (BST *bst) {
    /* the min node in bst is just the leftest node in the tree */
    node *ptr = bst->root;
    while(hasLeft(ptr)) {
        ptr = ptr->left;
    }
    return ptr;
}
node * successor(node *n) {
    if (hasRight(n))
        return min(subBST(n->right));   /* if it has a right then the succ is the smallest of the right tree(since above n is nodes bigger than n->right or smaller than n) */
    else {      /* if it doesn't have a right child than it's up to the first father n has that is bigger than n */
        node *ptr = n;
        while(isRightChild(ptr)) {
            ptr = ptr->p;
        }
        return ptr->p;
    }
}
node * predecessor(node *n) {
    if (hasLeft(n))
        return max(subBST(n->left));    /* if it has a left then the pre is the biggest of the left tree(since above n is nodes smaller than n->left or bigger than n) */
    else {
        /* if it doesn't have a left child than it's up to the first father n has that is smaller than n */
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

