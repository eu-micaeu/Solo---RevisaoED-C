#include <stdio.h>
#include <stdlib.h>
#include "listaSimplesmenteEncadeada.h"

ListaSE* inicializa_LE(){
    return NULL;
}

ListaSE* inserirInicio_LE(ListaSE *L, int num){
    ListaSE *aux = (ListaSE*)malloc(sizeof(ListaSE));
    aux->info = num;
    aux->prox = L;
    return aux;
}

void imprimir_LE(ListaSE *L){
    while(L != NULL){
        printf("\nValor: %d", L->info);
        L = L->prox;
    }
    printf("\n");
}

ListaSE* inserirFim_LE(ListaSE* L, int num){
    ListaSE* aux;
    ListaSE* novo = (ListaSE*)malloc(sizeof(ListaSE));
    novo->info = num;
    novo->prox = NULL;
    if (L == NULL){
        return novo;
    }else{
        aux = L;
        
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        
        aux->prox = novo;
        return L;
    }
}
