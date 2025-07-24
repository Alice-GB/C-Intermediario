// Unions permite armazenar diferentestipos de dados na mesma localização de memória
#include <stdio.h>

typedef struct {
    char proprietario[50];
    char placa[10];
    int ano;
    int idtipo; // 1 - Carro, 2 - Moto, 3 - Caminhão
        union{
            int idNum;
            char chassi[17];
        } id;
} Veiculo;

int main(){
    int i;
    Veiculo veiculos[2]; // Array de 2 veículos: Array é uma estrutura que amrazena elementos do mesmo tipo, 
    // porém, arrays de uniões permitem armazenar valores de diferentes tipos de dados.

    //Veiculo 1
    strcpy(veiculos[0].proprietario, "Alice Gomes Bernardo");
    strcpy(veiculos[0].placa, "ABC-1234");     
    veiculos[0].ano = 2020;
    veiculos[0].idtipo = 1; // Carro
    veiculos[0].id.idNum = 123456; // ID numérico para carro

    //Veiculo 2
    strcpy(veiculos[1].proprietario, "João Silva");
    strcpy(veiculos[1].placa, "XYZ-5678");
    veiculos[1].ano = 2018;
    veiculos[1].idtipo = 2; // Moto
    strcpy(veiculos[1].id.chassi, "1HGBH41JXMN109186"); // Chassi para moto
    
    for (i = 0; i < 2; i++) {
        printf("\nVeículo %d:\n", i + 1);
        printf("Proprietário: %s\n", veiculos[i].proprietario);
        printf("Placa: %s\n", veiculos[i].placa);
        printf("Ano: %d\n", veiculos[i].ano);
        printf("ID Tipo: %d\n", veiculos[i].idtipo);
        
        if (veiculos[i].idtipo == 1) {
            printf("ID Numérico: %d\n", veiculos[i].id.idNum);
        } else {
            printf("Chassi: %s\n", veiculos[i].id.chassi);
        }
    }

        
    return 0;
}

