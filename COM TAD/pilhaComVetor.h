#define MAX 50

typedef struct PilhaCV{
    int n;
    int vet[MAX];
}PilhaCV;

PilhaCV *cria();
 
void push (PilhaCV* p, int v);

float pop (PilhaCV* p);

void imprime(PilhaCV *p);


