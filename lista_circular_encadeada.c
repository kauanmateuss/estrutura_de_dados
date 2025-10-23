#include <stdio.h>
#include <stdlib.h>



typedef struct no{
    int info;
    struct no *proximo;
}NO;

typedef NO *LISTA_CIRC;


void criar_lista(LISTA_CIRC *);
int eh_vazia(LISTA_CIRC);
int tamanho(LISTA_CIRC);
void inserir(LISTA_CIRC *, int , int);
int buscar(LISTA_CIRC, int);
void remover(LISTA_CIRC *, int);
void destruir(LISTA_CIRC );

int main() {


    return 0;
}


void criar_lista(LISTA_CIRC *refeExterna){
    *refeExterna = NULL;
}

int eh_vazia(LISTA_CIRC refeExterna){
    return (refeExterna == NULL); // se a referencia aponta para NULL então é vazia
}

int tamanho(LISTA_CIRC refeExterna){
    // verificando se a lista está vazia
    if(refeExterna == NULL){
        return 0;
    }
    
    // se não for a lista vazia vai existir um elemento
    NO *aux;
    int cont;

    // percorrendo a lista verificando se o proximo elemento é nulo
    for(cont = 1, aux = refeExterna->proximo; aux != refeExterna; cont++){
        aux = aux->proximo;
    }

    return cont;
}

void inserir(LISTA_CIRC *refeExterna, int valor, int posicao){
    NO *novo;

    // verificando se a posicao é valida
    if(posicao < 1 || posicao > tamanho(*refeExterna) + 1){
        return;
    }

    // alocando espaço para o novo elemento
    novo = (NO*) malloc (sizeof(NO));

    // verificando se a alocação foi bem sucessida
    if(novo == NULL)
        return;

    novo->info = valor;

    // inserindo
    // caso seja um novo elemento em uma lista vazia, ele vai apontar para ele mesmo
    if(refeExterna == NULL){
        novo->proximo = novo;
        *refeExterna = novo;
    }
    else{
        // caso seja um novo ultimo
        NO *aux = *refeExterna;
        
        if(posicao == tamanho(*refeExterna) + 1){
            *refeExterna = novo;
        }
        else{
            // percorrendo até o que antecede
            for(; posicao > 1; aux = aux->proximo, posicao--); // aux = antecede
        }

        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
}

int buscar(LISTA_CIRC refeExterna, int posicao){
    // verificando se a posicao é valida
    if(posicao < 1 || posicao > tamanho(refeExterna)){
        return 0;
    }
    
    // percorrendo até a posicao que quero remover
    for(; posicao > 0; posicao--){
        refeExterna = refeExterna->proximo;
    }

    return refeExterna->info;

}


void remover(LISTA_CIRC *refeExterna, int posicao){
    // verificando se a posicao é válida
    if(posicao < 1 || posicao > tamanho(*refeExterna)){
        return;
    }

    // caso onde eu retiro um unico elemento da lista, a referencia vai apontar pra null
    if(tamanho(*refeExterna) == 1){
        *refeExterna = NULL;
    }
    else{
        NO *aux;
        NO *remover;
        int i;

        // percorrendo até o que antecede
        for(aux = *refeExterna, i = posicao; i > 1; aux = aux->proximo, i--);

        remover = aux->proximo;
        aux->proximo = remover->proximo;

        if(posicao == tamanho(*refeExterna))
            *refeExterna = aux;

        // limpando a memoria onde o elemento tava
        free(remover);
    }
}


void destruir(LISTA_CIRC refeExterna){
    // Limpar memoria para todos os elementos
    
    if(refeExterna != NULL) {
        NO *aux = refeExterna->proximo;

        while(aux != refeExterna){
            free(aux);
            aux = aux->proximo;
        }
    
        free(refeExterna);
    }

}