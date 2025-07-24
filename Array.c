#include <stdio.h>
typedef struct {
  int h; // Altura
  int l; // Largura
  int c; // Comprimento
  int r // Raio se tiver, caso contrario, colocar 1
} box;
int main() {
    int qtd,  arr;

    printf("********** Calculadora de Volume *********\n");
    printf("Quantidade de formas:\n");
    scanf("%d", &qtd);


  box boxes[qtd]; /// array armazena elementos de qualquer tipo de dado

  for(arr = 0; arr < qtd; arr++) {
    printf("Digite a altura da forma %d:\n", arr + 1); 
    scanf("%d", &boxes[arr].h);
     printf("Digite a largura da forma %d:\n", arr + 1);
     scanf("%d", &boxes[arr].l);
     printf("Digite o comprimento da forma %d:\n", arr + 1);
     scanf("%d", &boxes[arr].c);
    printf("Digite o raio (se aplicável) da forma %d:\n", arr + 1);
     scanf("%d", &boxes[arr].r);
  }


  int v, volume, forma;

  printf("********* Escolha uma forma ********** :\n");
        printf("1 - Cubo\n");
        printf("2 - Paralelepípedo\n");
        printf("3 - Cilindro\n");
        printf("4 - Esfera\n");
        printf("5 - Cone\n");
        printf("6 - Pirâmede\n");
        scanf("%d", &forma);

  switch (forma)
        {
            case 1:
            for (v = 0; v <= qtd; v++) {
                // Cubo
                volume = boxes[v].h*boxes[v].h*boxes[v].h;
                printf("O cubo %d tem volume de: %d\n", v, volume);
                 }
                break;
                

            case 2:
                 for (v = 0; v < qtd; v++) {
                // Paralelepipedo
                volume = boxes[v].h*boxes[v].l*boxes[v].c;
                printf("O paralelepípedo %d tem volume de: %d\n", v, volume);
                }
                break;
                
            case 3:
                for(v = 0; v < qtd; v++) {
                // Cilindro
                double pi = 3.14159;
                volume = boxes[v].h*(boxes[v].r*boxes[v].r)*pi;
                printf("O cilindro %d tem volume de: %d\n", v, volume);
                }
                break;

            case 4:
                for (v = 0; v < qtd; v++) {
                   // Esfera
                double pi = 3.14159;
                float x = 4.0/3.0;
                volume = x*(boxes[v].r*boxes[v].r*boxes[v].r)*pi;
                printf("A esfera %d tem volume de: %d\n", v, volume);
                }
                break;

            case 5:
                for (v = 0; v < qtd; v++) {
                //Cone
                double pi = 3.14159;
                float x = 1.0/3.0;
                volume = x*(boxes[v].r*boxes[v].r)*pi;
                printf(" O cone %d tem volume de: %d\n", v, volume);
                }
                break;

            case 6:
                for (v = 0; v < qtd; v++) {
                //Piramede
                volume = (boxes[v].h*(boxes[v].l*boxes[v].l)) / 3;
                printf(" %d volume %d\n", v, volume);
                }
                break;

            default:
                printf("Operação inválida.\n");
                break;
            }
  return 0;
}

