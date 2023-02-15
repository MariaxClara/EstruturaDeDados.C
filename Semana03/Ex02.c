#include <stdio.h>
#include <stdlib.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

/* Faça uma função que receba um valor n e crie dinamicamente um vetor de n
elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
crie uma função principal que leia um valor n e chame a função criada acima. Depois,
a função principal deve ler os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
memória alocada através da função criada para liberação. */

int *criaVetor(int n){ //Cria Vetor Dinamicamente
    int *ptrVetor;
    ptrVetor = malloc(n * sizeof(int));
    return ptrVetor;
}

void preencherVetor(int *vetor, int n){ //Preenche Vetor Com Valores
    for(int i = 0; i < n; i++){
        printf("Digite o valor do elemento %d: ", (i+1));
        scanf("%d", &vetor[i]);
    }
}

void imprimeVetor(int *vetor, int n){ //Imprime Vetor
    for(int i = 0; i < n; i++){
        printf("Elemento %d: %d\n", (i+1), vetor[i]);
    }
}

void liberarVetor(int *vetor){ //Libera Memória Alocada
    free(vetor);
}

void funcaoPrincipal(){
    int n, *vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    vetor = criaVetor(n);
    preencherVetor(vetor, n);
    imprimeVetor(vetor, n);
    liberarVetor(vetor);
}

int main(int argc, char const *argv[])
{
    funcaoPrincipal();
    return 0;
}
