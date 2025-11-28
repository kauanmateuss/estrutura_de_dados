#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *father, *left, *right;
}NODE;

typedef NODE *ARV;

void makeTree(ARV *arv, int v){
    *arv = (ARV)malloc(sizeof(NODE));

    if(!(*arv)){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(1);
    }

    (*arv)->info = v;
    (*arv)->father = NULL;
    (*arv)->left = NULL;
    (*arv)->right = NULL;
}

void setLeft(ARV arv, int v){
    arv->left = (ARV)malloc(sizeof(NODE));

    if(!arv->left){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(2);
    }

    arv->left->info = v;
    arv->left->father = arv;
    arv->left->left = arv->left->right = NULL;
}

void setRight(ARV arv, int v){
    arv->right = (ARV)malloc(sizeof(NODE));

    if(!arv->right){
        printf("ERRO, MEMORIA CHEIA\n");
        exit(3);
    }

    arv->right->info = v;
    arv->right->father = arv;
    arv->right->right = arv->right->left = NULL;
}

int info(ARV arv){
    return arv->info;
}

ARV left(ARV arv){
    return arv->left;
}

ARV right(ARV arv){
    return arv->right;
}

ARV father(ARV arv){
    return arv->father;
}

ARV brother(ARV arv){
    if(arv->father != NULL){
        if(arv->father->left == arv)
            return arv->father->right;
        else
            return arv->father->left;
    }

    return NULL;
}

int isLeft(ARV arv){
    if(arv->father != NULL){
        if(arv->father->left == arv)
            return 1;
        else
            return 0;
    }
    
    return 0;
}


int isRight(ARV arv){
    if(arv->father == NULL)
        return 0;
    else
        return !isLeft(arv);
}


void percursoLargura(ARV arv){
    FILA fila;
    criarFila(&fila);

    if(arv)
        insFila(fila, arv);

    while(!ehVaziaFila(fila)){
        printf("%d ", info(buscar(fila)));

        if(left(buscar(fila)))
            insFila(left(buscar(fila)));

        if(right(buscar(fila)))
            insFila(right(buscar(fila)));
        
        retFila(fila);
    }
}


void insEle(ARV *arv, int v){
    if(*arv == NULL)
        makeTree(arv, v);
    else{
        ARV no = *arv;

        do{
            if(v < no->info){
                if(no->left)
                    no = no->left;
                else{
                    setLeft(no, v);
                    break;
                }
            }
            else{
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


void remorcaoFusao(ARV *arv){
    if(*arv){
        ARV aux = *arv;

        if((*arv)->right == NULL){
            if((*arv)->left)
                (*arv)->left->father = (*arv)->father;
            
            *arv = (*arv)->left; // OU NULL;
        } 
        else{
            if((*arv)->left == NULL){
                (*arv)->right->father = (*arv)->father;
                *arv = (*arv)->right;
            }
            else{
                aux = (*arv)->left;

                while(aux->right)
                    aux = aux->right;

                aux->right = (*arv)->right;
                aux->right->father = aux;

                aux = *arv;

                *arv = (*arv)->left;
            }
        }

        free(aux);
    }
}


void remorcaoCopia(ARV *arv){
    if(*arv){
        ARV aux = *arv;

        if((*arv)->right == NULL){
            if((*arv)->left)
                (*arv)->left->father = (*arv)->father;
            
            *arv = (*arv)->left;
        }
        else{
            if((*arv)->left == NULL){
                (*arv)->right->father = (*arv)->father;
                *arv = (*arv)->right;
            }
            else{
                aux = (*arv)->right;

                while(aux->left)
                    aux = aux->left;

                (*arv)->info = aux->info;

                if(aux->father == *arv){
                    aux->father->right = aux->right;

                    if(aux->father->right){
                        aux->father->right->father = aux->father;
                    }
                }
                else{
                    aux->father->left = aux->left;

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