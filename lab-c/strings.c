#include <stdio.h>
#include <string.h> // Para funções de string

int main()
{
   // ------------------- Char simples ------------------- 
   char letra = 'A';
   char numero = '7';
   printf("Char letra: %c, Char numero: %c\n", letra, numero);

   // -------------------  Strings ------------------- 
   char nome[50] = "Joao";
   char sobrenome[50] = "Silva";
   char nome_completo[100];

   // Concatenar strings
   strcpy(nome_completo, nome);      // copia nome para nome_completo
   strcat(nome_completo, " ");       // adiciona espaço
   strcat(nome_completo, sobrenome); // adiciona sobrenome
   printf("Nome completo: %s\n", nome_completo);

   // Medir tamanho da string
   int tamanho = strlen(nome_completo);
   printf("Tamanho do nome completo: %d\n", tamanho);

   // Comparar strings
   if (strcmp(nome, sobrenome) == 0)
   {
      printf("Nome e sobrenome sao iguais\n");
   }
   else
   {
      printf("Nome e sobrenome sao diferentes\n");
   }

   // Acessar caracteres individuais
   printf("Primeira letra do nome: %c\n", nome[0]);
   printf("Ultima letra do sobrenome: %c\n", sobrenome[strlen(sobrenome) - 1]);

   // Modificar caracteres
   nome[0] = 'J'; // já era J, só exemplo
   printf("Nome modificado: %s\n", nome);

   return 0;
}
