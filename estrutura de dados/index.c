#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// constantes globais
#define MAX_LIVROS 50
#define TAM_STRING 100
// definição da struct
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int ano;
};

// funçao de limpar buffer de entrada---
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
// funçao principal
int main()
{

    struct Livro biblioteca[MAX_LIVROS];
    int totallivros = 0;
    int opcao;

    // laço principal do menu
    do
    {

        // exibe o menu do opçoes
        printf("===============================\n");
        printf("Menu de Opções:\n");
        printf("===============================\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Sair\n");
        printf("------------------\n");
        printf("Escolha uma opção: ");
        // le a opçao do usuario
        scanf("%d", &opcao);
        limparBuffer(); // limpar o \n deixado pelo scanf
        switch (opcao)
        {
        case 1: // cadastro livro
            printf("---Cadastro de novo livro---\n");
            if (totallivros < MAX_LIVROS)
            {
                printf("digite o Nome do livro: ");
                fgets(biblioteca[totallivros].nome, TAM_STRING, stdin);

                printf("digite o Autor do livro: ");
                fgets(biblioteca[totallivros].autor, TAM_STRING, stdin);

                printf("digite a Editora do livro: ");
                fgets(biblioteca[totallivros].editora, TAM_STRING, stdin);

                biblioteca[totallivros].nome[strcspn(biblioteca[totallivros].nome, "\n")] = 0;
                biblioteca[totallivros].autor[strcspn(biblioteca[totallivros].autor, "\n")] = 0;
                biblioteca[totallivros].editora[strcspn(biblioteca[totallivros].editora, "\n")] = 0;
                printf("digite o Ano de publicação do livro: ");
                scanf("%d", &biblioteca[totallivros].ano);
                limparBuffer(); // limpar o \n deixado pelo scanf

                totallivros++;
                // totallivros = totallivros + 1;
                printf("Livro cadastrado com sucesso!\n");
            }
            else
            {
                printf("Capacidade máxima de livros atingida!\n");
            }
            printf("pressione enter para continuar...");
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
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Ano de Publicação: %d\n", biblioteca[i].ano);
                    printf("------------------\n");
                }
                printf("------------------------------\n");
            }
            // pausa é crucial para que o usuario veja a lista antes
            // do proximo loop limpar a tela
            printf("pressione enter para continuar...");
            getchar();
            break;
        case 3: // sair
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            printf("pressione enter para continuar...");
            getchar();
            break;
        }
    } while (opcao != 3);

    return 0;
}
