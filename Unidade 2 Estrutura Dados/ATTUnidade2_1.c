#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    int x;
    int y;
} Ponto;

int main() {
    Ponto p1, p2;
    int distancia;

    printf("Digite as coordenadas x e y do ponto 1: ");
    scanf("%d %d", &p1.x, &p1.y);


    printf("Digite as coordenadas x e y do ponto 2: ");
    scanf("%d %d", &p2.x, &p2.y);

    distancia = abs(p1.x - p2.x) + abs(p1.y - p2.y);

    printf("Ponto 1: (%d, %d)\n", p1.x, p1.y);
    printf("Ponto 2: (%d, %d)\n", p2.x, p2.y);
    printf("Distancia Manhattan: %d\n", distancia);

    return 0;
}
