#include <stdio.h>
#include <stdlib.h>

typedef struct Dados{
    int num;
    struct Dados *prox;
}dados;

dados *topo;
dados *novo;
dados *aux;

void push();
void pop();
void itens();
int tamanho();

int main()
{
    int op;
    while(op != 4){
    printf("---------------------------------------\n");
    printf("1 - empilhar\n2 - desempilhar\n3 - mostrar os dados\n4 - sair\n");
    printf("Qual opção deseja escolher? ");
    scanf("%d", &op);
    switch(op){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            itens();
            break;
        case 4:
            break;
    }
}
return 0;
}

void push(){
    novo = (dados *)malloc(sizeof(dados));
    printf("Informe um número: ");
    scanf("%d", &novo->num);
    if(topo == NULL){
        topo = novo;
        topo->prox = NULL;
    }
    else{
        novo->prox = topo;
        topo = novo;
    }
    printf("item empilhado!\n\n");
}

void pop(){
    if(topo != NULL){
        int op;
        printf("quantos dados deseja desimpilhar da pilha? ");
        scanf("%d", &op);
        while(op != 0){
            dados *desempilhar;
            desempilhar = topo;
            topo = topo->prox;
            op--;
            if(topo == NULL){
                printf("a pilha está vazia!\n\n");
                break;
            }
            free(desempilhar);
        }
    }
    else{
        printf("Pilha vazia!\n\n");
    }
}

void itens(){
    if(topo == NULL){
        printf("pilha vazia!\n\n");
    }
    else{
        aux = topo;
        while(aux != NULL){
            printf("%d ", aux->num);
            aux = aux->prox;
        }
        putchar('\n');
    }
}

int tamanho(){
    int i = 0;
    aux = topo;
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }
    return i;
}







