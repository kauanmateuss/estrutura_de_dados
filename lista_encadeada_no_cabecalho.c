#include <stdio.h>
#include <stdlib.h>


//estrutura NO;
typedef struct no{
    int inf;
    struct no *proximo;

}NO;

typedef NO *LISTA_ENC;

void criar_lista(LISTA_ENC *); // cabeça da lista
int eh_vazia(LISTA_ENC);
void inserir(LISTA_ENC , int, int);
void buscar(LISTA_ENC , int);
void remover(LISTA_ENC , int);
void destruir(LISTA_ENC );

int main() {

    return 0;
}


void criar_lista(LISTA_ENC *lista){
    *lista = (NO *) malloc (sizeof(NO));  // cria o NO cabeçalho

    if(!(*lista)){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }


    (*lista)->proximo = NULL; // o NÓ aponta para o proximo(primeiro elemento) = NULL
    (*lista)->inf = 0;
}


int eh_vazia(LISTA_ENC lista){
    return (lista->proximo == NULL);    // se o proximo do nó cabeçalho(primeiro elemento)
}

int tamanho(LISTA_ENC lista){
    return (lista->inf);
}

void inserir(LISTA_ENC lista, int valor, int posicao){
    NO *novo;
    NO *aux;

    // verificando se a posicao é válida
    if(posicao < 1 || posicao > tamanho(lista) + 1){
        printf("ERRO, POSICAO INVALIDA\n");
        exit(2);
    }

    novo = (NO*) malloc(sizeof(NO)); // alocando memoria para o novo nó

    if(!novo){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }

    novo->inf = valor; // caso tenha sido alocado com sucesso, novo vai receber o valor digitado

    // pegando o NÓ que antecesse a posicao que quero inserir
    for(aux = lista; posicao > 1; aux = aux->proximo, posicao--); // aux vai ter o NÓ antecedente
    
    // O novo nó vai apontar para o antigo nó da posicao e o qu eantecede vai apontar para o novo
    novo->proximo = aux->proximo;
    aux->proximo = novo;

    // atualiza a quantidade de elementos da lista
    lista->inf++;

}

void buscar(LISTA_ENC lista, int posicao){
    int i;
    NO *aux;
    // verificar se a posicao é valida
    if(posicao < 1 || posicao > lista->inf){
        printf("ERRO, POSICAO INVALIDA\n");
        exit(2);
    }

    // caso a posicao seja válida, vou percorrer a lista e retornar a posicao
    aux = lista->proximo; // pula o cabeçalho e recebe o primeiro elemento
    for(i = 1; i < posicao; i++){
        aux = aux->proximo;
    }

    return aux->inf; // vai retornar a informação do elemento da posicao
}

void remover(LISTA_ENC lista, int posicao){
    NO *aux, *aux2;

    // verificando se a posicao é valida
    if(posicao < 1 || posicao > lista->inf){
        printf("ERRO, POSICAO INVALIDA\n");
        exit(2);
    }

    // caso a posicao seja válida, pegar o antecessor do elemento que eu quero remover
    for(aux = lista; posicao > 1; aux = aux->proximo, posicao--); // aux vai conter o antecessor

    // aux2 vai receber o endereço do elemento que eu quero remover(sucessor de aux)
    aux2 = aux->proximo;

    // aux vai apontar para o proximo do que eu quero remover
    aux->proximo = aux2->proximo;

    // removo aux2
    free(aux2);

    // atualizando a quantidade
    lista->inf--;
}

void destruir(LISTA_ENC lista){
    LISTA_ENC aux;

    aux = lista->proximo;
    while(aux != NULL){
        free(aux);
        aux = aux->proximo;

    }
}
