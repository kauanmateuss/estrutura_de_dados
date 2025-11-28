#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef struct {
    NODO *INICIO; // Vai apontar para o Ultimo PRIMEIRO NODO
    NODO *FIM;  // vai apontar para o PRIMEIRO NODO
}DESCRITOR;

typedef DESCRITOR *FILA;  // Ponteiro para descritor

void criar_fila(FILA *f){
    // alocando memoria para a fila
    *f = (FILA) malloc(sizeof(DESCRITOR));

    if(!*f){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }

    (*f)->INICIO = (*f)->FIM = NULL;
    
}

int eh_vazia_fila(FILA f){
    return (f->INICIO == NULL); // se o campo inicio do descritor for null então a lista é vazia
}

void ins_fila(FILA f, int v){
    // alocando memoria para um novo nodo
    NODO *novo = (NODO *) malloc(sizeof(NODO));

    if(!novo){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }

    // caso eu tenha memoria então vou ver os casos de inserção
    novo->inf = v;
    novo->next = NULL; // o novo ultimo não vai apontar pra ninguem

    // Verificando se é uma inserção em uma fila fazia
    if(eh_vazia(f)){
        f->INICIO = f->FIM = novo; // inicio e fim vão apontar para o novo nó
    }
    else{ // Se a fila não for vazia
        f->FIM->next = novo;
        f->FIM = novo; 
    }
}

int buscar(FILA f){
    // verifico se a lista não é vazia
    if(eh_vazia(f)){
        printf("ERRO AO BUSCAR");
        exit(2);
    }

    return f->INICIO->inf;
}

void remover(FILA f){
    NODO *aux = f->INICIO;

    // verifico se a fila é vazia
    if(eh_vazia(f)){
        printf("ERRO, RETIRADA EM FILA VAZIA\n");
        exit(3);
    }

    // retirada em fila que só tem 1 elemento
    if(aux->next == NULL){
        f->INICIO = f->FIM = NULL;
        free(aux);    
    }
    else{
        f->INICIO = aux->next;
        free (aux);
    }
}

int cons_ret(FILA f){
    // Verificando se a fila não está fazia
    if(eh_vazia(f)){
        printf("ERRO, LISTA VAZIA\n");
        exit(4);
    }

    // salvando o valor do inicio
    int valor = f->INICIO->inf;

    // chamo a função de remover
    remover(f);

    return valor;
}

void destruir(FILA f){
    NODO *aux;

    while(f->INICIO){
        aux = f->INICIO;
        f->INICIO = f->INICIO->next;
        free(aux);
    }
    free(f);
}

int main() {


    return 0;
}