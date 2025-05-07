#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nomeCompleto[81];   
    char sexo;              
    Data dataNascimento;
    float altura;           
    float peso;             
    int idadeAtual;
    float imc;
    float freqCardMax;
} PerfilSaude;

PerfilSaude* criarPerfil(char* nome, char sexo, Data dataNasc, float altura, float peso) {
    PerfilSaude* p = (PerfilSaude*) malloc(sizeof(PerfilSaude));
    if (p == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    strncpy(p->nomeCompleto, nome, 80);
    p->nomeCompleto[80] = '\0'; 
    p->sexo = sexo;
    p->dataNascimento = dataNasc;
    p->altura = altura;
    p->peso = peso;
    p->idadeAtual = 0;
    p->imc = 0.0f;
    p->freqCardMax = 0.0f;
    return p;
}

PerfilSaude* calcularDados(PerfilSaude* p) {
    time_t t = time(NULL);
    struct tm *dataAtual = localtime(&t);

    int idade = dataAtual->tm_year + 1900 - p->dataNascimento.ano;

    if (dataAtual->tm_mon + 1 < p->dataNascimento.mes ||
        (dataAtual->tm_mon + 1 == p->dataNascimento.mes && dataAtual->tm_mday < p->dataNascimento.dia)) {
        idade--;
    }
    p->idadeAtual = idade;

    p->imc = p->peso / (p->altura * p->altura);

    p->freqCardMax = 220.0f - (float)idade;

    return p;
}

void mostrarPerfil(PerfilSaude* p) {
    printf("Nome Completo: %s\n", p->nomeCompleto);
    printf("Sexo: %c\n", p->sexo);
    printf("Data de Nascimento: %02d/%02d/%d\n", p->dataNascimento.dia, p->dataNascimento.mes, p->dataNascimento.ano);
    printf("Altura: %.2f m\n", p->altura);
    printf("Peso: %.2f kg\n", p->peso);
    printf("Idade Atual: %d anos\n", p->idadeAtual);
    printf("Indice de Massa Corporal (IMC): %.2f\n", p->imc);
    printf("Frequencia Cardiaca Maxima: %.2f bpm\n", p->freqCardMax);
}

int main() {
    char nome[81];
    char sexo;
    Data dataNasc;
    float altura, peso;

    printf("Digite o nome completo: ");
    fgets(nome, sizeof(nome), stdin);
    size_t len = strlen(nome);
    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
    }

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &sexo);

    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &dataNasc.dia, &dataNasc.mes, &dataNasc.ano);

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    printf("Digite o peso (em kg): ");
    scanf("%f", &peso);

    PerfilSaude* perfil = criarPerfil(nome, sexo, dataNasc, altura, peso);
    perfil = calcularDados(perfil);

    printf("\n--- Dados do Perfil de Saude ---\n");
    mostrarPerfil(perfil);

    free(perfil);

    return 0;
}
