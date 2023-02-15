/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

/* Implemente uma funcao que receba como parametro um array de numeros reais de 
tamanho N e retorne quantos numeros negativos ha nesse array. Essa funcao deve 
obedecer ao prototipo:  ́
int negativos(float *vet, int N); */

#include <stdio.h>
#include <stdlib.h>

// Irá calcular a quantidade de números negativos no array
int negativos(float *vet, int N){
    int i, cont = 0;
    for(i = 0; i < N; i++){
        if(vet[i] < 0){
            cont++;
        }
    }
    return cont;
}

int main()
{
    int n, cont, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    float vet[n];

    printf("Digite a sequencia de numeros, separado por espaco: \n");
    for(int i = 0; i < n; i++){
        scanf("%f", &vet[i]);
    }    
    cont = negativos(vet, n);
    printf("A quantidade de numeros negativos e: %d", cont);

    return 0;
}
