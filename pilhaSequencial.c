#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int TOPO; // variável para guardar o indice do topo da pilha
    int val[MAX];

}PILHA;

void cria_pilha(PILHA *p){
    p->TOPO = -1; // pois quando incrementado vai ser 0;
}

int eh_vazia(PILHA *p){
    return p->TOPO == -1;
}

void push(PILHA *p, int v){
    // verificando se a pilha está cheia
    if(p->TOPO == (MAX - 1)){
        printf("ERRO, ESTOURO NA PILHA\n");
        exit(1);
    }

    p->TOPO++;
    p->val[p->TOPO] = v; // Sempre adicionando no TOPO
}

int top(PILHA *p){
    // verificando se a pilha é vazia
    if(eh_vazia(p)){
        printf("ERRO, PILHA VAZIA\n");
        exit(2);
    }
    else{// se não for vazia, retornar o topo da pilha
        return (p->val[p->TOPO]);
    }
}

void pop(PILHA *p){
    // verificar se a pilha está vazia
    if(eh_vazia(p)){
        printf("ERRO, PILHA VAZIA\b");
        exit(2);
    }

    // caso não seja vazia eu devo remover o topo da pilha
    p->TOPO--; // topo agora é o indice do antigo penultimo
}

int top_pop(PILHA *p){
    // primeiro verifico se a pilha é vazia
    if(eh_vazia(p)){
        printf("ERRO, PILHA VAZIA\n");
        exit(2);
    }

    // salvando o indice do topo para retornar o conteudo
    int valor = p->val[p->TOPO];

    // removendo o topo
    p->TOPO--;

    return valor;
}


int main(){
    return 0;
}