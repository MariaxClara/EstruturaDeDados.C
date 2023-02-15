#include <stdio.h>
#include <stdlib.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

//Estrutura da Lista
typedef struct lista {
    int data;
    struct lista *next;
} lista;

typedef struct lista *Lista;
//Estrutura da Matriz
typedef struct matriz_esparsa {
    int linhas;
    int colunas;
    Lista *matriz;
} matriz_esparsa;

typedef matriz_esparsa *MatrizEsparsa;

//Inicializa a Matriz
MatrizEsparsa inicializa_matriz(int linhas, int colunas) {
    MatrizEsparsa m = (MatrizEsparsa) malloc(sizeof(matriz_esparsa));
    m->linhas = linhas;
    m->colunas = colunas;
    m->matriz = (Lista *) malloc(linhas * sizeof(Lista));
    int i;
    for (i = 0; i < linhas; i++)
        m->matriz[i] = NULL;
    return m;
}

//Insere Elementos na Matriz
void insere_elemento(MatrizEsparsa m, int linha, int coluna, int valor) {
    Lista novo = (Lista) malloc(sizeof(lista));
    novo->data = valor;
    novo->next = m->matriz[linha];
    m->matriz[linha] = novo;
}

//Procura elementos na Matriz
void procura_elemento(MatrizEsparsa m, int valor) {
    int i;
    for (i = 0; i < m->linhas; i++) {
        Lista aux = m->matriz[i];
        while (aux != NULL) {
            if (aux->data == valor) {
                printf("Elemento %d encontrado na linha %d e coluna %d da matriz esparsa", valor, i);
}
            aux = aux->next;
        }
    }
}

//Remofe elementos da Matriz
void remove_elemento(MatrizEsparsa m, int linha, int coluna) {
    Lista aux = m->matriz[linha];
    Lista ant = NULL;
    while (aux != NULL) {
        if (aux->data == coluna) {
            if (ant == NULL)
                m->matriz[linha] = aux->next;
            else
                ant->next = aux->next;
            free(aux);
            return;
        }
        ant = aux;
        aux = aux->next;
    }
}

//Imprime a Matriz
void imprime_matriz(MatrizEsparsa m) {
    int i;
    for (i = 0; i < m->linhas; i++) {
        Lista aux = m->matriz[i];
        while (aux != NULL) {
            printf("%d ", aux->data);
            aux = aux->next;
        }
        printf("\n");
    }
}

//Libera a Matriz
void destroi_matriz(MatrizEsparsa m) {
    int i;
    for (i = 0; i < m->linhas; i++) {
        Lista aux = m->matriz[i];
        while (aux != NULL) {
            Lista ant = aux;
            aux = aux->next;
            free(ant);
        }
    }
    free(m->matriz);
    free(m);
}

int main(int argc, char const *argv[])
{
    MatrizEsparsa m = inicializa_matriz(2, 2);
    insere_elemento(m, 0, 0, 1);
    insere_elemento(m, 0, 1, 2);
    insere_elemento(m, 1, 0, 3);
    insere_elemento(m, 1, 1, 4);
    printf("Matriz:\n");
    imprime_matriz(m);
    printf("Procurando elemento 1:\n");
    procura_elemento(m, 1);
    remove_elemento(m, 0, 0);
    remove_elemento(m, 0, 1);
    printf("Matriz Final:\n");
    imprime_matriz(m);
    destroi_matriz(m);

    return 0;
}