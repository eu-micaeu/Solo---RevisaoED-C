#include<stdio.h>
#include<stdlib.h>

struct no{
	float info;
	struct no *prox;
};
typedef struct no No;

struct pilha{
	No *prim;
};
typedef struct pilha Pilha;

Pilha* inicializa(){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void push(Pilha *p, float v){
	No *novo;
	novo = (No*)malloc(sizeof(No));
	novo->info = v;
	novo->prox = p->prim;
	p->prim = novo;
}

void imprimir(Pilha *p){
	No *aux;
	
	if(p==NULL){
		printf("\nNao existe pilha!!!\n");
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

float pop(Pilha *p){
	No* aux;
	float v;
	if(p->prim==NULL){
		printf("\nPilha vazia!!!");
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

Pilha* eliminarPilha(Pilha *p){
	No *aux = p->prim, *t;
	if(aux==NULL){
		free(p);
		return NULL;
	}
	else{
		while(aux!=NULL){
			t = aux;
			aux = aux->prox;
			free(t);			
		}
		free(p);
		return NULL;
	}	
}

int main(){
	Pilha *p1;
	float r;
	p1 = inicializa();
	push(p1, 3.3);
	push(p1, 4.3);
	push(p1, 5.3);
	push(p1, 6.3);
	imprimir(p1);
	printf("\n");
	r = pop(p1);
	printf("\nNo %f excluido!\n",r);
	imprimir(p1);
	
	p1 = eliminarPilha(p1);

	imprimir(p1);
	return 0;
}