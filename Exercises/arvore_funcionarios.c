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

// BUSCA DE FUNCIONÁRIO
Funcionario* buscaFuncionario(Funcionario* base, int matricula){
    if (base == NULL){ // se chegou no fim da árvore e não achou
        return NULL;
    }
    
    if (matricula == base->matricula){ // se encontrou retorna o ponteiro
        return base;
    }
    
    if (matricula < base->matricula){ // se é menor procura na esquerda
        return buscaFuncionario(base->esquerda, matricula);
    } else { // se é maior procura na direita
        return buscaFuncionario(base->direita, matricula);
    }
}

// edição de funcionário
Funcionario* editarFuncionario(Funcionario* base, int nova_matricula, char* novo_nome,char* novoCargo, float novo_salario){
    Funcionario* alvo = buscaFuncionario(base, nova_matricula); // busca o funcionário pela matrícula
    
    if (alvo == NULL){ // se não encontrou
        printf("Funcionário não encontrado!\n");
        return base;
    }
    
    // se encontrou, atualiza os dados
    strcpy(alvo->nome, novo_nome);
    strcpy(alvo->cargo, novoCargo);
    alvo->salario = novo_salario;
    printf("Funcionário atualizado com sucesso!\n");
    
    return base;
}

// EXIBIÇÃO DE FUNCIONÁRIO
void mostrarHierarquia(Funcionario* base, int nivel){
    if (base != NULL){ // se não estiver vazio vai mostrar a árvore de funcionários
        mostrarHierarquia(base->esquerda, nivel + 1); // antes os da esquerda (menores)
        printf("Matrícula: %d | Nome: %s | Cargo: %s | Salário: R$ %.2f | Nível: %d\n", base->matricula, base->nome, base->cargo, base->salario, nivel);
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

int main (){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // trocar apara "Portuguese_Brazil" no windows

    Funcionario* raiz = NULL;
    int escolha = 1;
    
    // variáveis auxiliares
    int matricula;
    char nome[25];
    char cargo[25];
    float salario;

    while (escolha != 0){
        printf("------------------\n");
        printf("[1] Inserir funcionário\n");
        printf("[2] Editar funcionário\n");
        printf("[3] Buscar funcionário\n");
        printf("[4] Listar funcionários\n");
        printf("[0] Sair\n\n");

        printf("Insira a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: // inserção
                printf("\n--- Inserir novo funcionário ---\n");
                printf("Matrícula: ");
                scanf("%d", &matricula);
                printf("Nome: ");
                scanf(" %[^\n]", nome); // lê string com espaços
                printf("Cargo: ");
                scanf(" %[^\n]", cargo);
                printf("Salário: R$ ");
                scanf("%f", &salario);
                
                raiz = inserirFuncionario(raiz, matricula, nome, cargo, salario);
                printf("Funcionário inserido com sucesso!\n\n");
                break;
                
            case 2: // edição
                printf("\n--- Editar funcionário ---\n");
                printf("Digite a matrícula do funcionário que deseja editar: ");
                scanf("%d", &matricula);
                printf("Novo nome: ");
                scanf(" %[^\n]", nome);
                printf("Novo cargo: ");
                scanf(" %[^\n]", cargo);
                printf("Novo salário: R$ ");
                scanf("%f", &salario);
                
                raiz = editarFuncionario(raiz, matricula, nome, cargo, salario);
                printf("\n");
                break;
                
            case 3: // busca
                printf("\n--- Buscar funcionário ---\n");
                printf("Digite a matrícula: ");
                scanf("%d", &matricula);
                
                Funcionario* encontrado = buscaFuncionario(raiz, matricula);
                if (encontrado == NULL){
                    printf("Funcionário não encontrado!\n\n");
                } else {
                    printf("Funcionário encontrado:\n");
                    printf("Matrícula: %d | Nome: %s | Cargo: %s | Salário: R$ %.2f\n\n", 
                           encontrado->matricula, encontrado->nome, encontrado->cargo, encontrado->salario);
                }
                break;
                
            case 4: // listagem
                printf("\n--- Lista de funcionários ---\n");
                if (raiz == NULL){
                    printf("Não há funcionários cadastrados!\n\n");
                } else {
                    mostrarHierarquia(raiz, 1);
                    printf("\n");
                }
                break;
                
            case 0: // sair
                printf("\nEncerrando o programa...\n");
                liberarHierarquia(raiz); // libera toda a memória alocada
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n\n");
                break;
        }
    }

    return 0;
}
