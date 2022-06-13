#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int mis;
    char name[50];
    char stream[50];
    float cgpa;
    char email[50];
};

void Menu();

void display();
void insert();
void delete();
void search();
