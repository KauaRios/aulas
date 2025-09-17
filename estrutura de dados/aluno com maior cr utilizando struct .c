#include <stdio.h>
#include <string.h>

enum { MAX_NOME = 50, MAX_CURSO = 50 };

typedef struct {
    char nome[MAX_NOME];
    char curso[MAX_CURSO];
    float cr;
} Aluno;


void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    Aluno aluno[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(aluno[i].nome, MAX_NOME, stdin);
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';  // Remove '\n'

        printf("Digite o curso do aluno %d: ", i + 1);
        fgets(aluno[i].curso, MAX_CURSO, stdin);
        aluno[i].curso[strcspn(aluno[i].curso, "\n")] = '\0';

        printf("Digite o CR do aluno %d: ", i + 1);
        while (scanf("%f", &aluno[i].cr) != 1) {
            printf("Entrada inválida. Digite o CR novamente: ");
            limpa_buffer();
        }
        limpa_buffer(); 
    }

    
    int indice_maior = 0;
    for (int i = 1; i < 5; i++) {
        if (aluno[i].cr > aluno[indice_maior].cr) {
            indice_maior = i;
        }
    }

    printf("\n--- Dados dos Alunos ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%d) Nome: %s | Curso: %s | CR: %.2f\n",
               i + 1, aluno[i].nome, aluno[i].curso, aluno[i].cr);
    }

    printf("\n>> Aluno com o maior CR:\n");
    printf("Nome: %s\n", aluno[indice_maior].nome);
    printf("Curso: %s\n", aluno[indice_maior].curso);
    printf("CR: %.2f\n", aluno[indice_maior].nome);
