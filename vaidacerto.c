#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *father, *left, *right;
}NODE;


typedef NODE *ARV;

void makeTree(ARV *a, int v){
    *a = (ARV)malloc(sizeof(NODE));
}



int main() {
    return 0;
}