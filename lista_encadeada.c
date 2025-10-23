#include <stdio.h>
#include <stdlib.h>

// tipo nó
typedef struct no{
    int dados;
    struct no *proximo; // endereço do proximo NÓ

}NO;

// // tipo lista
// typedef struct{
//     NO *inicio; // endereço do tipo NÓ
//     int qtd;    // quantidade de elemento

// }LISTA;

typedef NO *LISTA; // LISTA é um ponteiro que aponta para NO;


//protótipos das funções do TAD LISTA
void criar_lista(LISTA *);
int tam(LISTA );
int eh_vazia(LISTA );
void inserir(LISTA *, int , int );
void remover(LISTA *, int );
void destruir(LISTA );

int main() {
    // LISTA lista;
    // NO no;

    // printf("ENDERECO NO: %p\n", &no);
    // printf("ENDERECO primeiro elemento: %p\n", lista.inicio);

    return 0;
}


void criar_lista(LISTA *lista){
    *lista = NULL;
}

int tam(LISTA lista){
    int qtd = 0;

    while(lista != NULL){
        qtd++;
        lista = lista->proximo;
    }

    return qtd;
}


int eh_vazia(LISTA lista){
    return (lista == NULL);  // Endereço do primeiro elemento for NULL a lista é vazia
}


void inserir(LISTA *lista, int valor, int posicao){
    NO *novo;   // Novo NÓ

    // verificando se a posicao é valida
    if(posicao < 1 || posicao > tam(*lista)+1){
        printf("ERRO, POSICAO INVALIDA\n");
        exit(1);
    }

    // se a posicao for válida
    // reservando memoria para o novo elemento
    novo = (NO *) malloc(sizeof(NO));

    if(!novo){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(2);
    }

    // novo vai receber o valor passado
    novo->dados = valor;

    // caso queira inserir na primeira posicao
    if(posicao == 1){
        novo->proximo = *lista; // novo vai apontar para o antigo primeiro
        *lista = novo;  // e a referencia vai apontar para o novo inicio;
    }
    // caso não seja na primeira posicao:
    else {
        NO *aux;

        for(aux = *lista; posicao > 2; aux = aux->proximo, posicao--);  // aux vai sair com o valor da posicao anterior ao que eu quero inserir

        novo->proximo = aux->proximo;  // novo vai apontar para o proximo do aux.
        aux->proximo = novo;  // posicao anterior vai apontar para o novo
    }
}

int buscar(LISTA lista, int posicao){
    // verificando se a posicao é valida
    if(posicao < 1 || posicao > tam(lista)){
        printf("ERRO, POSICAO INVALIDA\n");
        exit(1);
    }

    // caso a posicao seja válida
    // percorrendo a lista e vendo o valor do elemento da posicao buscada
    for(; posicao > 1; posicao--){
        lista = lista->proximo;
    }

    return lista->dados;
}

void remover(LISTA *lista, int posicao){
    NO *aux;
    
    // verificando se a posicao é válida
    if(posicao < 1 || posicao > tam(*lista)){
        printf("ERRO, POSICAO INVALIDA\n");
        exit(1);
    }

    // caso a posicao seja válida
    // caso seja o primeiro elemento
    if(posicao == 1){
        aux = *lista; // aux = primeiro elemento da lista
        *lista = aux->proximo;
        free(aux);
    }
    // caso não seja o a remorção do primeiro elemento
    else{
        NO *aux2;

        // percorrendo a lista até a posicao anterior a que eu quero remover
        for(aux = *lista; posicao > 2; aux = aux->proximo, posicao --);

        // aux2 = aux + 1;
        aux2 = aux->proximo; // aux2 vai receber o nó que eu quero remover

        aux->proximo = aux2->proximo;
        free(aux2);
    }
}

void destruir(LISTA lista){
    LISTA aux;
    while(lista){
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }
}