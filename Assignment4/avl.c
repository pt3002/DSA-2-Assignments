#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

void initAVL(avl *t){
    *t = NULL;
    return;
}

int height(avl t){
    if(t==NULL){
        return 0;
    }
    int l = height( t->left );
    int r = height( t-> right);
    if(l>r){
        return 1+l;
    }
    return 1+r;
}

void insertNode(avl *t, int data){
    node *nn;
    nn = (node *) malloc(sizeof(node));
    nn -> left = NULL;
    nn -> right = NULL;
    nn -> data = data;
    nn -> parent = NULL;
    nn -> bf = 0;
     
    // Tree empty condition
    if(*t == NULL){
        *t = nn;
        return;
    }

    if((*t) -> data > data){
        insertNode(&((*t) -> left), data);
        (*t) -> left -> parent = *t;
        (*t) -> bf = height((*t) -> left) - height((*t) -> right);
    }

    if((*t) -> data < data){
        insertNode(&((*t) -> right), data);
        (*t) -> right -> parent = *t;
        (*t) -> bf = height((*t) -> left) - height((*t) -> right);
    }
    
    return;
}

node* adjust(avl *t, int data){
    node *p;
    p = *t;
    while(p && p -> data != data){
        if(p ->data == data){
            break;
        }
        if(p -> data > data){
            p = p->left;
        }
        if(p -> data < data){
            p = p->right;
        }
    }
    node *pp;
    pp = p;
    while(pp!=NULL){
        if(pp->bf > 1 || pp->bf < -1){
            return pp;
        }
        pp = pp -> parent;
    }
    return NULL;
}

char* rotationtype(node *imb, int data){
    char *ans;
    ans = (char *)malloc(sizeof(char)*2);
    int i = 0;
    while(i<2){
        if(data > imb -> data){
            ans[i] = 'R';
            imb = imb -> right;
        }
        else if(data < imb -> data){
            ans[i] = 'L';
            imb = imb -> left;
        }
        i++;
    }
    return ans;
}

void LL(node **imb, avl *t){
    node *p = *imb;
    node *pp = p -> parent;          // pp is the parent of imbalanced node
    node *q = p ->left;            
    node *r = q->left;
    if(pp && pp -> left == p){
        pp -> left = q;
    }
    else if(pp && pp -> right == p){
        pp -> right = q;
    }
    else{
        *t = q;
    }
    q -> parent = pp;
    r -> parent = q;
    p -> parent = q;
    p -> left = q -> right;
    if(q->right){
        q -> right -> parent = p;
    }
    q -> left = r;
    q -> right = p;
    p -> bf = height(p -> left) - height(p -> right);
    q -> bf = height(q -> left) - height(q -> right);
    r -> bf = height(r -> left) - height(r -> right);
    while(pp){
        pp -> bf = height(pp -> left) - height(pp -> right);
        pp = pp->parent;
    }
    return ;
}

void RR(node **imb, avl *t){
    node *p = *imb;
    node *pp = p -> parent;
    node *q = p ->right ;
    node *r = q-> right;
    if(pp && pp -> left == p){
        pp -> left = q;
    }
    else if(pp && pp -> right == p){
        pp -> right = q;
    }
    else{
        *t = q;
    }
    q -> parent = pp;
    r -> parent = q;
    p -> parent = q;
    p -> right = q -> left;
    if(q->left){
        q -> left -> parent = p;
    }
    q -> left = p;
    q -> right = r;
    p -> bf = height(p -> left) - height(p -> right);
    q -> bf = height(q -> left) - height(q -> right);
    r -> bf = height(r -> left) - height(r -> right);
    while(pp){
        pp -> bf = height(pp -> left) - height(pp -> right);
        pp = pp->parent;
    }
    return ;
}

