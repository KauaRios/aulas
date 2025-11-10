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

// protótipos das funções
void limparBufferEntrada();
void exibirMenu();
void cadastrarlivro(struct Livro *biblioteca, int *totalLivros);
void listarlivros(const struct Livro *biblioteca, int totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void listaremprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

// função principal
int main()
{
    struct Livro *biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));
    struct Emprestimo *emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL)
    {
        printf("Erro: Falha ao alocar memoria.\n");
        return 1; // retorna 1 para indicar erro
    }

    int totallivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:
            cadastrarlivro(biblioteca, &totallivros);
            break;

        case 2: // listar livros
            listarlivros(biblioteca, totallivros);
            break;

        case 3: // realizar emprestimo
            realizarEmprestimo(biblioteca, totallivros, emprestimos, &totalEmprestimos);
            break;

        case 4: // listar emprestimos
            listaremprestimos(biblioteca, emprestimos, totalEmprestimos);
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
    } while (opcao != 0);

    limparBufferEntrada();

    return 0;
}

// função para limpar buffer de entrada
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// função que exibe o menu principal
void exibirMenu()
{
    printf("=====================\n");
    printf(" BIBLIOTECA PARTE 3 MESTRE\n");
    printf("=====================\n");
    printf("1 - Cadastrar Novo Livro\n");
    printf("2 - Listar todos os Livros\n");
    printf("3 - Realizar Emprestimo\n");
    printf("4 - Listar Emprestimos\n");
    printf("0 - Sair\n");
    printf("---------------------\n");
    printf("Escolha uma opcao: ");
}

/**
 * @brief cadastra novo livro
 * @param biblioteca array de livros
 * @param totallivros ponteiro para contador de livros, para que ele seja atualizado
 */
void cadastrarlivro(struct Livro *biblioteca, int *totalLivros)
{
    if (*totalLivros < MAX_LIVROS)
    {
        int indice = *totalLivros; // usa o valor apontado pelo ponteiro

        printf("Digite o nome do livro: ");
        fgets(biblioteca[indice].nome, TAM_STRING, stdin);
        printf("Digite o autor: ");
        fgets(biblioteca[indice].autor, TAM_STRING, stdin);
        printf("Digite a editora: ");
        fgets(biblioteca[indice].editora, TAM_STRING, stdin);

      

        // remove o '\n' do final das strings
        biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
        biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
        biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';


        printf("Digite o ano de publicacao: ");
        scanf("%d", &biblioteca[indice].ano);
        limparBufferEntrada();

     




        biblioteca[indice].disponivel = 1; // livro começa disponível
        (*totalLivros)++; // incrementa contador

        printf("Livro cadastrado com sucesso!\n");
    }
    else
    {
        printf("Limite de livros atingido.\n");
    }
}
void listarlivros(const struct Livro *biblioteca, int totalLivros){
    printf("---Lista de Livros Cadastrados ----\n");
    if(totalLivros==0){
        printf("Nenhum Livro Cadastrado Ainda. \n");
    } else{
        for (int i=0; i<totalLivros;i++){
            printf("------------------------\n");
            printf("LIVRO %d\n",i+1);
            printf("Nome: %s\n",biblioteca[i].nome);
            printf("Autor: %s\n",biblioteca[i].autor);
            printf("Status: %s\n", biblioteca[i].disponivel ? "Disponível" : "Emprestado");
            printf("Ano : %d\n ",biblioteca[i].ano );

        }
        printf("---------------\n");
    }
    printf("Pressione Enter Para Continuar");
    getchar();

}
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos){
            printf("----Realizar Emprestimo: \n");

            if(*totalEmprestimos>=MAX_EMPRESTIMOS){
                printf("Limite de Emprestimos Atingido");
            }else{
                printf("Livros Disponiveis : ");
                int disponiveis=0;
                for (int i=0;i<totalLivros;i++){
                if(biblioteca[i].disponivel){
                    printf("%d-%s\n",i+1,biblioteca[i].nome);
                    disponiveis++;
                }
            }
            if(disponiveis==0){
                printf("Nenhum Livro Disponivel \n");
            } else{
                printf("\nDigite o Numero do Livro Que deseja Emprestar : ");
                int numlivro;
                scanf("%d",&numlivro);
                limparBufferEntrada();

                int indice=numlivro-1;


                if(indice>=0 &&indice <totalLivros && biblioteca[indice].disponivel){
                    printf("Digite o Nome do Usuario : ");
                    fgets(emprestimos[*totalEmprestimos].NomeUsuario,TAM_STRING,stdin);

                    emprestimos[*totalEmprestimos].indicelivro=indice;
                    biblioteca[indice].disponivel=0;//modifica o array original


                    (*totalEmprestimos)++;//modifica o contador original
                    printf("\nEmprestimo Realizado Com Sucesso!\n");
                } else{
                    printf("\nNumero de livro invalido ou livro indisponivel \n");
                }

            }
           

}
}
void listaremprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos){
if(totalEmprestimos==0){
    printf("Nenhum Imprestimo Realizado");
} else {
    for(int i=0; i<totalEmprestimos;i++){
        int indiceLivro=emprestimos[i].indicelivro;
        printf("---------------------------\n");
        printf("EMPRESTIMO %d\n",i+1);
        printf("Livro: %s\n",biblioteca[indiceLivro].nome);
        printf("Usuario %s\n",emprestimos[i].NomeUsuario);
    }
    printf("-----------------\n");
}
printf("\nPressione Enter para Continuar");
getchar();



}

/**Libera memoria alocada para oas arrays dinamicos

 */
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos){



    free(biblioteca);
    free(emprestimos);
    printf("Memoria Liberada com Sucesso \n");
}

