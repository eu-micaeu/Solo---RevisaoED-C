typedef struct No {
    float valor;
    struct No* prox;
} NoLE;

typedef struct FilaCLE {
    NoLE* inicio;
    NoLE* fim;
} FilaCLE;

FilaCLE* criaFLE(void);
void insereFLE(FilaCLE* f, float v);
int vaziaFLE(FilaCLE* f);
float retiraFLE(FilaCLE* f);
void imprimeFLE(FilaCLE* f);