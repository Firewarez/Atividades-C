#include <stdio.h>

typedef struct {
    int dia;
    char mes[10];
    int ano;
} Data;

typedef struct {
    int pecas;
    float preco;
    Data diavenda;
} Venda;

Venda TotalVendas(Venda C, Venda D) {
    Venda T;
    T.pecas = C.pecas + D.pecas;
    T.preco = C.preco + D.preco;
    T.diavenda.dia = 0;
    T.diavenda.ano = 0;
    T.diavenda.mes[0] = '\0';
    return T;
}

int main() {
    Venda v1, v2, v3, total;

    for (int i = 1; i <= 3; i++) {
        printf("Digite as pecas vendidas da venda %d: ", i);
        if (i == 1) {
            printf("Digite as pecas vendidas da venda %d: ", i);
            scanf("%d", &v1.pecas);
            printf("Digite o preco da venda %d: ", i);
            scanf("%f", &v1.preco);
            printf("Digite o dia da venda %d: ", i);
            scanf("%d", &v1.diavenda.dia);
            printf("Digite o mes da venda %d: ", i);
            scanf("%s", v1.diavenda.mes);
            printf("Digite o ano da venda %d: ", i);
            scanf("%d", &v1.diavenda.ano);
        } else if (i == 2) {
            printf("Digite as pecas vendidas da venda %d: ", i);
            scanf("%d", &v2.pecas);
            printf("Digite o preco da venda %d: ", i);
            scanf("%f", &v2.preco);
            printf("Digite o dia da venda %d: ", i);
            scanf("%d", &v2.diavenda.dia);
            printf("Digite o mes da venda %d: ", i);
            scanf("%s", v2.diavenda.mes);
            printf("Digite o ano da venda %d: ", i);
            scanf("%d", &v2.diavenda.ano);
        } else {
            printf("Digite as pecas vendidas da venda %d: ", i);
            scanf("%d", &v3.pecas);
            printf("Digite o preco da venda %d: ", i);
            scanf("%f", &v3.preco);
            printf("Digite o dia da venda %d: ", i);
            scanf("%d", &v3.diavenda.dia);
            printf("Digite o mes da venda %d: ", i);
            scanf("%s", v3.diavenda.mes);
            printf("Digite o ano da venda %d: ", i);
            scanf("%d", &v3.diavenda.ano);
        }
    }

    Venda temp = TotalVendas(v1, v2);
    total = TotalVendas(temp, v3);

    printf("\nTotal de pecas vendidas: %d\n", total.pecas);
    printf("Total em preco: %.2f\n", total.preco);

    return 0;
}
