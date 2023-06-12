#include <stdio.h>
#include <stdlib.h>
#include "pilhaComVetor.h"

PilhaCV *cria()
{
    PilhaCV *p = (PilhaCV *)malloc(sizeof(PilhaCV));
    p->n = 0;
    return p;
}

void push(PilhaCV *p, int v)
{
    if (p->n == MAX)
    {
        printf("Capacidade da PilhaCV estourou.\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

float pop(PilhaCV *p)
{
    float v;
    if (p->n == MAX)
    {
        printf("PilhaCV vazia.\n");
        exit(1); /* aborta programa */
    }

    v = p->vet[p->n - 1];
    p->n--;
    return v;
}

void imprime(PilhaCV *p)
{
    printf("\nPilhaCV: ");
    for (int i = p->n - 1; i >= 0; i--)
    {
        printf("\n%d", p->vet[i]);
    }
    printf("\n");
}

