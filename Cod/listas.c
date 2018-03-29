#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

t_list* criaLista(){
    t_list *list = (t_list*) malloc(sizeof(list));
    list->primeiro=NULL;
    return list;
}

void inserirLista(t_list *lista, int n){
    e_list *novoElemento = (e_list *) malloc(sizeof(e_list));
    
    novoElemento->prox = lista->primeiro;
    lista->primeiro = novoElemento;
    novoElemento->i = n;


    //if (lista->primeiro != NULL){
    //    lista->primeiro = novoElemento;
    //    novoElemento->i = n;
    //    return ;
    //}
    //Irá percorrer toda a lista ate chegar na ultima posicao
    //e_list *percorre = lista->primeiro;
    //while (percorre->prox != NULL){
    //    percorre = percorre->prox;
    //}

}
