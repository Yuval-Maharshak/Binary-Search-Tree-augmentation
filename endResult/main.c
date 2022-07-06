#include "main.h"
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
    inOrderSize(bst.root);
}

void  inOrderSize(node *n) {
    if (n) {
        inOrderSize(n->left);
        printf("%d ", n->fields[0]);
        inOrderSize(n->right);
    }
}