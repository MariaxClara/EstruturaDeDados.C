/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/


/* Escreva uma funcao que dado um numero real passado como parametro, retorne a parte
inteira e a parte fracionaria deste numero. Escreva um programa que chama esta funcao. 
Prototipo: void frac(float num, int* inteiro, float* frac); */

#include <stdio.h>
#include <stdlib.h>

// Irá calcular a parte inteira e a parte fracionária do número
void frac(float num, int* inteiro, float* frac){
    *inteiro = (int)num;
    *frac = num - *inteiro;

}

int main()
{
    float num, fracao;
    int inteiro;
    printf("Digite um numero real: ");
    scanf("%f", &num);
    frac(num, &inteiro, &fracao);
    printf("Parte inteira: %d\n", inteiro);
    printf("Parte fracionaria: %.2f", fracao);

    return 0;
}
