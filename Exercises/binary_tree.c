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

Inserção de Funcionário: O sistema permitirá a inserção de um novo funcionário na árvore baseado na matrícula do funcionário (ok)
Atualização de Funcionário: O sistema permitirá a atualização dos dados de um funcionário existente.
Busca de Funcionário: O sistema permitirá buscar um funcionário pela matrícula.
Exibição de Funcionários: O sistema permitirá listar todos os funcionários cadastrados na árvore.(Ok)

*/

// ideia: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Funcionario{
    int matricula; // equivalente a valor
    char nome[25]; // \/\/\/\/\/\/ arrumar p ser dinamico \/\/\/\/\/\/\/\/
    char cargo[25]; // idem
    float salario;
    struct Funcionario* esquerda;
    struct Funcionario* direita;
}Funcionario;

Funcionario* criarFuncionario(int n_matricula, char* nome, char* cargo, float salario){
    Funcionario* novoFuncionario = (Funcionario*)malloc(sizeof(Funcionario)); // cria ponteiro do tamanho da strcut Funcionario
    if (novoFuncionario == NULL){ // verifica se deu certo a criação de um novo funcionário 
        fprintf(stderr,"Erro na alocação\n");
        exit(1); // se tudo ser errado sai 
    }
    // atribução ao campos 
    novoFuncionario->matricula = n_matricula;
    strcpy(novoFuncionario->nome, nome);
    strcpy(novoFuncionario->cargo, cargo);
    novoFuncionario->salario = salario;
    novoFuncionario->direita = NULL;
    novoFuncionario->esquerda = NULL;

    return novoFuncionario;
}

// INSERÇÃO DE FUNCIONÁRIO
Funcionario* inserirFuncionario(Funcionario* base, int n_matricula, char* nome, char* cargo, float salario){
    if(base == NULL){ // se n tiver nada na base vai ser o primeiro funcionário
        return criarFuncionario(n_matricula, nome, cargo, salario);
    }

    if(n_matricula < base->matricula){ // aqui descide se vai para a esquerda ou para a direita
        base->esquerda = inserirFuncionario(base->esquerda, n_matricula, nome, cargo, salario);
    } else {
        base->direita = inserirFuncionario(base->direita, n_matricula, nome, cargo, salario);
    }

    return base;
}

// edição de funcionário
Funcionario* editarFuncionario(Funcionario* base, int nova_matricula, char* novo_nome,char* novoCargo, float novo_salario){
    if (base == NULL){
      printf("Funcionário inexistente");
    } else {

  }

  // a fazer

  }

// EXIBIÇÃO DE FUNCIONÁRIO
void mostrarHierarquia(Funcionario* base, int nivel){
    if (base != NULL){ // se não estiver vazio vai mostrar a árvore de funcionários
      mostrarHierarquia(base->esquerda, nivel + 1); // antes os da esquerda (menores)
      printf("Matrícula: %d | Nome: %s | Cargo: %s | Salário: R$ %.2f | Nível: %d", base->matricula, base->nome, base->cargo, base->salario, nivel);

      mostrarHierarquia(base->direita, nivel + 1); // dps os da direita maiores
    }
}

// liberar memória
void liberarHierarquia(Funcionario* base){
    if (base != NULL){
        liberarHierarquia(base->esquerda);
        liberarHierarquia(base->direita); // percorre todos até a árvore estar vazia 
        free(base);
    }
}

Funcionario* buscaFuncionario(int matricula){
  // a fazer
}

int main (){
  setlocale(LC_ALL, "pt_BR.UTF-8"); // trocar apara "Portuguese_Brazil" no windows

  Funcionario* raiz = NULL;
  int escolha = 1;

  while (escolha != 0){
    printf("------------------");
    printf("[1] Inserir funcionário\n");
    printf("[2] Editar funcionário\n");
    printf("[3] Busca funcionário\n");
    printf("[4] Listar funcionários\n");
    printf("[0] Sair\n\n");

    printf("Insira a opção desejada: ");
    scanf("%d", &escolha);

    switch (escolha) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      default:
      break;
    }
  }

  liberarHierarquia(raiz);
}
