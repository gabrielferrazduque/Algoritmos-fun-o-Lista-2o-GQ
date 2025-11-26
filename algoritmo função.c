#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 1) Função que troca linhas p1 e p2 de uma matriz dinâmica de inteiros
int** trocaLinhas(int** mat, int linhas, int colunas, int p1, int p2) {
    if (p1 < 0 || p2 < 0 || p1 >= linhas || p2 >= linhas || p1 == p2) {
        // Troca inválida, retorna matriz igual à original
        int** nova = (int**)malloc(linhas * sizeof(int*));
        for (int i = 0; i < linhas; i++) {
            nova[i] = (int*)malloc(colunas * sizeof(int));
            for (int j = 0; j < colunas; j++) {
                nova[i][j] = mat[i][j];
            }
        }
        return nova;
    }

    // Copia toda a matriz e troca as linhas p1 e p2
    int** nova = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        nova[i] = (int*)malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++) {
            if (i == p1)
                nova[i][j] = mat[p2][j];
            else if (i == p2)
                nova[i][j] = mat[p1][j];
            else
                nova[i][j] = mat[i][j];
        }
    }
    return nova;
}

// 2) Função que retorna matriz de valor absoluto
float** matrizValorAbsoluto(int lin, int col, float** mat) {
    float** absMat = (float**)malloc(lin * sizeof(float*));
    for (int i = 0; i < lin; i++) {
        absMat[i] = (float*)malloc(col * sizeof(float));
        for (int j = 0; j < col; j++) {
            absMat[i][j] = fabsf(mat[i][j]);
        }
    }
    return absMat;
}

// 3a) Estrutura representando um aluno
typedef struct {
    char matricula[8];    // 7 + '\0'
    char nome[81];        // 80 + '\0'
    char turma;
    float notas[3];
} Aluno;

// 3b) Função que imprime dados dos alunos aprovados
void imprime_aprovados(int n, Aluno** turmas) {
    for (int i = 0; i < n; i++) {
        float media = (turmas[i]->notas[0] + turmas[i]->notas[1] + turmas[i]->notas[2]) / 3.0f;
        if (media >= 7.0f) {
            printf("Matrícula: %s\nNome: %s\nTurma: %c\nMédia: %.2f\n\n",
                   turmas[i]->matricula, turmas[i]->nome, turmas[i]->turma, media);
        }
    }
}

// 3c) Função principal
int main() {
    int i, j;
    // Teste das funções 1 e 2:
    printf("Teste da função trocaLinhas e matrizValorAbsoluto\n");
    int linhas = 3, colunas = 3;
    int** matInt = (int**)malloc(linhas * sizeof(int*));
    for (i = 0; i < linhas; i++) {
        matInt[i] = (int*)malloc(colunas * sizeof(int));
        for (j = 0; j < colunas; j++) {
            matInt[i][j] = i * 10 + j;
        }
    }
    int** matTroca = trocaLinhas(matInt, linhas, colunas, 0, 2);
    printf("Matriz trocando linha 0 e 2:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matTroca[i][j]);
        }
        printf("\n");
    }
    // Matriz float para teste valor absoluto
    float** matFloat = (float**)malloc(linhas * sizeof(float*));
    for (i = 0; i < linhas; i++) {
        matFloat[i] = (float*)malloc(colunas * sizeof(float));
        for (j = 0; j < colunas; j++) {
            matFloat[i][j] = (i-j) * ((i%2==0)?-1:1) * 1.1f;
        }
    }
    float** absMat = matrizValorAbsoluto(linhas, colunas, matFloat);
    printf("\nMatriz de valores absolutos:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%.1f ", absMat[i][j]);
        }
        printf("\n");
    }
    // Libera as matrizes de teste
    for (i = 0; i < linhas; i++) {
        free(matInt[i]);
        free(matFloat[i]);
        free(matTroca[i]);
        free(absMat[i]);
    }
    free(matInt);
    free(matFloat);
    free(matTroca);
    free(absMat);

    // 3c) Entrada dos alunos
    printf("\nCadastro de 5 alunos:\n");
    Aluno* alunos[5];
    for (i = 0; i < 5; i++) {
        alunos[i] = (Aluno*)malloc(sizeof(Aluno));
        printf("Aluno %d\n", i+1);
        printf("Matrícula: ");
        scanf("%7s", alunos[i]->matricula);
        getchar(); // Limpa buffer
        printf("Nome: ");
        fgets(alunos[i]->nome, 81, stdin);
        alunos[i]->nome[strcspn(alunos[i]->nome, "\n")] = '\0'; // Remove '\n' do final
        printf("Turma: ");
        scanf(" %c", &alunos[i]->turma);
        printf("Notas (separadas por espaço): ");
        scanf("%f %f %f", &alunos[i]->notas[0], &alunos[i]->notas[1], &alunos[i]->notas[2]);
        getchar(); // Para consumir o '\n'
    }
    printf("\nAlunos aprovados:\n");
    imprime_aprovados(5, alunos);

    // Libera memória de alunos
    for (i = 0; i < 5; i++) {
        free(alunos[i]);
    }

    return 0;
}
