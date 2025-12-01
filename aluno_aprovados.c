#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char matricula[8];
    char nome[80];
    char tipo;          // M ou F, por exemplo
    float notas[2];     // nota1 e nota2
} Aluno;

void imprime_aprovados(int n, Aluno turma[]) {
    int i;
    float media;

    printf("\n--- ALUNOS APROVADOS ---\n");

    for (i = 0; i < n; i++) {
        media = (turma[i].notas[0] + turma[i].notas[1]) / 2.0;

        if (media >= 6.0) {
            printf("Matricula: %s\n", turma[i].matricula);
            printf("Nome: %s\n", turma[i].nome);
            printf("Tipo: %c\n", turma[i].tipo);
            printf("Media: %.2f\n\n", media);
        }
    }
}

int main() {
    int n, i;
    Aluno *turma;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    turma = malloc(n * sizeof(Aluno));

    for (i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);

        printf("Matricula (7 caracteres): ");
        scanf("%7s", turma[i].matricula);

        printf("Nome: ");
        scanf(" %[^\n]", turma[i].nome);

        printf("Tipo (M/F): ");
        scanf(" %c", &turma[i].tipo);

        printf("Nota 1: ");
        scanf("%f", &turma[i].notas[0]);

        printf("Nota 2: ");
        scanf("%f", &turma[i].notas[1]);
    }

    imprime_aprovados(n, turma);

    free(turma);
    return 0;
}
