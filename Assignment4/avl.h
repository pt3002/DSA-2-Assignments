typedef struct node{
    int data;
    int bf;
    struct node *parent;
    struct node *left;
    struct node *right;
}node;

typedef node *avl;

void initAVL(avl *t);
void insertNode(avl *t, int data);
void inorder(avl t);
int height(avl t);
