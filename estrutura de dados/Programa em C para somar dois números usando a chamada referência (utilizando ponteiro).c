#include <stdio.h>

void somar(int *a, int *b, int *resultado)
{
    *resultado = *a + *b;
}

int main()
{
    int num1, num2, soma;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    somar(&num1, &num2, &soma);

    printf("A soma de %d e %d é: %d\n", num1, num2, soma);

    return 0;
}
/*Explicação:

#include <stdio.h>
Inclui a biblioteca padrão de entrada e saída em C (para usar printf e scanf).

void somar(int *a, int *b, int *resultado)

Função que recebe ponteiros para inteiros.

*resultado = *a + *b; → soma o valor de a com b e armazena no endereço de resultado.

Ou seja, faz a soma fora da função e devolve o resultado por referência (via ponteiro).

int main()

Declara três variáveis: num1, num2 e soma.

Entrada de dados:

scanf("%d", &num1); → lê um número do teclado e guarda em num1.

scanf("%d", &num2); → lê outro número e guarda em num2.

Chamada da função:

somar(&num1, &num2, &soma);

Passa os endereços de num1, num2 e soma.

A função soma os dois primeiros e guarda no terceiro.

Saída:

printf("A soma de %d e %d é: %d\n", num1, num2, soma);

Mostra os valores digitados e a soma.*/