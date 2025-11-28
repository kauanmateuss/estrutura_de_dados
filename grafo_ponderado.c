#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 10

struct arc {
    int adj;
    int peso;
};

struct arc g[MAXNODES][MAXNODES];

void ligarP(struct arc adj[][MAXNODES], int node1, int node2, int peso){
    adj[node1][node2].adj = 1;
    adj[node1][node2].peso = peso;
}

void removerP(struct arc adj[][MAXNODES], int node1, int node2){
    adj[node1][node2].adj = 0;
}

int adjacenteP(struct arc adj[][MAXNODES], int node1, int node2){
    return adj[node1][node2].adj;
}



int main(){
    return 0;
}