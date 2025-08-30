#include <stdio.h>
#include <math.h>

int main()
{
   // ----------- Inteiros -----------
   int a = 10, b = 3;

   // Operações aritméticas básicas
   int soma = a + b;
   int sub = a - b;
   int mult = a * b;
   int divi = a / b;
   int resto = a % b;

   // Operadores de atribuição e incrementos
   a += 5; // a = 15
   b *= 2; // b = 6
   a++;    // a = 16
   b--;    // b = 5

   // ----------- Ponto flutuante -----------
   float f = 3.14f;
   double d = 2.718281828;

   // Funções matemáticas
   double raiz = sqrt(d);          // raiz quadrada
   double pot = pow(f, 2);         // f^2
   double sen = sin(3.1415 / 2);   // seno
   double cosi = cos(0);           // cosseno
   double tanx = tan(0);           // tangente
   double abs_val = fabs(-7.5);    // valor absoluto
   double arred_up = ceil(2.3);    // arredonda para cima
   double arred_down = floor(2.8); // arredonda para baixo

   // ----------- Saída -----------
   printf("Inteiros: \n");
   printf("Soma: %d, Subtracao: %d, Multiplicacao: %d\n", soma, sub, mult);
   printf("Divisao: %d, Resto: %d\n", divi, resto);
   printf("a = %d, b = %d\n", a, b);

   printf("\nPonto Flutuante: \n");
   printf("Float: %.2f, Double: %.8f\n", f, d);
   printf("Raiz de d: %.4f, f^2: %.2f\n", raiz, pot);
   printf("Seno: %.2f, Cosseno: %.2f, Tangente: %.2f\n", sen, cosi, tanx);
   printf("Abs: %.2f, Ceil: %.2f, Floor: %.2f\n", abs_val, arred_up, arred_down);

   return 0;
}
