#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // strcpy

/* Exercicio 1 */
 typedef struct{
    int idade;
    int matricula;
    char nome[40];
}aluno;

    int main()
    {
        // inicializando variaveis do tipo struct aluno
    aluno aluno1, aluno2, aluno3;
    aluno aluno4 = {.matricula = 123456, .idade = 25, .nome = "Ana Maria"};  // forma alternativa de atribuição

    aluno3 = (aluno){26, 56789, "Carlos da Silva"}; // outra forma de atribuição 

     // outra forma de atribuir valores
    aluno1.idade =20;
    aluno1.matricula = 9876;
    strcpy(aluno1.nome, "Joao da Silva");

    aluno2.idade = 24;
    aluno2.matricula = 8765;
    strcpy(aluno2.nome, "Maria da Silva");
    
    printf("*****\n");
    printf("Dados dos alunos:\n");
    printf("Aluno 1: %s, Matricula: %d, Idade: %d\n", aluno1.nome, aluno1.matricula, aluno1.idade);
    printf("Aluno 2: %s, Matricula: %d, Idade: %d\n", aluno2.nome, aluno2.matricula, aluno2.idade);
    printf("Aluno 3: %s, Matricula: %d, Idade: %d\n", aluno3.nome, aluno3.matricula, aluno3.idade);
    printf("Aluno 4: %s, Matricula: %d, Idade: %d\n", aluno4.nome, aluno4.matricula, aluno4.idade);
    printf("*****");
        return 0;
    }