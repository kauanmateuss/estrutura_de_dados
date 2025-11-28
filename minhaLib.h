#ifndef MIHALIB.H
#define MINHALIB

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef struct {
    NODO *INICIO; // Vai apontar para o Ultimo PRIMEIRO NODO
    NODO *FIM;  // vai apontar para o PRIMEIRO NODO
}DESCRITOR;

typedef DESCRITOR *FILA;  // Ponteiro para descritor

void criar_fila(FILA *f);
int eh_vazia_fila(FILA f);
void ins_fila(FILA f, int v);
int buscar(FILA f);
void remover(FILA f);
int cons_ret(FILA f);
void destruir(FILA f);


#endif // MINHALIB