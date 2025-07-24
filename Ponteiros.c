#include<stdio.h> 
#include<string.h> // Para usar strcpy


typedef struct {
    int idade;
    int matricula;
    char disciplina[40];
    float horas;
} academico;

typedef struct {
    char nome[50];
    academico acesso;
} aluno;

void Disciplina(aluno *classe){ // Parametro de estrutura e testanto ponteiros
 strcpy(classe -> acesso.disciplina, "Programacao em C");
 classe -> acesso.horas = 60.0; // Atribuindo valores a disciplina e horas
}
void imprimiracademico(aluno *st) // * =  Define um ponteira para a struct aluno
{
    printf("\n********* Dados do Aluno *********\n");
    printf("Nome: %s\n", st ->nome); // -> = Acessa os membros da struct através do ponteiro
    printf("Idade: %d\n", st ->acesso.idade); // Uma struct dentro de outra, por isso é necessario usar o ponto para acessar os membros
    printf("Matricula: %d\n", st -> acesso.matricula);
    printf("Disciplina: %s\n", st ->acesso.disciplina);
    printf("Horas: %.2f\n", st ->acesso.horas);
}
int main(){
    
    aluno aluno1 = {"Maria Antonieta", {20, 9876}};
    aluno aluno2 = {"Pedro Alvares", {25, 5643}};
    // Atribuindo disciplina com a função fixa
    Disciplina(&aluno1);
    Disciplina(&aluno2);

    imprimiracademico(&aluno1); // & = amarzena o do endereço de memória da variável aluno1f
    imprimiracademico(&aluno2);

    return 0;

}