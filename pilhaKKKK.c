#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct nodo *next;
}NODE;

typedef NODE *PILHA;

void criarPilha(PILHA *p){
    *p = NULL;
}

int ehVazia(PILHA p){
    return p == NULL;
}

void push(PILHA *p, int v){
    NODE *novo = (PILHA) malloc(sizeof(NODE));

    if(!novo){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(1);
    }

    novo->info = v;
    novo->next = *p;
    *p = novo;
}

int top(PILHA p){
    if(ehVazia(p)){
        printf("ERRO, PILHA VAZIA\n");
        exit(2);
    }

    return p->info;
}

void pop(PILHA *p){
    NODE *aux = *p;
    if(ehVazia(*p)){
        printf("ERRO, PILHA VAZIA\n");
        exit(3);
    }

    *p = aux->next;
    free(aux);
}

int topPop(PILHA *p){
    int valor;
    NODE *aux = *p;

    if(ehVazia(*p)){
        printf("ERRO, PILHA VAZIA\n");
        exit(3);
    }

    valor = (*p)->info;
    
    *p = aux->next;
    free(aux);
    
    return valor;
}

void destruir(PILHA p){
    NODE *aux;

    while(p){
        aux = p;
        p = p->next;
        free(aux);
    }
}

int main() {
    return 0;
}