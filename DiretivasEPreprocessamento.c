// ********** DIRETIVAS E PREPROCESSAMENTO **********

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


#define NIVEL 4 // Nivel máximo 

#define VAR(name, num)name##num

void VerificarNivel(int nota) {
        
#if NIVEL >= 1
    if (nota < 60){
    printf("Está no nível 1: Insuficiente\n");
    }
#endif

#if NIVEL >= 2
   if (nota >= 60 && nota < 75){
    printf("Está no nível 2: Regular\n");
    }
#endif

#if NIVEL >= 3
    if (nota >= 75 && nota < 90){
        printf("Está no nível 3: Bom\n");
        }
#endif

#if NIVEL >= 4
if (nota >= 90){
        printf("Está no nível 4: Excelente \n");
        }
#endif

}

int main(){

    char *nome1 = "Alice Borges";
    char *nome2 = "João Silva";
    char *nome3 = "Maria Oliveira";

    int nota[3];
    int qtd;

    printf("********** SISTEMA DE NOTAS **********\n");


    for(int i = 0; i < 3; i++){
        printf("Digite a nota do aluno (0 a 100) %d: ", i + 1);
        scanf("%d", &nota[i]);
    }

    for(int i = 0; i < 3; i++){
       printf("\nDigite o número do aluno que deseja verificar o nível (1-3): ");
        scanf("%d", &qtd);

        if (qtd == 1) printf("Aluno: %s\n", nome1);
        if (qtd == 2) printf("Aluno: %s\n", nome2);
        if (qtd == 3) printf("Aluno: %s\n", nome3);

        printf("Nota: %d\n", nota[qtd - 1]);
        VerificarNivel(nota[qtd - 1]);
    }

     printf("\nHorário da Verificação: %s\n", __TIME__);

        return 0;

}