#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "bst.h"
#include "stack.h"

//To initialise the tree
void initBST(Treenode **root){
    *root = NULL;
}

//Inserting node recursively
Treenode* insertNode(Treenode* root, int mis, char name[]){
    if(root == NULL){
        Treenode* newnode = (Treenode *)malloc(sizeof(Treenode));
        newnode -> mis = mis;
        newnode -> name = (char *)malloc(strlen(name));
		strcpy(newnode -> name, name);
		newnode -> left = newnode -> right = NULL;
		return newnode; 
    }

    if(root -> mis > mis){
        root -> left = insertNode(root->left, mis, name);
    }

    else if(root -> mis < mis){
        root -> right = insertNode(root->right, mis, name);
    }

    return root;
}

//Inorder Traversal for checking
void inorder(Treenode* root){

    if (root != NULL) {
        inorder(root->left);
        printf("%d - %s\n", root->mis, root->name);
        inorder(root->right);
    }
}

//Remove node from a tree
Treenode* removeNode(Treenode* root, int key){
    Treenode *p;    //Pointer for finding the node to be deleted
    Treenode *q;    //Pointer to find its parent
    Treenode *r;
    Treenode *rp;
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
Treenode* search(Treenode* root, int mis){

    if (root == NULL || root->mis == mis)
       return root;
    
    if (root->mis < mis)
       return search(root->right, mis);
 
    return search(root->left, mis);
}

//Destroy Tree
void Destroy_Tree(Treenode* root){

    if(root==NULL)
        return;

    Destroy_Tree(root->left);
    Destroy_Tree(root->right);
    free(root);
}

//Postorder iterative traversal
void postOrderIterative(Treenode* root)
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
void Display_Level(Treenode *root, int level){
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