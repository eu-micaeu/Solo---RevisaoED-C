struct node {
    int num;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* inicializaAB();

Node* inserir(Node* root, int x);

void imprimir(Node* root, int nivel);

Node* buscar(Node* root, int cod);

Node* minimo(Node* root);

Node* remover(Node* root, int cod);

void liberar(Node* root);
