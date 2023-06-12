#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    float valor;
    struct No* prox;
} No;

typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;

Fila* cria(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insere(Fila* f, float v)
{
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = v;
    novoNo->prox = NULL;
    
    if (f->fim == NULL) {
        f->inicio = novoNo;
        f->fim = novoNo;
    } else {
        f->fim->prox = novoNo;
        f->fim = novoNo;
    }
}

int vazia(Fila* f)
{
    return (f->inicio == NULL);
}

float retira(Fila* f)
{
    if (vazia(f)) {
        printf("Fila vazia.\n");
        exit(1); /* aborta programa */
    }
    
    float valor = f->inicio->valor;
    No* temp = f->inicio;
    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp);
    
    return valor;
}

void libera(Fila* f)
{
    No* atual = f->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    free(f);
}

void imprime(Fila* f)
{
    No* atual = f->inicio;
    while (atual != NULL) {
        printf("%.2f --> ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main()
{
    Fila* fila = cria();
    
    insere(fila, 1.5);
    insere(fila, 2.3);
    insere(fila, 4.7);
    
    imprime(fila);
    
    printf("Elemento removido: %.2f\n", retira(fila));
    printf("Elemento removido: %.2f\n", retira(fila));
    
    imprime(fila);
    
    insere(fila, 3.1);
    insere(fila, 1.3);
    
    imprime(fila);

    printf("Elemento removido: %.2f\n", retira(fila));
    printf("Elemento removido: %.2f\n", retira(fila));

    imprime(fila);
    
    libera(fila);
    
    return 0;
}
