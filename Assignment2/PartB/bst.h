typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

typedef node *bst;

void init_bst(bst *t);

void insert(bst *t, int d);

// Sorting Algorithm
int* sort(int *postorder, int inorderSize);

void inorder_traversal(bst t);
void postorder_traversal(bst t);

void buildTree(bst *t, int *inorder, int *postorder, int inorderSize, int* postorderSize);