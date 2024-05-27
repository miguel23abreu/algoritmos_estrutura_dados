#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int num;
    struct no *esquerda;
    struct no *direita;
}No;

typedef struct{
    No *raiz;
    int tam;
}ArvB;

No *novo;

void inserir(ArvB *arv, int valor);
void inserir_esquerda(No *no, int valor);
void inserir_direita(No *no, int valor);
No* remover(No *raiz, int chave);
No* inserir_V_rapido(No *no, int valor);
No* buscaNO(No *raiz, int chave);
void listar(No *raiz);
int tamanho(No *raiz);
int busca(No *raiz, int chave);
int altura(No *raiz);
int alturaNo(No *raiz, int chave);

int main(){
    setlocale(LC_ALL, "");
    int op, valor, op1, op2;
    ArvB arv;
    arv.raiz = NULL;
    do{
        printf("---------------------------------------------------\n");
        printf("0 - sair\n1 - inserir\n2 - listar\n3 - buscar\n4 - remover\n5 - altura de uma sub-arvore\n");
        printf("escolha a sua opção: ");
        scanf("%d", &op);
        switch(op){
        case 1:
            printf("Obs: o valor deve ser diferente de 0!\n");
            printf("digite o valor que deseja inserir: ");
            scanf("%d", &valor);
            if(valor == 0){
                while(valor == 0){
                    printf("\nObs: o valor deve ser diferente de 0!\n");
                    printf("digite o valor que deseja inserir: ");
                    scanf("%d", &valor);
                }
            }
            //inserir(&arv, valor);
            arv.raiz = inserir_V_rapido(arv.raiz, valor);
            break;
        case 2:
            putchar('\n');
            listar(arv.raiz);
            putchar('\n');
            printf("tamanho: %d\naltura: %d\n", tamanho(arv.raiz), altura(arv.raiz));
            break;
        case 3:
            putchar('\n');
            printf("digite o valor que deseja procurar: ");
            scanf("%d", &op1);
            int escolha = busca(arv.raiz, op1);
            if(escolha != 0){
                printf("elemento %d encontrado!", escolha);
            }
            else{
                printf("elemento não encontrado ou não inserido!");
            }
            putchar('\n');
        case 4:
            putchar('\n');
            printf("digite qual valor deseja remover da arvore: ");
            scanf("%d", &op2);
            remover(arv.raiz, op2);
            break;
        case 5:
            putchar('\n');
            int op3;
            printf("digite o valor da sub-arvore da qual deseja saber a altura: ");
            scanf("%d", &op3);
            printf("a altura da sub-arvore %d é: %d\n", op3, alturaNo(arv.raiz, op3));
            break;
        case 0:
            break;
        default:
            printf("\nopção inválida!\n");
        }
    }while(op != 0);

    return 0;
}

void inserir(ArvB *arv, int valor){
    if(arv->raiz == NULL){
        novo = (No *)malloc(sizeof(No));
        novo->num = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }
    else{
        if(valor < arv->raiz->num){
            inserir_esquerda(arv->raiz, valor);
        }
        if(valor > arv->raiz->num){
            inserir_direita(arv->raiz, valor);
        }
    }
}

void inserir_esquerda(No *no, int valor){
    if(no->esquerda == NULL){
        novo = (No *)malloc(sizeof(No));
        novo->num = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }
    else{
        if(valor < no->esquerda->num){
            inserir_esquerda(no->esquerda, valor);
        }
        if(valor > no->esquerda->num){
            inserir_direita(no->esquerda, valor);
        }
    }
}

void inserir_direita(No *no, int valor){
    if(no->direita == NULL){
        novo = (No *)malloc(sizeof(No));
        novo->num = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }
    else{
        if(valor < no->direita->num){
            inserir_esquerda(no->direita, valor);
        }
        if(valor > no->direita->num){
            inserir_direita(no->direita, valor);
        }
    }
}

No* inserir_V_rapido(No *raiz, int valor){
    if(raiz == NULL){
    novo = (No *)malloc(sizeof(No));
    novo->num = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
    }
    else{
        if(valor < raiz->num){
            raiz->esquerda = inserir_V_rapido(raiz->esquerda, valor);
            return raiz;
        }
        if(valor > raiz->num){
            raiz->direita = inserir_V_rapido(raiz->direita, valor);
            return raiz;
        }
    }
}

void listar(No *raiz){
    if(raiz != NULL){
        listar(raiz->esquerda);
        printf("%d ", raiz->num);
        listar(raiz->direita);
    }
}

No* remover(No *raiz, int chave){
    if(raiz == NULL){
        printf("valor não encontrado\n");
        return NULL;
    }
    else{
        if(raiz->num == chave){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                printf("valor removido\n");
                return NULL;
            }
            else{
                No *aux;
                No *aux2;
                No *salvo;
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    if(raiz->direita == NULL){
                        aux = raiz->esquerda;
                        free(raiz);
                        printf("valor removido\n");
                        return aux;
                    }
                    else{
                        aux = raiz->direita;
                        free(raiz);
                        printf("valor removido\n");
                        return aux;
                    }
                }
                else{
                    aux = raiz->esquerda;
                    while(aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->num = aux->num;
                    aux->num = chave;
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
        }
        }
        else{
            if(raiz->num > chave){
                raiz->esquerda = remover(raiz->esquerda, chave);
                return raiz;
            }
            else{
                raiz->direita = remover(raiz->direita, chave);
                return raiz;
            }
        }
}
}

int tamanho(No *raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
}

int altura(No *raiz){
    if(raiz == NULL || raiz->esquerda == NULL && raiz->direita == NULL){
        return 0;
    }
    else{
        int esq = 1 + altura(raiz->esquerda);
        int dir = 1 + altura(raiz->direita);
        if(esq > dir){
            return esq;
        }
        else{
            return dir;
        }
    }
}

No *buscaNO(No *raiz, int chave){
    if(raiz == NULL){
        return NULL;
    }
    else{
        if(raiz->num == chave){
            return raiz;
        }
        else{
            if(chave < raiz->num){
                return buscaNO(raiz->esquerda, chave);
            }
            else{
                return buscaNO(raiz->direita, chave);
            }
        }
    }
}

int alturaNo(No *raiz, int chave){
    No *no = buscaNO(raiz, chave);
    if(no != NULL){
        return altura(no);
    }
    else{
        return -1;
    }
}

int busca(No *raiz, int chave){
    if(raiz == NULL){
        return 0;
    }
    else{
        if(raiz->num == chave){
            return raiz->num;
        }
        else{
            if(chave < raiz->num){
                return busca(raiz->esquerda, chave);
            }
            else{
                return busca(raiz->direita, chave);
            }
        }
    }
}
