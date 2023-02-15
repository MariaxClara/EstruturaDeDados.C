/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

/* Implemente uma funcao que calcule as raızes de uma equac ̧ao do segundo grau do tipo 
Ax2 + Bx + C = 0.
A variavel A tem que ser diferente de zero.
Essa funcao deve obedecer ao seguinte prototipo: 
int raizes(float A,float B,float C,float * X1,float * X2);
Essa funcao deve ter como valor de retorno o numero de raIzes reais e distintas da
equacao. Se existirem raízes reais, seus valores devem ser armazenados nas variaveis apontadas por X1 e X2. */

#include <stdio.h>
#include <stdlib.h>

// Irá calcular as raízes da equação do segundo grau
int raizes(float A,float B,float C,float * X1,float * X2){
    int delta = (B*B) - (4*A*C);
    if(delta < 0){
        printf("Nao existe raiz real");
        return 0;
    }else if (delta == 0)
        {
        printf("Existe apenas uma raiz real");
        *X1 = (-B + sqrt(delta)) / (2*A);
        return 1;
        }
        else
        {  
        printf("Existem duas raizes reais");
        *X1 = (-B + sqrt(delta)) / (2*A);
        *X2 = (-B - sqrt(delta)) / (2*A);
        return 2;
        }       
}

int main(int argc, char const *argv[])
{
    float A, B, C, X1, X2, aux;

    printf("Digite o valor de A: ");
    scanf("%f", &A);
    printf("Digite o valor de B: ");
    scanf("%f", &B);
    printf("Digite o valor de C: ");
    scanf("%f", &C);

    //Chama a função
    aux = raizes(A, B, C, &X1, &X2);

    //Compara os valores retornados para descobrir se existe existem uma ou duas raízes reais
    if(aux == 2){
        printf("\nX1 = %.2f\n", X1);
        printf("X2 = %.2f", X2);
    }
    if (aux == 1){
        printf("\nX1 = %.2f", X1);
    }
    return 0;
}
