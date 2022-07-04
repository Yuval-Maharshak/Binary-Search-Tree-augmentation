#define NUM_OF_FIELDS 1     /* (CHANGEABLE) The number of new fields in the node structure */

typedef struct Node node;       /* a node in the tree */
struct Node {
    double key;     /* key or value of node */
    node *p;        /* the parent of the node */
    node *left;     /* the left child of the node */
    node *right;    /* the right child of the node */

    int fields[NUM_OF_FIELDS];      /* an array of ints with each element represent an added field */
};
typedef struct bst {
    node *root;     /* the root of the tree */
} BST;      /* A binary search tree with augmented fields. */


