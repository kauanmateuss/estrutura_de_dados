#include <stdio.h>
#include <stdlib.h>

#define TAM 8

typedef struct {
    int chave;
    char livre;
}HASH;

typedef HASH TABELA[TAM];

int funcaoHashing(int chave){
    return chave % TAM;
}

void inserirChave(TABELA tabela, int n){
    int pos = funcaoHashing(n);
    int k = 1;

    while(k < TAM && tabela[pos].livre != 'L' && tabela[pos].livre != 'R'){
        pos = (pos+k) % TAM;
        k = k + 1;
    }

    if(k < TAM){
        tabela[pos].chave = n;
        tabela[pos].livre = 'O';
    }
    else
        printf("TABELA CHEIA OU EM LOOP\n");
}

void removerChave(TABELA tabela, int chave){
    int pos = buscarChave(tabela, chave);

    if(pos < TAM){
        tabela[pos].livre = 'R';
    }
    else{
        printf("ELEMENTO NAO ESTA NA TABELA\n");
    }
}

int buscarChave(TABELA tabela, int chave){
    int pos = funcaoHashing(chave);
    int k = 1;

    while(k < TAM && tabela[pos].livre != 'L' && tabela[pos].chave != chave){
        pos = (pos+k) % TAM;
        k += 1;
    }

    if(k < TAM && tabela[pos].livre == 'O' && tabela[pos].chave == chave)
        return pos;
    else
        return TAM;
}

int main() {
    return 0;
}