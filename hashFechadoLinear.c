#include <stdio.h>
#include <stdlib.h>

#define TAM 8

typedef struct{
    int chave;
    char livre;
}HASH;

typedef HASH TABELA[TAM];

int funcaoHashing(int chave){
    return chave % TAM;
}

void inserir(TABELA tabela, int n){
    int i = 0; // Indice
    int pos = funcaoHashing(n);

    // enquanto tiver espaço e não tiver posicao livre então atualizo meu i
    while(i < TAM && tabela[(pos+i) % TAM].livre != 'L' && tabela[(pos+i) % TAM].livre != 'R')
        i = i + 1;

    if(i < TAM) {
        tabela[(pos+i) % TAM].chave = n;
        tabela[(pos+i) % TAM].livre = 'O';
    }
    else{
        printf("TABELA CHEIA\n");
    }
}

void remover(TABELA tabela, int n){
    int posicao = buscar(tabela, n);

    // verifico se a posicao é valida
    if(posicao < TAM)
        tabela[posicao].livre = 'R';
    else{
        printf("ELEMENTO NAO ESTA PRESENTE\n");
    }
}


int buscar(TABELA tabela, int n){
    int i = 0;
    int pos = funcaoHashing(n);

    while(i < TAM && tabela[(pos+i) % TAM].livre != 'L' && tabela[(pos+i) % TAM].chave != n)
        i = i+1;

    if(i < TAM && tabela[(pos+1) % TAM].chave == n && tabela[(pos+1)% TAM].livre == 'O')
        return ((pos+i) % TAM);
    else
        return TAM;
}

int main(){
    return 0;
}