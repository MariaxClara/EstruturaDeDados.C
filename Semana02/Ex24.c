/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

 /* Escreva uma funcao que receba um array de inteiros V e os enderecos de duas variaveis 
inteiras, min e max, e armazene nessas variaveis o valor mınimo e maximo do array. 
Escreva tambem uma funcao main que use essa funcao. */

#include <stdio.h>
#include <stdlib.h>

// Irá calcular o valor mínimo e máximo do array
void min_max(int* v, int n, int* min, int* max){
    int i;
    *min = v[0];
    *max = v[0];
    for(i = 0; i < n; i++){
        if(v[i] < *min){
            *min = v[i];
        }
        if(v[i] > *max){
            *max = v[i];
        }
    }
}

int main()
{
    int v, i, min, max;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &v);

    float vet[v];

    printf("Digite a sequencia de numeros, separado por espaco: \n");
    for(int i = 0; i < v; i++){
        scanf("%d", &vet[i]);
    }    
    
    min_max(vet, v, &min, &max);
    printf("O menor valor do vetor e: %d\n", min);
    printf("O maior valor do vetor e: %d", max);

    return 0;
}
