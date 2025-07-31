#include<stdio.h>
#include<stdlib.h> // malloc, calloc e realloc

/******* Anotações ********/
// Alocação de memória dinâmica é o processi de alocar e liberar memória conforme a necessidade.
// malloc(bytes) retorna um ponteiro para o bloco de memória que tem tamanho em bytes
// calloc(itens, tamanho) retorna um ponteiro para o bloco de memória que tem tamanho em bytes e inicializa com 0, 
// usando dois parâmetros: número de elementos e tamanho de cada elemento e tipicamente para os arrays
// realloc(ponteiro, bytes) redimensiona o bloco de memória apontado por ponteiro para o novo tamanho em bytes
// free(ponteiro) libera o bloco de memória apontado por ponteiro

int main(){

    int *idAluno = NULL;
    int qtd, total = 0;
    char resp;

    printf("Quantos alunos você deseja cadastrar?");
    scanf("%d", &qtd);
    idAluno = (int *)malloc(qtd *sizeof(*idAluno)); 

    if(idAluno == NULL) {
        printf("Memória insuficiente!\n");
        return 1; // encerra o programa se não conseguir alocar memória
    }

    for(int i =0; i < qtd; i++){
        printf("Informe o seu Registro de aluno (RA) %d:", i+1);
        scanf("%d", &idAluno[i]);

    }

    total = qtd;

    printf("Deseja adicionar mais alunos? Informe S (SIM) ou N (NÃO)\n");
    scanf("%s", &resp);

    if( resp == 'S' || resp == 's') {
        int novos;
         printf("Quantos novos alunos você deseja cadastrar?");
        scanf("%d", &novos);

    
       int *temp = realloc(idAluno, (total + novos) * sizeof(*idAluno));
        if(temp == NULL) {
        printf("Erro ao realocar memória\n");
        free(idAluno); // Libera o bloco de memória alocado
        return 1; 
        }

        idAluno =  temp;
        // Preenche os novos registros de alunos
        for(int i = total; i < total + novos; i++) {
            printf("Informe o seu Registro de aluno (RA) %d:", i+1);
            scanf("%d", &idAluno[i]);
        }
        total += novos;
    
    } else {
        printf("Nenhum novo aluno foi adicionado.\n");
    }
    printf("Total de alunos cadastrados: %d\n", total);

    free(idAluno); // libera o bloco de memória alocado para o RA

    return 0;

}