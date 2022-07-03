#include "operationBST.h"

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

int (*funcs[1]) (node *) = {&size};

Insert(funcs)


