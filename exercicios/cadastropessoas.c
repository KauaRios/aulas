#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int idade;
} Pessoa;

int main() {
    int n;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);

    Pessoa *pessoas = (Pessoa *) malloc(n * sizeof(Pessoa));
    if (pessoas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        char buffer[100];
        printf("Nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", buffer);

        pessoas[i].nome = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        if (pessoas[i].nome == NULL) {
            printf("Erro ao alocar memória para o nome.\n");
            return 1;
        }
        strcpy(pessoas[i].nome, buffer);

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
    }

    printf("\n--- Pessoas Cadastradas ---\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s | Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    // Liberar memória
    for (int i = 0; i < n; i++) {
        free(pessoas[i].nome);
    }
    free(pessoas);

    return 0;
}
