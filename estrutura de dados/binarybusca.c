#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1; // valor não encontrado
}



int main(){
    int vetor[] = {10,20,30,40,50,60,70,80,90,100};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    int valorProcurado = 80;
    int resultado = buscaBinaria(vetor, tamanho, valorProcurado);



    printf("Valor %d encontrado no índice: %d\n", valorProcurado, resultado);











    return 0;
}