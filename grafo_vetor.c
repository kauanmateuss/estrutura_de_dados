#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 500

typedef struct nodetype {
    int info;
    int point;
    int next;
}TIPONODO;

typedef TIPONODO listaNodos[MAXNODES];

void joinwt(listaNodos node, int p, int q, int wt){
    int r, r2;

    r2 = -1;
    r = node[p].point; // pega o primeiro arco do nó p

    // percorrendo a lista de arcos, vendo se já existe arco para q
    while(r >= 0 && node[r].point != q){
        r2 = r;
        r = node[r].next;
    }

    // verifico se o arco existe e atualizo o peso caso exista
    if(r >= 0){
        node[r].info = wt;
        return;
    }
    // se não existir então eu crio um novo arco
    r = getNode();
    node[r].point = q;
    node[r].next = -1;
    node[r].info = wt;

    // coloco novo arco na lista
    (r2 < 0) ? (node[p].point = r) : (node[r2].next = r);
}

int main(){
    return 0;
}