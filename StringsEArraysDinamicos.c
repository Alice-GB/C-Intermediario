    //********** STRING ********** 
    //Alocar memomria para um ponteiro string
    // Podemos utilizar o comprimento de string ao invés do operador sizeof
    // é melhor para o gerenciamento de memória porque não aloca mais memória do que o necessário

    //********** ARRAYS DINÂMICOS ********** 
    // o ARRAY DINÂMICO é um array que pode crescer ou diminuir de tamanho conforme necessário
    // Como os arrays tem elementos que não são alocados todos de uma vez, usam uma estrutura de dados 
    // para manter o controle do tamanho, da capacidade do array e o ponteiro para os elementos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *strname;  // nome da disciplina
    int *alunos; // quantidade de alunos
    int qtdAlunos; // quantidade de alunos cadastrados
    int capAlunos; // capacidade total do array de alunos
} Disciplina;
    

    //arrays dinâmicos
typedef struct{
    Disciplina *elementos;
    int tam; // tamanho do array
    int capTotal; // capacidade total do array
}dinArr;  

int main() {

        // Irei fazer um exemplo utilizando string e arrays dinâmicos para gerenciar a quantidade de alunos de cada disciplina
            dinArr arr;
            int i, j;
            char temp[100];

            arr.tam = 0; // Inicializa a quantidade de alunos
            arr.capTotal = 2; // Define a capacidade inicial do array
            arr.elementos = malloc(arr.capTotal * sizeof(Disciplina)); // Aloca memória para o array de IDs de alunos

            if (arr.elementos == NULL) {
            printf("Erro ao alocar memória.\n");
                return 1; 
            }

            printf("Quantas disciplinas deseja cadastrar?\n");
            int qtdDisciplinas;
            scanf("%d", &qtdDisciplinas);
            getchar(); // Consome o '\n' deixado pelo scanf

            // Loop para cadastrar disciplinas
            for(qtdDisciplinas =0; qtdDisciplinas < 2; qtdDisciplinas++) {
                if(arr.tam >= arr.capTotal){
                    arr.capTotal += 5; // Aumenta a capacidade total do array
                    arr.elementos = realloc(arr.elementos, arr.capTotal * sizeof(Disciplina)); // Realoca memória para o array de IDs de alunos
                    if (arr.elementos == NULL) {    
                        printf("Erro ao realocar memória.\n");
                        return 1; 
                    } 
                }
                
                    printf("Digite o nome da disciplina %d? ", qtdDisciplinas+1);
                    fgets(temp, sizeof(temp), stdin);
                    temp[strcspn(temp, "\n")] = 0; // Remove o caractere de nova linha
                    arr.elementos[arr.tam].strname = strdup(temp); // Agora strname tem o valor correto!
                    
                    //Inicializando

                    arr.elementos[arr.tam].qtdAlunos = 0; // Inicializa a quantidade de alunos cadastrados
                    arr.elementos[arr.tam].capAlunos = 2; // Capacidade inicial do array alunos
                    arr.elementos[arr.tam].alunos = malloc(arr.elementos[arr.tam].capAlunos * sizeof(int)); // Aloca memória para o array

                    int numAlunos;
                    printf("Quantos alunos deseja cadastrar na disciplina %s? ", arr.elementos[arr.tam].strname);
                    scanf("%d", &numAlunos);

                    for(j = 0; j < numAlunos; j++) {
                        if(arr.elementos[arr.tam].qtdAlunos >= arr.elementos[arr.tam].capAlunos) {
                            arr.elementos[arr.tam].capAlunos += 5; // Aumenta a capacidade do array de alunos
                            arr.elementos[arr.tam].alunos = realloc(arr.elementos[arr.tam].alunos, arr.elementos[arr.tam].capAlunos * sizeof(int)); // Realoca memória para o array de alunos
                            if (arr.elementos[arr.tam].alunos == NULL) {    
                                printf("Erro ao realocar memória.\n");
                                return 1; 
                            } 

                            if(arr.elementos[arr.tam].alunos == NULL){
                                printf("Erro ao alocar memória para os alunos.\n");
                                return 1; 
                            }
                        }
                        printf("Digite o ID do aluno %d: ", j + 1);
                        scanf("%d", &arr.elementos[arr.tam].alunos[arr.elementos[arr.tam].qtdAlunos]);

                        arr.elementos[arr.tam].qtdAlunos++;

                        }

                    arr.tam++; // Incrementa a quantidade de disciplinas cadastradas

            }

            // Exibe as disciplinas e os alunos cadastrados

            printf("\nDisciplinas e Alunos Cadastrados:\n");
            for(i = 0; i < arr.tam; i++) {
                printf("Disciplina: %s\n", arr.elementos[i].strname);
                printf("Quantidade de Alunos: %d\n", arr.elementos[i].qtdAlunos);
                printf("Alunos: ");
                for(j = 0; j < arr.elementos[i].qtdAlunos; j++) {
                    printf("%d ", arr.elementos[i].alunos[j]);
                }
                printf("\n");

                // Libera a memória alocada
                free(arr.elementos[i].alunos);
                free(arr.elementos[i].strname);                          
            }
            free(arr.elementos); // Libera a memória alocada para o array de disciplinas
            return 0;
        }