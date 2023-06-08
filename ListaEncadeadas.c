#include <stdio.h>
#include <stdlib.h>

// Lista encadeada:

//Struct
typedef struct l{
    int info;
    struct l *prox;
} Lista;

//Inicializar
Lista* inicializa_LE(){
    return NULL;
}

//Inserir no inicio
Lista* inserirInicio_LE(Lista *L, int num){
    Lista *aux = (Lista*)malloc(sizeof(Lista));
    aux->info = num;
    aux->prox = L;
    return aux;
}

//Imprimir
void imprimir_LE(Lista *L){
    while(L != NULL){
        printf("\nValor: %d", L->info);
        L = L->prox;
    }
    printf("\n");
}

//Inserir no fim
Lista* inserirFim_LE(Lista *L, int num){
    Lista *aux;
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    if (L == NULL){
        return novo;
    }else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        return L;
    }
}

//Concatena
Lista* concatena_LE(Lista* L1, Lista* L2) {
    Lista* aux1 = L1;
    Lista* aux2 = L2;

    if (L1 == NULL)
        return L2;
    if (L2 == NULL) 
        return L1;

    while (aux1 -> prox != NULL) 
        aux1 = aux1 -> prox;
        
    aux1 -> prox = aux2;
    return L1;
}

//Contar
int contar_LE(Lista* L) {
    int contador = 0;
    while (L != NULL) {
        contador++;
        L = L->prox;
    }
    return contador;
}

//Separa
Lista* separa_LE(Lista* li, int n){
    Lista *p, *aux;
    p = li;
    while (p != NULL){ 
       if(p->info == n){ 
            aux = p->prox; 
            p->prox = NULL; 
            break; 
        }
        p = p->prox; 
    }
    return aux; 
}

//Constroi
Lista* constroi_LE(int n, int *v){
    Lista *lista = NULL;
    Lista *aux;

    if(n > 0){
        lista = (Lista*) malloc(sizeof(Lista));
        lista->info = v[0];
        lista->prox = NULL;
        aux = lista;

        for(int i = 1; i < n; i++){
            Lista *novo = (Lista*) malloc(sizeof(Lista));
            novo->info = v[i];
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;
        }
    }
    return lista;
}

//Prefixo
Lista* prefixo_LE(Lista* li, int n) {
    if (li == NULL || n <= 0) { // verifica se a lista é válida e se n é positivo
        return li;
    }
    
    Lista* anterior = NULL;
    Lista* atual = li;
    int i = 0;
    while (i < n && atual != NULL) { // percorre os primeiros n nós da lista
        anterior = atual;
        atual = atual->prox;
        i++;
    }
    if (i == n) { // se encontrou n nós, remove o prefixo
        anterior->prox = NULL; // ajusta o ponteiro para o final do prefixo
        free(li); // libera a memória alocada para o prefixo removido
        li = atual; // atualiza o ponteiro para o primeiro nó da nova lista
    }
    
    return li;
}


// ---------------------------------------------------------------------------------------------------------------

//Lista circular:

//Struct
typedef struct lc{
    int info;
    struct lc *prox;
}ListaC;

//Inicializar
ListaC* inicializa_LC(){
    return NULL;
}

//Inserir no incio
ListaC* inserirInicio_LC(ListaC *L, int num){
    ListaC *novo, *aux = L;
	novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = num;

    if(L!=NULL){
        novo->prox = L;
    }else{
		novo->prox = novo;
		return novo;
	}

    while(aux->prox != L){
        aux = aux->prox;
    }

    aux->prox = novo;

    return novo;
}

//Imprimir
void imprimir_LC(ListaC *L){
	ListaC *aux = L;
	if(aux != NULL){
		do{
			printf("\nValor: %d", aux->info);
			aux = aux->prox;
		}while(aux != L);
	}
    printf("\n");
}

//Inserir no Fim
ListaC* inserirFim_LC(ListaC *L, int num){
	ListaC *novo, *aux = L;
	novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = num;
	if(L != NULL){
		novo->prox = L;
		while(aux->prox != L){
			aux = aux->prox;			
		}
		aux->prox = novo;
		return L;
	}
	else{
		novo->prox = novo;
		return novo;
	}
}

//Concatena
ListaC* concatena_LC(ListaC* L1, ListaC* L2) {
    if (L1 == NULL)
        return L2;
    if (L2 == NULL) 
        return L1;

    // Encontra o último elemento de cada lista
    ListaC* ultimo1 = L1;
    while (ultimo1->prox != L1)
        ultimo1 = ultimo1->prox;
    ListaC* ultimo2 = L2;
    while (ultimo2->prox != L2)
        ultimo2 = ultimo2->prox;

    // Liga as listas circularmente
    ultimo1->prox = L2;
    ultimo2->prox = L1;

    return L1;
}

//Contar
int contar_LC(ListaC* L) {
    if (L == NULL) {
        return 0;
    }

    int contador = 1;
    ListaC* atual = L->prox;

    while (atual != L) {
        contador++;
        atual = atual->prox;
    }

    return contador;
}

