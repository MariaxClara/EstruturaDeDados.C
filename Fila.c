#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

// Definindo as estruturas
typedef struct Client
{
    int items;
} TClient;

typedef TClient *PClient;

typedef struct QueueClient
{
    int start;
    int length;
    PClient *clients;
} TQueueClient;

typedef TQueueClient *PQueueClient;

typedef struct Worker
{
    int items;
    int time;
} TWorker;

typedef TWorker *PWorker;

typedef struct QueueWorker
{
    int start;
    int length;
    PWorker *workers;
} TQueueWorker;

typedef TQueueWorker *PQueueWorker;

// Criar a fila de Clientes
PQueueClient createQueueClient(int length)
{
    PQueueClient queue = (PQueueClient)malloc(sizeof(TQueueClient));
    queue->clients = (PClient *)malloc(sizeof(PClient) * length);
    queue->start = 0;
    queue->length = 0;

    return queue;
}

// Adicionar um cliente na fila
void addQueueClient(PQueueClient queue, int items)
{
    PClient client = (PClient)malloc(sizeof(TClient));

    client->items = items;

    queue->clients[queue->length] = client;

    queue->length++;
}

// Remover um cliente da fila
int removeQueueClient(PQueueClient queue)
{
    PClient client;
    int output;

    if (queue->length <= 0)
        return NULL;

    client = queue->clients[queue->start];

    output = client->items;

    free(client);

    queue->start++;
    queue->length--;

    return output;
}

// Criar a fila de Trabalhadores
PQueueWorker createQueueWorker(int length)
{
    PQueueWorker queue = (PQueueWorker)malloc(sizeof(TQueueWorker));
    queue->workers = (PWorker *)malloc(sizeof(PWorker) * length);
    queue->start = 0;
    queue->length = 0;

    return queue;
}

// Adicionar um trabalhador na fila
void addQueueWorker(PQueueWorker queue, int time)
{
    PWorker worker = (PWorker)malloc(sizeof(TWorker));

    worker->time = time;

    worker->items = 0;

    queue->workers[queue->length] = worker;

    queue->length++;
}

// Calcular o tempo de trabalho
int calculateTime(PQueueClient clientQueue, PQueueWorker workerQueue, PWorker worker, int n_Workers)
{
    int free_workers = 0, items = 0, i, result = 0;

    while (TRUE)
    {
        free_workers = 0;
        for (i = 0; i < n_Workers; i++)
        {
            worker = workerQueue->workers[i];
            if (worker->items == 0)
            {
                items = removeQueueClient(clientQueue);

                if (items == NULL)
                {
                    free_workers++;
                    continue;
                }

                worker->items = (worker->time * items) - 1;
            }
            else
                worker->items--;
        }

        if (free_workers == n_Workers)
            break;
        else
            result++;
    }
    printf("%d", result);
}

// Liberar a fila de Clientes
void freePQueueClient(PQueueClient queue)
{
    int i;

    for (i = 0; i < queue->length; i++)
    {
        free(queue->clients[i]);
    }

    free(queue->clients);
    free(queue);
}

// Liberar a fila de Trabalhadores
void freePQueueWorker(PQueueWorker queue)
{
    int i;

    for (i = 0; i < queue->length; i++)
    {
        free(queue->workers[i]);
    }

    free(queue->workers);
    free(queue);
}

int main()
{

    int number_workers, number_clients, i, input, result, free_workers = 0, items = 0;
    PQueueWorker workerQueue;
    PQueueClient clientQueue;
    PWorker worker;

    scanf("%d", &number_workers);

    scanf("%d", &number_clients);

    workerQueue = createQueueWorker(number_workers);
    clientQueue = createQueueClient(number_clients);

    for (i = 0; i < number_workers; i++)
    {
        scanf("%d", &input);
        addQueueWorker(workerQueue, input);
    }

    for (i = 0; i < number_clients; i++)
    {
        scanf("%d", &input);
        addQueueClient(clientQueue, input);
    }

    calculateTime(clientQueue, workerQueue, worker, number_workers);

    freePQueueClient(clientQueue);
    freePQueueWorker(workerQueue);
    free(worker);

    return 0;
}