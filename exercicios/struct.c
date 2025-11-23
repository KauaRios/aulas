#include <stdio.h>

// Definindo a struct
typedef struct aluno{
    int matricula;
    char nome[32];  
    char curso[26]; 
} Aluno;

void limpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

}

int main(){
    int n = 3;
    int i;
    Aluno a[n];


    for(i = 0; i < n; i++){
        printf("\n--- Aluno %d ---\n", i+1); // Só pra ficar organizado visualmente

        printf("Digite o nome do aluno: ");
        // Importante: %s lê até o primeiro espaço. Se digitar "Kauã Silva", vai dar erro no próximo scanf.
        scanf("%s", a[i].nome); 
        limpaBuffer();



        printf("Digite a matricula do aluno: ");
        scanf("%d", &a[i].matricula);
        limpaBuffer();


        printf("Digite o curso do aluno: ");
        scanf("%s", a[i].curso);
        limpaBuffer();
    }
    for(i=0;i<n;i++){
        printf("-------------------------------------");
        printf("Matricula: %d\n",a[i].matricula);
        printf("Nome: %s\n",a[i].nome);
        printf("Curso: %s\n",a[i].curso);
        printf("-------------------------------------");
        
    }

    return 0;
}