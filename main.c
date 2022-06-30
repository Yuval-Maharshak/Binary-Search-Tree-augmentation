#include "head.h"

int main() {
    node *r = createNode(5);
    BST bst = {r};
    insert(&bst, createNode(4));
    insert(&bst, createNode(6));
    delete(&bst, r);
    preOrderBST(&bst);
    printf("\n");
    inOrderBST(&bst);
    printf("\n");
    postOrderBST(&bst);
}