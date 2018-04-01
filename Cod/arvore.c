#include <stdio.h>
#include <stdlib.h>
#include "readgml.h"
#include "network.h"
#include "arvore.h"
#include <time.h>

/*Funcao recursiva que imprime a arvore em sentido em ordem
*primeiro ela caminha ate a ultima folha do lado esquerdo e depois volta
*imprimindo o valor e após isso indo para o lado direito
**Possui alguns ifs que servem para deixar a tela mais simetrica*/
void printArvoreRecursivo(e_tree *folha){
    if (folha != NULL){
        printArvoreRecursivo(folha->left);

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

/*Chama a funcao recursiva que ira imprimir a arvore*/
void printArvore(t_tree *arvore){
    printArvoreRecursivo(arvore->folha_inicial);
}

/*Funcao recursiva que procura e insere a folha no seu lugar adequado na arvore
*Primeiro ela verifica se o grau é menor ou maior, se for maior, ele verifica
*se ainda pode andar mais na arvore para o lado esquerdo e, em caso negatio, ele insere a folha na arvore.
*quando o grau é menor ele faz a mesma coisa, porem para o lado direito da arvore*/
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

/*Aloca uma folha e retorna o endereco dela*/
e_tree* alocaFolha(){
    e_tree *folha = (e_tree *) malloc(sizeof(e_tree));
    folha->left = NULL;
    folha->right = NULL;
    return folha;
}

/*Funcao que tem a responsabilidade de criar a arvore e enviar para a funcao
*insereArvoreOrdenada todos os dados necessarios para armazenar todos os vertices*/
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

/*Funcao que percorre a arvore desalocando todas as folhas no percurso*/
void desalocaFolha(e_tree *folha){
    if (folha != NULL){
        desalocaFolha(folha->left);
        free(folha);
        desalocaFolha(folha->right);
    }
    return;
}

/*Funcao que desaloca a arvore*/
void desalocaArvore(t_tree *arvore){
    desalocaFolha(arvore->folha_inicial);
    free(arvore);
}
