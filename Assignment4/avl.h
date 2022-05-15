typedef struct node{
    char* data;
    int bf;
    struct node *parent;
    struct node *left;
    struct node *right;
}node;

typedef node *avl;

void initAVL(avl *t);
void insertNode(avl *t, char* data);
void inorder(avl t);
int height(avl t);
node* adjust(avl *t, char* data);
void Destroy_Tree(avl *t);
avl removeNode(avl root, char* key);
void LL(node **imb,avl *t);
void RR(node **imb,avl *t);
void RL(node **imb,avl *t);
void LR(node **imb,avl *t);
char* rotationtype(node *imb, char* data);
