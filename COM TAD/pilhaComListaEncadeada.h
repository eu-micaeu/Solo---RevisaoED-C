struct no{
	float info;
	struct no *prox;
};
typedef struct no No;

struct PilhaLE{
	No *prim;
};
typedef struct PilhaLE PilhaLE;

PilhaLE* criaLE();

void pushLE(PilhaLE *p, float v);

void imprimirLE(PilhaLE *p);

float popLE(PilhaLE *p);

PilhaLE* eliminarPilhaLE(PilhaLE *p);
