#include <stdio.h>
#include <stdlib.h>

#define numEntradas 8

typedef struct hash {
    int chave;
    struct hash *prox;
}HASH;

typedef HASH* TABELA[numEntradas];

// funcao calcula a posicao que vou inserir o dado
int funcaoHashing(int chave){
    return chave % numEntradas;
}

void inserirHash(TABELA tabela, int chave){
    HASH *novo;

    // posicao que vou inserir a nova chave
    int pos = funcaoHashing(chave);

    novo = (HASH*)malloc(sizeof(HASH));

    if(!novo){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(1);
    }

    // chave armazenada
    novo->chave = chave;
    novo->prox = tabela[pos]; // novo vai apontar para o antigo elemento
    tabela[pos] = novo; // tabela vai apontar para o novo
}

HASH* localizarHash(TABELA tabela, int chave){
    int pos = funcaoHashing(chave); // pego a posicao que essa chave está na tabela

    HASH *aux;

    // verifico se existe algum elemento na posicao
    if(tabela[pos] != NULL){
        // verifico se a chave é a primeira da lista
        if(tabela[pos]->chave == chave)
            return tabela[pos];
        else{
            // se nao for a primeira então tenho que ir percorrendo a lista pra encontrar a chave
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
    // localizando o indice que a chave tá
    int pos = funcaoHashing(chave);

    HASH *aux;

    // Se na posicao tiver elementos
    if(tabela[pos] != NULL){
        // verifico se a chave é o primeiro elemento na posicao
        if(tabela[pos]->chave == chave){
            aux = tabela[pos];
            tabela[pos] = tabela[pos]->prox;
            free(aux);
        }
        else{
            HASH *ant = tabela[pos];

            aux = tabela[pos]->prox;

            while(aux != NULL && aux->chave != chave){
                ant = aux;
                aux = aux->prox;
            }

            // Se aux existe então removo ele
            if(aux != NULL){
                ant->prox = aux->prox;
                free(aux);
            }
            else{
                // se aux for nulll então já percorri tudo e não encontrei
                printf("NUMERO NAO ENCONTRADO\n");
            }
        }
    }
    else{
        printf("NUMERO NAO ENCONTRADO\n");
    }
}


int main() {

    return 0;
}