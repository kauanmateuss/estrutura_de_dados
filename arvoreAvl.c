#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int num, altD, altE;
    struct nodo *dir, *esq;
} NODO;

typedef NODO *ARV_AVL;

void rotacaoDireita(ARV_AVL *no) {
    ARV_AVL aux1, aux2;
    aux1 = (*no)->esq;
    aux2 = aux1->dir;

    // realizando a rotação
    (*no)->esq = aux2; //  o filho direito da subarvore esquerda vira o filho esquerdo do nó
    aux1->dir = *no;

    // ajustando altura do no que desceu
    if((*no)->esq == NULL){
        (*no)->altE = 0;
    }
    // se tiver filho esquerdo, verifico qual a maior altura 
    else{
        if((*no)->esq->altE > (*no)->esq->altD){
            // filho esquerdo maior que o direito;
            (*no)->altE = (*no)->esq->altE +1; //
        }
        else{
            // filho direito maior do que o esquerdo
            (*no)->altE = (*no)->esq->altD +1;
        }
    }

    // ajustando altura de aux1(nova raiz)
    if(aux1->dir->altE > aux1->dir->altD){
        aux1->altD = aux1->dir->altE + 1;
    }
    else{
        aux1->altD = aux1->dir->altD + 1;
    }

    // atualizando a raiz
    *no = aux1;
}


void rotacaoEsquerda(ARV_AVL *no){
    ARV_AVL aux1, aux2;

    aux1 = (*no)->dir;
    aux2 = aux1->esq;

    // faazendo a rotacao
    (*no)->dir = aux2;
    aux1->esq = *no;

    // atualizando altura do no que desceu
    if((*no)->dir == NULL)
        (*no)->altD = 0;
    else{
        // verificando a altura do filho direito do no
        if((*no)->dir->altE > (*no)->dir->altD)
            (*no)->altD = (*no)->dir->altE + 1;
        else
            (*no)->altD = (*no)->dir->altD + 1;
    }

    // verificando a altura do nó que subiu
    if(aux1->esq->altE > aux1->dir->altD)
        aux1->altE = aux1->esq->altE + 1;
    else
        aux1->altE = aux1->esq->altD + 1;

    *no = aux1;
}

void balanceamento(ARV_AVL *arv){
    int FBpai, FBfilho;

    FBpai = (*arv)->altD - (*arv)->altE;

    if(FBpai == -2){
        FBfilho = (*arv)->esq->altD - (*arv)->esq->altE;

        if(FBfilho <= 0){
            rotacaoDireita(arv);
        }
        else{
            rotacaoEsquerda(&((*arv)->dir));
            rotacaoDireita(arv);
        }
    }
}

int main() {
    return 0;
}