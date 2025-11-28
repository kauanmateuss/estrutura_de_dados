#include <stdio.h>
#include <stdio.h>
#include "minhaLib.h"

typedef struct nodo{
    int inf;
    struct nodo *father;
    struct nodo *left;
    struct nodo *right;
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
    // verificando se T é raiz
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


void percusoLargura(TREE t){
    FILA fila;
    criar_fila(&fila);

    // verifico se a arvore é vazia
    if(t != NULL){
        // colocando a raiz na fila
        ins_fila(fila, t);
    }

    // percorrendo a fila enquanto não estiver vazia
    while(!eh_vazia_fila(fila)){
        // visito o nó (primeiro da fila)
        printf("%d ", info(buscar(fila)));

        // se tiver filho na esquerda eu coloco na fila
        if(left(buscar(fila)))
            ins_fila(fila, left(buscar(fila)));

        // se tiver filho na direita eu coloco na fila
        if(right(cons_fila(fila)))
            ins_fila(fila, right(buscar(fila)));

        // removo o nó que já foi visitado da fila
        remover(fila);
    }
}


void ins_ele(TREE *t, int v){
    // verifico se não existe arvore
    if(*t == NULL)
        makeTree(t, v);
    else{
        TREE raiz = *t;

        // percorrendo a arvore e verificando se é maior ou menor do que a raiz
        do{
            if(v < raiz->inf){
                // se tem filho na esquerda eu atualizo a raiz
                if(raiz->left)
                    raiz = raiz->left;
                else{ // se nao tem na esquerda entao eu insiro o novo no
                    setLeft(raiz, v);
                    break;
                }
            }
            else{
                if(raiz->right)
                    raiz = raiz->right;
                else{
                    setRight(raiz, v);
                    break;
                }
            }

        }while(1);
    }
}


void remocaoFusao(TREE *t){
    // se a arvore não for vazia
    if(*t){
        TREE temp = *t;

        // caso 1: Se não tenho filho na direita
        if((*t)->right == NULL){
            // verifico se tem na esquerda
            if((*t)->left){
                (*t)->left->father = (*t)->father;
            }

            *t = (*t)->left;
        }
        // caso 2:
        else{
            // Se tem na direita e não tem na esquerda
            if((*t)->left == NULL){
                (*t)->right->father = (*t)->father;
                *t = (*t)->right;
            }
            // caso 3: Fusao
            else{
                temp = (*t)->left;

                // percorrendo até o mais direito da subarvore esquerda
                while(temp->right)
                    temp = temp->right;

                // atualizando quem aponta pra quem
                temp->right = (*t)->right;
                temp->right->father = temp;

                temp = *t;

                *t = (*t)->left;
            }
        }
        
        free(temp);
    }
}


void remocaoCopia(TREE *t){
    // verificando se a arvore não é vazia
    if(*t){
        TREE temp = *t;

        // caso 1:
        if((*t)->right == NULL){
            if((*t)->left)
                (*t)->left->father = (*t)->father;

            *t = (*t)->left;
        }
        else{
            // caso 2: direito existe e esquerdo não
            if((*t)->left == NULL){
                (*t)->right->father = (*t)->father;
                *t = (*t)->right;
            }
            // caso 3: Tem 2 filhos, fazer a copia
            else{
                temp = (*t)->right;

                // percorrendo até o ultimo filho esquerdo da subarvore direita
                while(temp->left)
                    temp = temp->left;

                // copio o conteudo
                (*t)->inf = temp->inf;

                // caso meu sucessor seja filho a direita do que eu quero remover
                if(temp->father == *t){
                    temp->father->right = temp->right;

                    // se o sucessor tiver filho na direita, atualizo o pai também
                    if(temp->father->right){
                        temp->father->right->father = temp->father;
                    }
                }
                // verificando se não for filho direito, for nivel mais alto
                else{
                    temp->father->left = temp->right;
                    // se o que eu quero remover tiver filho direito, atualizo o pai dele
                    if(temp->father->left)
                        temp->father->left->father = temp->father;
                }
            }
        }

        free(temp);
    }
}


int main() {
    return 0;
}