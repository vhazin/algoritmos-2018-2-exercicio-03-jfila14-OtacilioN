#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    struct Node *prox;
} node;

typedef struct Fila
{
    struct Node *inicial;
    struct Node *final;
} fila;

node *aloca(int id);
void inicia(fila *FILA, int idInicial);
void insere(fila *FILA, int id);
void exibe(fila *FILA);
void retira(fila *FILA, int id);

int main(void)
{
    fila *FILA = (fila *)malloc(sizeof(fila));
    unsigned int n;
    unsigned int id;
    scanf("%d", &n);
    scanf("%d", &id);
    inicia(FILA, id);
    n--;
    while (n--)
    {
        scanf("%d", &id);
        insere(FILA, id);
    }

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &id);
        retira(FILA, id);
    }
    exibe(FILA);
    printf("\n");
    return 0;
}

node *aloca(int id)
{
    node *novo = (node *)malloc(sizeof(node));
    novo->id = id;
    return novo;
}

void inicia(fila *FILA, int idInicial)
{
    node *novo = aloca(idInicial);
    novo->prox = NULL;
    FILA->inicial = novo;
    FILA->final = novo;
}

void insere(fila *FILA, int id)
{
    node *novo = aloca(id);
    novo->prox = NULL;

    node *tmp = FILA->final;
    tmp->prox = novo;
    FILA->final = novo;
}

void exibe(fila *FILA)
{

    node *tmp;
    tmp = FILA->inicial;
    while (tmp != NULL)
    {
        printf("%d ", tmp->id);
        tmp = tmp->prox;
    }
}

void retira(fila *FILA, int id)
{
    node *tmp = FILA->inicial;
    node *anterior = NULL;
    while (tmp != NULL)
    {
        if (tmp->id == id)
        {
            if (!anterior)
            {
                FILA->inicial = tmp->prox;
                break;
            }
            if (tmp->prox == NULL)
                FILA->final = NULL;

            anterior->prox = tmp->prox;
            break;
        }
        anterior = tmp;
        tmp = tmp->prox;
    }

    free(tmp);
}
