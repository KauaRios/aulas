#include <stdio.h>
#include <string.h>

enum { MAX_NOME = 60, MAX_DATA = 11, MAX_CURSO = 40 };

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char datanasc[MAX_DATA];
    char Curso[MAX_CURSO];
    float cr;
} Aluno;

static void le_linha(char* buf, size_t tam) {
    if (fgets(buf, (int)tam, stdin)) {
        size_t n = strlen(buf);
        if (n && buf[n - 1] == '\n')
            buf[n - 1] = '\0';
    }
}

static void limpa_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard characters
    }
}

int main(void) {
    Aluno a = {0};

    printf("Matrícula: ");
    while (scanf("%d", &a.matricula) != 1) {
        printf("Valor inválido. Tente novamente: ");
        limpa_buffer();
    }
    limpa_buffer(); // clean newline after scanf

    printf("Nome: ");
    le_linha(a.nome, sizeof a.nome);

    printf("Data de nascimento (dd/mm/aaaa): ");
    le_linha(a.datanasc, sizeof a.datanasc);

    printf("Curso: ");
    le_linha(a.Curso, sizeof a.Curso);

    printf("CR: ");
    while (scanf("%f", &a.cr) != 1) {
        printf("Valor inválido. Tente novamente: ");
        limpa_buffer();
    }

    // Output
    puts("\n--- Dados do Aluno ---");
    printf("Nome:        %s\n", a.nome);
    printf("Matrícula:   %d\n", a.matricula);
    printf("Nascimento:  %s\n", a.datanasc);
    printf("Curso:       %s\n", a.Curso);
    printf("CR:          %.1f\n", a.cr);

    return 0;
}
