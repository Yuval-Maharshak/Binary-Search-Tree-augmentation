#include <stdio.h>
#include <stdlib.h>

#define isBigger(n1, n2) (n1->key > n2->key) /* is the key of n1 bigger than the key of n2 */
#define isSmaller(n1, n2) (n1->key < n2->key) /* is the key of n1 smaller than the key of n2 */
#define equalKey(n1, n2) (n1->key == n2->key) /* does the keys of n1 and n2 equal */
#define isLeaf(n) (!(n->left || n->right)) /* is n a leaf (no children) */
#define hasLeft(n) (n->left) /* does n have a left son */
#define hasRight(n) (n->right) /* does n have a right son */
#define isLeftChild(n) (n->p && n->p->left == n) /* n is the left child of his parent */
#define isRightChild(n) (n->p && n->p->right == n) /* n is the left child of his parent */

/*typedef struct Node node;
struct Node {
    double key;
    node *p;
    node *left;
    node *right;
};

typedef struct BinarySearchTree{
    node *root;
} BST;*/

BST * subBST(node *n);
node * createNode(double key);

void insert(BST *, node *);
void delete(BST *, node *);

node * search(BST *, double);
node * max(BST *);
node * min(BST *);
node * successor(node *);
node * predecessor(node *);

void preOrderBST(BST *b);
void inOrderBST(BST *b);
void postOrderBST(BST *b);
void pre_order(node *b);
void in_order(node *b);
void post_order(node *b);

char state(node *n);

