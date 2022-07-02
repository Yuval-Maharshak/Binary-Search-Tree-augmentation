#include "augmention.h"

typedef struct Node node;
struct Node {
    double key;
    node *p;
    node *left;
    node *right;

    int size;
};

