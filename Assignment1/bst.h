#include<stdlib.h>

//Structure for node of tree
typedef struct Treenode{
    int mis;
    char *name;
    struct Treenode *left;
    struct Treenode *right;
}Treenode;


//Tree functions
void initBST(Treenode **root);
Treenode* insertNode(Treenode* root, int mis, char name[]);
Treenode* search(Treenode* root, int mis);
void Destroy_Tree(Treenode* root);
void inorder(Treenode* root);
Treenode* removeNode(Treenode* root, int key);
void postOrderIterative(Treenode* root);
void Display_Level(Treenode *root, int level);

