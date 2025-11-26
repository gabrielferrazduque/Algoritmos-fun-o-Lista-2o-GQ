#include<stdio.h> 
#include<stdlib.h>  


// a) Defina um tipo estruturado em C que represente um aluno (dica: use typedef para 
// definir que o nome da estrutura criada seja Aluno). Considere que um aluno possui uma 
// matrícula que é uma string de no máximo 7 posições (sem contar com o caractere nulo), 
// um nome com no máximo 80 posições (sem contar com o caractere nulo), uma turma 
// que é implementada como um caractere e 3 notas do tipo real. 

typedef struct {
    char matricula[8]; // 7 characters + null terminator
    char nome[81];     // 80 characters + null terminator
    char turma;        // single character
    float notas[3];    // array of 3 real numbers
} Aluno;

// b
) Em seguida, implemente uma função que imprima o número de matrícula, o nome, a 
// turma e a média de todos os alunos aprovados na disciplina. Assuma que o critério de 
// aprovação é dado pela média das três notas (deve ser maior ou igual a 7,0). A função 
// recebe como parâmetros o número de alunos e um vetor de ponteiros para os dados 
// dos alunos.  Essa função deve obedecer ao protótipo:  
// void imprime_aprovados (int n, Aluno** turmas); 

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


// c) Escreva um programa (função main) que declare um vetor de ponteiros para alunos 
// de 5 posições, peça para o usuário preencher o vetor com os dados dos alunos e depois 
// de preenchido chame a função imprime_aprovados. 

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


