#include <stdio.h>
#include <stdlib.h>

#define MAX 8

typedef struct{
    int chave;
    char livre;
}HASH;


typedef HASH TABELA[MAX];

int funcaoHashing(int chave){
    return chave % MAX;
}

void inserir(TABELA tabela, int n){
    int i = 0;

    int pos = funcaoHashing(n);

    while(i < MAX && tabela[(pos+i) % MAX].livre != 'L' && tabela[(pos+i) % MAX].livre != 'R')
        i = i+1;

    if(i < MAX){
        tabela[(pos+i) % MAX].chave = n;
        tabela[(pos+i) % MAX].livre = 'O';
    }
    else{
        printf("TABELA CHEIA\n");
    }
}

int buscar(TABELA tabela, int n){
    int i = 0;
    int pos = funcaoHashing(n);

    while(i < MAX && tabela[(pos+i) % MAX].livre != 'L' && tabela[(pos+i)% MAX].chave != n)
        i = i + 1;

    if(i < MAX && tabela[(pos+i) % MAX].chave == n && tabela[(pos+i) % MAX].livre == 'O')
        return ((pos+i) % MAX);
    else
        return MAX;
}


void remover(TABELA tabela, int n){
    int posicao = buscar(tabela, n);

    if(posicao < MAX)
        tabela[posicao].livre = 'R';
    else{
        printf("ELEMENTO NAO ESTA NA LISTA\n");
    }
}

int main(){
    return 0;
}