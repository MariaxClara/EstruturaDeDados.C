/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

/* Implemente uma funcao que calcule a area da superficie e o volume de uma esfera de raio R. 
Essa funcao deve obedecer ao prototipo: 
void calc_esfera(float R, float *area, float *volume)

A area da superfıcie e o volume sao dados, respectivamente, por:  ̃
A = 4 * p * R * R
V = 4/3 * p * R * R * R */

#include <stdio.h> 
#include <stdlib.h>

// Irá calcular a área e o volume da esfera
void calc_esfera(float R, float *area, float *volume){
    *area = 4 * 3.14 * R * R;
    *volume = (4 * 3.14 * R * R * R) / 3;
}

int main()
{
    float raio, area, volume;
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);
    calc_esfera(raio, &area, &volume);
    printf("Area: %.2f\n", area);
    printf("Volume: %.2f", volume);
    return 0;
}
