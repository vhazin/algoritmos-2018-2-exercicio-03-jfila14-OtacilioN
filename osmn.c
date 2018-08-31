#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id; /* Valor do no */
    struct Node *prox; /* Ponteiro para o proximo no */
} node;

typedef struct Fila
{
    struct Node *inicial; /* Ponteiro para o primeiro no da lista */
    struct Node *final; /* Ponteiro para o ultimo no da lista */
} fila;

node *aloca(int id);
void inicia(fila *FILA, int idInicial);
void insere(fila *FILA, int id);
void exibe(fila *FILA);
void retira(fila *FILA, int id);

int main(void)
{
    /* aloca o espaco de memoria com o tamanho da fila e casta o retorno para pornteiro de fila */
    fila *FILA = (fila *)malloc(sizeof(fila)); 
    unsigned int n;
    unsigned int id;
    scanf("%d", &n);
    scanf("%d", &id);
    inicia(FILA, id); /* Executa uma interacao fora para iniciar a fila */
    n--; /* Tira a interacao que rodou fora */
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
    free(FILA);
    return 0;
}

/* Aloca o no na memoria e retorna um ponteiro pra ele */
node *aloca(int id)
{
    node *novo = (node *)malloc(sizeof(node));
    novo->id = id;
    return novo;
}

/* Inicia a fila inserindo o primeiro id */
void inicia(fila *FILA, int idInicial)
{
    node *novo = aloca(idInicial);
    novo->prox = NULL;
    FILA->inicial = novo;
    FILA->final = novo;
}

/* Insere o elemento id no final da fila */
void insere(fila *FILA, int id)
{
    node *novo = aloca(id);
    novo->prox = NULL;

    node *tmp = FILA->final;
    tmp->prox = novo;
    FILA->final = novo;
}

/* percorre a fila exibindo-a */
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

/* Retira o elemento da fila */
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
