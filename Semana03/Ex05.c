#include <stdio.h>
#include <stdlib.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

/* Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, data de
nascimento e CPF. Crie uma variável que é um ponteiro para este TAD (no programa
principal). Depois crie uma função que receba este ponteiro e preencha os dados da
estrutura e também uma uma função que receba este ponteiro e imprima os dados da
estrutura. Finalmente, faça a chamada a esta função na função principal. */

typedef struct dados //Struct dos Dados
{
        char nome[50];
        char dataNascimento[10];
        char cpf[11];
} pessoas;

void preencheDados(pessoas *pessoa, int n) //Preechimento de Dados, laço for passando por cada posição do vetor e preenchendo cada dado
{   
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Digite o nome da pessoa %d: ", i+1);
        scanf("%s", pessoa[i].nome);
        printf("Digite a data de nascimento da pessoa %d: ", i+1);
        scanf("%s", pessoa[i].dataNascimento);
        printf("Digite o CPF da pessoa %d: ", i+1);
        scanf("%s", pessoa[i].cpf);
    }
}

void imprimeDados(pessoas *pessoa, int n) //Imprime o vetor, laço for passando por cada posição e imprimindo
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Data de nascimento: %s\n", pessoa[i].dataNascimento);
        printf("CPF: %s\n", pessoa[i].cpf);
    }
}  

int main(int argc, char const *argv[]) //Libera a memória no final
{
    pessoas *pessoa;
    int n;
    char *ptrVet;

    printf("Digite a quantidade de pessoas: ");
    scanf("%i", &n);

    ptrVet = malloc(n*sizeof(char));
    preencheDados(pessoa, n);
    imprimeDados(pessoa, n);

    free(pessoa);
    
    return 0;
}
