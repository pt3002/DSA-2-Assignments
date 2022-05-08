#include<stdio.h>
#include<stdlib.h>
#include "avl.h"
#include<string.h>

int monthfind(char *m){
    if(strcmp(m, "January")==0){
        return 1;
    }
    else if(strcmp(m, "February")==0){
        return 2;
    }
    else if(strcmp(m, "March")==0){
        return 3;
    }
    else if(strcmp(m, "April")==0){
        return 4;
    }
    else if(strcmp(m, "May")==0){
        return 5;
    }
    else if(strcmp(m, "June")==0){
        return 6;
    }
    else if(strcmp(m, "July")==0){
        return 7;
    }
    else if(strcmp(m, "August")==0){
        return 8;
    }
    else if(strcmp(m, "September")==0){
        return 9;
    }
    else if(strcmp(m, "October")==0){
        return 10;
    }
    else if(strcmp(m, "November")==0){
        return 11;
    }
    else if(strcmp(m, "December")==0){
        return 12;
    }
}

void afterinsert(avl *t, int data){
    node *imb;
    node *imbp; // parent of imbalanced node
    imb = adjust(t,data);
    while(imb!=NULL){
        imbp = imb -> parent;
        if(imb -> bf > 1 || imb -> bf < -1){
            printf("--------Imbalanced Node - %d-------------\n",imb->data);
            printf("Type of rotation - %s -  on node - %d\n",rotationtype(imb,data),imb->data);
            char *a = rotationtype(imb,data);
            if(a[0]=='L' && a[1]=='L'){
                LL(&imb, t);
            }
            else if(a[0]=='R' && a[1] == 'R'){
                RR(&imb, t);
            }
            else if(a[0]=='R' && a[1] == 'L'){
                RL(&imb, t);
            }
            else if(a[0]=='L' && a[1] == 'R'){
                LR(&imb, t);
            }
        }
        imb = imbp;
    }
}

int main(){
    avl t1;
    node *imb;

    //Initialize avl tree
    initAVL(&t1);
    while(1){
        char *month;
        month = (char *)malloc(sizeof(char)*20);
		printf("Enter name or none to exit- ");
		scanf("%s",month);
        if(month[0]=='n'){
            break;
        }
        else{
            int x = monthfind(month);
            printf("Month - %s -- %d\n",month,x);
            insertNode(&t1, x);
            afterinsert(&t1 ,x);
            inorder(t1);
            printf("\n");
        }
    }
    while(1){
        int i; 
        printf("Do you want to delete any node ? otherwise enter 0 - ");
        scanf("%d",i);
        if(i ==0){
            break;
        }
        else{
            t1 = removeNode(t1, i);
            
        }
    }

    //Add new node
    // insertNode(&t1, 1);
    // afterinsert(&t1, 1);
    // inorder(t1);
    // printf("|||||||||||||||||||||||||||||||||||||\n");
    // insertNode(&t1, 2);
    // afterinsert(&t1, 2);
    // inorder(t1);
    // printf("|||||||||||||||||||||||||||||||||||||\n");
    // insertNode(&t1, 3);
    // afterinsert(&t1, 3);
    // inorder(t1);
    // printf("|||||||||||||||||||||||||||||||||||||\n");
    // insertNode(&t1, 4);
    // afterinsert(&t1, 4);
    // inorder(t1);
    // printf("|||||||||||||||||||||||||||||||||||||\n");
    // insertNode(&t1, 5);
    // afterinsert(&t1, 5);
    // inorder(t1);
    // printf("|||||||||||||||||||||||||||||||||||||\n");
    // insertNode(&t1, 6);
    // afterinsert(&t1, 6);
    // inorder(t1);
    // printf("|||||||||||||||||||||||||||||||||||||\n");
    // insertNode(&t1, 7);
    // afterinsert(&t1, 7);
    // inorder(t1);
    // printf("|||||||||||||||||||||||||||||||||||||\n");
    // insertNode(&t1, 8);
    // afterinsert(&t1, 8);
    // inorder(t1);
    // printf("|||||||||||||||||||||||||||||||||||||\n");
    // insertNode(&t1, 50);
    // afterinsert(&t1, 50);
    // inorder(t1);
    Destroy_Tree(&t1);
    inorder(t1);
    return 0;
}