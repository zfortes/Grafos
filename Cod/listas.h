#ifndef _LISTAS_H
#define _LISTAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct eList{
    int i;
    struct eList *prox;
}e_list;

typedef struct list{
    struct eList *primeiro;
}t_list;

t_list* criaLista();
void inserirLista(t_list *lista, int n);

#endif
