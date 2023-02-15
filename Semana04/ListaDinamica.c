#include <stdio.h>
#include <stdlib.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

struct lista
{
    int valor;
    struct lista *prox;
} lista;
typedef struct lista *Lista;

// Função que cria uma lista vazia
Lista cria_lista()
{
    Lista li = (Lista) malloc(sizeof(struct lista));
    if (li != NULL)
        li->prox = NULL;
    return li;
}

// Função que libera a memória alocada para a lista
Lista libera_lista(Lista li)
{
    if(li != NULL)
    {
        Lista no;
        while((li->prox) != NULL)
        {
            no = li;
            li = li->prox;
            free(no);
        }
        free(li);
    }
}

//Insere de acordo com a posição informada pelo usuário a partir 1
//(Insere no início, quanto no meio, quanto no final)
void adiciona_na_posicao(Lista li, int valor, int posicao)
{
    int i;
    //Verifica se a alocação foi feita
    if(li == NULL){
        printf("Alocação Falhou!");
        return 0;
    }
    Lista no = (Lista) malloc(sizeof(struct lista));
    //Verifica se a alocação foi feita
    if(no == NULL){
        printf("Alocação Falhou!");
        return 0;
    }    
    //Cria um nó auxiliar para percorrer a lista
    //Percorre a lista até a posição informada e atribui o valor ao nó
    no->valor = valor;
    for(i = 0; i < posicao - 1; i++)
        li = li->prox;
    no->prox = li->prox;
    li->prox = no;
}

//Retira de acordo com o valor informado pelo usuário
int retira_especifico(Lista li, int valor)
{
    if(li == NULL)
        return 0;
    Lista no = li->prox;
    Lista ant = li;
    while(no != NULL && no->valor != valor)
    {
        ant = no;
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    ant->prox = no->prox;
    free(no);
    return 1;
}

//Retira da posição informada pelo usuário 
void retira_da_posicao(Lista li, int posicao)
{
    int i;
    if(li == NULL)
        return;
    for(i = 0; i < posicao - 1; i++)
        li = li->prox;
    Lista no = li->prox;
    li->prox = no->prox;
    free(no);
}
        
//Função que imprime a lista
void imprime_lista(Lista li)
{
    if(li == NULL)
        return;
    Lista no = li->prox;
    while(no != NULL)
    {
        printf("%d ", no->valor);
        no = no->prox;
    }
}

int main(int argc, char const *argv[])
{
    int i;
    Lista li = cria_lista();
    for (i = 0; i < 10; i++)
    {
        adiciona_na_posicao(li, i, i+1);
    }
    printf("Lista: ");
    imprime_lista(li);
    printf("\n");
    printf("Retira o valor da quinta posicao: ");
    retira_da_posicao(li, 5);
    imprime_lista(li);
    printf("\n");
    printf("Retira o valor 3: ");
    retira_especifico(li, 3);
    imprime_lista(li);
    libera_lista(li);
    return 0;
}

