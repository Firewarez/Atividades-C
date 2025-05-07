#include <stdio.h>

typedef struct {
    int horas;
    int minutos;
    int segundos;
} Horario;

int horarioParaSegundos(Horario h) {
    return h.horas * 3600 + h.minutos * 60 + h.segundos;
}

void imprimirHorario(Horario h) {
    printf("%02d:%02d:%02d", h.horas, h.minutos, h.segundos);
}

int main() {
    Horario h1, h2;
    int seg1, seg2, diferenca;

    printf("Digite o primeiro horario (HH MM SS): ");
    scanf("%d %d %d", &h1.horas, &h1.minutos, &h1.segundos);

    printf("Digite o segundo horario: ");
    scanf("%d %d %d", &h2.horas, &h2.minutos, &h2.segundos);

    seg1 = horarioParaSegundos(h1);
    seg2 = horarioParaSegundos(h2);

    if (seg2 < seg1) {
        Horario temp = h1;
        h1 = h2;
        h2 = temp;

        int tempSeg = seg1;
        seg1 = seg2;
        seg2 = tempSeg;
    }

    diferenca = seg2 - seg1;

    printf("Horario 1: ");
    imprimirHorario(h1);
    printf("\nHorario 2: ");
    imprimirHorario(h2);
    printf("\nDiferenca em segundos: %d\n", diferenca);

    return 0;
}
