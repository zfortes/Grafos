#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "readgml.h"
#include "network.h"
#include <time.h>

int ler(){
	char aux;
	int i=0, j=0;
	FILE *rest;
	srand(time(NULL));
	/*Abre o arquivo e joga para dentro da variável*/
	rest=fopen("karate.gml", "r");

	if(rest==NULL){
		printf("Impossivel ler o arquivo\n");
		return 1;
	}

    NETWORK *network = (NETWORK *) malloc(sizeof(NETWORK));

    read_network(network, rest);



    printf("%d\n", network->nvertices);


    fclose(rest);
	return 0;
}

int main(){
    int i = 0;

    //t_list *lista = criaLista();



    ler();







//    for (i; i<11; i++){
//        inserirLista(lista, i);
//    }

//    e_list *percorre = lista->primeiro;
//    printf("passou\n" );
//    while (percorre != NULL){
//        printf("%d\n", percorre->i);
//        percorre = percorre->prox;
//    }
    return 0;
}
