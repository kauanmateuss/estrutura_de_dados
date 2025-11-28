#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Tamanho maximo da fila


typedef struct {
    int N; // Numero de elementos
    int INICIO; // Indice do inicio da fila
    int FIM; // Indice do final da fila
    int val[MAX]; // Fila com tamanho max
}FILA;


void criar_fila(FILA *f){
    f->N = 0;    // vai iniciar com 0 elementos
    f->INICIO = 0; // inicio vai ser o indice 0
    f->FIM = -1; // Pois quando incrementado vai se tornar 0
}

int eh_vazia(FILA *f){
    return (f->N == 0); // se N não tiver elementos então retorna 1
}

int tam(FILA *f){
    return (f->N);
}

int ins(FILA *f, int v){
    // verificando se a fila tá cheia
    if(f->N == MAX){
        printf("FILA CHEIA\n");
        exit(1);
    }

    // se Não tiver cheia:
    f->FIM = ((f->FIM) + 1) % MAX; // Incrementando o fim circularmente
    
    // inserindo no final da fila
    f->val[f->FIM] = v;

    f->N++; // atualiza a quantidade de elementos da fila

}

int buscar(FILA *f){
    // Verificando se a fila é vazia
    if(eh_vazia(f)){
        printf("ERRO, CUNSULTA INVÁLIDA\n");
        exit(2);
    }

    return (f->val[f->INICIO]); // vai retornar o primeiro da fila
}

void remover(FILA *f){
    // verificando se a fila é vazia
    if(eh_vazia(f)){
        printf("ERRO, CONSULTA INVALIDA\n");
        exit(2);
    }
    else{ // Se a fila não for vazia eu vou remover o primeiro elemento da lista
        f->INICIO = ((f->INICIO) + 1) % MAX; // Incremento o inicio circularmente

        f->N--; // e atualizo o numero de elementos da fila
    }
}

int cons_ret(FILA *f){
    // verifico se a fila é vazia
    if(eh_vazia(f)){
        exit(4);
    }
    else{ // se nao for vazia eu retorno o valor do inicio e removo ele
        int v = f->val[f->INICIO]; // Salvando o indice do inicio em v
        f->INICIO = (f->INICIO + 1) % MAX;  // se eu atingir um indice invalido ele vai ser 0

        f->N--;
        
        return v;
    }
}


// Usando Recursividade
void gera_fila(FILA *f, int m, int n){
    // verificando se o intervalo é valido
    if(m > n){
        printf("ERRO, INTERVALO INVALIDO\n");
        exit(5);
    }

    // caso base
    if(m == n){
        criar_fila(f);
        ins(f, m);
    }

    // caso recursivo
    gera_fila(f, m, n-1);
    ins(f, n);
}


int main() {


    return 0;
}