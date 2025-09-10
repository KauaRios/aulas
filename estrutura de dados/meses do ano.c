#include <stdio.h>
#include <string.h>


struct mes {
   const char* nome;
    const char*  abrev;
    int dias;
    int numero;
};

int main() {

    const struct mes meses[12] = {
        {"janeiro", "jan", 31, 1},
        {"fevereiro", "fev", 28, 2},
        {"marco", "mar", 31, 3},
        {"abril", "abr", 30, 4},
        {"maio", "mai", 31, 5},
        {"junho", "jun", 30, 6},
        {"julho", "jul", 31, 7},
        {"agosto", "ags", 31, 8},
        {"setembro", "set", 30, 9},
        {"outubro", "out", 31, 10},
        {"novembro", "nov", 30, 11},
        {"dezembro", "dez", 31, 12}
    };

    char entrada[20];
    int encontrado = 0;

    printf("Digite o nome ou abreviacao do mes: ");
    scanf("%s", entrada);


    for (int i = 0; i < 12; i++) {
        if (strcmp(entrada, meses[i].nome) == 0 || strcmp(entrada, meses[i].abrev) == 0) {
            printf("Mes: %s\n", meses[i].nome);
            printf("Abreviacao: %s\n", meses[i].abrev);
            printf("Dias: %d\n", meses[i].dias);
            printf("Numero: %d\n", meses[i].numero);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Mes nao encontrado.\n");
    }

    return 0 ;
}