//Separa
ListaC* separa_LC(ListaC* li, int n) {
    ListaC *p, *nova;
    p = li;
    
    do {
        p = p->prox;
    } while (p != li && p->info != n);
    
    if (p == li)
        return NULL;
    
    nova = p->prox;
    p->prox = li;
    p = nova;
    while (p->prox != li)
        p = p->prox;
    p->prox = nova;
    
    return nova;
}

//Constroi
ListaC* constroi_LC(int n, int *v) {
    ListaC* lista = NULL;
    ListaC* aux;

    if (n > 0) {
        lista = (ListaC*) malloc(sizeof(ListaC));
        lista->info = v[0];
        lista->prox = lista;
        aux = lista;

        for (int i = 1; i < n; i++) {
            ListaC* novo = (ListaC*) malloc(sizeof(ListaC));
            novo->info = v[i];
            novo->prox = lista;
            aux->prox = novo;
            aux = novo;
        }
    }

    return lista;
}

//Prefixo
ListaC* prefixo_LC(ListaC* l, int n){
    ListaC* aux = l;
    ListaC* LR = inicializa_LC();
    ListaC* LR_aux = inicializa_LC();
    ListaC* LR_aux2 = inicializa_LC();
    int j = 0, i = 0;
    if(l == NULL){
        printf("A lista fornecida é vazia");
        return NULL;
    }
    do{
        j++;
        aux = aux-> prox;
    }while(aux != l);
    if(j <= n){
        return NULL;
    }
    do{
        ListaC* novo = (ListaC*) malloc(sizeof(ListaC));
        novo->info = aux->info;
        novo->prox = NULL;
        if (LR == NULL) {
            LR = novo;
            LR_aux = LR;
        }else{
            LR_aux -> prox = novo;
            while(LR_aux -> prox != NULL){
                LR_aux = LR_aux -> prox;
            }
        }
        aux = aux-> prox;
    }while(aux != l);
    LR_aux ->prox = LR;
    do{
        LR_aux = LR_aux -> prox;
    }while(LR_aux ->prox != LR);
        LR_aux2 = LR_aux;
    for(i = 0; i < n; i++){
        LR_aux2 = LR -> prox;
        free(LR);
        LR = LR_aux2;
    }
    LR_aux -> prox = LR;
    l = LR;
    return l;
}

// ---------------------------------------------------------------------------------------------------------------

//Lista duplamente encadeada:

//Struct
typedef struct lde{
    int info;
    struct lde *prox;
    struct lde *ant;
} ListaDE;

//Inicializar
ListaDE* inicializa_LDE(){
    return NULL;
}

//Inserir no incio
ListaDE *inserirInicio_LDE(ListaDE *L, int num)
{
    ListaDE *novo;

    novo = (ListaDE*) malloc(sizeof(ListaDE));
    novo->info = num;
    novo->prox = L;
    novo->ant = NULL;

    if (L != NULL) {
        L->ant = novo;
    }
    return novo;
}

//Imprimir
void imprimir_LDE(ListaDE *L){
    while (L != NULL) {
        printf("\nValor: %d",  L->info);
        L = L->prox;
    }
    printf("\n");
}

//Inserir no Fim
ListaDE *inserirFim_LDE(ListaDE *L, int num)
{
    ListaDE *novo, *aux = L;

    novo = (ListaDE*) malloc(sizeof(ListaDE));
    novo->info = num;
    novo->prox = NULL;
    novo->ant = NULL;

    if (L == NULL) {
        return novo;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        return L;
    }
}

//Concatena
ListaDE* concatena_LDE(ListaDE* L1, ListaDE* L2) {
    if (L1 == NULL)
        return L2;
    if (L2 == NULL) 
        return L1;

    // Encontra o último elemento de L1
    ListaDE* ultimo1 = L1;
    while (ultimo1->prox != NULL)
        ultimo1 = ultimo1->prox;

    // Liga L1 com L2
    ultimo1->prox = L2;
    L2->ant = ultimo1;

    return L1;
}

//Contar
int contar_LDE(ListaDE* L) {
    int contador = 0;
    while (L != NULL) {
        contador++;
        L = L->prox;
    }
    return contador;
}

//Separa
ListaDE* separa_LDE(ListaDE* li, int n){
    ListaDE *p, *aux;
    p = li;
    while (p != NULL){
        if(p->info == n){
            aux = p->prox;
            p->prox = NULL;
            aux->ant = NULL;
            break;
        }
        p = p->prox;
    }
    return aux;
}

//Constroi
ListaDE* constroi_LDE(int n, int *v) {
    ListaDE *lista = NULL;
    ListaDE *aux;

    if (n > 0) {
        lista = (ListaDE*) malloc(sizeof(ListaDE));
        lista->info = v[0];
        lista->ant = NULL;
        lista->prox = NULL;
        aux = lista;

        for (int i = 1; i < n; i++) {
            ListaDE *novo = (ListaDE*) malloc(sizeof(ListaDE));
            novo->info = v[i];
            novo->ant = aux;
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;
        }
    }

    return lista;
}

