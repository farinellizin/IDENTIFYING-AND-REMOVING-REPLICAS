#ifndef LISTA_HPP
#define LISTA_HPP
#define MAXTAM 100
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct Item {
    string val;   
} Item;

typedef struct List {
    Item vet[MAXTAM];
    int first;
    int last;
} List;

void create_empty_list (List *l);
void list_insert(List *l, Item d);
void list_print(List*l);
void name_most_popsup(List *l);
void replacing_repeated_names(List *l);

#endif