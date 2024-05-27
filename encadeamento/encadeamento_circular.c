#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct lista{
    int numero;
    struct lista *prox;
    struct lista *ant;
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
    printf("Qual op��o deseja escolher? ");
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
    printf("Informe um n�mero: ");
    scanf("%d", &novo->numero);
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        fim->prox = NULL;
        inicio->ant = NULL;
    }
    else{
        novo->prox = inicio;
        inicio = novo;
        novo->prox->ant = inicio;
        inicio->ant = fim;
        fim->prox = inicio;
    }
    printf("N�mero inserido!\n\n");
}

void excluir(){
    int pos;
    printf("informe a posi��o que deseja excluir: ");
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
        aux->prox->ant = morta->ant;
    }
    else{
        printf("posi��o inexistente na lista!\n\n");
    }
}

void listar(){
    int op;
    printf("deseja listar come�ando pelo �ltimo elemento ou pelo primeiro?\n1 - come�ar pelo primeiro\n2 (ou qualquer numero) - come�ar pelo �ltimo \nqual? ");
    scanf("%d", &op);
    if(op == 1){
        if(inicio == NULL){
        printf("lista vazia!\n\n");
    }
    else{
        printf("listando: ");
        aux = inicio;
        do{
            printf("%d ", aux->numero);
            aux = aux->prox;
        }while (aux != inicio);
        putchar('\n');
    }
    }
    else{
        if(inicio == NULL){
        printf("lista vazia!\n\n");
    }
    else{
        printf("listando: ");
        aux = fim;
        do{
            printf("%d ", aux->numero);
            aux = aux->ant;
        }while(aux != fim);
    }
        putchar('\n');
    }
}

void visualizar(){
    int pos;
    printf("informe uma posi��o: ");
    scanf("%d", &pos);
    if(pos <= (tamanho() - 1)){
        aux = inicio;
        while(pos >0){
            aux = aux->prox;
            pos--;
        }
        printf("N�mero: %d\n\n", aux->numero);
    }
    else{
        printf("posi��o inexistete na lista!\n\n");
    }
}

int tamanho(){
    int i = 0;
    aux = inicio;
    do{
        aux = aux->prox;
        i++;
    }while (aux != inicio);
    return i;
}
