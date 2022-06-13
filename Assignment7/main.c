#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

struct Student obj_S;    //object of struct
FILE *read_pointer;
FILE *write_pointer;
long int size = sizeof(obj_S);

void insert(){
    printf("Inserting students record option active!\n");
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
    printf("Displaying all Records - \n");
    rewind(read_pointer);

    while(fread(&obj_S, size, 1 , read_pointer)==1){
        printf("%d-%s-%s-%f-%s\n",obj_S.mis, obj_S.name, obj_S.stream, obj_S.cgpa, obj_S.email);
    }
    return;
}

void search(){
    char a[50];
    printf("By which field do you want to search mis, name, stream, cgpa or email - ");
    scanf("%s", a);
    rewind(read_pointer);

    int flag = 0;

    if(strcmp(a,"mis")==0){
        
        int m;
        printf("Please enter MIS: ");
        scanf("%d", &m);
        while(fread(&obj_S, size, 1, read_pointer) == 1){
            if(obj_S.mis==m){
                printf("%d-%s-%s-%f-%s\n",obj_S.mis, obj_S.name, obj_S.stream, obj_S.cgpa, obj_S.email);
                flag = 1;
            }
        }
    }

    else if(strcmp(a,"name")==0){
        char b[50];
        printf("Please enter name: ");
        scanf("%s",b);
        while(fread(&obj_S, size, 1, read_pointer) == 1){
            if(strcmp(obj_S.name, b)== 0){
                printf("%d-%s-%s-%f-%s\n",obj_S.mis, obj_S.name, obj_S.stream, obj_S.cgpa, obj_S.email);
                flag = 1;
            }
        }
    }

    else if(strcmp(a,"stream")==0){
        char b[50];
        printf("Please enter stream: ");
        scanf("%s",b);
        while(fread(&obj_S, size, 1, read_pointer) == 1){
            if(strcmp(obj_S.stream, b)== 0){
                printf("%d-%s-%s-%f-%s\n",obj_S.mis, obj_S.name, obj_S.stream, obj_S.cgpa, obj_S.email);
                flag = 1;
            }
        }
    }

    else if(strcmp(a,"cgpa")==0){
        float m;
        printf("Please enter CGPA: ");
        scanf("%f", &m);
        while(fread(&obj_S, size, 1, read_pointer) == 1){
            if(obj_S.cgpa==m){
                printf("%d-%s-%s-%f-%s\n",obj_S.mis, obj_S.name, obj_S.stream, obj_S.cgpa, obj_S.email);
                flag = 1;
            }
        }
    }

    else if(strcmp(a,"email")==0){
        char b[50];
        printf("Please enter email: ");
        scanf("%s",b);
        while(fread(&obj_S, size, 1, read_pointer) == 1){
            if(strcmp(obj_S.email, b)== 0){
                printf("%d-%s-%s-%f-%s\n",obj_S.mis, obj_S.name, obj_S.stream, obj_S.cgpa, obj_S.email);
                flag = 1;
            }
        }
    }

    else{
        printf("Please enter proper field\n");
        return;
    }

    if(flag == 0){
        printf("No results found !\n");
    }
    return;
}

void delete(){
    int m;
    printf("Enter student mis to delete - ");
    scanf("%d", &m);
    write_pointer = fopen("temp.dat","wb");

    rewind(read_pointer);
    while(fread(&obj_S, size, 1, read_pointer) == 1){
        if(obj_S.mis == m){
            fwrite(&obj_S, size,1, write_pointer);
        }
    }

    fclose(read_pointer);
    fclose(write_pointer);
    remove("data.dat");
    rename("temp.dat", "data.dat");
    read_pointer = fopen("data.dat","rb+");
    printf("Deletion Successful\n");
    return;
}

void stream_count(){
    rewind(read_pointer);
    int comp = 0,elec = 0,instru = 0,meta = 0,prod = 0,entc = 0,civil = 0,mech = 0;
    while(fread(&obj_S, size, 1, read_pointer) == 1){
        if(strcmp(obj_S.stream,"comp")==0){
            comp+=1;
        }
        if(strcmp(obj_S.stream,"elec")==0){
            elec+=1;
        }
        if(strcmp(obj_S.stream,"instru")==0){
            instru+=1;
        }
        if(strcmp(obj_S.stream,"prod")==0){
            prod+=1;
        }
        if(strcmp(obj_S.stream,"civil")==0){
            civil+=1;
        }
        if(strcmp(obj_S.stream,"entc")==0){
            entc+=1;
        }
        if(strcmp(obj_S.stream,"mech")==0){
            mech+=1;
        }
        if(strcmp(obj_S.stream,"meta")==0){
            meta+=1;
        }
    }

    printf("Comp count - %d\n",comp);
    printf("Elec count - %d\n",elec);
    printf("Entc count - %d\n",entc);
    printf("Meta count - %d\n",meta);
    printf("Instru count - %d\n",instru);
    printf("Civil count - %d\n",civil);
    printf("Mech count - %d\n",mech);
    printf("Prod count - %d\n",prod);
    return;
}

void Menu(){
    printf("Menu Options - \n");
    printf("1 - Insert Record\n");
    printf("2 - Search Record by any field\n");
    printf("3 - Delete Record\n");
    printf("4 - Display all Records\n");
    printf("5 - Display count of students from each stream\n");
    printf("0 - To Exit\n");
    printf("Streams available - comp,elec,instru,meta,prod,entc,civil,mech\n");
}

int main(){

    read_pointer = fopen("data.dat", "rb+");

    if(read_pointer == NULL){
        printf("Cannot open file");
        return 0;
    }

    Menu();

    while(1){

            int o;
            printf("Enter option - ");
            scanf("%d",&o);
            printf("\n");
            if(o==1){
                insert();
                printf("\n");
            }
            else if(o==2){
                search();
                printf("\n");
            }
            else if(o==3){
                delete();
                printf("\n");
            }
            else if(o==4){
                display();
                printf("\n");
            }
            else if(o==5){
                stream_count();
                printf("\n");
            }
            else if(o==0){
                break;
            }
            else{
                printf("Invalid option\n");
            }
    }

    return 0;
}
