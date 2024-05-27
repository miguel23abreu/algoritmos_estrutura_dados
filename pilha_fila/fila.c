#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct
{
    No *prim;
    No *fim;
    int tam;
} Fila;

void criar_fila(Fila *fila)
{
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void inserir_na_fila(Fila *fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (fila->prim == NULL)//se lista vazia
        {
            fila->prim = novo;
            fila->fim = novo;
        }
        else
        {
            fila->fim->proximo = novo;//o antigo ultimo elemento da fila aponta para o novo elemento.
            fila->fim = novo;//O novo elemento vira  o fim da fila
        }
        fila->tam++;
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No *remover_da_fila(Fila *fila)//retorna ponteiro void
{
    No *remover = NULL;

    if (fila->prim)//se houver elemento
    {
        remover = fila->prim;//auxiliar
        fila->prim = remover->proximo;//primeira posicao recebe o segundo elemento.
        fila->tam--;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

void imprimir(Fila *fila)
{
    No *aux = fila->prim;
    printf("\t------- FILA --------\n\t");
    while (aux)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;//recebe o enderco do no seguinte
    }
    printf("\n\t------- FIM FILA --------\n");
}

int main()
{
    No *r;
    Fila fila;
    int opcao, valor;

    criar_fila(&fila);//inicia os elementos com NULL

    do
    {
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
            break;
        case 2:
            r = remover_da_fila(&fila);//retorna o endereco do removido
            if (r)
            {
                printf("Removido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(&fila);
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