void RL(node **imb, avl *t){
    node *p = *imb;
    node *pp = p -> parent;
    node *q = p ->right;
    node *r = q -> left;
    if(pp && pp -> left == p){
        pp -> left = r;
    }
    else if(pp && pp -> right == p){
        pp -> right = r;
    }
    else{
        *t = r;
    }
    r -> parent = pp;
    p -> parent = r;
    q -> parent = r;
    p -> right = r -> left;
    if(r->left){
        r -> left -> parent = p;
    }
    q -> left = r -> right;
    if(r-> right){
        r -> right -> parent = p;
    }
    r -> left = p;
    r -> right = q;
    p -> bf = height(p -> left) - height(p -> right);
    q -> bf = height(q -> left) - height(q -> right);
    r -> bf = height(r -> left) - height(r -> right);
    while(pp){
        pp -> bf = height(pp -> left) - height(pp -> right);
        pp = pp->parent;
    }
    return ;
}

void LR(node **imb, avl *t){
    node *p = *imb;
    node *pp = p -> parent;
    node *q = p -> left;
    node *r = q -> right;
    if(pp && pp -> left == p){
        pp -> left = r;
    }
    else if(pp && pp -> right == p){
        pp -> right = r;
    }
    else{
        *t = r;
    }
    r -> parent = pp;
    q -> parent = r;
    p -> parent = r;
    p -> left = r -> right;
    if(r -> right){
        r -> right -> parent = p;
    }
    q -> right = r -> left;
    if(r -> left){
        r -> left -> parent = q;
    }
    r -> left = q;
    r -> right = p;
    p -> bf = height(p -> left) - height(p -> right);
    q -> bf = height(q -> left) - height(q -> right);
    r -> bf = height(r -> left) - height(r -> right);
    while(pp){
        pp -> bf = height(pp -> left) - height(pp -> right);
        pp = pp->parent;
    }
    return ;
}

void inorder(avl t){
    if(!t){
        return;
    }
    inorder(t -> left);
    if(t->parent){
        printf("%d - %d - %d\n", t->data, t->parent->data, t->bf);
    }
    else{
        printf("%d - %d\n", t->data, t->bf);
    }
    inorder(t -> right);
}

//Destroy Tree
void Destroy_Tree(avl *t){

    if(*t==NULL)
        return;

    Destroy_Tree(&((*t)->left));
    (*t)->left = NULL;
    Destroy_Tree(&((*t)->right));
    (*t)->right = NULL;
    free(*t);
    (*t) = NULL;
}

