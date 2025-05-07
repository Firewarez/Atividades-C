#include <stdio.h>

typedef struct {
    int numero;
    float notas[3];
} Aluno;

void lerAlunos(Aluno alunos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o numero do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].numero);

        for (int j = 0; j < 3; j++) {
            printf("Digite a nota %d do aluno %d: ", j + 1, i + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
        printf("\n");
    }
}

int main() {
    Aluno alunos[4];

    lerAlunos(alunos, 4);

    printf("Notas e medias dos alunos:\n");
    for (int i = 0; i < 4; i++) {
        float soma = 0.0;
        printf("Aluno %d:\n", alunos[i].numero);
        for (int j = 0; j < 3; j++) {
            printf("  Nota %d: %.2f\n", j + 1, alunos[i].notas[j]);
            soma += alunos[i].notas[j];
        }
        printf("  Media: %.2f\n\n", soma / 3);
    }

    return 0;
}
