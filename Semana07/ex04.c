#include <stdio.h>
#include <stdlib.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

 typedef struct lista {
     char data;
     struct lista *next;
 } lista;

 typedef struct lista *Lista;

void inicializa(Lista l) {
    l = NULL;
}

Lista insere_na_lista(Lista l, char c) {
    Lista novo = (Lista) malloc(sizeof(lista));
    novo->data = c;
    novo->next = l;
    return novo;
}

void qtd_operadores(Lista l) {
    Lista p;
    for (p = l; p != NULL; p = p->next) {
        procura_na_lista(l, p->data);
    }
}

int procura_na_lista(Lista l, char c) {
    Lista p;
    int aux = 0;
    for (p = l; p != NULL; p = p->next) {
        if (p->data == c) {
             aux++;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int quantidade, sequencia, i, j;
    char operador, operador2;
    Lista lista = (Lista) malloc(sizeof(lista));
    Lista aux = (Lista) malloc(sizeof(lista));
    inicializa(lista);
    inicializa(aux);

    scanf("%d %d", &quantidade, &sequencia);
    quantidade = quantidade * 2;
    while (quantidade != 0) {
        scanf("%c %c", &operador,&operador2);
        aux = insere_na_lista(aux, operador);
        aux = insere_na_lista(aux, operador2);
        quantidade--;
    }
    sequencia = sequencia * 2;
    while (sequencia != 0) {
        scanf("%c", &operador);
        lista = insere_na_lista(lista, operador);
        sequencia--;
    }
    
    return 0;
}

