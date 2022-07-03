#define NUM_OF_FIELDS 1

typedef struct Node node;
struct Node {
    double key;
    node *p;
    node *left;
    node *right;

    int fields[NUM_OF_FIELDS];
};
typedef struct bst {
    node *root;
} BST;


