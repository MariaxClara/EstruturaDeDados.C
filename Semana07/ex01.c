#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

typedef struct node {
    char data;
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

void empilha(Pilha p, char x) {
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
    char x = aux->data;
    p->topo = aux->next;
    free(aux);
}

//recebe uma expressão posfixa simples e devolve o valor da correspondente expressão aritmética.
Pilha calcula_expressao(char str[], Pilha p) {
    int i;
    char a, b, c;
    int x, y, z;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != '*' && str[i] != '+') {
            empilha(p, str[i]);
        } else {
            a = p->topo->data;
            desempilha(p);
            b = p->topo->data;
            desempilha(p);
            if (str[i] == '+') {
                x = a - '0';
                y = b - '0';
                z = x + y;
                c = z + '0';
                empilha(p, c);
            } else {
                x = a - '0';
                y = b - '0';
                z = x * y;
                c = z + '0';
                empilha(p, c);
            }
        }
    }
    return p;
}

void imprime(Pilha p){
    while (p->topo != NULL){
        printf("%c", p->topo->data);
        desempilha(p);
    }
}

void liberar(Pilha p){
    while (p->topo != NULL){
        desempilha(p);
    }
    free(p);
}

int main(int argc, char const *argv[])
{
    Pilha p = cria_pilha();
    char str[99];

    printf("Digite a expressão posfixa: \n");
    gets(str);
    p = calcula_expressao(str, p);
    imprime(p);
    liberar(p);

}
