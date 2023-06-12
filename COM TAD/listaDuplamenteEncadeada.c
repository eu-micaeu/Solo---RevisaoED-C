#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

ListaDE* inicializa_LDE(){
    return NULL;
}

//Inserir no incio
ListaDE *inserirInicio_LDE(ListaDE *L, int num)
{
    ListaDE *novo;

    novo = (ListaDE*) malloc(sizeof(ListaDE));
    novo->info = num;
    novo->prox = L;
    novo->ant = NULL;

    if (L != NULL) {
        L->ant = novo;
    }
    return novo;
}

//Imprimir
void imprimir_LDE(ListaDE *L){
    while (L != NULL) {
        printf("\nValor: %d",  L->info);
        L = L->prox;
    }
    printf("\n");
}

//Inserir no Fim
ListaDE *inserirFim_LDE(ListaDE *L, int num)
{
    ListaDE *novo, *aux = L;

    novo = (ListaDE*) malloc(sizeof(ListaDE));
    novo->info = num;
    novo->prox = NULL;
    novo->ant = NULL;

    if (L == NULL) {
        return novo;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        return L;
    }
}