//Prefixo
ListaDE* prefixo_LDE (ListaDE *L1, int n){
    ListaDE *p = L1;
    int cont=0;
    //Verifica se a lista é nula
    if(p==NULL){
        printf("Lista nula");
        return 0;
    }
    //Enquanto o nó da lista nao for nulo e o numero de execucoes for menor que o numero pedido
    while (p != NULL && cont<n) {
        p = p->prox;
        cont++;
    }
    if(p==NULL && cont==n){
        printf("numero de elementos para retirar maior/igual numero de elementos da lista");
        return  NULL;
	} else{
	    p->ant = NULL;
        free(L1);
        return p;
	}
}


// ---------------------------------------------------------------------------------------------------------------

// Função main
int main(){
    printf("\n========================================================================\n");

    //Lista encadeada: 
    printf("\nLista encadeada:\n");
    Lista *LE = inicializa_LE();
    LE = inserirInicio_LE(LE, 2);
    LE = inserirInicio_LE(LE, 1);
    imprimir_LE(LE);
    LE = inserirFim_LE(LE, 3);
    imprimir_LE(LE);
    Lista *LE2 = inicializa_LE();
    LE2 = inserirInicio_LE(LE2, 4);
    LE2 = inserirInicio_LE(LE2, 5);
    LE2 = inserirInicio_LE(LE2, 6);
    LE2 = inserirInicio_LE(LE2, 7);
    Lista *Concatena_LE = concatena_LE(LE, LE2);
    imprimir_LE(Concatena_LE);
    Lista *Separa_LE = separa_LE(Concatena_LE, 7);
    imprimir_LE(Separa_LE);
    int vet_LE[4] = {1, 2, 3, 4};
    Lista *Constroi_LE = constroi_LE(4, vet_LE);
    imprimir_LE(Constroi_LE);
    Lista *Prefixo_LE = prefixo_LE(Constroi_LE, 2);
    imprimir_LE(Prefixo_LE);
    printf("\nQuantidade de elementos: %d", contar_LE(Prefixo_LE));
    //

    printf("\n========================================================================\n\n");

    //Lista circular:
    printf("Lista circular:\n");
    ListaC *LC = inicializa_LC();
    LC = inserirInicio_LC(LC, 2);
    LC = inserirInicio_LC(LC, 1);
    imprimir_LC(LC);
    LC = inserirFim_LC(LC, 3);
    imprimir_LC(LC);
    ListaC *LC2 = inicializa_LC();
    LC2 = inserirInicio_LC(LC2, 4);
    LC2 = inserirInicio_LC(LC2, 5);
    LC2 = inserirInicio_LC(LC2, 6);
    LC2 = inserirInicio_LC(LC2, 7);
    ListaC *Concatena_LC = concatena_LC(LC, LC2);
    imprimir_LC(Concatena_LC);
    ListaC *Separa_LC = separa_LC(Concatena_LC, 7);
    imprimir_LC(Separa_LC);
    int vet_LC[4] = {1, 2, 3, 4};
    ListaC *Constroi_LC = constroi_LC(4, vet_LC);
    imprimir_LC(Constroi_LC);
    ListaC *Prefixo_LC = prefixo_LC(Constroi_LC, 2);
    imprimir_LC(Prefixo_LC);
    printf("\nQuantidade de elementos: %d", contar_LC(Constroi_LC));
    //

    printf("\n========================================================================\n\n");

    //Lista duplamente encadeada:
    printf("Lista duplamente encadeada:\n");
    ListaDE *LDE = inicializa_LDE();
    LDE = inserirInicio_LDE(LDE, 2);
    LDE = inserirInicio_LDE(LDE, 1);
    imprimir_LDE(LDE);
    LDE = inserirFim_LDE(LDE, 3);
    imprimir_LDE(LDE);
    ListaDE *LDE2 = inicializa_LDE();
    LDE2 = inserirInicio_LDE(LDE2, 4);
    LDE2 = inserirInicio_LDE(LDE2, 5);
    LDE2 = inserirInicio_LDE(LDE2, 6);
    LDE2 = inserirInicio_LDE(LDE2, 7);
    ListaDE *Concatena_LDE = concatena_LDE(LDE, LDE2);
    imprimir_LDE(Concatena_LDE);
    ListaDE *Separa_LDE = separa_LDE(Concatena_LDE, 7);
    imprimir_LDE(Separa_LDE);
    int vet_LDE[4] = {1, 2, 3, 4};
    ListaDE *Constroi_LDE = constroi_LDE(4, vet_LDE);
    imprimir_LDE(Constroi_LDE);
    ListaDE *Prefixo_LDE = prefixo_LDE(Constroi_LDE, 2);
    imprimir_LDE(Prefixo_LDE);
    printf("\nQuantidade de elementos: %d", contar_LDE(Concatena_LDE));

    //
    printf("\n========================================================================\n\n");
    getchar();
    return 0;

}
