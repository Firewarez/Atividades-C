#include <stdio.h>


typedef struct {
    char titulo[51];       
    char autor[51];        
    int ano_publicacao;
} TipoLivro;

int main() {
    TipoLivro livros[3];

    for (int i = 0; i < 3; i++) {
        printf("Digite o titulo do livro %d: ", i + 1);

        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);

        size_t len = 0;
        while (livros[i].titulo[len] != '\0') len++;
        if (len > 0 && livros[i].titulo[len - 1] == '\n') {
            livros[i].titulo[len - 1] = '\0';
        }

        printf("Digite o autor do livro %d: ", i + 1);
        fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
        len = 0;
        while (livros[i].autor[len] != '\0') len++;
        if (len > 0 && livros[i].autor[len - 1] == '\n') {
            livros[i].autor[len - 1] = '\0';
        }

        printf("Digite o ano de publicacao do livro %d: ", i + 1);
        scanf("%d", &livros[i].ano_publicacao);

        
        getchar();
    }

    
    printf("\nDetalhes dos livros:\n");
    for (int i = 0; i < 3; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano de Publicacao: %d\n\n", livros[i].ano_publicacao);
    }

    return 0;
}
