#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

Node* inicializaAB() {
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

