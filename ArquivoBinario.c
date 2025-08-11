// fgetc(fp) -> le 1 caractere por vez do arquivo fp.Retorna EOF quando chegar ao final
//fgets(BUFF, N, FP) -> Le até N-1 caracteres do arquivo FP, ou até encontrar um '\n' ou EOF.
//fscan(fp) ->  Lê dados formatados do arquivo, usando os especificadores (%d, %s, etc.),
// e guarda nas variáveis passadas. Para leitura de strings, para no espaço ou nova linha.
//fputc(char, fp) → Escreve um caractere no arquivo fp.
//fputs(str, fp) → Escreve uma string inteira no arquivo fp.
//fprintf(fp, str, vars) → Escreve texto formatado no arquivo fp (como printf, mas para arquivo).

#include <stdio.h>
#include <string.h>

/*Manipulando arquivos */

typedef struct {
    int matricula;
    char nome[50];
} Pessoa;

int main() {
   
    Pessoa Aluno, lido;
    for(int i = 0; i < 2; i++) {
        printf("Digite a matricula do aluno %d: ", i + 1);
        fscanf(stdin, "%d", &Aluno.matricula);
        getchar(); // Limpar o buffer do teclado após ler a matrícula

        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(Aluno.nome, sizeof(Aluno.nome), stdin);

        // Remove '\n' do fgets, se existir
        size_t len = strlen(Aluno.nome);
        if(len > 0 && Aluno.nome[len-1] == '\n')
        Aluno.nome[len-1] = '\0';

        // Escrever no arquivo
        FILE *fptr = fopen("alunos.dat", "ab");
        fwrite(&Aluno, sizeof(Aluno), 1, fptr);
        fclose(fptr);
    }

         // Ler o segundo aluno
        FILE *fptr = fopen("alunos.dat", "rb");
        fseek(fptr, 1 * sizeof(Aluno), SEEK_SET);
        fread(&lido, 1, sizeof(Aluno), fptr);
        fclose(fptr);

        // Mostrar dados lidos
        printf("Matricula: %d\nNome: %s\n", lido.matricula, lido.nome);

        return 0;
        
}