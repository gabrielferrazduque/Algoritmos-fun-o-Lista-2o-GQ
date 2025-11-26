#include<stdio.h>
#include<stdlib.h> 
float** matrizValorAbsoluto(int lin, int col, float** mat) {
    float** nova_mat;
    // alocar nova_mat dinamicamente
    nova_mat = (float**)malloc(lin * sizeof(float*));
    for (int i = 0; i < lin; i++) {
        nova_mat[i] = (float*)malloc(col * sizeof(float));
    }

    // copiar os valores de mat para nova_mat
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] < 0) {
                nova_mat[i][j] = -mat[i][j];
            } else {
                nova_mat[i][j] = mat[i][j];
            }
        }
    }

    return nova_mat;
}

int main() {
    float valores[3][4] = {
        {1.0, -2.0, 3.0, 4.0},
        {5.0, 6.0, -7.0, 8.0},
        {9.0, -10.0, 11.0, 12.0}
    };
    float* mat[3];
    for (int i = 0; i < 3; i++) {
        mat[i] = valores[i];
    }
    int linhas = 3;
    int colunas = 4;
    float** nova_mat;
    nova_mat = matrizValorAbsoluto(linhas, colunas, (float**)mat);
    printf("Matriz com valores absolutos:\n");
    for (int i = 0; i < linhas; i++) {  
        for (int j = 0; j < colunas; j++) {
            printf("%.1f ", nova_mat[i][j]);
        }
        printf("\n");
    }
}  

return 0;
   
    // liberar a memória alocada para nova_mat
    for (int i = 0; i < lin; i++) {
        free(nova_mat[i]);
    }
    free(nova_mat);     

    return 0;

 