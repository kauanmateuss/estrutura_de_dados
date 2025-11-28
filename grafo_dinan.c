#include <stdio.h>
#include <stdlib.h>

struct nodetype {
    int info;
    struct nodetype *point;
    struct nodetype *next;
};

struct nodetype *nodeptr;

