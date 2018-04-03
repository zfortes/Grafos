#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readgml.h"
#include "network.h"
#include "arvore.h"

#include "listas.h"

//Carrega o grafo na lista
void inicializaLista(t_list *lista, NETWORK* network){

    int i= network->nvertices -1;
    while (i >= 0){
        e_list *novoElemento = (e_list *) malloc(sizeof(e_list));
        novoElemento->prox = lista->primeiro;
        lista->primeiro = novoElemento;
        novoElemento->degree = network->vertex[i].degree;
        novoElemento->id = network->vertex[i].id;

        novoElemento->edge = (EDGE*)malloc(network->vertex->degree*sizeof(EDGE));

        for (int j = 0 ; j < network->vertex[i].degree; j++){
            novoElemento->edge[j].target = network->vertex[i].edge[j].target + 1;
        }

        i--;
    }
}

//Cria uma lista vazia
t_list* criaLista(){
    t_list *list = (t_list*) malloc(sizeof(list));
    list->primeiro=NULL;
    return list;
}

//Retira um elemento de qualquer posicao da lista
void retiraListaQualquerPosicao(t_list *lista, e_list* elemento){
    if (lista!=NULL){
        e_list *aux = lista->primeiro;
        e_list *aux2;
        if (lista->primeiro->id == elemento->id){
            lista->primeiro = lista->primeiro->prox;
            return ;
        }

        while ((aux->id != elemento->id) && (aux->prox != NULL)){
            aux2 = aux;
            aux=aux->prox;
            printf("passou\n" );
        }
            if (aux->id == elemento->id){
                printf("passou3\n" );
                aux2->prox == aux->prox;
            }

    }
}

//insere elemento no fim da lista
void insereElementoListaFinal(t_list *lista, e_list *elemento){

    if (elemento != NULL){
        e_list *novoElemento = (e_list*) malloc(sizeof(e_list));
        novoElemento->id = elemento->id;
        novoElemento->degree = elemento->degree;

        novoElemento->edge = (EDGE*)malloc(elemento->degree*sizeof(EDGE));

        for (int j = 0 ; j < elemento->degree; j++){
            novoElemento->edge[j].target = elemento->edge[j].target;
        }


        novoElemento->prox = NULL;


        e_list *aux = lista->primeiro;
        int i=0;
        if (aux != NULL){
            while (aux->prox != NULL){
                aux = aux->prox;

                i++;
            }
            aux->prox = novoElemento;
        }else{
            lista->primeiro = novoElemento;
        }
    }

}

//insere elemento no inicio da lista
void insereElementoListaInicio(t_list *lista, e_list *elemento){
    e_list *novoElemento = (e_list*) malloc(sizeof(e_list));
    novoElemento->id = elemento->id;
    novoElemento->degree = elemento->degree;

    novoElemento->edge = malloc(elemento->degree*sizeof(EDGE));
    for (int i = 0 ; i < elemento->degree; i++){
        novoElemento->edge[i] = elemento->edge[i];
    }


    novoElemento->prox = lista->primeiro;
    lista->primeiro = novoElemento;
}

//printa a lista de cliques
void insereListaCliquesFinal(t_list *lista){
    if (lista->primeiro != NULL){
        e_list *aux = lista->primeiro;
        printf("\n________________________\n");
        printf("Clique maximal {");
        while(aux != NULL){
            printf("%d,", aux->id);
            aux=aux->prox;
        }
        printf("}");
        printf("\n_____________________\n");
    }


}
//Retira um elemento da lista
e_list* retiraLista(t_list *lista){
    e_list *aux = lista->primeiro;
    if (lista->primeiro != NULL){
        lista->primeiro = lista->primeiro->prox;
    }else{
        aux = NULL;
    }
    return aux;
}
