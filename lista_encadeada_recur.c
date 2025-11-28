#include <stdio.h>
#include <stdlib.h>

// tipo NO
typedef struct no{
    int info;
    struct no *proximo;
}NO;

// tipo lista que aponta para o primeiro no
typedef NO *LISTA;

// prototipo das funções
void criar_lista(LISTA *);



int main() {

    return 0;
}



void criar_lista(LISTA *lista){
    *lista = NULL;

}

int eh_vazia(LISTA lista){
    return(lista == NULL);
}

int tamanho(LISTA lista){
    if(!lista)
        return 0;
    else
        return (1 + tamanho(lista->proximo));
}

int buscar(LISTA lista, int posicao){
    // verificando se a posicao é valida
    if(posicao < 1 || posicao > tamanho(lista)){
        printf("ERRO, POSICAO INVALIDA\n");
        exit(1);
    }

    // caso base se a posicao foi a primeira
    if(posicao == 1)
        return lista->info;
    else
        return (buscar(lista->proximo, posicao-1));
}