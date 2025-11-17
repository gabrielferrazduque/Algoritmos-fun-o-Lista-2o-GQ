#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 1) trocaLinhas: retorna uma nova matriz (cópia profunda) com as linhas p1 e p2 trocadas.
   Se p1 ou p2 inválidos (fora do intervalo) ou p1 == p2, retorna uma cópia idêntica da matriz. */
int** trocaLinhas(int** mat, int linhas, int colunas, int p1, int p2) {
    if (linhas <= 0 || colunas <= 0 || mat == NULL) return NULL;

    int** nova = (int**)malloc(linhas * sizeof(int*));
    if (!nova) return NULL;

    for (int i = 0; i < linhas; i++) {
        nova[i] = (int*)malloc(colunas * sizeof(int));
        if (!nova[i]) {
            // Em caso de falha, liberar o que já foi alocado e retornar NULL
            for (int k = 0; k < i; k++) free(nova[k]);
            free(nova);
            return NULL;
        }
    }

    // Se índices inválidos ou iguais, apenas copia sem trocar
    if (p1 < 0 || p2 < 0 || p1 >= linhas || p2 >= linhas || p1 == p2) {
        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                nova[i][j] = mat[i][j];
        return nova;
    }

    // Copia e troca as linhas p1 e p2
    for (int i = 0; i < linhas; i++) {
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

/* 2) matrizValorAbsoluto: retorna uma nova matriz de float com os valores absolutos */
float** matrizValorAbsoluto(int lin, int col, float** mat) {
    if (lin <= 0 || col <= 0 || mat == NULL) return NULL;

    float** absMat = (float**)malloc(lin * sizeof(float*));
    if (!absMat) return NULL;

    for (int i = 0; i < lin; i++) {
        absMat[i] = (float*)malloc(col * sizeof(float));
        if (!absMat[i]) {
            for (int k = 0; k < i; k++) free(absMat[k]);
            free(absMat);
            return NULL;
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            absMat[i][j] = fabsf(mat[i][j]);
        }
    }
    return absMat;
}

/* 3a) Definição do tipo Aluno */
typedef struct {
    char matricula[8];  /* 7 caracteres + '\0' */
    char nome[81];      /* 80 caracteres + '\0' */
    char turma;         /* um caractere */
    float notas[3];     /* 3 notas reais */
} Aluno;

/* 3b) imprime_aprovados: imprime matrícula, nome, turma e média dos aprovados (média >= 7.0) */
void imprime_aprovados(int n, Aluno** turmas) {
    if (n <= 0 || turmas == NULL) return;

    int encontrou = 0;
    for (int i = 0; i < n; i++) {
        if (turmas[i] == NULL) continue;
        float media = (turmas[i]->notas[0] + turmas[i]->notas[1] + turmas[i]->notas[2]) / 3.0f;
        if (media >= 7. 


   return ;

return 
