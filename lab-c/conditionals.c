#include <stdio.h>
#include <windows.h>

int main() {
   SetConsoleOutputCP(65001);
   printf("Verificando maioridade");

   int age = 0;
   printf("\nQual sua idade? ");
   scanf("%d", &age);

   if (age >= 18) {
      printf("Você é maior de idade! \n");

      int opt;
      printf("Escolha seu plano agora: \n");
      printf("1 - Free \n");
      printf("2 - Premium \n");
      printf("3 - Deluxe \n");

      scanf("%d", &opt);

      switch (opt) {
         case 1:
            printf("Você escolheu o plano: \n");
            printf("1 - Free \n");
            break;
         case 2:
            printf("Você escolheu o plano: \n");
            printf("2 - Premium \n");
            break;
         case 3:
            printf("Você escolheu o plano: \n");
            printf("3 - Deluxe \n");
            break;
         default:
            printf("Opção invalida: \n");
            break;
      }
   } else {
      printf("Você é menor de idade!");
   }

   return 0;
}