
/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e exiba o maior endereço. */

int main(){

    int a, b;

    printf("Endereco de a:%d\n",&a);
    printf("Endereco de b:%d\n",&b);
    if (&a > &b){
        printf("O maior endereco de memoria eh :%d\n",&a);
    } else {
        printf("O maior endereco de memoria eh :%d\n",&b);
    }
    
    return 0;
}