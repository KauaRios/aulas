#include <stdio.h>
#include <string.h>
enum{ MAX_NOME=50,MAX_DISC=20};
typedef struct{
    char nome[MAX_NOME];
    char disciplina[MAX_DISC];
    float nota;
}Aluno;
int main(void){
    Aluno aluno_nota[10];
    printf("Nome :");
    fgets(aluno_nota[0].nome,sizeof aluno_nota[0].nome,stdin);
    aluno_nota[0].nome[strcspn(aluno_nota[0].nome,"\n")]='\0';
    printf("disciplina : ");
    fgets(aluno_nota[0].disciplina,sizeof aluno_nota[0].disciplina,stdin);
    aluno_nota[0].disciplina[strcspn(aluno_nota[0].disciplina,"\n")]='\0';
    printf("nota : ");
    scanf("%f",&aluno_nota[0].nota);
    puts("\n---DADOS---");
    printf("nome: %s\n",aluno_nota[0].nome);
    printf("disciplina: %s\n",aluno_nota[0].disciplina);
    printf("nota: %.1f\n",aluno_nota[0].nota);
    
    return 0;
}
