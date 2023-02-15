#include <stdlib.h>
#include <stdio.h>

/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

/* Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função
malloc. Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima. */

int alocaMatriz(int m, int n){
    int **matriz;
    matriz = malloc(m * sizeof(int));
    for(int i = 0; i < m; i++){
        matriz[i] = malloc(n * sizeof(int));
    }
    return matriz;
}

void liberarMatriz(int **matriz, int m){
    for(int i = 0; i < m; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(int argc, char const *argv[])
{
    int m, n, *matriz;
    matriz = malloc((m+1) * sizeof(int));
    
    printf("Digite o tamanho da matriz (m x n): ");
    scanf("%d %d", &m, &n);
    matriz = alocaMatriz(m, n);
    liberarMatriz(matriz, m);

    return 0;
}
