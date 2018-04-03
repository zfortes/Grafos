#include <stdio.h>
#include <stdlib.h>
#include "readgml.h"
#include "network.h"
#include "arvore.h"
#include "listas.h"
#include <time.h>

t_list *listaGraph;

//Une um elemento a uma lista
t_list* uniao(t_list *lista, e_list *elemento){
    if (elemento != NULL){
        insereElementoListaFinal(lista, elemento);
    }
    return lista;
}

//Procura pelos vizinhos do elemento
t_list* inter(t_list *lista, e_list *elemento){
    t_list *novaLista  = criaLista();
    if (elemento != NULL){
        e_list *aux = lista->primeiro;
        int i;
        while (aux != NULL){
            for (i=0; i <= elemento->degree; i++){
                if (aux->id == elemento->edge[i].target){
                    insereElementoListaFinal(novaLista, aux);
                }
            }
            aux = aux->prox;
        }
    }

    return novaLista;
}


void printaLista(t_list *lista){
    if (lista != NULL){
        e_list *aux = lista->primeiro;
        while (aux != NULL){
            printf("%d, ", aux->id);
            aux = aux->prox;
        }
    }
}




void procuraClique(t_list *r, t_list *x, t_list *p){
    t_list *nr ;
    t_list *nx ;
    t_list *np ;


    if ((x->primeiro == NULL) && (p->primeiro == NULL)){
        insereListaCliquesFinal(r);
        return ;
    }else{

        e_list *v;

        v = retiraLista(p);
        while (v != NULL ){

            nr = uniao(r, v);

            np = inter(p, v);

            nx = inter(x, v);


            procuraClique(nr, nx, np);

            printf("______________\n" );
            printf("V = %d\n", v->id);
            printaLista(r);
            printf("\n______________\n" );
            retiraListaQualquerPosicao(r, v);
            printf("______________\n" );
            printaLista(r);
            printf("\n______________\n" );
            printf("**********************\n" );
            insereElementoListaFinal(x, v);
            v = retiraLista(p);

        }

    }
}


/*Le o grafo do arquivo e o salva em memoria*/
int ler(NETWORK *network){
	char aux;
	int i=0, j=0;
	FILE *rest;
	srand(time(NULL));
	/*Abre o arquivo e joga para dentro da variável*/
	rest=fopen("karate.gml", "r");

    /*Verifica se o arquivo foi encontrado*/
	if(rest==NULL){
        printf("________________________\n");
		printf("Impossivel ler o arquivo\n");
		return 1;
	}

    /*Envia o arquivos para a funcao que le ele*/
    read_network(network, rest);

    fclose(rest);
	return 0;
}


int main(){
    int i = 0;

    //t_list *lista = criaLista();
    NETWORK *network = (NETWORK *) malloc(sizeof(NETWORK));


    /*Encerra o programa se a funcao ler retornar algum erro*/
    if (ler(network) == 1){
        printf("Programa encerrado!\n");
        printf("________________________\n");
        return 0;
    }
    t_tree *arvore = criarArvoreOrganizada(network);
     listaGraph = criaLista();




     t_list *listaP;
     listaP = criaLista();
     inicializaLista(listaGraph, network);
     inicializaLista(listaP, network);

     t_list *nr = criaLista();
     t_list *nx = criaLista();

     procuraClique(nr, nx, listaP);


    printArvore(arvore);

    desalocaArvore(arvore);


    return 0;
}
