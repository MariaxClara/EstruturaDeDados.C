#include <stdio.h>
#include <stdlib.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

#define MAX 100

struct valor
{
    int valor;
} valor;

struct lista
{
    int qtd_pos;
    struct valor numeros[MAX];
    
} lista;

typedef struct lista *Lista;

Lista cria_lista()
{
    Lista li = (Lista) malloc(sizeof(struct lista));
    if (li != NULL)
        li->qtd_pos = 0;
    return li;
}

Lista libera_lista(Lista li)
{
    free(li);
}

int adiciona_na_posicao(Lista li, struct valor num, int posicao)
{
    int i;
    if(li == NULL)
        return 0;
    if(posicao < 1 || posicao > li->qtd_pos + 1)
        return 0;
    for(i = li->qtd_pos - 1; i >= posicao - 1; i--)
        li->numeros[i+1] = li->numeros[i];
    li->numeros[posicao-1] = num;
    li->qtd_pos++;
    return 1;
}

int retira_da_posicao(Lista li, int posicao)
{
    int i;
    if(li == NULL)
        return 0;
    if(posicao < 1 || posicao > li->qtd_pos)
        return 0;
    for(i = posicao - 1; i < li->qtd_pos - 1; i++)
        li->numeros[i] = li->numeros[i+1];
    li->qtd_pos--;
    return 1;
}

int retira_especifico(Lista li, int valor)
{
    int i;
    if(li == NULL)
        return 0;
    for(i = 0; i < li->qtd_pos; i++)
        if(li->numeros[i].valor == valor)
            break;
    if(i == li->qtd_pos)
        return 0;
    for(i = i; i < li->qtd_pos - 1; i++)
        li->numeros[i] = li->numeros[i+1];
    li->qtd_pos--;
    return 1;
}

void imprime_lista(Lista li)
{
    int i;
    if(li == NULL)
        return;
    for(i = 0; i < li->qtd_pos; i++)
        printf("%d ", li->numeros[i].valor);
}

int main()
{
    Lista li = cria_lista();
    struct valor num;
    int i;
    for(i = 0; i < 10; i++)
    {
        num.valor = i;
        adiciona_na_posicao(li, num, (i+1));
    }
    //Como inicialmente a lista estava populada com 10 elementos,
    printf("Lista inicial: ");
    imprime_lista(li);
    printf("\n");

    //Retira-se o valor da quinta posição
    printf("Retirando o valor da quinta posicao: ");
    retira_da_posicao(li, 5);
    //Imprime-se a lista sem a quinta posição
    imprime_lista(li);
    printf("\n");
    //Retira-se o valor 3 da lista
    printf("Retirando o valor 3 da lista: ");
    retira_especifico(li, 3);

    //Imprime-se a lista sem o valor 3 e sem a quinta posição
    imprime_lista(li);

    //Libera-se a lista
    libera_lista(li);
    return 0;

}
    