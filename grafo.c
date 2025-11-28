#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 10

struct node{
    
};

struct arc{
    int adj;
};

struct graph{
    struct node nodes[MAXNODES];
    struct node arcs[MAXNODES][MAXNODES];
};

struct graph g;

void ligar(int adj[][MAXNODES], int node1, int node2){
    adj[node1][node2] = 1;
}

void remover(int adj[][MAXNODES], int node1, int node2){
    adj[node1][node2] = 0;
}

int adjacente(int adj[][MAXNODES], int node1, int node2){
    return adj[node1][node2];
}

int procurarCaminho(int adj[][MAXNODES], int k, int a, int b){
    int c;

    // se o comprimento for 1, caso base
    if(k == 1)
        return (adjacente(adj, a, b))
    
    for(c = 0; c < n; ++c)
}


int main(){


    return 0;
}