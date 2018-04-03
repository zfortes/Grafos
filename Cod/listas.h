
/*################ LISTAS ################*/
typedef struct eList{
    int id;
    int degree;
    struct eList *prox;
    EDGE *edge;
}e_list;


typedef struct list{
    struct eList *primeiro;
}t_list;

typedef struct listaClqiues{
    t_list *lista;
    int tamanho;
}cliques_list;

/*#######################################*/

//Carrega o grafo na lista
void inicializaLista(t_list *, NETWORK *);

//Cria uma lista vazia
t_list* criaLista();

//insere elemento no fim da lista
void insereElementoListaFinal(t_list *, e_list *);

//insere elemento no inicio da lista
void insereElementoListaInicio(t_list *lista, e_list *elemento);

//Exibi o clique de cliques
void insereListaCliquesFinal(t_list *lista);

//Retira um elemento da lista
e_list* retiraLista(t_list *lista);

//Retira um elemento de qualquer posicao da lista
void retiraListaQualquerPosicao(t_list *lista, e_list* elemento);
