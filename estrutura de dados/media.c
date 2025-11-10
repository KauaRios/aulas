#include <stdio.h>  // Para funções de entrada e saída, como printf

typedef struct {
    float sm1;
    float sm2;
    float av;
    float avs;
} Alunos;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // Limpa o buffer de entrada
}

float calculamedia(float sm1, float sm2, float av, float avs) {
    float media = (sm1 + sm2 + av + avs) / 4.0;
    return media;
}

int main() {
    Alunos Meualuno;
    float mediaFinal;

    printf("Digite a nota do seu simulado 1: ");
    scanf("%f", &Meualuno.sm1);
    limparBuffer();

    printf("Digite a nota do seu simulado 2: ");
    scanf("%f", &Meualuno.sm2);
    limparBuffer();

    printf("Digite a nota da AV: ");
    scanf("%f", &Meualuno.av);
    limparBuffer();

    printf("Digite a nota da AVS: ");
    scanf("%f", &Meualuno.avs);
    limparBuffer();

    mediaFinal = calculamedia(Meualuno.sm1, Meualuno.sm2, Meualuno.av, Meualuno.avs);

    printf("A média final do aluno é: %.2f\n", mediaFinal);

    return 0;
}
