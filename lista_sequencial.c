#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // tamanho da lista


// definindo o tipo lista
typedef struct{
	int qtd;
	int valores[MAX];
}LISTA;

// protótipos das funções

void criar_lista(LISTA *);
int tamanho(LISTA *);
void inserir(LISTA *, int, int);
int buscar(LISTA *, int);
void remover(LISTA *, int);

// Resolucao atividade
int pertence(LISTA *, int);

int main() {
	// definindo a lista
	LISTA li;
	int valor, pos, opcao;

	// criando a lista
	criar_lista(&li);

	while(opcao != 0){
		printf("O que deseja fazer: 1 - inserir, 2- buscar, 3 - remover, 4-ver valores, 0 - SAIR\n");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				printf("Digite o valor e a posicao do novo elemento: ");
				scanf("%d %d", &valor, &pos);

				// adicionando o valor na lista
				inserir(&li, valor, pos);
				break;
			
			case 2:
				printf("Digite a posicao do elemento que deseja buscar:");
				scanf("%d", &pos);

				// printando o valor buscado
				printf("Valor: %d\n", buscar(&li, pos));
				break;

			case 3:
				printf("Digite a posicao do elemento que deseja remover: ");
				scanf("%d", &pos);

				// removendo o valor da lista
				remover(&li, pos);
				printf("Valor removido\n");
				break;

			case 4:
				// printando valores da lista
				for(int i = 0; i < li.qtd; i++){
					printf("%d\n", li.valores[i]);
				}
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



// Corpos das funções
void criar_lista(LISTA *lista){
	// inicializando a quantidade como zero
	lista->qtd = 0;
}

void inserir(LISTA *lista, int valor, int pos){
	int i;
	
	// verificando se a lista está cheia:
	if(lista->qtd == MAX){
		printf("ERRO, LISTA CHEIA\n");
		exit(1);
	}
	else{
		// verificando se a posição é válida
		if(pos < 1 || pos > lista->qtd + 1){
			printf("ERRO, POSICAO INVALIDA\n");
			exit(2);
		}
		
		// se a posicao for válida
		// movendo os elementos para inserir o novo. Só vai mover caso queira inserir entre 2 posicoes
		for(i = lista->qtd; i >= pos; i--){
			lista->valores[i] = lista->valores[i-1];
		}
		
		// inserindo o novo valor na lista
		lista->valores[pos-1] = valor;
		
		// incrementando a lista
		lista->qtd++;
	}
}

int buscar(LISTA *lista, int pos){
	// verificando se a posição que deseja buscar é válida:
	if(pos < 1 || pos > lista->qtd){
		printf("ERRO, POSICAO INVALIDA\n");
		return 0;
	}
	else{
		return lista->valores[pos-1];
	}
}

void remover(LISTA *lista, int pos){
	int i;
	
	// verificando se a posição é valida:
	if(pos < 1 || pos > lista->qtd){
		printf("ERRO, POSICAO INVALIDA\n");
		exit(3);
	}
	else{
		// removendo o valor da posição e reorganizazndo os outros valores no vetor
		lista->qtd--;
		
		// sobscreve o valor que deseja remover
		for(i = pos-1; i < lista->qtd; i++){
			lista->valores[i] = lista->valores[i+1];
		}	
	}
}

int pertence(LISTA *lista, int valor){
	// percorrendo a lista para ver se o valor está nela
	int i;

	for(i = 0; i < lista->qtd; i++){
		// verificando cada valor com o valor buscado
		if(valor == lista->valores[i]){
			return 1; // valor pertence a lista
		}
		else{
			return 0; // valor não pertence a lista
		}
	}

}


void gerar_lista(LISTA *lista, int menor, int maior){
	// intervalo inválido
	if(menor > maior){
		printf("ERRO, intervalo invalido\n");
		exit(4);
	}
	else{
		// caso base:
		if(maior == menor){
			criar_lista(lista);
			inserir(lista, menor, 1);
		}
		else{
			// chamada recursiva
			gera_lista(lista, menor+1, maior);
			inserir(lista, menor, 1);
		}
	}
}



