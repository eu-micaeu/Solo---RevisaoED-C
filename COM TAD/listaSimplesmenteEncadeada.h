typedef struct l{
    int info;
    struct l *prox;
} ListaSE;

ListaSE* inicializa_LE();

ListaSE* inserirInicio_LE(ListaSE *L, int num);

void imprimir_LE(ListaSE *L);

ListaSE* inserirFim_LE(ListaSE *L, int num);