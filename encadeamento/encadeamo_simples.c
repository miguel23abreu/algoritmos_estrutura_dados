#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct lista{
    int numero;
    struct lista *prox;
}Lista;

Lista *novo;
Lista *inicio;
Lista *fim;
Lista *aux;

void inserir();
void listar();
int tamanho();
void visualizar();
void excluir();

//---------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    int op;
    while(op != 5){
    printf("---------------------------------------\n");
    printf("1 - inserir\n2 - excluir\n3 - exibir\n4 - listar todos\n5 - Sair\n");
    printf("Qual opção deseja escolher? ");
    scanf("%d", &op);
    switch(op){
        case 1:
            inserir();
            break;
        case 2:
            excluir();
            break;
        case 3:
            visualizar();
            break;
        case 4:
            listar();
            break;
        case 5:
            break;
        }
    }
    return 0;
}
//----------------------------------------------------------------------------------------------------------------

void inserir(){
    novo = (Lista *)malloc(sizeof(Lista));
    printf("Informe um número: ");
    scanf("%d", &novo->numero);
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        fim->prox = NULL;
    }
    else{
        novo->prox = inicio;
        inicio = novo;
    }
    printf("Número inserido!\n\n");
}

void excluir(){
    int pos;
    printf("informe a posição: ");
    scanf("%d", &pos);
    if(pos <= (tamanho() - 1)){
        aux = inicio;
        while(pos > 1){
            aux = aux->prox;
            pos--;
        }
        Lista *morta;
        morta = aux->prox;
        aux->prox = morta->prox;
    }
    else{
        printf("posição inexistente na lista!\n\n");
    }
}

void listar(){
    printf("listando: ");
    if(inicio == NULL){
        printf("lista vazia!\n\n");
    }
    else{
        aux = inicio;
        while(aux != NULL){
            printf("%d ", aux->numero);
            aux = aux->prox;
        }
        putchar('\n');
    }
}

void visualizar(){
    int pos;
    printf("informe uma posição: ");
    scanf("%d", &pos);
    if(pos <= (tamanho() - 1)){
        aux = inicio;
        while(pos >0){
            aux = aux->prox;
            pos--;
        }
        printf("Número: %d\n\n", aux->numero);
    }
    else{
        printf("posição inexistete na lista!\n\n");
    }
}

int tamanho(){
    int i = 0;
    aux = inicio;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}



