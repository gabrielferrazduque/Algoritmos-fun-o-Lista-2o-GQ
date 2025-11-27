#include<stdio.h>
#include<stdlib.h>



typedef struct {
    char matricula[8]; // 7 characters + null terminator
    char nome[81];     // 80 characters + null terminator
    char turma;        // single character
    float notas[3];    // array of 3 real numbers
} Aluno;



void imprime_aprovados(int n, Aluno** turmas) {
    printf("Alunos aprovados:\n");
    for (int i = 0; i < n; i++) {
        float media = (turmas[i]->notas[0] + turmas[i]->notas[1] + turmas[i]->notas[2]) / 3.0;
        if (media >= 7.0) {
            printf("Matricula: %s, Nome: %s, Turma: %c, Media: %.2f\n", 
                   turmas[i]->matricula, turmas[i]->nome, turmas[i]->turma, media);
        }
    }
}



int main() {
    Aluno* turmas[5];
    for (int i = 0; i < 5; i++) {
        turmas[i] = (Aluno*)malloc(sizeof(Aluno));
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%7s", turmas[i]->matricula);
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %80[^\n]", turmas[i]->nome);
        printf("Digite a turma do aluno %d: ", i + 1);
        scanf(" %c", &turmas[i]->turma);
        printf("Digite as 3 notas do aluno %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%f", &turmas[i]->notas[j]);
        }
    }

    imprime_aprovados(5, turmas);

    // Liberar memória alocada
    for (int i = 0; i < 5; i++) {
        free(turmas[i]);
    }

    return 0;
}