#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int play(char p, char table[3][3])
{
   int l, c;
   printf("Linha: ");
   if (scanf("%d", &l) != 1)
   {
      printf("Entrada invalida!\n");
      fflush(stdin); 
      return 0;
   }
   printf("Coluna: ");
   if (scanf("%d", &c) != 1)
   {
      printf("Entrada invalida!\n");
      fflush(stdin); 
      return 0;
   }
   fflush(stdin);
   if (l <= 0 || l > 3 || c <= 0 || c > 3)
   {
      printf("Posicao invalida!\n\n");
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
      printf("Posicao ja ocupada!\n");
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
      return 1;
   if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[1][1] == table[2][0])
      return 1;
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
   int playing = 1;
   while (playing)
   {
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
               printf("Vitoria do jogador: %c\n", player);
               break;
            }
            movs++;
            if (movs == 9)
            {
               render(table, player);
               printf("Deu velha!\n");
               break;
            }
            player = (player == 'O') ? 'X' : 'O';
         }
      }
      int opcao = 0;
      printf("\n[1] Jogar novamente\n[2] Sair\nEscolha uma opcao: ");
      if (scanf("%d", &opcao) != 1)
      {
         opcao = 2;
      }
      fflush(stdin); 
      if (opcao != 1)
      {
         playing = 0;
         printf("Saindo...\n");
      }
   }
   return 0;
}
