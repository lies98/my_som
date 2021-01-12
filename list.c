//
// Created by Lies Amarouche on 08/01/2021.
//
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "list.h"
#include "data.h"

list list_allocation(int size) {
    list p;
    p = malloc(size);
    if(p == NULL) {
        fprintf(stderr, "Erreur : impossible d’allouer la memoire\n");
        exit(-1);
    }
    return p;
}
//creer une nouvelle liste
list list_contructor() {
    list l;
    l = list_allocation(sizeof(*l));
    l->next = l;
    l->prev = l;
    return l;
}

//renvoie la taille d'une liste
int size(list l) {
    int count;
    list it;
    count = 0;
    for(it = l->next; it != l; it = it->next) {
        count++;
    }
    return count;
}
position back(list l) {
    return l->prev->val;
}
//ajouter un elment a la fin de la liste
void push_back(list l, position data) {
    list cell;
    cell = list_allocation(sizeof(*cell));

    cell->val.i = data.i;
    cell->val.j = data.j;
    cell->prev = l->prev;
    cell->next = l;
    l->prev->next = cell;
    l->prev = cell;
}

void pop_back(list l) {
    list to_del;
    to_del = l->prev;
    l->prev->prev->next = l;
    l->prev = l->prev->prev;
    free(to_del);
}
