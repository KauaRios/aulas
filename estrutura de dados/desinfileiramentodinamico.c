#include <stdio.h>
#include <stdlib.h>

typedef int Elemento;

//-------------fila encadeada dinamica----------------
typedef struct No {
    Elemento elemento;
    struct No *prox;
} No;

typedef struct {
    No *inicio; // cabeça (frente)
    No *fim;    // cauda (trás)
    size_t tam; // opcional
} Fila;

void fila_init(Fila *f) {
    f->inicio = f->fim = NULL;
    f->tam = 0;
}

int fila_vazia(const Fila *f) {
    return f->inicio == NULL;
}

int enfileirar(Fila *f, Elemento e) {
    No *novo_no = (No*) calloc(1, sizeof *novo_no);
    if (!novo_no)
        return 0;

    novo_no->elemento = e;
    novo_no->prox = NULL;

    if (f->fim != NULL)
        f->fim->prox = novo_no;
    else
        f->inicio = novo_no;

    f->fim = novo_no;
    f->tam++;
    return 1;
}

int desenfileirar(Fila *f, Elemento *out) {
    if (f->inicio != NULL) {
        No *aux = f->inicio;
        f->inicio = f->inicio->prox;
        if (f->inicio == NULL) {
            f->fim = NULL;
        }
        if (out)
            *out = aux->elemento;
        free(aux);
        f->tam--;
        return 1;
    }
    return 0;
}

void fila_libera(Fila *f) {
    Elemento lixo;
    while (desenfileirar(f, &lixo));
}

static int max_abs(const int *A, size_t n) {
    int m = 0;
    for (size_t i = 0; i < n; i++) {
        int v = A[i] < 0 ? -A[i] : A[i];
        if (v > m)
            m = v;
    }
    return m;
}

void radix_lsd_com_filas(int *A, size_t n, int m_base) {
    if (n == 0 || m_base <= 1)
        return;

    Fila *B = (Fila*) malloc(m_base * sizeof *B);
    for (int b = 0; b < m_base; ++b)
        fila_init(&B[b]);

    int m = max_abs(A, n);
    for (int exp = 1; m / exp > 0; exp *= m_base) {
        for (size_t j = 0; j < n; ++j) {
            int dig = (A[j] / exp) % m_base;
            enfileirar(&B[dig], A[j]);
        }
        size_t k = 0;
        for (int b = 0; b < m_base; ++b) {
            Elemento x;
            while (desenfileirar(&B[b], &x)) {
                A[k++] = x;
            }
        }
    }

    for (int b = 0; b < m_base; ++b)
        fila_libera(&B[b]);
    free(B);
}

static void print_v(const int *v, size_t n) {
    for (size_t i = 0; i < n; ++i)
        printf("%d%s", v[i], (i + 1 == n) ? "\n" : ", ");
}

int main(void) {
    Fila F;
    fila_init(&F);
    enfileirar(&F, 10);
    enfileirar(&F, 20);
    enfileirar(&F, 30);
    Elemento e;
    while (desenfileirar(&F, &e))
        printf("Desenfileirou: %d\n", e);

    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    size_t n = sizeof A / sizeof *A;
    printf("Antes : ");
    print_v(A, n);
    radix_lsd_com_filas(A, n, 10);
    printf("Depois: ");
    print_v(A, n);
    return 0;
}
