#include <stdio.h>
#include <stdlib.h>
#include "filaComListaEncadeada.h"

FilaCLE* criaFLE(void)
{
    FilaCLE* f = (FilaCLE*)malloc(sizeof(FilaCLE));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insereFLE(FilaCLE* f, float v)
{
    NoLE* novoNo = (NoLE*)malloc(sizeof(NoLE));
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

int vaziaFLE(FilaCLE* f)
{
    return (f->inicio == NULL);
}

float retiraFLE(FilaCLE* f)
{
    if (vaziaFLE(f)) {
        printf("FilaCLE vazia.\n");
        exit(1); /* aborta programa */
    }
    
    float valor = f->inicio->valor;
    NoLE* temp = f->inicio;
    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp);
    
    return valor;
}

void imprimeFLE(FilaCLE* f)
{
    NoLE* atual = f->inicio;
    while (atual != NULL) {
        printf("%.2f --> ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}


