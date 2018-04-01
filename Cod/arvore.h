#ifndef _ARVORE_H
#define _ARVORE_H

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

void printArvoreRecursivo(e_tree *folha);
void insereArvoreOrdenada(e_tree *folhaInserir, e_tree *folha);
void printArvore(t_tree *arvore);
e_tree* alocaFolha();
t_tree* criarArvoreOrganizada(NETWORK *network);

#endif
