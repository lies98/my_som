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
position front(list l) {
    return l->next->val;
}
//ajouter un element a la fin de la liste
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
//retire le premier element de la list
void pop_front(list l) {
    list to_del;
    to_del = l->next;
    l->next->next->prev = l;
    l->next = l->next->next;
    free(to_del);
}

position getList(list l, unsigned int index){

    unsigned int count;
    position it= l->next->val;

    for(count = 0; count < index; ++count){
        l = l->next;
        it = l->next->val;
    }


    return it;


}

void clear(list l) {
    list it, to_del;
    it = l->next;
    while(it != l) {
        to_del = it;
        it = it->next;
        free(to_del);
    }
    l->next = l;
    l->prev = l;
}
