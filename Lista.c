#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//   Informações
/*  Aluna: Maria Clara Almeida Galvao
    RA: 156592
    Turma: Noturno
*/

//   Estrutura da Lista
typedef struct Lista
{
    char entrada[20];
    int numero;
    struct Lista *prox;

} Lista;
typedef Lista *ListaPtr;

//   Imprime recursivamente a lista
void imprime_rec_invertido(ListaPtr lista)
{
    if (lista == NULL)
        return;
    imprime_rec_invertido(lista->prox);
    printf("%s\n", lista->entrada);
}

// Libera a memória alocada para a lista
void liberar_rec(ListaPtr lista)
{
    if (lista == NULL)
        return;
    liberar_rec(lista->prox);
    free(lista);
}

// Remove elemento da lista
ListaPtr remove_elemento(ListaPtr lista, char *entrada)
{
    ListaPtr ant = NULL;
    ListaPtr atual = lista;
    while (atual != NULL)
    {
        if (strcmp(atual->entrada, entrada) == 0)
        {
            if (ant == NULL)
            {
                lista = atual->prox;
            }
            else
            {
                ant->prox = atual->prox;
            }
            free(atual);
            return lista;
        }
        ant = atual;
        atual = atual->prox;
    }
    return lista;
}

// Insere os produtos em ordem decrescente
ListaPtr inserir_decrescente(ListaPtr lista, char entrada[], int numero)
{
    ListaPtr novo = (ListaPtr)malloc(sizeof(Lista));
    ListaPtr ant = NULL, atual = lista;
    strcpy(novo->entrada, entrada);
    novo->numero = numero;
    novo->prox = NULL;

    // Se a lista estiver vazia
    if (lista == NULL)
    {
        return novo;
    }

    // Se a lista ja estiver algum elemento
    while (atual != NULL)
    {
        if (atual->numero > numero)
        {
            ant = atual;
            atual = atual->prox;
        }
        else
        {
            if (ant == NULL)
            {
                novo->prox = lista;
                return novo;
            }
            else
            {
                novo->prox = ant->prox;
                ant->prox = novo;
                return lista;
            }
        }
    }
    ant->prox = novo;
    return lista;
}

// Verifica se já existe o produto digitado na lista
int existeIgual(char entrada[], ListaPtr lista)
{
    if (lista == NULL)
        return 0;
    if (strcmp(lista->entrada, entrada) == 0)
        return 1;
    return existeIgual(entrada, lista->prox);
}

int main()
{
    ListaPtr lista = NULL;
    int inteiro;
    char palavra[20];
    char palavra_retirar[20];
    int verificador = 0;
    char palavraComparar[20];

    do
    {
        // Lê o primeiro produto
        scanf("%s", palavra);
        if (atoi(palavra) != -1)
        {
            // Vê se o usuario digitou a senha
            if (strcmp("UNIFESPSJC", palavra) == 0)
            {
                scanf("%s", palavra_retirar);
                // Verifica se o produto existe
                verificador = existeIgual(palavra_retirar, lista);
                // Se existir, remove o produto
                if (verificador == 1)
                {
                    lista = remove_elemento(lista, palavra_retirar);
                }
            }
            else
            {
                // Se não, lê um inteiro
                do
                {
                    scanf("%d", &inteiro);
                } while (inteiro < 0);
                // Verifica se o produto existe na lista
                verificador = existeIgual(palavra, lista);
                // Se não, insere o produto na lista
                if (verificador == 0)
                {
                    lista = inserir_decrescente(lista, palavra, inteiro);
                }
            }
        }
        // Condição de parada
    } while (atoi(palavra) != -1);
    // Imprime recursivamente do menor para o maior
    imprime_rec_invertido(lista);
    // Libera a memória alocada para a lista
    liberar_rec(lista);

    return 0;
}