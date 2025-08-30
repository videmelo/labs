#include <stdio.h>
#include <windows.h>

int main() {
   SetConsoleOutputCP(65001);
   printf("Olá Mundo!");

   int a = 10;
   int b = 5;

   printf("\nAs váriaveis em c iniciam como lixo de memória");
   printf("\nSoma: %d + %d = %d", a, b, a + b);
   printf("\nSubtração: %d - %d = %d", a, b, a - b);
   printf("\nMultiplacação: %d * %d = %d", a, b, a * b);
   printf("\nDivisão: %d / %d = %d", a, b, a / b);
   printf("\nResto: %d / %d = %d", a, b, a % b);
   printf("\nValor absoluto: %d", abs(b - 10));

   float n1 = 8;
   float n2 = 3;
   printf("\nGerando media de notas:\nNota: %f\nNota: %f\nMédia: %f", n1, n2, (n1 + n2) / 2);

   return 0;
} 