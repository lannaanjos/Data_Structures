#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* esquerda;
    struct No* direita;
}No;

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL){
        fprintf(stderr,"Erro na alocação\n");
        exit(1);
    }

    novoNo->valor = valor;
    novoNo->direita = NULL;
    novoNo->esquerda = NULL;

    return novoNo;
}

No* inserirNo(No* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }

    if(valor < raiz->valor){
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}


int main (){
    printf("olá");
}