/*Enunciado:
Desenvolver um sistema em linguagem C para gerenciar um cadastro de funcionários utilizando a estrutura de dados árvore binária. O sistema permitirá realizar operações de inserção, atualização, busca e listagem de funcionários de forma eficiente, utilizando a árvore binária para organizar os funcionários de acordo com sua matrícula (ou outro critério único).



Detalhes do sistema:

A árvore binária de pesquisa será composta por nós que contêm as seguintes informações sobre o funcionário:

Matrícula: Um identificador único para cada funcionário.
Nome: O nome do funcionário.
Cargo: Cargo ou função desempenhada pelo funcionário.
Salário: Salário do funcionário.
Ponteiros:
left: Ponteiro para o filho esquerdo (se existir).
right: Ponteiro para o filho direito (se existir).


Operações do Sistema

Inserção de Funcionário: O sistema permitirá a inserção de um novo funcionário na árvore, baseado na matrícula do funcionário.
Atualização de Funcionário: O sistema permitirá a atualização dos dados de um funcionário existente.
Busca de Funcionário: O sistema permitirá buscar um funcionário pela matrícula.
Exibição de Funcionários: O sistema permitirá listar todos os funcionários cadastrados na árvore.

*/

// ideia: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Funcionario{
    int matricula; // equivalente a valor
    char nome[25];
    char cargo[25];
    float salario;
    struct No* esquerda;
    struct No* direita;
}Funcionario;

Funcionario* criarNo(int n_matricula, char* nome[], char* cargo[], float salario){
    Funcionario* novoFuncionario = (Funcionario*)malloc(sizeof(Funcionario));
    if (novoFuncionario == NULL){
        fprintf(stderr,"Erro na alocação\n");
        exit(1);
    }

    novoFuncionario->matricula = n_matricula;

    novoFuncionario->direita = NULL;
    novoFuncionario->esquerda = NULL;

    return novoFuncionario;
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