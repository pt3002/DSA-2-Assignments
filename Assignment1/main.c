#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

int main(){
    Treenode *root;
    initBST(&root);
    
    root = insertNode(root, 7, "Prerna");
    insertNode(root, 20, "Abc");
    insertNode(root, 5, "pqr");
    insertNode(root, 15, "john");
    insertNode(root, 10, "jack");
    insertNode(root, 4, "harry");
    insertNode(root, 33, "riya");
    insertNode(root, 2, "ghi");
    //insertNode(root, 25, "jessy");
    
    int option;
    printf("Enter following options to perform operations on a tree\n");
    printf("1 - To insert a new node\n");
    printf("2 - To remove a node\n");
    printf("3 - To search a node\n");
    printf("4 - Post order traversal\n");
    printf("5 - To display all nodes at a particular level\n");
    printf("6 - To destroy tree\n");
    printf("7 - To show inorder Traversal\n");
    printf("-1 - To exit\n");
    
    while(1){
    		printf("Enter option - ");
		scanf("%d",&option);
		
		if(option == 1){
			int mis;
			printf("Enter MIS - ");
			scanf("%d",&mis);
			char name[20];
			printf("Enter name - ");
			scanf("%s",name); 
			if(root==NULL){
				root = insertNode(root, mis, name);
			}
			else{
				insertNode(root, mis, name);
			}
			
   //root = insertNode(root, 7, "Prerna");
    //insertNode(root, 20, "Abc");
    //insertNode(root, 5, "pqr");
    //insertNode(root, 15, "john");
    //insertNode(root, 10, "jack");
    //insertNode(root, 4, "harry");
    //insertNode(root, 33, "riya");
    //insertNode(root, 2, "ghi");
    //insertNode(root, 25, "jessy");
		}
		
		if(option == 2){
			int key;
			printf("Enter mis to be deleted - ");
			scanf("%d",&key);
			root = removeNode(root,key);
			printf("Now tree is - \n");
			inorder(root);
   //Removing nodes
    //printf("Removing nodes - ");
    //root = removeNode(root, 85);          //Key is not there
    //root = removeNode(root, 2);            //Key is leaf node
    //root = removeNode(root, 5);              //Key has only LST
    //root = removeNode(root, 20);               //Both LST and RST
    //root = removeNode(root, 7);                 //Deleting root
		}
		
		if(option == 3){
			int key;
			printf("Enter mis to be searched - ");
			scanf("%d",&key);
			Treenode *answer = search(root, key);
    			if(answer != NULL){
		    		printf("Found\n");
		    	}
		    	else{
		    		printf("Not found\n");
		    	}
		}
		
		if(option == 4){
			postOrderIterative(root);
			printf("\n");	
		}
		
		if(option == 5){
			int level;
			printf("Enter level-");
			scanf("%d",&level);
			Display_Level(root, level);
		}
		
		if(option == 6){
			Destroy_Tree(root); 
		}
		
		if(option == 7){
			inorder(root);
		}
		
		if(option == -1){
			break;
		}
		printf("===============================================================================================");
		printf("\n");
		
	}
    return 0;
}