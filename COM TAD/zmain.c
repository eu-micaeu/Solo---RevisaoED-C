#include <stdio.h>
#include <stdlib.h>
#include "listaSimplesmenteEncadeada.h"
#include "listaCircularEncadeada.h"
#include "listaDuplamenteEncadeada.h"
#include "pilhaComVetor.h"
#include "pilhaComListaEncadeada.h"
#include "filaComVetor.h"
#include "filaComListaEncadeada.h"
#include "arvoreBinaria.h"

int main()
{
    int op = 0, opLE = 0;
    int vLESI, vLESF;
    ListaSE *listaSE;
    ListaC *listaC;
    ListaDE *listaDE;
    PilhaCV *pilhaCV;
    PilhaLE *pilhaLE;
    Node *raiz;
    FilaCV *filaCV;
    FilaCLE *filaCLE;
    do
    {
        printf("\nESCOLHA UMA OPCAO:\n1 - Lista Encadeada Simples\n2 - Lista Encadeada Circular\n3 - Lista Duplamente Encadeada\n4 - Pilha + Vetor\n5 - Pilha + Lista Encadeada Simples\n6 - Fila + Vetor\n7 - Fila + Lista Encadeada Simples\n8 - Arvore Binaria\n0 - Sair\n\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            do
            {

                printf("\nESCOLHA UMA OPCAO:\n1 - Inicializar\n2 - Inserir no inicio\n3 - Inserir no fim\n4 - Imprimir\n0 - Sair\n\n");
                scanf("%d", &opLE);
                switch (opLE)
                {
                case 1:
                    listaSE = inicializa_LE();
                    break;
                case 2:
                    printf("Digite um valor para inserir no inicio: ");
                    scanf("%d", &vLESI);
                    listaSE = inserirInicio_LE(listaSE, vLESI);
                    break;
                case 3:
                    printf("Digite um valor para inserir no fim: ");
                    scanf("%d", &vLESF);
                    listaSE = inserirFim_LE(listaSE, vLESF);
                    break;
                case 4:
                    imprimir_LE(listaSE);
                    break;
                default:
                    break;
                }
            } while (opLE != 0);
            break;
        case 2:
            do
            {

                printf("\nESCOLHA UMA OPCAO:\n1 - Inicializar\n2 - Inserir no inicio\n3 - Inserir no fim\n4 - Imprimir\n0 - Sair\n\n");
                scanf("%d", &opLE);
                switch (opLE)
                {
                case 1:
                    listaC = inicializa_LC();
                    break;
                case 2:
                    printf("Digite um valor para inserir no inicio: ");
                    scanf("%d", &vLESI);
                    listaC = inserirInicio_LC(listaC, vLESI);
                    break;
                case 3:
                    printf("Digite um valor para inserir no fim: ");
                    scanf("%d", &vLESF);
                    listaC = inserirFim_LC(listaC, vLESF);
                    break;
                case 4:
                    imprimir_LC(listaC);
                    break;
                default:
                    break;
                }
            } while (opLE != 0);
            break;
        case 3:
            do
            {

                printf("\nESCOLHA UMA OPCAO:\n1 - Inicializar\n2 - Inserir no inicio\n3 - Inserir no fim\n4 - Imprimir\n0 - Sair\n\n");
                scanf("%d", &opLE);
                switch (opLE)
                {
                case 1:
                    listaDE = inicializa_LDE();
                    break;
                case 2:
                    printf("Digite um valor para inserir no inicio: ");
                    scanf("%d", &vLESI);
                    listaDE = inserirInicio_LDE(listaDE, vLESI);
                    break;
                case 3:
                    printf("Digite um valor para inserir no fim: ");
                    scanf("%d", &vLESF);
                    listaDE = inserirFim_LDE(listaDE, vLESF);
                    break;
                case 4:
                    imprimir_LDE(listaDE);
                    break;
                default:
                    break;
                }
            } while (opLE != 0);
            break;
        case 4:
            do
            {

                printf("\nESCOLHA UMA OPCAO:\n1 - Inicializar\n2 - Empilhar\n3 - Desempilhar\n4 - Imprimir\n0 - Sair\n\n");
                scanf("%d", &opLE);
                switch (opLE)
                {
                case 1:
                    pilhaCV = cria();
                    break;
                case 2:
                    printf("Digite um valor para empilhar: ");
                    scanf("%d", &vLESI);
                    push(pilhaCV, vLESI);
                    break;
                case 3:
                    printf("\bValor desempilhado: %f\n", pop(pilhaCV));
                    break;
                case 4:
                    imprime(pilhaCV);
                    break;
                default:
                    break;
                }
            } while (opLE != 0);
            break;
        case 5:
            do
            {

                printf("\nESCOLHA UMA OPCAO:\n1 - Inicializar\n2 - Empilhar\n3 - Desempilhar\n4 - Imprimir\n0 - Sair\n\n");
                scanf("%d", &opLE);
                switch (opLE)
                {
                case 1:
                    pilhaLE = criaLE();
                    break;
                case 2:
                    printf("Digite um valor para empilhar: ");
                    scanf("%d", &vLESI);
                    pushLE(pilhaLE, vLESI);
                    break;
                case 3:
                    printf("\bValor desempilhado: %f\n", popLE(pilhaLE));
                    break;
                case 4:
                    imprimirLE(pilhaLE);
                    break;
                default:
                    break;
                }
            } while (opLE != 0);
            break;
        case 6:
            do
            {

                printf("\nESCOLHA UMA OPCAO:\n1 - Inicializar\n2 - Enfilerar\n3 - Desenfilerar\n4 - Imprimir\n0 - Sair\n\n");
                scanf("%d", &opLE);
                switch (opLE)
                {
                case 1:
                    filaCV = criaFCV();
                    break;
                case 2:
                    printf("Digite um valor para enfilerar: ");
                    scanf("%d", &vLESI);
                    insereFCV(filaCV, vLESI);
                    break;
                case 3:
                    printf("\bValor desenfilerado: %f\n", retiraFCV(filaCV));
                    break;
                case 4:
                    imprimeFCV(filaCV);
                    break;
                default:
                    break;
                }
            } while (opLE != 0);
            break;
        case 7:
            do
            {

                printf("\nESCOLHA UMA OPCAO:\n1 - Inicializar\n2 - Enfilerar\n3 - Desenfilerar\n4 - Imprimir\n0 - Sair\n\n");
                scanf("%d", &opLE);
                switch (opLE)
                {
                case 1:
                    filaCLE = criaFLE();
                    break;
                case 2:
                    printf("Digite um valor para enfilerar: ");
                    scanf("%d", &vLESI);
                    insereFLE(filaCLE, vLESI);
                    break;
                case 3:
                    printf("\bValor desenfilerado: %f\n", retiraFLE(filaCLE));
                    break;
                case 4:
                    imprimeFLE(filaCLE);
                    break;
                default:
                    break;
                }
            } while (opLE != 0);
            break;
        case 8:
            do
            {
                printf("\n1-INICIALIZA\n2-INSERIR\n3-IMPRIMIR\n4-REMOVER\n0-SAIR\n\n");
                scanf("%d", &opLE);
                switch (opLE)
                {
                case 1:
                    raiz = inicializaAB();
                    break;
                case 2:
                    printf("\nDigite o numero para adicionar: ");
                    scanf("%d", &vLESI);
                    raiz = inserir(raiz, vLESI);
                    printf("\n");
                    break;
                case 3:
                    printf("\n");
                    imprimir(raiz, 2);
                    printf("\n");
                    break;
                case 4:
                    printf("\nDigite o numero para remover: ");
                    scanf("%d", &vLESF);
                    raiz = remover(raiz, vLESF);
                    printf("\n");
                    break;
                default:
                    break;
                }
            }while(opLE != 0);
        default:
            break;
        };
    }while (op != 0);
    return 0;
}