#include <stdio.h>
#include <stdlib.h>
#include "readgml.h"
#include "network.h"
#include <time.h>

typedef struct eList{
    int i;
    struct eList *prox;
}e_list;

typedef struct list{
    struct eList *primeiro;
}t_list;

t_list* criaLista();
void inserirLista(t_list *lista, int n);

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
//Le o grafo do arquivo e o salva em memoria
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


    /*
    printf("%d\n", network->nvertices);
    printf("directed = %d\n", network->directed);

    // imprime todos os ids dos vertices
    printf("\n____ID_____\n", );
    for (i=0; i < 34; i++){
        printf("Id 2 = %d\n", network->vertex[i].id);
    }
    printf("\n___________\n" );

    // imprime
    printf("Id 2 = %d\n", network->vertex[0].id);
    printf("Grau = %d\n", network->vertex[0].degree);
    */

    fclose(rest);
	return 0;
}

int main(){
    int i = 0;

    t_list *lista = criaLista();



    ler();

   for (i; i<11; i++){
       inserirLista(lista, i);
   }

   /*
   e_list *percorre = lista->primeiro;
   printf("passou\n" );
   while (percorre != NULL){
       printf("%d\n", percorre->i);
       percorre = percorre->prox;
   }*/
    return 0;
}
