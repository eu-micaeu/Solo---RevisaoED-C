//Lista circular:

//Struct
typedef struct lc{
    int info;
    struct lc *prox;
}ListaC;

//Inicializar
ListaC* inicializa_LC();

//Inserir no incio
ListaC* inserirInicio_LC(ListaC *L, int num);

//Imprimir
void imprimir_LC(ListaC *L);

//Inserir no Fim
ListaC* inserirFim_LC(ListaC *L, int num);