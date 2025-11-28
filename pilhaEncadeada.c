#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int inf;
    struct nodo *next;
}NODE;

typedef NODE *PILHA;

void criar_pilha(PILHA *p){
    *p = NULL;
}

int eh_vazia(PILHA p){
    return (p == NULL);
}

void push(PILHA *p, int v){
    // alocando memoria para o novo element
    NODE *novo = (NODE *) malloc(sizeof(NODE));

    if(novo == NULL){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }

    novo->inf = v;
    novo->next = (*p);
    (*p) = novo;
}

int top(PILHA p){
    // verificando se a pilha é vazia
    if(eh_vazia(p)){
        printf("ERRO, PILHA VAZIA\n");
        exit(2);
    }

    return p->inf;
}

void pop(PILHA *p){
    NODE *aux = *p;
    // verificando se a pilha é vazia
    if(eh_vazia(*p)){
        printf("ERRO, PILHA VAZIA\n");
        exit(2);
    }

    *p = aux->next;
    free(aux);
}

int top_pop(PILHA *p){
    // verifico se é vazia;
    if(eh_vazia(*p)){
        printf("ERRO, PILHA VAZIA\n");
        exit(2);
    }

    int valor = (*p)->inf;
    NODE *aux = *p;
    *p = aux->next;

    free(aux);

    return valor;
}

void destroi(PILHA p){
    NODE *aux;

    while(p){
        aux = p;
        p = p->next;
        free(aux);
    }
}

int main(){
    return 0;
}