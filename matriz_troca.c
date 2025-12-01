#include <stdio.h>
#include <stdlib.h>

void trocaLinhas(int **mat, int colunas, int p1, int p2) {
    int i, aux;

    for (i = 0; i < colunas; i++) {
        aux = mat[p1][i];
        mat[p1][i] = mat[p2][i];
        mat[p2][i] = aux;
    }
}

int main() {
    int linhas, colunas;
    int p1, p2;
    int i, j;
    int **mat;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    // Alocação da matriz
    mat = malloc(linhas * sizeof(int *));
    for (i = 0; i < linhas; i++) {
        mat[i] = malloc(colunas * sizeof(int));
    }

    // Leitura da matriz
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Entradas das linhas a serem trocadas
    printf("Digite p1 e p2 (indices das linhas a serem trocadas): ");
    scanf("%d %d", &p1, &p2);

    // Verificação de validade
    if (p1 >= 0 && p1 < linhas && p2 >= 0 && p2 < linhas) {
        trocaLinhas(mat, colunas, p1, p2);

        printf("\nMatriz apos a troca:\n");
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Indices invalidos!\n");
    }

    // Desalocação de memória
    for (i = 0; i < linhas; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
