#include <stdio.h>
#include <windows.h>

int main() {
   SetConsoleOutputCP(65001);
   printf("Olá Mundo!");

   int age = 0;
   printf("\nQual sua idade? ");
   scanf("%d", &age);
   printf("Sua idade é %d", age);

   float height = 0;
   printf("\nQual sua altura? ");
   scanf("%f", &height);
   printf("Sua altura é %f", height);

   char name;
   printf("\nQual a primeira letra do seu nome? ");
   fflush(stdin);
   scanf("%c", &name);
   printf("Sua a primeira letra do seu nome é %c", name);
   return 0;
} 