//
// Created by Lies Amarouche on 08/02/2021.
//

#ifndef MY_SOM_LIST_H
#define MY_SOM_LIST_H
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include<assert.h>
#include "data.h"





struct element {
    position val;         // valeur contenue dans la cellule
    struct element *next; // pointeur sur la cellule suivante
    struct element *prev; // pointeur sur la cellule precedente
};

typedef struct element* list;

list list_allocation(int size);
list list_contructor();
int size(list l) ;;
position back(list l);
void push_back(list l, position data);
void pop_back(list l);
#endif //MY_SOM_LIST_H
