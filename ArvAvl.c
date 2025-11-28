#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int info, altE, altD;
    struct node *left, *right;
}NODE;

typedef NODE *ARV_AVL;

void rotacaoDireita(ARV_AVL *arv){
    ARV_AVL aux1, aux2;

    aux1 = (*arv)->left;
    aux2 = aux1->right;

    (*arv)->left = aux2;
    aux1->right = *arv;

    if((*arv)->left == NULL){
        (*arv)->altE = 0;
    }
    else{
        if((*arv)->left->altE > (*arv)->left->altD){
            (*arv)->altE = (*arv)->left->altE + 1;
        }
        else{
            (*arv)->altE = (*arv)->left->altD + 1;
        }
    }

    if(aux1->right->altE > aux1->right->altD){
        aux1->altD = aux1->right->altE + 1;
    }
    else{
        aux1->altD = aux1->right->altD + 1;
    }

    *arv = aux1;
}

void rotacaoEsquerda(ARV_AVL *arv){
    ARV_AVL aux1, aux2;

    aux1 = (*arv)->right;
    aux2 = aux1->left;

    (*arv)->right = aux2;
    aux1->left = *arv;

    if((*arv)->right == NULL){
        (*arv)->altD = 0;
    }
    else{
        if((*arv)->right->altE > (*arv)->right->altD){
            (*arv)->altD = (*arv)->right->altE + 1;
        }
        else{
            (*arv)->altD = (*arv)->right->altD + 1;
        }
    }

    if(aux1->left->altE > aux1->left->altD){
        aux1->altE = aux1->left->altE + 1;   
    }
    else{
        aux1->altE = aux1->left->altD + 1;
    }

    *arv = aux1;
}

void balanceamento(ARV_AVL *arv){
    int FBpai, FBfilho;

    FBpai = (*arv)->altD - (*arv)->altE;

    if(FBpai == 2){
        FBfilho = (*arv)->right->altD - (*arv)->right->altE;

        if(FBfilho >= 0){
            rotacaoEsquerda(arv);
        }
        else{
            rotacaoDireita(&((*arv)->right));
            rotacaoEsquerda(arv);
        }
    }
    else{
        if(FBpai == -2){
            FBfilho = (*arv)->left->altD - (*arv)->left->altE;

            if(FBfilho <= 0){
                rotacaoDireita(arv);
            }
            else{
                rotacaoEsquerda(&((*arv)->left));
                rotacaoDireita(arv);
            }
        }
    }
}

int main() {
    return 0;
}