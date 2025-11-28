#include <stdio.h>
#include <stdlib.h>

#define NUMNODES 100 // numero de nós da minha arvore

typedef struct{
    int inf;
    int father;
    int left;
    int right;
}NODE;

typedef struct{
    int root; // Raiz da arvore
    NODE nodes[NUMNODES];
    int nodeFree;
}TREE;

int getNode(TREE *t){
    // verificar se o node é livre
    if(t->nodeFree != -1){
        int i = t->nodeFree;
        t->nodeFree = t->nodes[t->nodeFree].left; // nodeFree = proximo nodeFree
        return i;
    }
    else{ // se o node não tiver livre
        return -1;
    }
}

void freeNode(TREE *t, int node){
    t->nodes[node].left = t->nodeFree;
}

void makeTree(TREE *t, int x){
    int i, ind;
    
    // percorrendo a arvore e fazendo o campo left apontar para o proximo
    for(i = 0; i < NUMNODES - 1; i++){
        t->nodes[i].left = i+1;
    }
    t->nodes[i].left = -1; // ultimo campo = -1

    ind = getNode(t); // ind = proximo node livre que nesse caso é o node 0;

    // verificando se o node é livre
    if(ind != -1){
        t->nodes[ind].inf = x;
        t->nodes[ind].left = -1;
        t->nodes[ind].right = -1;
        t->nodes[ind].father = -1;
    }
    else{ // se o node não for livre
        printf("IMPOSSIVEL CONSTRUIR A ARVORE\n");
        exit(1);
    }
}


// função para inserir um novo filho a esquerda, p é o pai e x é o valor
void setLeft(TREE *t, int p, int x){
    int ind = getNode(t); // Pegando o proximo espaço livre

    // verificando se o node está livre
    if(ind != -1){
        t->nodes[p].left = ind; // o pai p agora vai apontar para o novo filho a esquerda
        t->nodes[ind].inf = x;
        t->nodes[ind].left = -1;
        t->nodes[ind].right = -1;
        t->nodes[ind].father = p;
    }
    else{
        printf("ERRO, IMPOSSIVEL INSERIR UM FILHO A ESQUERDA\n");
        exit(2);
    }
}

void setRight(TREE *t, int p, int x){
    int ind = getNode(t); // ind = proximo nodo livre

    // verificando se o node está livre
    if(ind != -1){
        t->nodes[p].right = ind;
        t->nodes[ind].father = p;
        t->nodes[ind].inf = x;
        t->nodes[ind].left = -1;
        t->nodes[ind].right = -1;
    }
    else{
        printf("ERRO, IMPOSSIVEL INSERIR FILHO A DIREITA\n");
        exit(3);
    }
}

int info(TREE *t, int p){
    return (t->nodes[p].inf);
}

int left(TREE *t, int p){
    return t->nodes[p].left;
}

int rigth(TREE *t, int p){
    return t->nodes[p].right;
}

int father(TREE *t, int p){
    return t->nodes[p].father;
}

int brother(TREE *t, int p){
    // verificando o pai de p existe
    if(father(t, p) != -1){
        // verifico se o p é um filho a esqueda
        if(isLeft(t, p)) // se for o da esquerda, então o irmão é o da direita
            return rigth(t, father(t, p)); // filho direito do pai
        else
            return t->nodes[t->nodes[p].father].left; // retorna o indice do filho esquerdo
    }
    // se não tiver irmão
    return -1;
}

int isLeft(TREE *t, int p){
    int pai = father(t, p);

    // verificando se o pai é a raiz
    if(pai == -1)
        return 0;
    
    // verificando se é o esquerdo do pai
    if(left(t, pai) == p)
        return 1;

    // caso não seja o da esquerda
    return 0;
}


int isRight(TREE *t, int p){
    // verificando se existe um pai
    if(father(t, p) != -1)
        return(!ifLeft(t, p));
    
    return 0;
}

int main() {
    return 0;
}