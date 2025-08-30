#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main() {
   int matriz[LINHAS][COLUNAS];
   int i, j;

   // Preenchendo a matriz com valores
   printf("Digite os elementos da matriz %dx%d:\n", LINHAS, COLUNAS);
   for (i = 0; i < LINHAS; i++) {
      for (j = 0; j < COLUNAS; j++) {
         printf("Elemento [%d][%d]: ", i, j);
         scanf("%d", &matriz[i][j]);
      }
   }

   // Exibindo a matriz
   printf("\nMatriz digitada:\n");
   for (i = 0; i < LINHAS; i++) {
      for (j = 0; j < COLUNAS; j++) {
         printf("%d\t", matriz[i][j]);
      }
      printf("\n");
   }

   return 0;
}