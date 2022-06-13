#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

struct Student obj_S;    //object of struct
FILE *read_pointer;
FILE *write_pointer;
long int size = sizeof(obj_S);

void insert(){
    fseek(read_pointer,0,SEEK_END);
    printf("Enter student MIS - ");
    scanf("%d", &obj_S.mis);

    printf("Enter student Name - ");
    scanf("%s", obj_S.name);

    printf("Enter student stream - ");
    scanf("%s", obj_S.stream);

    printf("Enter student cgpa - ");
    scanf("%f", &obj_S.cgpa);

    printf("Enter student email - ");
    scanf("%s", obj_S.email);

    fwrite(&obj_S, size, 1, read_pointer);

    return;
}

void display(){
    rewind(read_pointer);

    while(fread(&obj_S, size, 1 , read_pointer)==1){
        printf("%d-%s-%s-%f-%s\n",obj_S.mis, obj_S.name, obj_S.stream, obj_S.cgpa, obj_S.email);
    }
}

void search(){
    char a[50];
    printf("Enter name you want to search - ");
    scanf("%s", a);
    rewind(read_pointer);

    while(fread(&obj_S, size, 1, read_pointer) == 1){
        if(strcmp(obj_S.name, a)== 0){
            printf("%d-%s-%s-%f-%s\n",obj_S.mis, obj_S.name, obj_S.stream, obj_S.cgpa, obj_S.email);
            break;
        }
    }
}

void delete(){
    char a[50];
    printf("Enter student name to delete - ");
    scanf("%s", a);
    write_pointer = fopen("temp.txt","wb");

    rewind(read_pointer);
    while(fread(&obj_S, size, 1, read_pointer) == 1){
        if(strcmp(obj_S.name, a)!=0){
            fwrite(&obj_S, size,1, write_pointer);
        }
    }

    fclose(read_pointer);
    fclose(write_pointer);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    read_pointer = fopen("data.txt","rb+");
    printf("Deletion Successful\n");
}

void Menu(){
    printf("Menu Options - \n");
    printf("1 - Insert Record\n");
    printf("2 - Search Record by any field\n");
    printf("3 - Delete Record\n");
    printf("4 - Display all Records\n");
    printf("5 - Display count of students from each stream\n");
    printf("0 - To Exit\n");
}

int main(){

    read_pointer = fopen("data.txt", "rb+");

    if(read_pointer == NULL){
        printf("Cannot open file");
        return 0;
    }

    Menu();

    insert();

    display();

    //delete();

    //search();

    return 0;
}
