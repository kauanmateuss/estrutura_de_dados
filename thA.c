#include <stdio.h>
#include <stdlib.h>

#define numEntradas 8

typedef struct hash{
    int chave;
    struct hash *prox;
}HASH;

typedef HASH* TABELA[numEntradas];

int funcaoHashing(int chave){
    return chave % numEntradas;
}

void inserirHash(TABELA tabela, int chave){
    HASH *novo;

    int pos = funcaoHashing(chave);

    novo = (HASH*)malloc(sizeof(HASH));

    if(!novo){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(1);
    }

    novo->chave = chave;
    novo->prox = tabela[pos];
    tabela[pos] = novo;
}

HASH* localizarHash(TABELA tabela, int chave){
    int pos = funcaoHashing(chave);

    HASH *aux;

    if(tabela[pos] != NULL){
        if(tabela[pos]->chave == chave)
            return tabela[pos];
        else{
            aux = tabela[pos]->prox;

            while(aux != NULL && aux->chave != chave)
                aux = aux->prox;

            return aux;
        }
    }
    else{
        return NULL;
    }
}

void excluirHash(TABELA tabela, int chave){
    int pos = funcaoHashing(chave);


    HASH *aux;

    if(tabela[pos] != NULL){
        if(tabela[pos]->chave == chave){
            aux = tabela[pos];
            tabela[pos]= tabela[pos]->prox;
            free(aux);
        }
        else{
            HASH *ant = tabela[pos];

            aux = tabela[pos]->prox;

            while(aux != NULL && aux->chave != chave){
                ant = aux;
                aux = aux->prox;
            }

            if(aux != NULL){
                ant->prox = aux->prox;
                free(aux);
            }
            else{
                printf("NUMERO NAO ENCONTRADO\n");
            }
        }
    }
    else{
        printf("NUMERO NAO ENCONTRADO\n");
    }
}


int main(){

    return 0;
}