#include <stdio.h>


typedef struct{
    char nome[30];
    int idade;
    int altura;
} Pessoa;






int main(){
    Pessoa pessoas[3];
    printf("Cadastro de 3 pessoas:\n");
    for(int i=0; i<3;i++){
        printf("Digite o nome da pessoa %d: ", i+1);
        scanf("%s", pessoas[i].nome);
        printf("Digite a idade da pessoa %d: ", i+1);
        scanf("%d", &pessoas[i].idade);
        printf("Digite a altura da pessoa %d (em cm): ", i+1);
        scanf("%d", &pessoas[i].altura);
    }    
          


    printf("\nDados cadastrados:\n");
    for(int i=0; i<3;i++){
        printf("Pessoa %d: Nome: %s, Idade: %d, Altura: %d cm\n", i+1, pessoas[i].nome, pessoas[i].idade, pessoas[i].altura);
    }
  







return 0;
}
