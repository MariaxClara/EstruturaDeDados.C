#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//   Informações
/*  Aluna: Maria Clara Almeida Galvao
    RA: 156592
    Turma: Noturno
*/
 
typedef struct No
{
    int info;
    struct No *prox;
} No;
 
typedef struct ListaCircular
{
    struct No *inicio;
} ListaCircular;
 
typedef struct No *circularptr;
typedef struct ListaCircular *circular;
 
circularptr cabeca_lista(int info, circularptr inicio)
{
 
    circularptr me = (circularptr)malloc(sizeof(No));
    if (me == NULL)
    {
        printf("Alocação de memória falhou\n");
        return NULL;
    }
    me->info = info;
    me->prox = inicio;
    return me;
}
 
circular inicializar_lista()
{
    circular me = (circular)malloc(sizeof(ListaCircular));
    if (me == NULL)
    {
        printf("Erro de alocação de memória\n");
    }
    me->inicio = NULL;
    return me;
}
 
void inserir_ord(circular l, int x)
{
    // Criar um nó e alocar memória
    circularptr no = cabeca_lista(x, l->inicio);
    if ((l->inicio == NULL))
    {
        // Colocar o primeiro nó na lista
        l->inicio = no;
        no->prox = l->inicio;
    }
    else
    {
        circularptr aux = l->inicio;
        circularptr aux2 = NULL;
        if ((aux->info >= x))
        {
            while (aux->prox != l->inicio)
            {
                // Ir para o próximo nó da lista
                aux = aux->prox;
            }
            // Conectar o nó novo ao final da lista
            aux->prox = no;
            no->prox = l->inicio;
            l->inicio = no;
        }
        else
        {
            aux2 = aux;
            // Colocar na posição correta
            while (aux->prox != l->inicio && x > aux->info)
            {
                aux2 = aux;
                aux = aux->prox;
            }
            if ((aux->info >= x))
            {
                // Adiciona um elemento entre dois nós
                no->prox = aux2->prox;
                aux2->prox = no;
            }
            else
            {
                // Adiciona no final da lista
                no->prox = aux->prox;
                aux->prox = no;
            }
        }
    }
}
 
int converter_p_int(char s)
{
    //FAZ A CONVERSÃO DA ENTRADA PARA NÚMEROS INTEIROS, AINDA AUXILIA NA VERIFICAÇÃO DE DIGITOS INCOMPATÍVEIS
    int n = 0;
    n = n * 10 + s - '0';
    if (n == 17) // Letra A
    {
        n = 1;
    }
    else if (n == 1)
    {
        n = 0;
    }
    else if (n == 33) // Letra Q
    {
        n = 11;
    }
    else if (n == 26) // Letra J
    {
        n = 10;
    }
    else if (n == 27)
    {
        n = 12;
    }
    else if (n == 2){
        n = 2;
    }
    else if (n == 3){
        n = 3;
    }
    else if (n == 4){
        n = 4;
    }
    else if (n == 5){
        n = 5;
    }
    else if (n == 6){
        n = 6;
    }
    else if (n == 7){
        n = 7;
    }
    else if (n == 8){
        n = 8;
    }
    else if (n == 9){
        n = 9;
    }
    else
    {
        n = 0;
    }
    return n;
}
 
int converter_p_char(int n)
{
    //CONVERTE TODOS OS NÚMEROS INTEIROS PARA LETRAS PARA MOSTRAR A SAIDA
    int s = 0;
    if (n == 1)
    {
        s = 'A';
    }
    else if (n == 11)
    {
        s = 'Q';
    }
    else if (n == 10)
    {
        s = 'J';
    }
    else if (n == 12)
    {
        s = 'K';
    }
    else
    {
        s = n + '0';
    }
    return s;
}
 
