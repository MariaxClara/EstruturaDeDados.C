#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct pilha {
    node *topo;
} pilha;

typedef pilha *Pilha;
typedef node *Node;


Pilha cria_pilha() {
    Pilha p = (Pilha) malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

void empilha(Pilha p, int x) {
    Node novo = (Node) malloc(sizeof(node));
    novo->data = x;
    novo->next = p->topo;
    p->topo = novo;
}

void desempilha(Pilha p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!");
        exit(1);
    }
    Node aux = p->topo;
    int x = aux->data;
    p->topo = aux->next;
    free(aux);
}

void torre_hanoi(Pilha po, Pilha pd) {
    int n;
    n = po->topo->data;
    desempilha(po);
    empilha(pd, n);
}

int verifica_qtd_jogadas(int m, int n){
    int quantidade = 0;
    quantidade = pow(2, n) - 1;
    if (quantidade < m)
        return 1;
    else
        return 0;
}

Pilha inicia_pilhas(Pilha p1, int n){
    int i;
    for (i = 0; i < n; i++)
        empilha(p1, i);
    return p1;
}

void move_torre(int po, int pd, Pilha p1, Pilha p2, Pilha p3){
    if (po == 1 && pd == 2) {
        torre_hanoi(p1, p2);
    } else if (po == 1 && pd == 3) {
        torre_hanoi(p1, p3);
    } else if (po == 2 && pd == 1) {
        torre_hanoi(p2, p1);
    } else if (po == 2 && pd == 3) {
        torre_hanoi(p2, p3);
    } else if (po == 3 && pd == 1) {
        torre_hanoi(p3, p1);
    } else if (po == 3 && pd == 2) {
        torre_hanoi(p3, p2);
    }
}

void qtd_discos_final(Pilha p, int n){
    Node aux = p->topo;
    int qtd = 0;
    while (aux != NULL) {
        qtd++;
        aux = aux->next;
    }
    if (qtd != n) {
        printf("Wrong move!");
        exit(1);
    }
}

int main(int argc, char const *argv[])
{
    int m,n,i, po, pd, x = 0, y = 0, z = 0, opc = 0;
    Pilha p1 = cria_pilha();
    Pilha p2 = cria_pilha();
    Pilha p3 = cria_pilha();
    scanf("%d %d",&n,&m);
    p1 = inicia_pilhas(p1, n);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d",&po,&pd);
        move_torre(po, pd, p1, p2, p3);
    }
    if (verifica_qtd_jogadas(m,n) == 1){
        printf("Unfinished");
        return 0;
    } else {
        printf("Solved");
    }
    return 0;
}
