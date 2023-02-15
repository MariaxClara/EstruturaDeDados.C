#include <stdio.h>
#include <stdlib.h>

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

//Cria pilha
Pilha cria_pilha() {
    Pilha p = (Pilha) malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

//Empilha
void empilha(Pilha p, char x) {
    Node novo = (Node) malloc(sizeof(node));
    novo->data = x;
    novo->next = p->topo;
    p->topo = novo;
}


//Desempilha
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


// A função recebe uma expressão posfixa simples e devolve na forma infixa, a funçao imprime o primeiro um número e depois um operador até chegar no final dos números
Pilha posfixa_infix(Pilha p, char str[]){
    int i, x, y;
    char a, b, c;
    x = strlen(str) - 1;
    for (i = 0; i <= x/2; i++) {
        empilha(p, str[i]);
        if (i != x || x != 1)
        {
            empilha(p, str[x]);
        }
        x--;
    }

    //Empilha o último número
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0')
        {
            if (str[i+1] == '+' || str[i+1] == '*')
            {
                empilha(p, str[i]);
            }
        }
    }
    return p;
}

//Imprime invertido, coloca os números em outra pilha e depois imprime a pilha com a saida invertida
void imprime_inversa(Pilha p){
    Pilha aux = cria_pilha();
    while (p->topo != NULL)
    {
        empilha(aux, p->topo->data);
        desempilha(p);
    }
    while (aux->topo != NULL)
    {
        printf("%c", aux->topo->data);
        desempilha(aux);
    }
}

//Libera a pilha
void libera_pilha(Pilha p) {
    Node aux = p->topo;
    while (aux != NULL) {
        Node t = aux->next;
        free(aux);
        aux = t;
    }
    free(p);
}

// Chama as funções
int main(int argc, char const *argv[])
{
    Pilha p = cria_pilha();
    char str[100];
    gets(str);
    p = posfixa_infix(p, str);
    imprime_inversa(p);
    libera_pilha(p);
    return 0;
}

