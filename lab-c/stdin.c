#include <stdio.h>
#include <string.h>

int main()
{
   char nome[50];
   char frase[100];
   char caractere;

   // ------------------- puts e printf -------------------
   printf("=== Saída com printf e puts ===\n");
   printf("Olá com printf\n");
   puts("Olá com puts (adiciona \\n automaticamente)");

   // ------------------- scanf -------------------
   printf("\n=== Entrada com scanf (apenas uma palavra) ===\n");
   printf("Digite seu primeiro nome: ");
   scanf("%49s", nome); // lê até 49 caracteres
   printf("Você digitou (scanf): %s\n", nome);

   fflush(stdin); // limpa o buffer de entrada

   // ------------------- fgets -------------------
   printf("\n=== Entrada com fgets (linha completa, aceita espaços) ===\n");
   printf("Digite seu nome completo: ");
   fgets(nome, sizeof(nome), stdin);

   // remover \n que o fgets captura
   nome[strcspn(nome, "\n")] = '\0';
   printf("Você digitou (fgets): %s\n", nome);

   // ------------------- fputs -------------------
   printf("\n=== Saída com fputs ===\n");
   fputs("Imprimindo com fputs (sem \\n automático)", stdout);
   putchar('\n'); // adicionar quebra manual

   // ------------------- getchar e putchar -------------------
   printf("\n=== getchar e putchar ===\n");
   printf("Digite um caractere: ");
   caractere = getchar();
   printf("Você digitou: ");
   putchar(caractere);
   putchar('\n');

   fflush(stdin); // limpa o buffer

   // ------------------- fgets em frases -------------------
   printf("\n=== Lendo uma frase inteira ===\n");
   printf("Digite uma frase: ");
   fgets(frase, sizeof(frase), stdin);
   frase[strcspn(frase, "\n")] = '\0'; // remove \n
   printf("Frase digitada: %s\n", frase);

   printf("\n=== Programa finalizado ===\n");
   return 0;
}
