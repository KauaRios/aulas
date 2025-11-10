#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constantes globais
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100

// definição da struct
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int ano;
    int disponivel; // 1 para sim, 0 para não
};

struct Emprestimo
{
    int indicelivro; // para saber qual livro da biblioteca foi emprestado
    char NomeUsuario[TAM_STRING];
};

// funçao de limpar buffer de entrada---
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// funçao principal
int main()
{
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    // inicializa toda a memoria com zero
    biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));
    // usamos malloc para array dinamico
    emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // laço principal do menu
    if (biblioteca == NULL || emprestimos == NULL)
    {
        printf("erro: Falha ao alocar Memoria.\n");
        return 1; // retorna 1 para indicar erro
    }

    int totallivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do
    {
        // exibe o menu do opçoes
        printf("===============================\n");
        printf("Menu de Opcoes:\n");
        printf("===============================\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Realizar Emprestimos\n");
        printf("4. Listar Emprestimos\n");
        printf("0. Sair\n");
        printf("------------------\n");
        printf("Escolha uma opcao: ");
        // le a opçao do usuario
        scanf("%d", &opcao);
        limparBuffer(); // limpar o \n deixado pelo scanf

        switch (opcao)
        {
        case 1: // cadastro livro
            printf("---Cadastro de novo livro---\n");
            if (totallivros < MAX_LIVROS)
            {
                printf("Digite o Nome do livro: ");
                fgets(biblioteca[totallivros].nome, TAM_STRING, stdin);

                printf("Digite o Autor do livro: ");
                fgets(biblioteca[totallivros].autor, TAM_STRING, stdin);

                printf("Digite a Editora do livro: ");
                fgets(biblioteca[totallivros].editora, TAM_STRING, stdin);

                // Remove o \n do final das strings
                biblioteca[totallivros].nome[strcspn(biblioteca[totallivros].nome, "\n")] = 0;
                biblioteca[totallivros].autor[strcspn(biblioteca[totallivros].autor, "\n")] = 0;
                biblioteca[totallivros].editora[strcspn(biblioteca[totallivros].editora, "\n")] = 0;

                printf("Digite o Ano de publicacao do livro: ");
                scanf("%d", &biblioteca[totallivros].ano);
                limparBuffer(); // Correção do nome da função

                biblioteca[totallivros].disponivel = 1; // Todo livro novo está disponível
                totallivros++;

                printf("Livro cadastrado com sucesso!\n");
            }
            else
            {
                printf("Capacidade máxima de livros atingida!\n");
            }
            printf("Pressione enter para continuar...");
            getchar();
            break;

        case 2: // listar livros
            printf("---Lista de Livros Cadastrados---\n");
            if (totallivros == 0)
            {
                printf("Nenhum livro cadastrado.\n");
            }
            else
            {
                for (int i = 0; i < totallivros; i++)
                {
                    printf("Livro %d:\n", i + 1);
                    printf("  Nome: %s\n", biblioteca[i].nome);
                    printf("  Autor: %s\n", biblioteca[i].autor);
                    printf("  Editora: %s\n", biblioteca[i].editora);
                    printf("  Ano de Publicacao: %d\n", biblioteca[i].ano);
                    printf("  Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Emprestado");
                    printf("------------------\n");
                }
            }
            printf("Pressione enter para continuar...");
            getchar();
            break;

        case 3: // realizar emprestimo
            printf("------Realizar Emprestimo------\n");
            if (totalEmprestimos >= MAX_EMPRESTIMOS)
            {
                printf("Limite de Emprestimo Atingido \n");
            }
            else
            {
                printf("Livros disponiveis para emprestimo:\n");
                int disponiveis = 0;
                for (int i = 0; i < totallivros; i++)
                {
                    if (biblioteca[i].disponivel)
                    {
                        printf("%d - %s\n", i + 1, biblioteca[i].nome);
                        disponiveis++;
                    }
                }

                if (disponiveis == 0)
                {
                    printf("Nenhum livro disponivel no momento.\n");
                }
                else
                {
                    printf("Digite o numero do livro que deseja emprestar: ");
                    int numLivro;
                    scanf("%d", &numLivro);
                    limparBuffer();

                    int indice = numLivro - 1; // converte para o indice do array (0 a n-1)

                    if (indice >= 0 && indice < totallivros && biblioteca[indice].disponivel)
                    {
                        printf("Digite o nome do usuario: ");
                        fgets(emprestimos[totalEmprestimos].NomeUsuario, TAM_STRING, stdin);
                        emprestimos[totalEmprestimos].NomeUsuario[strcspn(emprestimos[totalEmprestimos].NomeUsuario, "\n")] = 0;

                        emprestimos[totalEmprestimos].indicelivro = indice;
                        totalEmprestimos++;
                        biblioteca[indice].disponivel = 0; // marca o livro como nao disponivel

                        printf("Emprestimo realizado com sucesso!\n");
                    }
                    else
                    {
                        printf("Numero de livro invalido ou livro indisponivel.\n");
                    }
                }
            } 
            printf("Pressione enter para continuar...");
            getchar();
            break; // <--- ESTE BREAK ESTAVA FALTANDO

        case 4: // listar emprestimos
            printf("------Lista de Emprestimos------\n");
            if (totalEmprestimos == 0)
            {
                printf("Nenhum emprestimo realizado.\n");
            }
            else
            {
                for (int i = 0; i < totalEmprestimos; i++)
                {
                    int indiceLivro = emprestimos[i].indicelivro;
                    printf("Emprestimo %d:\n", i + 1);
                    printf("  Livro: %s\n", biblioteca[indiceLivro].nome);
                    printf("  Usuario: %s\n", emprestimos[i].NomeUsuario);
                    printf("------------------\n");
                }
            }
            printf("Pressione enter para continuar...");
            getchar();
            break;

        case 0: // sair
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
            printf("Pressione enter para continuar...");
            getchar();
            break;
        }
    } while (opcao != 0); // Corrigido para sair com a opção 0

    free(biblioteca);
    free(emprestimos);

    return 0;
    // fim do programa
}