/*----------------------------
          Cabeçalho
  Nome: Maria Clara Almeida Galvão
  Turma: NB
  RA: 156592
 ---------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Registro para data e informações do aluno

struct data{
  int dia;
  int mes;
  int ano;
};

struct aluno{
  char nome[30];
  struct data dataNasc;
  int ra;
  float notas[3];
  int freq;
};

void imprimeMenu();
void menuInsere(struct aluno[],int);
void listaAlunos(struct aluno[],int);
void verificaQtd_Alunos(int n, int op);
void buscarAluno(struct aluno turma[], int n);
void removeAluno(struct aluno turma[], int n);

int main(){
  struct aluno turmaAED[50];
  int n = 0, op = 0, aux = 1;

  //Loop para o menu
  while(op != 5){
    imprimeMenu();
    printf("\nOpcao: ");
    scanf("%i",&op);
    switch(op){
      case 1:
      //Verifica se a turma está cheia
        verificaQtd_Alunos(n,op);
        aux = insereAluno(turmaAED,n);
        //Verifica se o aluno inserido, utilizou um lugar de um aluno removido
        if (aux == 0){
          n--;
        }
        n++;
        break;
      case 2:
      //Verifica se a turma está vazia 
        verificaQtd_Alunos(n, op);
        removeAluno(turmaAED,n);
        break;
      case 3:
      //Lista os alunos
        listaAlunos(turmaAED,n);
        break;
      case 4:
      //Busca por um aluno pelo RA
        buscarAluno(turmaAED,n);
        break;
      case 5:
        printf("\nObrigado.");
        break;
      default:
        printf("\nOpção Inválida.");
        break;
    }
  }
  return 0;
}

void imprimeMenu(){
  printf("\n1 - Inserir Aluno.");
  printf("\n2 - Remover Aluno.");
  printf("\n3 - Listar Alunos.");
  printf("\n4 - Buscar Aluno.");
  printf("\n5 - Sair.");
}

void verificaQtd_Alunos(int n, int op){
  //Verifica se a turma está cheia
  if(n == 50){
    printf("\nTurma Cheia.");
    exit(0);
  }
  //Verifica se a turma está vazia
  if(n == 0 && op != 1){
    printf("\nNenhum aluno cadastrado.");
    exit(0);
  }
}

int insereAluno(struct aluno turma[], int n){
  int i, aux = 0;
  
  //Verifica se o aluno a ser inserido, será o primeiro...Caso contrário, verifica se há algum espaço de um aluno removido anteriormente para inserir o novo aluno
  if (n != 0){
  for(i = 0; i < n; i++){
    if (turma[i].ra == 0){
      menuInsere(turma,i);
      return (aux);
      }
    }
  }
  //Se não houver espaço para um aluno removido, o novo aluno será inserido no final da turma
  menuInsere(turma, n);
  return (1);
};

void menuInsere(struct aluno turma[],int n){
  int i;

  getchar();
  printf("Nome: ");
  fgets(turma[n].nome,sizeof(turma[n].nome),stdin);
  turma[n].nome[strlen(turma[n].nome)-1] = '\0';
  printf("Data de Nascimento\n");
  printf("Dia: ");
  scanf("%i",&turma[n].dataNasc.dia);
  printf("Mes: ");
  scanf("%i",&turma[n].dataNasc.mes);
  printf("Ano: ");
  scanf("%i",&turma[n].dataNasc.ano);
  printf("RA: ");
  scanf("%i",&turma[n].ra);
  for(i=0;i<n;i++){
    if(turma[n].ra == turma[i].ra){
      printf("\nAluno ja cadastrado.\n");
      exit(0);
    }
  }
  for(i=0;i<3;i++){
    printf("Nota %i: ",i+1);
    scanf("%f",&turma[n].notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&turma[n].freq);
}

void listaAlunos(struct aluno turma[],int n){
  //Imprime todos os alunos
  int i,j;

  for(i=0;i<n;i++){
    if (turma[i].ra == 0 || turma[i].dataNasc.dia > 31 || turma[i].dataNasc.dia < 0){
      continue;
    }
    printf("\n\nNome: %s\n",turma[i].nome);
    printf("Data de Nascimento: %i/%i/%i\n",turma[i].dataNasc.dia,turma[i].dataNasc.mes,turma[i].dataNasc.ano);
    printf("RA: %i\n",turma[i].ra);
    for(j=0;j<3;j++)
      printf("Nota %i: %.2f\n",j+1,turma[i].notas[j]);
    printf("Frequencia: %i\n",turma[i].freq);
  }
}

void buscarAluno(struct aluno turma[], int n){

  //Busca por um aluno pelo RA, caso o RA seja encontrado, o aluno é listado, se não for encontrado, é exibida uma mensagem de erro. Além disso, permite que o usuário faça várias buscas até que ele deseje sair.
    int aluno_ra, i, j, aux = 1, aux2 = 0;
    while (aux == 1)
    {
    printf("Digite o RA do aluno: \n");
    scanf("%i", &aluno_ra);
    for(i = 0; i < n; i++){
        if(turma[i].ra == aluno_ra){
            aux2 = 1;
            printf("\nNome: %s\n",turma[i].nome);
            printf("Data de Nascimento: %i/%i/%i\n",turma[i].dataNasc.dia,turma[i].dataNasc.mes,turma[i].dataNasc.ano);
            printf("RA: %i\n",turma[i].ra);
            for(j=0;j<3;j++)
                printf("Nota %i: %.2f\n",j+1,turma[i].notas[j]);
            printf("Frequencia: %i\n",turma[i].freq);
            break;
        }    
    }
      if (aux2 == 0){
        printf("Aluno não encontrado.\n");
      }
    printf("\nDeseja buscar outro aluno?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%i", &aux);
    }
};

void removeAluno(struct aluno turma[], int n){
    
    //Remove um aluno pelo RA, caso o RA seja encontrado, o aluno é removido, se não for encontrado, é exibida uma mensagem de erro
    //Quando o RA é encontrado e o aluno é removido, as informações são substituídas, para que o espaço seja ocupado por um novo aluno posteriormente
    //Quando o RA é encontrado, o elemento do vetor é movido para o final do vetor para que as informações sejam substituídas.
    int aluno_ra, i, aux = 0;

    printf("Digite o RA do aluno: \n");
    scanf("%i", &aluno_ra);

    for(i = 0; i < n; i++){
        if(turma[i].ra == aluno_ra){
            aux = 1;
        }
    }

    if (aux != 1){
        printf("Aluno não encontrado\n");
    } else {
    for(i = 0; i < n; i++){
        if(turma[i].ra == aluno_ra){
            for(int j = i; j < n; j++){
                turma[j] = turma[j+1];
            }
            n--;
            printf("Aluno removido com sucesso\n");
            break;
            }
        }
    }
};
