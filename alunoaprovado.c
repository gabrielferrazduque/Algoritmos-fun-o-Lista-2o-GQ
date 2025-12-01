#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATR 8
#define MAX_NOME 81
#define NUM_NOTAS 3

typedef struct {
	char matricula[MAX_MATR];
	char nome[MAX_NOME];
	char turma;
	float nota[NUM_NOTAS];
} Aluno;

void imprime_aprovados(int n, Aluno *turma) {
	printf("\nAlunos aprovados (media >= 7.0):\n");
	for (int i = 0; i < n; ++i) {
		float soma = 0.0f;
		for (int j = 0; j < NUM_NOTAS; ++j) soma += turma[i].nota[j];
		float media = soma / NUM_NOTAS;
		if (media >= 7.0f) {
			printf("Matricula: %s, Nome: %s, Turma: %c, Media: %.2f\n",
				   turma[i].matricula, turma[i].nome, turma[i].turma, media);
		}
	}
}

int main(void) {
	int n;
	printf("Quantos alunos? ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		fprintf(stderr, "Numero invalido de alunos\n");
		return 1;
	}

	Aluno *turma = malloc(sizeof(Aluno) * n);
	if (!turma) {
		perror("malloc");
		return 1;
	}

	for (int i = 0; i < n; ++i) {
		printf("\nAluno %d\n", i + 1);
		printf("Matricula (max %d chars): ", MAX_MATR - 1);
		if (scanf("%7s", turma[i].matricula) != 1) {
			turma[i].matricula[0] = '\0';
		}

		int c = getchar();
		if (c != '\n' && c != EOF) ungetc(c, stdin);

		printf("Nome: ");
		if (!fgets(turma[i].nome, MAX_NOME, stdin)) turma[i].nome[0] = '\0';
		else {
			size_t len = strcspn(turma[i].nome, "\n");
			turma[i].nome[len] = '\0';
		}

		printf("Turma (letra): ");
		scanf(" %c", &turma[i].turma);

		for (int j = 0; j < NUM_NOTAS; ++j) {
			printf("Nota %d: ", j + 1);
			if (scanf("%f", &turma[i].nota[j]) != 1) turma[i].nota[j] = 0.0f;
		}
	}

	imprime_aprovados(n, turma);
	free(turma);
	return 0;
}

