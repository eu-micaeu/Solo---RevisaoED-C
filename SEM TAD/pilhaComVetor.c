#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct pilha{
    int n;
    int vet[MAX];
}Pilha;

Pilha *cria(){ 
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}
 
void push (Pilha* p, int v)
{
 if (p->n == MAX) { /* capacidade esgotada */
    printf("Capacidade da pilha estourou.\n");
    exit(1); /* aborta programa */
 }
 /* insere elemento na próxima posição livre */
 p->vet[p->n] = v;
 p->n++;
}

float pop (Pilha* p)
{
    float v;
    if (p->n == MAX) {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    /* retira elemento do topo */
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

void imprime(Pilha *p) {
    printf("\nPilha: ");
    for(int i=p->n-1; i>=0; i--) {
        printf("\n%d", p->vet[i]);
    }
    printf("\n");
}

int main(){
    Pilha *p1;
    int ret;
    int op;
    int num;
    printf("\nInsira a opcao que deseja:\n1 - CRIA\n2 - RETIRAR DO TOPO\n3 - IMPRIMIR\n4 - ADICIONA\n\n");
    scanf("%d", &op);
    do{
        switch (op)
        {
        case 1:
            p1 = cria();
            break;
        case 4:
            printf("\nAdicione na pilha:\n");
            scanf("%d", &num);
            push(p1, num);
            break;
        case 3:
            imprime(p1);
            printf("\n");
            break;
        case 2:
            printf("\nRetirando o topo da pilha:\n");
            ret = pop(p1);
            printf("%d\n", ret);
            break;
        default:
            printf("ESCOLHA OUTRO NUMERO QUE SEJA VALIDO");
        }
        printf("\nInsira a opcao que deseja:\n1 - CRIA\n2 - RETIRAR DO TOPO\n3 - IMPRIMIR\n4 - ADICIONAR\n\n");
        scanf("%d", &op);
    }while(op != 0);
    
    
    return 0;
}

