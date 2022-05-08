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
node* adjust(avl *t, int data);
void Destroy_Tree(avl *t);
avl removeNode(avl root, int key);
void LL(node **imb,avl *t);
void RR(node **imb,avl *t);
void RL(node **imb,avl *t);
void LR(node **imb,avl *t);
char* rotationtype(node *imb, int data);
