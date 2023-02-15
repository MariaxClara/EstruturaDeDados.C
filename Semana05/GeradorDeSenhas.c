#include <stdio.h>
#include <stdlib.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

/* Declarando as estruturas da Fila */
struct no {
  char tipo;
  int numero;
  struct no *prox;
};

typedef struct no *no;

struct fila {
  no inicio;
  no fim;
};

typedef struct fila *fila;

/* Inicializa a Fila */
fila cria_fila() {
  fila f = (fila)malloc(sizeof(struct fila));
  f->inicio = NULL;
  f->fim = NULL;
  return f;
}

/* Insere Ordenado Na Fila, a prioridade sempre vai ser o primeiro da fila*/
void insere_ordenado(fila f, char tipo, int posicao) {
  no novo = (no)malloc(sizeof(struct no));
  novo->tipo = tipo;
  novo->numero = posicao;
  novo->prox = NULL;
  if (f->inicio == NULL) {
    f->inicio = novo;
    f->fim = novo;
  } else {
    no aux = f->inicio;
    no ant = NULL;
    while (aux != NULL && aux->tipo == 'P') {
      ant = aux;
      aux = aux->prox;
    }
    if (ant == NULL) {
      novo->prox = f->inicio;
      f->inicio = novo;
    } else {
      ant->prox = novo;
      novo->prox = aux;
    }
    if (aux == NULL) {
      f->fim = novo;
    }
  }
}
/* Imprime a fila */
void imprime_fila(fila f) {
  no aux = f->inicio;
  while (aux != NULL) {
    printf("%c", aux->tipo);
    aux = aux->prox;
  }
}

/* Retira da fila de acordo com o tipo da senha */
void retira_da_fila(fila f, char tipo) {
  no aux = f->inicio;
  no ant = NULL;
  while (aux != NULL && aux->tipo != tipo) {
    ant = aux;
    aux = aux->prox;
  }
  if (aux != NULL) {
    if (ant == NULL) {
      f->inicio = aux->prox;
    } else {
      ant->prox = aux->prox;
    }
    if (aux->prox == NULL) {
      f->fim = ant;
    }
    free(aux);
  }
}

void liberar_fila(fila f) {
  no aux = f->inicio;
  while (aux != NULL) {
    no aux2 = aux;
    aux = aux->prox;
    free(aux2);
  }
  free(f);
}

/* 3 Pacientes 3 Normais, e retira um da prioridade e outro da normal */
int main() {
  int n, i, qtd_p = 1, qtd_n = 1;
  char tipo;
  fila f = cria_fila();
  printf("Paciente 1 - Fila Normal\n");
  insere_ordenado(f, 'N', qtd_n);
  qtd_n++;
  printf("Paciente 1 - Fila Prioridade\n");
  insere_ordenado(f, 'P', qtd_p);
  qtd_p++;
  printf("Paciente 2 - Fila Prioridade\n");
  insere_ordenado(f, 'P', qtd_p);
  qtd_p++;
  printf("Paciente 2 - Fila Normal\n");
  insere_ordenado(f, 'N', qtd_n);
  qtd_n++;
  printf("Paciente 3 - Fila Prioridade\n");
  insere_ordenado(f, 'P', qtd_p);
  qtd_p++;
  printf("Paciente 3 - Fila Normal\n");
  insere_ordenado(f, 'N', qtd_n);

  printf("Ordem da Fila Final:");
  imprime_fila(f);
  printf("\nRetira um paciente da fila - Prioridade");
  retira_da_fila(f, 'P');
  printf("\n");
  printf("Ordem da Fila Final:");
  imprime_fila(f);
  printf("\nRetira um paciente da fila - Normal");
  retira_da_fila(f, 'N');
  printf("\n");
  printf("Ordem da Fila Final:");
  imprime_fila(f);

  liberar_fila(f);
  return 0;
}