//Remove node from a tree
avl removeNode(avl root, int key){
    avl p;    //Pointer for finding the node to be deleted
    avl q;    //Pointer to find its parent
    avl r;
    avl rp;
    p = root;
    avl pp;

    //Checking if tree is empty
    if(root == NULL){
        return NULL; 
    }

    //Locating the node to be deleted and its parent
    while(p){
        if(p->data == key){
            break;
        }

        q=p;

        if(p->data > key){
            p = p->left;
        }

        else{
            p = p->right;
        }
    }

    //If key to be deleted is not found
    if(!p){
        return root;
    }

    //Checking if p is the leaf node
    if(p->left == p->right){
        if(p == root){
            root = NULL;   //parent node does not exist i.e. only one node is there in this tree
        }
        else{
            if(q->left == p){
                q->left = NULL;
            }
            else{
                q->right = NULL;
            }
        }
        pp = p -> parent;
        printf("%d--parent node of deleted node \n",pp -> data);

        //changing balance factors of all nodes
        while(pp){
            pp -> bf = height(pp -> left) - height(pp -> right);
            //This means height of left subtree is more than right subtree
            if(pp -> bf > 1){
                printf("Imbalanced Node - %d\n", pp -> data);
                avl child;
                child = pp -> left;
                // //LL rotation
                if(child -> bf >= 0){
                    printf("LL rotation\n");
                    LL(&(pp), &root);
                }
                //LR rotation
                else{
                    printf("LR rotation\n");
                    LR(&(pp), &root);
                }
            }
            else if(pp -> bf < -1){
                printf("Imbalanced Node - %d\n", pp -> data);
                avl child;
                child = pp -> right;
                // //RL rotation
                if(child -> bf >= 0){
                    printf("RL rotation\n");
                    RL(&(pp), &root);
                }
                //RR rotation
                else{
                    printf("RR rotation\n");
                    RR(&(pp), &root);
                }
            }
            pp = pp->parent;
        }
        free(p);
        return root;
    }

    //If p has only left sub tree
    if(p->left != NULL && p->right == NULL){
        if(p == root){
            root = p->left;
        }
        else{
            if(q->left == p){
                q->left = p->left;
                p -> left -> parent = q;
            }
            else{
                q->right = p->left;
                p -> left -> parent = q;
            }
        }
        pp = p -> parent;
        //changing balance factors of all nodes
        while(pp){
            pp -> bf = height(pp -> left) - height(pp -> right);
            //This means height of left subtree is more than right subtree
            if(pp -> bf > 1){
                printf("Imbalanced Node - %d\n", pp -> data);
                avl child;
                child = pp -> left;
                // //LL rotation
                if(child -> bf >= 0){
                    printf("LL rotation\n");
                    LL(&(pp), &root);
                }
                //LR rotation
                else{
                    printf("LR rotation\n");
                    LR(&(pp), &root);
                }
            }
            else if(pp -> bf < -1){
                printf("Imbalanced Node - %d\n", pp -> data);
                avl child;
                child = pp -> right;
                // //RL rotation
                if(child -> bf >= 0){
                    printf("RL rotation\n");
                    RL(&(pp), &root);
                }
                //RR rotation
                else{
                    printf("RR rotation\n");
                    RR(&(pp), &root);
                }
            }
            pp = pp->parent;
        }
        free(p);
        return root;
    }

    //If p has only right sub tree
    if(p->right != NULL && p->left == NULL){
        if(p == root){
            root = p->right;
        }
        else{
            if(q->left = p){
                q->left = p->right;
                p -> right -> parent = q; 
            }
            else{
                q->right = p->right;
                p -> right -> parent = q; 
            }

        }
        pp = p -> parent;
        //changing balance factors of all nodes
        while(pp){
            pp -> bf = height(pp -> left) - height(pp -> right);
            //This means height of left subtree is more than right subtree
            if(pp -> bf > 1){
                printf("Imbalanced Node - %d\n", pp -> data);
                avl child;
                child = pp -> left;
                // //LL rotation
                if(child -> bf >= 0){
                    printf("LL rotation\n");
                    LL(&(pp), &root);
                }
                //LR rotation
                else{
                    printf("LR rotation\n");
                    LR(&(pp), &root);
                }
            }
            else if(pp -> bf < -1){
                printf("Imbalanced Node - %d\n", pp -> data);
                avl child;
                child = pp -> right;
                // //RL rotation
                if(child -> bf >= 0){
                    printf("RL rotation\n");
                    RL(&(pp), &root);
                }
                //RR rotation
                else{
                    printf("RR rotation\n");
                    RR(&(pp), &root);
                }
            }
            pp = pp->parent;
        }
        free(p);
        return root;
    }

    //If p has both LST AND RST
    if(p->right != NULL && p->left != NULL){
        r = p->left;
        rp = NULL;
        while(r->right){
            rp = r;
            r = r->right;
        }

        p->data = r->data;
        if(rp){
            rp ->right = r->left;
            r -> left -> parent = rp;
        }
        else{
            p->left = r->left;
            r -> left -> parent =p ;
        }
        pp = r -> parent;
        //changing balance factors of all nodes
        while(pp){
            pp -> bf = height(pp -> left) - height(pp -> right);
            //This means height of left subtree is more than right subtree
            if(pp -> bf > 1){
                printf("Imbalanced Node - %d\n", pp -> data);
                avl child;
                child = pp -> left;
                // //LL rotation
                if(child -> bf >= 0){
                    printf("LL rotation\n");
                    LL(&(pp), &root);
                }
                //LR rotation
                else{
                    printf("LR rotation\n");
                    LR(&(pp), &root);
                }
            }
            else if(pp -> bf < -1){
                printf("Imbalanced Node - %d\n", pp -> data);
                avl child;
                child = pp -> right;
                // //RL rotation
                if(child -> bf >= 0){
                    printf("RL rotation\n");
                    RL(&(pp), &root);
                }
                //RR rotation
                else{
                    printf("RR rotation\n");
                    RR(&(pp), &root);
                }
            }
            pp = pp->parent;
        }
        free(r);
        return root;
    }

}

