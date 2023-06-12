typedef struct lde{
    int info;
    struct lde *prox;
    struct lde *ant;
} ListaDE;

//Inicializar
ListaDE* inicializa_LDE();

//Inserir no incio
ListaDE *inserirInicio_LDE(ListaDE *L, int num);

//Imprimir
void imprimir_LDE(ListaDE *L);

//Inserir no Fim
ListaDE *inserirFim_LDE(ListaDE *L, int num);