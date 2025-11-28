#include <stdio.h>
#include <stdlib.h>
#include "minhaLib.h"

typedef struct node{
    int inf;
    struct node *father;
    struct node *left;
    struct node *right;
}NODE;

typedef NODE *TREE;

void makeTree(TREE *t, int x){
    // alocando memoria para a raiz da arvore
    *t = (TREE) malloc(sizeof(NODE));

    if(!(*t)){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }

    (*t)->inf = x;
    (*t)->father = NULL;
    (*t)->left = NULL;
    (*t)->right = NULL;
}

void setLeft(TREE t, int x){
    // alocando memoria pra o filho a esquerda
    t->left = (TREE) malloc(sizeof(NODE));

    if(!t->left){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(2);
    }

    t->left->inf = x;
    t->left->father = t;
    t->left->left = NULL;
    t->left->right = NULL;
}

void setRight(TREE t, int x){
    // alocando memoria para um novo filho direito
    t->right = (TREE) malloc(sizeof(NODE));

    if(!t->right){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(2);
    }

    t->right->inf = x;
    t->right->father = t;
    t->right->left = NULL;
    t->right->right = NULL;
}

int info(TREE t){
    return t->inf;
}

TREE left(TREE t){
    return t->left;
}

TREE right(TREE t){
    return t->right;
}

TREE father(TREE t){
    t->father;
}

TREE brother(TREE t){
    // verificando se tem pai
    if(t->father != NULL){
        // verificando se é o esquerdo
        if(isLeft(t))
            return (t->father)->right;
        else
            return (t->father)->left;
    }

    return NULL;
}

int isLeft(TREE t){
    // verificando se tem pai
    if(t->father == NULL)
        return 0;

    if(t->father->left == t)
        return 1;

    return 0;
}


int isRight(TREE t){
    if(t->father){
        return (!isLeft(t));
    }
    return 0;
}

void percusoLargura(TREE arvore){
    // Utiliza-se fila para colocar os nos da arvore encadeada
    FILA fila;
    cria_fila(&fila);

    // verifico se a arvore é vazia, se não for é porque tem uma raiz
    if(arvore){
        ins_fila(fila, arvore); // Coloco a raiz da arvore na fila;
    }

    // percorrendo a fila e verificando se ela não é vazia
    while(!eh_vazia_fila(fila)){
        printf("%d ", info(cons(fila))); // pegando a informação do no na fila
        // se tiver no a esquerda da raiz, adiciono na fila
        if(left(cons(fila)))
            ins_fila(fila, left(cons(fila)));

        // se tiver filho a direita da raiz, adiciono na fila
        if(right(cons(fila)))
            ins_fila(fila, right(cons(fila)));

        // retiro o primeiro da fila, e o proximo é o filho que adicionei
        ret(fila);
    }
}

void percusoPreOrdem(TREE arvore){
    // Caso base: Se a arvore estiver fazia
    if(arvore){
        // vou no nó, depois esquerda e depois direita
        printf("%d ", info(arvore));
        percusoPreOrdem(left(arvore));
        percusoPreOrdem(right(arvore));
    }
}

void percusoInOrdem(TREE arvore){
    //se não tiver vazia, faço o percuso
    if(arvore){
        percusoInOrdem(left(arvore));
        printf("%d ", info(arvore));
        percusoInOrdem(right(arvore));
    }
}

void percusoPosOrdem(TREE arvore){
    if(arvore){
        percusoPosOrdem(left(arvore));
        percusoPreOrdem(right(arvore));
        printf("%d ", info(arvore));
    }
}

 

int main() {
    return 0;
}