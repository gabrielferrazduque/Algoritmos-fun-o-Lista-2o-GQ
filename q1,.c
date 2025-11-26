#include<stdio.h> 
#include<stdlib.h> 
 
nt** trocaLinhas(int** mat, int linhas, int colunas, int p1, int p2) {
    int** nova_mat;
    int* aux;
    // alocar nova_mat dinamicamente
    nova_mat = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        nova_mat[i] = (int*)malloc(colunas * sizeof(int));
    }

    // copiar os valores de mat para nova_mat
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            nova_mat[i][j] = mat[i][j];
        }
    }

    // trocar as linhas p1 e p2 em nova_mat
    aux = nova_mat[p1];
    nova_mat[p1] = nova_mat[p2];
    nova_mat[p2] = aux;

    return nova_mat;
}

int main() {
    int valores[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int* mat[3];
    for (int i = 0; i < 3; i++) {
        mat[i] = valores[i];
    }
    int linhas = 3;
    int colunas = 4;
    int p1 = 0; // linha 1
    int p2 = 2; // linha 3
    int** nova_mat;
    nova_mat = trocaLinhas((int**)mat, linhas, colunas, p1, p2);
    printf("Matriz com linhas trocadas:\n");
    for (int i = 0; i < linhas; i++) {  
        for (int j = 0; j < colunas; j++) {
            printf("%d ", nova_mat[i][j]);
        }
        printf("\n");
    }
} 

// Output esperado:
// Matriz com linhas trocadas:
// 9 10 11 12 
// 5 6 7 8 
// 1 2 3 4 


return 0;
}int** trocaLinhas(int** mat, int linhas, int colunas, int p1, int p2) {
    int** nova_mat;
    int* aux;
    // alocar nova_mat dinamicamente
    nova_mat = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        nova_mat[i] = (int*)malloc(colunas * sizeof(int));
    }               
    // copiar os valores de mat para nova_mat
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {             

            nova_mat[i][j] = mat[i][j];
        }
    }       
    // trocar as linhas p1 e p2 em nova_mat
    aux = nova_mat[p1];
    nova_mat[p1] = nova_mat[p2];
    nova_mat[p2] = aux;

    return nova_mat; 
}

return 0;
