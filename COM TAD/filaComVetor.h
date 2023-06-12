#define N 100

typedef struct FilaCV {
    int ini, fim;
    float vet[N];
} FilaCV;

FilaCV* criaFCV(void);

int vaziaFCV(FilaCV* f);

void insereFCV(FilaCV* f, float v);

float retiraFCV(FilaCV* f);

void imprimeFCV(FilaCV* f);
