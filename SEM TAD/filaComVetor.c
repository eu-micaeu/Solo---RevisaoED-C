#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct fila {
    int ini, fim;
    float vet[N];
} Fila;

Fila* cria(void)
{
    // Aloca memória para a nova instância da fila
    Fila* f = (Fila*)malloc(sizeof(Fila));

    // Define os valores iniciais para o início e fim da fila
    f->ini = f->fim = 0; /* inicializa fila vazia */

    // Retorna o ponteiro para a nova instância da fila
    return f;
}


void insere(Fila* f, float v)
{
    // Verifica se a fila está cheia, ou seja, se o próximo elemento a ser inserido
    // ocuparia a posição do início da fila. Isso é feito comparando se o valor de
    // "(f->fim + 1) % N" é igual ao valor de "f->ini".
    if (((f->fim + 1) % N) == f->ini) { 
        printf("Capacidade da fila estourou.\n");
        exit(1); // Aborta o programa, pois a fila está cheia e não é possível inserir mais elementos.
    }

    // Insere o novo elemento na próxima posição livre do vetor "vet" da fila.
    f->vet[f->fim] = v;

    // Atualiza o valor de "f->fim" para apontar para a próxima posição livre,
    // considerando que a fila é circular e a posição seguinte é dada por "(f->fim + 1) % N".
    f->fim = (f->fim + 1) % N;
}


int vazia(Fila* f)
{
    return (f->ini == f->fim);
}

float retira(Fila* f)
{
    float v;

    // Verifica se a fila está vazia usando a função "vazia()" definida anteriormente.
    if (vazia(f)) {
        printf("Fila vazia.\n");
        exit(1); // Aborta o programa, pois não é possível remover elementos de uma fila vazia.
    }

    // Armazena o valor do elemento no início da fila.
    v = f->vet[f->ini];

    // Atualiza o valor de "f->ini" para indicar o próximo elemento a ser removido,
    // considerando que a fila é circular e a posição seguinte é dada por "(f->ini + 1) % N".
    f->ini = (f->ini + 1) % N;

    // Retorna o valor do elemento removido.
    return v;
}

void libera(Fila* f)
{
    free(f);
}

void imprime(Fila* f)
{
    int i = f->ini;

    // Percorre a fila a partir do início até o fim, utilizando o índice "i".
    while (i != f->fim) {
        // Imprime o valor do elemento no índice "i" do vetor "vet" da fila.
        printf("%.2f ", f->vet[i]);

        // Atualiza o valor de "i" para o próximo elemento na fila,
        // considerando que a fila é circular e a posição seguinte é dada por "(i + 1) % N".
        i = (i + 1) % N;
    }

    // Após imprimir todos os elementos, imprime uma nova linha para separar a saída.
    printf("\n");
}

int main()
{
    Fila* fila = cria();
    
    insere(fila, 1.5);
    insere(fila, 2.3);
    insere(fila, 4.7);
    
    imprime(fila);

    printf("Elemento removido: %.2f\n", retira(fila));
    printf("Elemento removido: %.2f\n", retira(fila));
    
    imprime(fila);

    insere(fila, 3.1);
    
    imprime(fila);

    libera(fila);
    
    return 0;
}
