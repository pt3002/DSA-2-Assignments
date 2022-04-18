#include<stdlib.h>

//Structure for node of tree
typedef struct node{
    int mis;
    char *name;
    struct node *left;
    struct node *right;
}node;

typedef node *bst;

//Tree functions
void init_bst(bst *t);
void insertNode(bst *t, int mis, char name[]);
node* search(bst t, int mis);
void Destroy_Tree(node* root);
void inorder(bst t);
node* removeNode(node* root, int key);
void postOrderIterative(node* root);
void Display_Level(node *root, int level);

