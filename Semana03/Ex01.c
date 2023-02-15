#include <stdio.h> 
#include <stdlib.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

/* Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada. */

void preencherVetor(int *vetor, int n){ //Preenche Vetor Com Valores
    for(int i = 0; i < n; i++){
        printf("Digite o valor do elemento %d: ", (i+1));
        scanf("%d", &vetor[i]);
    }
}

void imprimirVetor(int *vetor, int n){ //Imprime o Vetro
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}

int main(int argc, char const *argv[]) //Libera a memória no final
{
    int n, *ptrVetor;
    printf("Digite um valor N: ");
    scanf("%i", &n);

    ptrVetor = malloc(n * sizeof(int));
    preencherVetor(ptrVetor, n);
    imprimirVetor(ptrVetor, n);
    free(ptrVetor);
    return 0;

}
