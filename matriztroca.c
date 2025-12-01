#include <stdio.h>
#include <stdlib.h>

/* Allocate a rows x cols matrix as an array of int* rows */
int **allocate_matrix(int rows, int cols) {
    int **m = malloc(rows * sizeof(int *));
    if (!m) return NULL;
    for (int i = 0; i < rows; ++i) {
        m[i] = malloc(cols * sizeof(int));
        if (!m[i]) {
            for (int j = 0; j < i; ++j) free(m[j]);
            free(m);
            return NULL;
        }
    }
    return m;
}

void free_matrix(int **m, int rows) {
    if (!m) return;
    for (int i = 0; i < rows; ++i) free(m[i]);
    free(m);
}

void read_matrix(int **m, int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            scanf("%d", &m[i][j]);
}

void print_matrix(int **m, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) printf("%d%s", m[i][j], j+1<cols?" ":"\n");
    }
}

/* Swap two rows p1 and p2 (0-based indices) by swapping pointers */
int trocaslinhas(int **m, int rows, int cols, int p1, int p2) {
    if (!m) return -1;
    if (p1 < 0 || p1 >= rows || p2 < 0 || p2 >= rows) return -2;
    if (p1 == p2) return 0; /* nothing to do */
    int *tmp = m[p1];
    m[p1] = m[p2];
    m[p2] = tmp;
    return 0;
}

int main(void) {
    int rows, cols;
    if (printf("Enter rows and cols: ") && fflush(stdout), scanf("%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Invalid input for rows and cols\n");
        return 1;
    }
    if (rows <= 0 || cols <= 0) {
        fprintf(stderr, "rows and cols must be positive\n");
        return 1;
    }

    int **mat = allocate_matrix(rows, cols);
    if (!mat) {
        fprintf(stderr, "Allocation failed\n");
        return 1;
    }

    printf("Enter %d integers (row-major):\n", rows * cols);
    read_matrix(mat, rows, cols);

    printf("Original matrix:\n");
    print_matrix(mat, rows, cols);

    printf("Enter two row indices to swap (1-based): ");
    int r1, r2;
    if (scanf("%d %d", &r1, &r2) != 2) {
        fprintf(stderr, "Invalid input for row indices\n");
        free_matrix(mat, rows);
        return 1;
    }

    /* Convert to 0-based */
    int err = trocaslinhas(mat, rows, cols, r1-1, r2-1);
    if (err == -2) {
        fprintf(stderr, "Row index out of range\n");
        free_matrix(mat, rows);
        return 1;
    }

    printf("Matrix after swapping rows %d and %d:\n", r1, r2);
    print_matrix(mat, rows, cols);

    free_matrix(mat, rows);
    return 0;
}
