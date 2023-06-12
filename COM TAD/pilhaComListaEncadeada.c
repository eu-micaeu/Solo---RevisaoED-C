#include<stdio.h>
#include<stdlib.h>
#include "pilhaComListaEncadeada.h"

PilhaLE* criaLE(){
	PilhaLE *p = (PilhaLE*)malloc(sizeof(PilhaLE));
	p->prim = NULL;
	return p;
}

void pushLE(PilhaLE *p, float v){
	No *novo;
	novo = (No*)malloc(sizeof(No));
	novo->info = v;
	novo->prox = p->prim;
	p->prim = novo;
}

void imprimirLE(PilhaLE *p){
	No *aux;
	
	if(p==NULL){
		printf("\nNao existe PilhaLE!!!\n");
		exit(1);
	}
	else{
		aux = p->prim;
		while(aux!=NULL){
			printf("%f\n",aux->info);
			aux = aux->prox;
		}
	}
}

float popLE(PilhaLE *p){
	No* aux;
	float v;
	if(p->prim==NULL){
		printf("\nPilhaLE vazia!!!");
		exit(1);
	}
	else{
		aux = p->prim->prox;
		v = p->prim->info;
		free(p->prim);
		p->prim = aux;
		return v;
	}	
}

