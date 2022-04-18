#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "bst.h"
#include "stack.h"

//To initialise the tree
void init_bst(bst *t){
    *t = NULL;
    return;
}

//Inserting node recursively
void insertNode(bst *t, int mis, char name[]){
    node *nn;
    nn = (node *) malloc(sizeof(node));
    nn -> left = NULL;
    nn -> right = NULL;
    nn -> mis = mis;
    nn -> name = (char *)malloc(strlen(name));
	strcpy(nn -> name, name); 
     
    // Tree empty condition
    if(*t == NULL){
        *t = nn;
        return;
    }

    if((*t) -> mis > mis){
        insertNode(&((*t) -> left), mis, name);
    }

    if((*t) -> mis < mis){
        insertNode(&((*t) -> right), mis, name);
    }

    return;
}

//Inorder Traversal for checking
void inorder(bst t){
    if(!t){
        return;
    }
    inorder(t -> left);
    printf("%d - %s\n", t->mis, t->name);
    inorder(t -> right);
}

//Remove node from a tree
bst removeNode(bst root, int key){
    bst p;    //Pointer for finding the node to be deleted
    bst q;    //Pointer to find its parent
    bst r;
    bst rp;
    p = root;

    //Checking if tree is empty
    if(root == NULL){
        return NULL; 
    }

    //Locating the node to be deleted and its parent
    while(p){
        if(p->mis == key){
            break;
        }

        q=p;

        if(p->mis > key){
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
            }
            else{
                q->right = p->left;
            }
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
            }
            else{
                q->right = p->right;
            }
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

        p->mis = r->mis;
        if(rp){
            rp ->right = r->left;
        }
        else{
            p->left = r->left;
        }
        free(r);
        return root;
    }

}

//Search recursively a tree
node* search(bst t, int mis){

    if (t == NULL || t->mis == mis)
       return t;
    
    if (t->mis < mis)
       return search(t->right, mis);
 
    return search(t->left, mis);
}

//Destroy Tree
void Destroy_Tree(bst t){

    if(t==NULL)
        return;

    Destroy_Tree(t->left);
    Destroy_Tree(t->right);
    free(t);
}

//Postorder iterative traversal
void postOrderIterative(node* root)
{
    // Check for empty tree
    if (root == NULL)
        return;
     
    struct Stack* stack = createStack(100);
    do
    {
        // Reaching leftmost node
        while (root)
        {
            // first push right child of root and then root to stack and then set root to root's left
            if (root->right)
                push(stack, root->right);
            push(stack, root);
            root = root->left;
        }
 
        // Pop an item from stack and set it as root    
        root = pop(stack);
 
        // If the popped item has a right child and the right child is not processed yet, then process right child before root
        if (root->right && peek(stack) == root->right)
        {
            pop(stack); // remove right child from stack
            push(stack, root); // push root back 
            root = root->right; 
        }
        else 
        {
            printf("%d ", root->mis);
            root = NULL;
        }
    } while (!isEmpty(stack));
}

//Display node at ith level
void Display_Level(node *root, int level){
        if(root == NULL){
            return ;
        }

        if(level == 1){
            printf("%d-%s \n",root->mis, root->name);
        }

        else if(level>1){
            Display_Level(root->left, level-1);
            Display_Level(root->right, level-1);
        }

    }