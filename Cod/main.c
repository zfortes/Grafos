#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


int main(){
    int i = 0;

    t_list *lista = criaLista();

    for (i; i<11; i++){
        inserirLista(lista, i);
    }

    e_list *percorre = lista->primeiro;
    printf("passou\n" );
    while (percorre != NULL){
        printf("%d\n", percorre->i);
        percorre = percorre->prox;
    }
    return 0;
}
