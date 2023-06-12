#include <stdio.h>
#include <stdlib.h>
#include "listaCircularEncadeada.h"

//Inicializar
ListaC* inicializa_LC(){
    return NULL;
}

//Inserir no incio
ListaC* inserirInicio_LC(ListaC *L, int num){
    ListaC *novo, *aux = L;
	novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = num;

    if(L!=NULL){
        novo->prox = L;
    }else{
		novo->prox = novo;
		return novo;
	}

    while(aux->prox != L){
        aux = aux->prox;
    }

    aux->prox = novo;

    return novo;
}

//Imprimir
void imprimir_LC(ListaC *L){
	ListaC *aux = L;
	if(aux != NULL){
		do{
			printf("\nValor: %d", aux->info);
			aux = aux->prox;
		}while(aux != L);
	}
    printf("\n");
}

//Inserir no Fim
ListaC* inserirFim_LC(ListaC *L, int num){
	ListaC *novo, *aux = L;
	novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = num;
	if(L != NULL){
		novo->prox = L;
		while(aux->prox != L){
			aux = aux->prox;			
		}
		aux->prox = novo;
		return L;
	}
	else{
		novo->prox = novo;
		return novo;
	}
}