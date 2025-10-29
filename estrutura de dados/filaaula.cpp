#include <stdio.h>

#define MAX_FILA 5
typedef int Elemento;

typedef struct {
    Elemento v[MAX_FILA];
    int inicio;
    int fim;
} Fila;

void fila_init(Fila *f) {
    f->inicio = -1; // -1 = vazia
    f->fim = -1;
}

// Retorna 1 se sucesso, 0 se fila cheia
int enfileirar(Fila *f, Elemento e) {
    if ((f->inicio == 0 && f->fim == MAX_FILA - 1) || (f->fim + 1 == f->inicio)) {
        return 0; // cheia
    }

    if (f->inicio == -1) {
        f->inicio = 0;
        f->fim = 0;
    } else if (f->fim == MAX_FILA - 1) {
        f->fim = 0; // wrap
    } else {
        f->fim++;
    }

    f->v[f->fim] = e;
    return 1;
}
// mostra o elemento removido
void fila_dump(const Fila *f) {
    if (f->inicio == -1) {
        puts("[]");
        return;
    }

    printf("[");
    int i = f->inicio;
    while (1) {
        printf("%d", f->v[i]);

        if (i == f->fim)
            break;

        printf(" ");
        i = (i + 1) % MAX_FILA; // anda em modo circular
    }
    puts("]");
}





int main() {
    Fila F;
    fila_init(&F);
    for(int x:(int[]){10,20,30,40,50}){
        if(enfileirar(&F,x))
        printf("Enfileirou %d\n",x);
        else
        printf("Fila cheia, nao enfileirou %d\n",x);
        fila_dump(&F);
    }

    if (!enfileirar(&F,60))
        puts("OVERFLOW detected!");


    return 0;
}
