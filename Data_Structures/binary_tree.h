#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;              // valor do nó
    int nivel;              // nível do nó
    struct No* esquerda;    // próximo nó se for menor
    struct No* direita;     // próximo nó se for maior
}

// Criação do nó
No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No)); // cria do tamanho de um nó

    if (novoNo == NULL){
        // stderr = standard error, que é seprado do stdout (saída normal do programa)
        // serve para manter mensagens de erro separadas da saída normal
        fprintf(stderr, "Erro na alocação\n");
        exit(1); // encerra o programa imediatamente com código de saída 1 (código de erro)
    }

    // atribuição dos campos
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
}

void inserirNo(){

}

void editarNo(){

}

void deletarNo(){

}

void buscarNo(){

}

void liberarArvore(){

}

void checarBalanceamento(){

}
