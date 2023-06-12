#include <stdio.h>
#include <stdlib.h>
#include "filaComVetor.h"

#define N 100

FilaCV* criaFCV(void)
{
    FilaCV* f = (FilaCV*)malloc(sizeof(FilaCV));
    f->ini = f->fim = 0;
    return f;
}


void insereFCV(FilaCV* f, float v)
{
    if (((f->fim + 1) % N) == f->ini) { 
        printf("Capacidade da fila estourou.\n");
        exit(1);
    }
    f->vet[f->fim] = v;
    f->fim = (f->fim + 1) % N;
}

int vaziaFCV(FilaCV* f)
{
    return (f->ini == f->fim);
}

float retiraFCV(FilaCV* f)
{
    float v;
    if (vaziaFCV(f)) {
        printf("Fila vazia.\n");
        exit(1);
    }
    v = f->vet[f->ini];
    f->ini = (f->ini + 1) % N;
    return v;
}

void imprimeFCV(FilaCV* f)
{
    int i = f->ini;
    while (i != f->fim) {
        printf("%.2f \n", f->vet[i]);
        i = (i + 1) % N;
    }
    printf("\n");
}

