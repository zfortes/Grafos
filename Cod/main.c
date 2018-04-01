#include <stdio.h>
#include <stdlib.h>
#include "readgml.h"
#include "network.h"
#include <time.h>

/*################ LISTAS ################*/
typedef struct eList{
    int id;
    int degree;
    struct eList *prox;
}e_list;

typedef struct list{
    struct eList *primeiro;
}t_list;

/*#######################################*/



/*################# Arvores ###############*/
typedef struct tree{
    struct tree *left;
    struct tree *right;
    VERTEX *vertex;
    int id;
    int degree;
}e_tree;

typedef struct t_tree{
    struct tree* folha_inicial;
}t_tree;

/*#######################################*/

void inserirLista(t_list *lista, NETWORK *);

t_list* criaLista(){
    t_list *list = (t_list*) malloc(sizeof(list));
    list->primeiro=NULL;
    return list;
}


void inserirLista(t_list *lista, NETWORK* network){

    int i;
    while (i < network->nvertices){
        e_list *novoElemento = (e_list *) malloc(sizeof(e_list));
        novoElemento->prox = lista->primeiro;
        lista->primeiro = novoElemento;
        novoElemento->degree = network->vertex[i].degree;
        novoElemento->id = network->vertex[i].id;
        i++;
    }




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

void insereArvoreOrdenada(e_tree *folhaInserir, e_tree *folha){
    if (folhaInserir->degree >= folha->degree){
        if (folha->left == NULL){
            folha->left = folhaInserir;
            return ;
        }
        insereArvoreOrdenada(folhaInserir, folha->left);
        return ;
    }
    if (folha->right == NULL){
        folha->right = folhaInserir;
        return ;
    }
    insereArvoreOrdenada(folhaInserir, folha->right);
    return ;
}

e_tree* alocaFolha(){
    e_tree *folha = (e_tree *) malloc(sizeof(e_tree));
    folha->left = NULL;
    folha->right = NULL;
    return folha;
}

t_tree* criarArvoreOrganizada(NETWORK *network){
    int i=0;
    t_tree *arvore = (t_tree *) malloc(sizeof(t_tree));

    e_tree *aux = NULL;
    arvore->folha_inicial = alocaFolha();
    arvore->folha_inicial->id = network->vertex[i].id;
    arvore->folha_inicial->degree = network->vertex[i].degree;
    i++;

    while (i < network->nvertices){
        aux = alocaFolha();
        aux->id = network->vertex[i].id;
        aux->degree = network->vertex[i].degree;
        insereArvoreOrdenada(aux, arvore->folha_inicial);
        i++;
    }
    return arvore;
}

//Le o grafo do arquivo e o salva em memoria
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

/*Funcao recursiva que imprime a arvore*/
void printArvoreRecursivo(e_tree *folha){
    if (folha != NULL){
        printArvoreRecursivo(folha->left);

        /*Paroniza os espaços para que a interface fique simetrica*/
        if (folha->id < 10){
            printf("ID = 0%d |", folha->id);
        }else{
            printf("ID = %d |", folha->id);
        }
        if (folha->degree < 10){
            printf("GRAU = 0%d |\n", folha->degree);
        }else{
            printf("GRAU = %d |\n", folha->degree);
        }
        
        printArvoreRecursivo(folha->right);
    }
    return;
}

void printArvore(t_tree *arvore){
    printArvoreRecursivo(arvore->folha_inicial);
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

    printArvore(arvore);

   /*
   e_list *percorre = lista->primeiro;
   printf("passou\n" );
   while (percorre != NULL){
       printf("%d\n", percorre->i);
       percorre = percorre->prox;
   }*/
    return 0;
}
