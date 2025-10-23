#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int inf;
    struct no *proximo;
    struct no *anterior;

}NO;

typedef NO *LISTA;

void criar_lista(LISTA *);
int eh_vazia(LISTA);
int tamanho(LISTA);
void inserir(LISTA, int, int);
int buscar(LISTA, int);
void remover(LISTA, int);
void destruir(LISTA);


int main(){
    LISTA lista;
    int valor, posicao, opcao = -1;

    criar_lista(&lista);

    while(opcao != 0){
		printf("O que deseja fazer: 1 - inserir, 2- buscar, 3 - remover, 4-destruir, 0 - SAIR\n");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				printf("Digite o valor e a posicao do novo elemento: ");
				scanf("%d %d", &valor, &posicao);

				// adicionando o valor na lista
				inserir(lista, valor, posicao);

				break;
			
			case 2:
				printf("Digite a posicao do elemento que deseja buscar:");
				scanf("%d", &posicao);

				// printando o valor buscado
				printf("Valor: %d\n", buscar(lista, posicao));
				break;

			case 3:
				printf("Digite a posicao do elemento que deseja remover: ");
				scanf("%d", &posicao);

				// removendo o valor da lista
				remover(lista, posicao);
				printf("Valor removido\n");
				break;

			case 4:
				printf("DESTRUINDO...");
                destruir(lista);
				break;

			case 0:
				printf("Saindo...\n");
				break;

			default:
				printf("Opcao invalida, tente novamente\n");
				break;
		}

	}



    return 0;
}


void criar_lista(LISTA *lista){
    // definindo um nó cabeçalho
    *lista = (NO*) malloc(sizeof(NO));

    // verificando se alocou a memoria
    if((*lista) == NULL){
        return;
    }
    
    (*lista)->anterior = (*lista)->proximo = (*lista);
    (*lista)->inf = 0;
}

int eh_vazia(LISTA lista){
    return(lista->inf == 0);
}

int tamanho(LISTA lista){
    return(lista->inf);
}

void inserir(LISTA lista, int valor, int posicao){
    NO *novo, *aux;

    // verificando se a posicao é valida
    if(posicao < 1 || posicao > tamanho(lista)+1){
        return;
    }

    novo = (NO*) malloc(sizeof(NO));

    if(!novo)
        return;

    novo->inf = valor;

    // caso de inserção
    // percorrendo até a posicao que antecede onde eu quero inserir
    for(aux = lista; posicao > 1; aux = aux->proximo, posicao--);

    novo->proximo = aux->proximo;
    novo->anterior = aux;
    aux->proximo->anterior = novo;
    aux->proximo = novo;

    lista->inf++;
}

int buscar(LISTA lista, int posicao){
    // verificando se a posicao é valida
    if(posicao < 1 || posicao > tamanho(lista)){
        return 0;
    }

    // percorrendo a lista até o elemento que eu quero
    while(posicao > 0){
        lista = lista->proximo;
        posicao--;
    }

    return (lista->inf);
}

void remover(LISTA lista, int posicao){
    NO *aux, *aux2;

    // verificar se a posicao é valida
    if(posicao < 1 || posicao > tamanho(lista)){
        return;
    }

    // caso de retirada
    // percorre até o nó que antecede o que eu quero remover
    for(aux = lista; posicao > 1; aux = aux->proximo, posicao--);

    aux2 = aux->proximo;
    aux2->proximo->anterior = aux2->anterior;
    aux->proximo = aux2->proximo;

    free(aux2);

    lista->inf--;

}


void destruir(LISTA lista){
    NO *aux;
    int tamanho = lista->inf;

    do{
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }while(tamanho--);
}