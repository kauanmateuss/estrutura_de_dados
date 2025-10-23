#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int inf;
    struct no *anterior;
    struct no *proximo;
}NO;

typedef NO *LISTA;

void criar_lista(LISTA *);
int eh_vazia(LISTA);
int tamanho(LISTA);
void inserir(LISTA *, int , int);
int buscar(LISTA, int);
void remover(LISTA *, int);
void destruir(LISTA);


int main(){
    LISTA lista;
    int valor, posicao, opcao = -1;

    criar_lista(&lista);

    while(opcao != 0){
		printf("O que deseja fazer: 1 - inserir, 2- buscar, 3 - remover, 4-ver valores, 0 - SAIR\n");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				printf("Digite o valor e a posicao do novo elemento: ");
				scanf("%d %d", &valor, &posicao);

				// adicionando o valor na lista
				inserir(&lista, valor, posicao);

				break;
			
			case 2:
				printf("Digite a posicao do elemento que deseja buscar:");
				scanf("%d", &posicao);

				// printando o valor buscado
				printf("Valor: %d\n", buscar(lista, posicao));
				break;

			case 3:
				// printf("Digite a posicao do elemento que deseja remover: ");
				// scanf("%d", &posicao);

				// // removendo o valor da lista
				// remover(&li, pos);
				// printf("Valor removido\n");
				break;

			case 4:
				// // printando valores da lista
				// for(int i = 0; i < lista->qtd; i++){
				// 	printf("%d\n", valores[i]);
				// }
				break;

			case 0:
				printf("Saindo...\n");
				break;

			default:
				printf("Opcao invalida, tente novamente\n");
				break;
		}

	}

}


void criar_lista(LISTA *lista){
    *lista = NULL;
}

int eh_vazia(LISTA lista){
    return (lista == NULL);
}

int tamanho(LISTA lista){
    int cont;

    // percorrendo a lista verificando se o proximo é NULL
    for(cont = 0; lista; lista = lista->proximo, cont++);

    return cont;
}


void inserir(LISTA *lista, int valor, int posicao){
    // verificando se a posicao para inserir é válida
    if(posicao < 1 || posicao > tamanho(*lista)+1){
        return;
    }

    NO *novo = (NO*) malloc(sizeof(NO));

    // verificando se a memoria foi alocada
    if(!novo)
        return;


    novo->inf = valor;

    // Situação de inserção de um novo elemento na lista vazia
    // quando quero inserir em uma lista vazia
    if(posicao == 1){
        // se a lista está vazia
        novo->anterior = NULL;
        novo->proximo = *lista; // novo aponta para o antigo primeiro, caso não exista, então aponta para NULL
        *lista = novo;
        
        // se existir o proximo, então a lista não estava vazia e o anterior do antigo primeiro tem que apontar para o novo primeiro
        if((*lista)->proximo){
            (*lista)->proximo->anterior = novo;
        }
    }
    else{
        // posicao final ou qualquer outra posicao que não seja a primeira ou ultima
        NO *aux;
        // percorrendo até o que antecece
        for(aux = *lista; posicao > 2; aux = aux->proximo, posicao--);
        
        // caso seja a ultima posicao
        novo->anterior = aux;
        novo->proximo = aux->proximo;
        aux->proximo = novo;

        // caso seja em outra posicao, o anterior do antigo recebe o novo
        if(novo->proximo)
            novo->proximo->anterior = novo;
    }
}

int buscar(LISTA lista, int posicao){
    int i = 0;

    // verificando se a posicao é válida
    if(posicao < 1 || posicao > tamanho(lista))
        return 0;

    // percorrendo até a posicao que foi passada
    for(; posicao > 1; posicao--)
        lista = lista->proximo;

    return (lista->inf);
}

void remover(LISTA *lista, int posicao){
    NO *aux;
    // verificando se a posicao é valida
    if(posicao < 1 || posicao > tamanho(*lista))
        return;

    // caso onde eu removo um elemento onde só tem ele na lista
    if(posicao == 1){
        aux = *lista; // aux vai apontar para o primeiro elemento
        *lista = aux->proximo; // refeExterna vai apontar para o proximo do primeiro

        // se o proximo do primeiro for != NULL então o anterior dele vai ser null
        if(*lista)
            (*lista)->anterior = NULL;
        
        free(aux);
    }
    else{
        // percorrendo até o elemento que quero remover
        for(aux = (*lista)->proximo; posicao > 2; aux = aux->proximo, posicao--);
        aux->anterior->proximo = aux->proximo;

        // situação onde não seja o ultimo
        if(aux->proximo){
            aux->proximo->anterior = aux->anterior;
        }

        free(aux);
    }
}

void destruir(LISTA lista){
    NO *aux;

    while(lista != NULL){
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }
    
}

void inverter_lista(LISTA *lista){
    // verificando se a lista é vazia
    if(*lista){
        NO *aux;

        do{
            aux = (*lista)->proximo; // aux vai apontar para o segundo elemento;
            (*lista)->proximo = (*lista)->anterior; // 
            (*lista)->anterior = aux;

            // verificando se o proximo elemento da lista existe
            if(aux)
                *lista = aux; // caso exista, a referencia vai apontar para o proximo
        }while(aux);
    }
}