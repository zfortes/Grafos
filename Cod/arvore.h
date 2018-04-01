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

/*Funcao recursiva que imprime a arvore em sentido em ordem
*primeiro ela caminha ate a ultima folha do lado esquerdo e depois volta
*imprimindo o valor e após isso indo para o lado direito
**Possui alguns ifs que servem para deixar a tela mais simetrica*/
void printArvoreRecursivo(e_tree *folha);

/*Funcao recursiva que procura e insere a folha no seu lugar adequado na arvore
*Primeiro ela verifica se o grau é menor ou maior, se for maior, ele verifica
*se ainda pode andar mais na arvore para o lado esquerdo e, em caso negatio, ele insere a folha na arvore.
*quando o grau é menor ele faz a mesma coisa, porem para o lado direito da arvore*/
void insereArvoreOrdenada(e_tree *folhaInserir, e_tree *folha);

/*Chama a funcao recursiva que ira imprimir a arvore*/
void printArvore(t_tree *arvore);

/*Aloca uma folha e retorna o endereco dela*/
e_tree* alocaFolha();

/*Funcao que tem a responsabilidade de criar a arvore e enviar para a funcao
*insereArvoreOrdenada todos os dados necessarios para armazenar todos os vertices*/
t_tree* criarArvoreOrganizada(NETWORK *network);

/*Funcao que percorre a arvore desalocando todas as folhas no percurso*/
void desalocaFolha(e_tree *folha);

/*Funcao que desaloca a arvore*/
void desalocaArvore(t_tree *arvore);

#endif
