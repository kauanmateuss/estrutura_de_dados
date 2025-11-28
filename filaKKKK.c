#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}NODE;

typedef struct{
    NODE *inicio;
    NODE *fim;
}DESCRITOR;

typedef DESCRITOR *FILA;

void criarFila(FILA *f){
    *f = (FILA) malloc(sizeof(DESCRITOR));

    if(!(*f)){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(1);
    }

    (*f)->inicio = NULL;
    (*f)->fim = NULL;
}

int ehVazia(FILA f){
    return f->fim == NULL;
}

void insFila(FILA f, int v){
    NODE *novo = (NODE *)malloc(sizeof(NODE));

    if(!novo){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(2);
    }

    novo->info = v;
    novo->next = NULL;

    if(ehVazia(f)){
        f->inicio = novo;
        f->fim = novo;
    }
    else{
        f->fim->next = novo;
        f->fim = novo;
    }
}

int buscar(FILA f){
    if(ehVazia(f)){
        printf("ERRO, FILA VAZIA\n");
        exit(3);
    }

    return f->inicio->info;
}

void remover(FILA f){
    NODE *aux = f->inicio;

    if(ehVazia(f)){
        printf("ERRO, FILA VAZIA\n");
        exit(3);
    }

    // temos 2 casos de remocao: se a fila só tem 1 elemento ou se tem mais
    if(aux->next == NULL){
        f->inicio = f->fim = NULL;
        free(aux);
    }
    else{
        f->inicio = aux->next;
        free(aux);
    }


}

int main() {
    return 0;
}