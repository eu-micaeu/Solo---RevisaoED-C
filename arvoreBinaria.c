#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* inicializa() {
    return NULL;
}

Node* inserir(Node* root, int x) {
    if (root == NULL) {
        Node* aux = (Node*)malloc(sizeof(Node));
        aux->num = x;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else {
        if (x > root->num) {
            root->right = inserir(root->right, x);
        } else if (x < root->num) {
            root->left = inserir(root->left, x);
        }
    }
    return root;
}

void imprimir(Node* root, int nivel) {
    if (root != NULL) {
        imprimir(root->right, nivel + 1);

        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }

        if (nivel > 0) {
            printf("|__");
        }

        printf("%d\n", root->num);

        imprimir(root->left, nivel + 1);
    }
}


Node* buscar(Node* root, int cod) {
    if (root != NULL) {
        if (root->num == cod) {
            return root;
        } else {
            if (cod > root->num) {
                return buscar(root->right, cod);
            } else {
                return buscar(root->left, cod);
            }
        }
    }
    return NULL;
}

Node* minimo(Node* root) {
    if (root != NULL) {
        Node* aux = root;
        while (aux->left != NULL) {
            aux = aux->left;
        }
        return aux;
    }
    return NULL;
}

Node* remover(Node* root, int cod) {
    if (root == NULL) {
        return root;
    }
    if (cod < root->num) {
        root->left = remover(root->left, cod);
    } else if (cod > root->num) {
        root->right = remover(root->right, cod);
    } else {
        if (root->left == NULL) {
            Node* aux = root->right;
            free(root);
            return aux;
        } else if (root->right == NULL) {
            Node* aux = root->left;
            free(root);
            return aux;
        }
        Node* aux = minimo(root->right);
        root->num = aux->num;
        root->right = remover(root->right, aux->num);
    }
    return root;
}

void liberar(Node* root) {
    if (root != NULL) {
        liberar(root->left);
        liberar(root->right);
        free(root);
    }
}

int main() {
    int op = 0;
    int num, numRem, numBus;
    Node* root;
    printf("\n-----------------------------------------------------Arvore binaria-----------------------------------------------------");
    do{
        printf("\n\n1-INICIALIZA\n2-INSERIR\n3-IMPRIMIR\n4-REMOVER\n5-BUSCAR\n0-SAIR\n\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            root = inicializa();
            break;
        case 2:
            printf("\nDigite o numero para adicionar: ");
            scanf("%d", &num);
            root = inserir(root, num);
            printf("\n");
            break;
        case 3:
            printf("\n");
            imprimir(root, 2);
            printf("\n");
            break;
        case 4:
            printf("\nDigite o numero para remover: ");
            scanf("%d", &numRem);
            root = remover(root, numRem);
            printf("\n");
            break;
        case 5:
            printf("\nDigite o numero para buscar: ");
            scanf("%d", &numBus);
            if(buscar(root, numBus) != NULL){
                printf("ESSE NUMERO ESTA NA ARVORE");
            }else{
                printf("ESSE NUMERO NAO ESTA NA ARVORE");
            };
            printf("\n");
            break;
        default:
            break;
        }
    }while(op != 0);
    return 0;
}
