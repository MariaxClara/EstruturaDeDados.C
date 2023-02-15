/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/


#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que declare um inteiro, um real e um char, e ponteiros para in-
teiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de
cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a
modificacao. */

int main(){

    int i, *p;
    char c, *pc;
    float f, *pf;

    i = 10;
    p = &i;
    printf("Valor de i: %d\n", i);

    c = 'a';
    pc = &c;
    printf("Char de C: %c\n", c);

    f = 10.5;
    pf = &f;
    printf("Valor de f: %f\n", f);

    *p = 20;
    printf("Novo Valor de i: %d\n", i);

    *pc = 'b';
    printf("Novo Char de C: %c\n", c);

    *pf = 20.5;
    printf("Novo Valor de f: %f", f);

    return 0;
}