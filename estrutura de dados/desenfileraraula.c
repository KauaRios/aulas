#include <stdio.h>

#define MAX_FILA 5
typedef int Elemento;

typedef struct {
    Elemento v[MAX_FILA];
    int inicio;
    int fim;
} Fila;

void fila_init(Fila *f) {
    f->inicio = -1;
    f->fim = -1;
}

void fila_preenche_demo(Fila *f) {
    // insere manualmente 3 elementos (40, 50, 60)
    f->v[3] = 40;
    f->v[4] = 50;
    f->v[0] = 60;
    f->inicio = 3;
    f->fim = 0; // fila circular: ordem 3 -> 4 -> 0
}

int desenfileirar(Fila *f, Elemento *out) {
    if (f->inicio == -1) return 0; // fila vazia

    *out = f->v[f->inicio];

    // se removeu o último elemento
    if (f->inicio == f->fim) {
        f->inicio = f->fim = -1;
    } 
    // se chegou ao fim do vetor
    else if (f->inicio == MAX_FILA - 1) {
        f->inicio = 0;
    } 
    else {
        f->inicio++;
    }

    return 1; // sucesso
}

int main() {
    Fila F;
    fila_init(&F);
    fila_preenche_demo(&F);

    Elemento x;
    while (desenfileirar(&F, &x)) {
        printf("Desenfileirou %d\n", x);
    }

    puts("UNDERFLOW detected!");
    return 0;
}
