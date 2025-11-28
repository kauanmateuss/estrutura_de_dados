#include <stdio.h>
#include <stdlib.h>
#include "minhaLib.h"

typedef struct node {
    int inf;
    struct node *father, *left, *right;
}NODE;

typedef NODE *ARVORE;

void makeTree(ARVORE *arv, int v){
    // criando a arvore
    *arv = (ARVORE) malloc(sizeof(NODE));

    if(!(*arv)){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }

    (*arv)->inf = v;
    (*arv)->father = NULL;
    (*arv)->left = NULL;
    (*arv)->right = NULL;
}

void setLeft(ARVORE arv, int v){
    // alocando memoria para o novo elemento
    arv->left = (ARVORE) malloc(sizeof(NODE));

    if(!arv->left){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }

    arv->left->inf = v;
    arv->left->father = arv;
    arv->left->left = arv->left->right = NULL;
}

void setRight(ARVORE arv, int v){
    // alocando memoria para um novo filho direito
    arv->right = (ARVORE) malloc(sizeof(NODE));

    if(!arv->right){
        printf("ERRO, MEMORIA INSUFICIENTE\n");
        exit(1);
    }

    arv->right->inf = v;
    arv->right->father = arv;
    arv->right->right = arv->right->left = NULL;
}

int info(ARVORE arv){
    return arv->inf;
}

ARVORE left(ARVORE arv){
    return arv->left;
}

ARVORE right(ARVORE arv){
    return arv->right;
}

ARVORE father(ARVORE arv){
    return arv->father;
}

ARVORE brother(ARVORE arv){
    // verifico se arv não não raiz
    if(arv->father != NULL){
        // verifico se é o esquerdo
        if(arv->father->left == arv)
            return arv->father->right;
        else
            return arv->father->left;
    }

    return NULL;
}

int isLeft(ARVORE arv){
    // verificando se arv não é raiz
    if(arv->father != NULL){
        // verificando se é o esquerdo
        if(arv->father->left == arv)
            return 1;
        else
            return 0;
    }

    return 0;
}

int isRight(ARVORE arv){
    if(arv->father != NULL){
        return !isLeft(arv);
    }

    return 0;
}

void percursoLargura(ARVORE arv){
    // percuso em largura tenho que linearizar a arvore, adicionando em uma fila
    FILA fila;
    criar_fila(&fila);

    // se a arvore não for vazia, coloco na fila
    if(arv)
        ins_fila(fila, arv);

    // percorrendo enquanto a fila não é vazia
    while(!eh_vazia_fila(fila)){
        // consulto o no
        printf("%d ", info(buscar(fila)));

        // verifico o filho esquerdo, se existir coloco na fila
        if(left(buscar(fila))){
            ins_fila(fila, left(buscar(fila)));
        }

        // verifico se tem filho na direita, se tiver coloco na fila
        if(right(buscar(fila)))
            ins_fila(fila, right(buscar(fila)));

        // depois de verificar o no da arvore, removo
        remover(fila);
    }
}

void percursoPreOrdem(ARVORE arv){
    // se a arvore não for vazia eu percorro

    if(arv){
        // consulto o no, esquerda e direita
        printf("%d ", info(arv));
        percursoPreOrdem(left(arv));
        percursoPreOrdem(right(arv));
    }
}



void ins_ele(ARVORE *arv, int v){
    // verifico se a arvore existe, caso não, eu crio
    if(*arv == NULL)
        makeTree(arv, v);
    else{
        ARVORE no = *arv;

        // percorrendo a arvore verificando se é maior ou menor
        do {
            if(v < no->inf){
                // se tem filho na esquerda eu atualizo
                if(no->left)
                    no = no->left;
                else{
                    setLeft(no, v);
                    break;
                }
            }
            // caso seja maior ou igual
            else{
                // se for maior, verifico se tem filho na direita
                if(no->right)
                    no = no->right;
                else{
                    setRight(no, v);
                    break;
                }
            }

        }while(1);
    }
}


// Para remover, temos que verificar os 3 casos: se não tem filho na direita, se não tem na esquerda e se tem os dois
void removerFusao(ARVORE *arv){
    // se a arvore não for fazia
    if(*arv){
        ARVORE aux = *arv;

        // caso 1: se não tem filho na direita
        if((*arv)->right == NULL){
            // se tem filho esquerdo
            if((*arv)->left)
                (*arv)->left->father = (*arv)->father;

            *arv = (*arv)->left; // OU NULL
        }
        // caso 2 e 3:
        else{
            // caso 2: se não tem esquerdo
            if((*arv)->left == NULL){
                (*arv)->right->father = (*arv)->father;
            }
            // caso 3: tem os dois filhos: fazer fusao
            else{
                aux = (*arv)->left;

                // percorrendo até o ultimo nó direito da subarvore esquerda
                while(aux->right)
                    aux = aux->right;

                // ajustando as referencias
                aux->right = (*arv)->right;
                aux->right->father = aux;

                aux = *arv;

                *arv = (*arv)->left;
            }
        }

        free(aux);

    }
}


void remocaoCopia(ARVORE *arv){
    // verifico se não é vazia
    if(*arv){
        ARVORE aux = *arv;

        // caso 1: onde não tem filho na direita
        if((*arv)->right == NULL){
            // verifico se tem na esquerda, se sim, atualizo o pai dele
            if((*arv)->left)
                (*arv)->left->father = (*arv)->father;
            
            *arv = (*arv)->left;
        }
        // caso 2 e 3:
        else{
            // caso 2: tem filho direito e não tem filho esquerdo
            if((*arv)->left == NULL)
                (*arv)->right->father = (*arv)->father;
            // caso3: Tenho que fazer por cópia
            else{
                aux = (*arv)->right;

                // percorrendo até o ultimo nó esquerdo da subarvore direita
                while(aux->left)
                    aux = aux->left;

                // copiando o valor para o NO que quero remover
                (*arv)->inf = aux->inf;

                // ajustando as ferecências
                // verifico se aux é o nó direito do que eu quero remover
                if(aux->father == *arv){
                    aux->father->right = aux->right; // Filho dir de arv aponta para o filho direito de aux

                    if(aux->father->right) // se esse filho direito existir, tenho que ajustar o pai dele
                        aux->father->right->father = aux->father;
                }
                // Se não for o filho direito, então é mais alto. Atualizo as referências
                else{
                    aux->father->left = aux->right;
                    // verifico se tem filho direito
                    if(aux->father->left)
                        aux->father->left->father = aux->father;
                }
            }
        }

        free(aux);
    }
}




int main() {
    return 0;
}