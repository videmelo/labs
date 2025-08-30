// objetivo: criar um jogo da velha

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int play(char p, char table[3][3])
{
   int l, c;
   char buffer[100];

   printf("Linha: ");
   fgets(buffer, sizeof(buffer), stdin);
   if (sscanf(buffer, "%d", &l) != 1)
   {
      printf("Entrada inválida!\n");
      return 0;
   }

   printf("Coluna: ");
   fgets(buffer, sizeof(buffer), stdin);
   if (sscanf(buffer, "%d", &c) != 1)
   {
      printf("Entrada inválida!\n");
      return 0;
   }

   if (l <= 0 || l > 3 || c <= 0 || c > 3)
   {
      printf("[    Posição invalida!   ]\n\n");
      return 0;
   }

   if (table[l - 1][c - 1] == ' ')
   {
      system("cls");
      table[l - 1][c - 1] = p;
      return 1;
   }
   else
   {
      printf("[   Posição já ocupada!  ]\n\n");
      return 0;
   }
}

int wins(char table[3][3])
{
   for (int i = 0; i < 3; i++)
   {
      if (table[i][0] != ' ' && table[i][0] == table[i][1] && table[i][1] == table[i][2])
         return 1;

      if (table[0][i] != ' ' && table[0][i] == table[1][i] && table[1][i] == table[2][i])
         return 1;
   }

   if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2])
   {
      return 1;
   }

   if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[1][1] == table[2][0])
   {
      return 1;
   }

   return 0;
}

void render(char table[3][3], char player)
{
   printf("[---- Jogo da Velha -----]\n");
   printf("[   Vez do jogador: %c    ]\n\n", player);
   for (int i = 0; i < 3; i++)
   {
      printf("      ");
      printf(" %c  |  %c  |  %c \n", table[i][0], table[i][1], table[i][2]);
      printf("      ");
      if (i < 2)
         printf("--- + --- + ---\n");
   }
   printf("\n[------------------------]\n\n");
}

int main()
{
   SetConsoleOutputCP(65001);
   char table[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

   char player = 'O';
   int movs = 0;

   system("cls");

   while (1)
   {
      render(table, player);
      if (play(player, table))
      {  
         if (wins(table))
         {
            render(table, player);
            printf("Vitória do jogador: %c", player);
            break;
         }
         movs++;
         if (movs == 9)
         {
            render(table, player);
            printf("Deu velha!");
            break;
         }
         if (player == 'O')
         {
            player = 'X';
         }
         else
         {
            player = 'O';
         }
      }
   }

   return 0;
}