void imprimir(circular l)
{
    //Imprime a lista circular
    
    
    
        circularptr aux = l->inicio;
        //verifica se já passou pelo fim da lista
        while (aux != NULL)
        {
            // mostra o nó 
            if (aux->info == 1 || aux->info == 10 || aux->info == 12 || aux->info == 11)
            {
                printf("%c", converter_p_char(aux->info));
            }
            else
            {
                printf("%d", aux->info);
            }
            // Vai para o próximo
            aux = aux->prox;
            if ((aux == l->inicio))
            {
                // Se chegou no fim da lista, termina
                return;
            }
        }
    
}
 
int contar_iguais(circular l)
{
    //Conta quantos trios podem ser feitos com os números repetidos
    circularptr temp = l->inicio;
    int cont = 0, parar;
    parar = contar_cartas(l);
    if (parar == 1){
        return cont;
    }
    else{
    do
    {
        if (temp->info == temp->prox->info)
        {
            if (temp->prox->info == temp->prox->prox->info)
            {
                cont++;
            }
        }
        temp = temp->prox;
        parar--;
    } while (parar != 0);
    return cont;
    }
}
 
void retira_iguais(circular l)
{
    //Pula todos as cartas iguais da lista para faciliar contar os trios formados por números sequenciais
    circularptr temp = l->inicio;
    int parar = 0;
    do
    {
        if (temp->info == temp->prox->info)
        {
            temp->prox = temp->prox->prox;
        }
        else
        {
            temp = temp->prox;
        }
        parar++;
    } while (parar != 9);
}
 
int contar_cartas(circular l)
{
    //Conta o total de cartas, depois de remover as repetidas
    circularptr temp = l->inicio;
    int cont = 0;
 
    do
    {
        cont++;
        temp = temp->prox;
    } while (temp != l->inicio);
    return cont;
}
 
int contar_sequencia(circular l)
{
    //Conta quantos trios podem ser feitos com os números sequenciais
    circularptr temp;
    int cont = 0, parar = 0, aux = 0;
 
    parar = contar_cartas(l);
    temp = l->inicio;
    do
    {
        if (temp->info == 11 && temp->prox->info == 12 && temp->prox->prox->info == 1)
        {
            cont++;
        }
        if (temp->info == 12 && temp->prox->info == 1 && temp->prox->prox->info == 2)
        {
            cont++;
        }
 
        if (temp->prox->info == ((temp->info) + 1))
        {
            if (temp->prox->prox->info == ((temp->info) + 2))
            {
                cont++;
            }
        }
        temp = temp->prox;
        parar--;
    } while (parar != 0);
    return cont;
}
 
void liberar(circular l)
{
    //libera a lista circular
    circularptr temp = l->inicio;
    circularptr hold = NULL;
    do
    {
        hold = temp;
        temp = temp->prox;
        free(hold);
    } while (temp != l->inicio);
    free(l);
}
 
int main()
{
    circular list = inicializar_lista();
    int verificador = 0, carta_int, quant, quant2;
    char carta;
 
    do
    {
        //Pega a carta e converte para número. Se for um dígito inválido, o verificador é acionado e ao sair do loop, o programa é devolve um print vazio
        carta = getchar();
        carta_int = converter_p_int(carta);
        if (carta_int > 13 || carta_int < 0)
        {
            verificador = 10;
        }
        else
        {
            if(carta_int != 0){
                //Se for um dígito válido, é adicionado à lista
                inserir_ord(list, carta_int);
                verificador++;
            }
            else{
                verificador++;
            }
            
        }
    } while (verificador < 9);
    
    //Se a lista estiver vazia, o programa é encerrado
    if ((list->inicio == NULL))
    {
        printf("\n0");
        return 0;
    }
 
    //Encerra se o verificador é acionado por um dígito inválido
    if (verificador == 10)
    {
        printf("\n0");
        return 0;
    }
    //Imprime a lista
    imprimir(list);
    //Chama a função para contar os iguais
    quant = contar_iguais(list);
    //Retira os iguais da lista
    retira_iguais(list);
    //Chama a função para contar os trios formados por números sequenciais e soma a quantidade
    quant2 = contar_sequencia(list);
    printf("\n%d", quant + quant2);
    //Libera a lista
    liberar(list);
    return 0;
}