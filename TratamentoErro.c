#include <stdio.h>
#include <errno.h>
#include <string.h>

/*TRATAMENTO DE ERRO COM ERRNO E RETORNO DE 0 E DIFERENTE DE 0 */

int main() {}

    FILE *alunos;
    
    errno = 0; // zera errno antes da chamada
    alunos = fopen("alunos.txt", "r"); // tenta abrir arquivo que não existe

    if (alunos == NULL) {
        // Mostra o código do erro
        fprintf(stderr, "Erro ao abrir arquivo. Codigo errno: %d\n", errno);

        // Mostra a mensagem descritiva do erro
        fprintf(stderr, "Descricao do erro: %s\n", strerror(errno));

        // Outra forma de mostrar mensagem de erro
        perror("Mensagem perror");
        
        return 1; // saída com erro
    }

    // Se abrir corretamente, fechar arquivo
    fclose(alunos);

    return 0; // saída bem sucedida
}