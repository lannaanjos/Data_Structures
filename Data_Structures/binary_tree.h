#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;              // valor do nó
    int nivel;              // nível do nó
    struct No* esquerda;    // próximo nó se for menor
    struct No* direita;     // próximo nó se for maior
}No;

// Criação do nó
No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No)); // cria do tamanho de um nó

    if (novoNo == NULL){
        // stderr = standard error, que é seprado do stdout (saída normal do programa)
        // serve para manter mensagens de erro separadas da saída normal
        fprintf(stderr, "Erro na alocação\n");
        // encerra o programa imediatamente com código de saída 1 (código de erro)
        exit(1);
    }

    // atribuição dos campos
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
}

// Inserção de nó
void inserirNo(No* raiz, int valor){
    // se a raiz estiver vazia será criado o primeiro nó
    if(raiz == NULL){
        raiz = criarNo(valor);
    }

    if (valor < raiz->valor){
        raiz->esquerda = inserirNo(raiz->esquerda, valor);  // insere à esquerda se o valor for menor
    } else {
        raiz->direita = inserirNo(raiz->direita, valor);    // insere à direita se o valor for maior
    }

    return raiz;
}

void editarNo(No* raiz, int novoValor){
    if (raiz->valor == novoValor){
        printf("Nó já possui valor '%d'", novoValor);
        return;
    }
}

void deletarNo(){

}

void buscarNo(){

}

void liberarArvore(){

}

void checarBalanceamento(){

}
