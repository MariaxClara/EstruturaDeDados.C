#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do  
teclado. Em seguida, compare seus enderec ̧os e exiba o conteudo do maior endereco. */

int main(){

    int a, b;

    scanf("%d",&a);
    scanf("%d",&b);

    if (&a > &b){
        printf("O inteiro: %d\n",a);
        printf("Tem o maior endereco de memoria eh :%d",&a);

    } else {
        printf("O inteiro: %d\n",b);
        printf("Tem o maior endereco de memoria eh :%d\n",&b);
    }
    
    return 0;
}