#include <stdio.h>
#include <stdlib.h>

int play(char player, char board[3][3])
{
   int line, column;
   printf("Linha: ");
   if (scanf("%d", &line) != 1)
   {
      printf("Entrada invalida!\n");
      fflush(stdin); 
      return 0;
   }
   printf("Coluna: ");
   if (scanf("%d", &column) != 1)
   {
      printf("Entrada invalida!\n");
      fflush(stdin); 
      return 0;
   }
   fflush(stdin);
   if (line <= 0 || line > 3 || column <= 0 || column > 3)
   {
      printf("Posicao invalida!\n\n");
      return 0;
   }
   if (board[line - 1][column - 1] == ' ')
   {
      system("cls");
      board[line - 1][column - 1] = player;
      return 1;
   }
   else
   {
      printf("Posicao ja ocupada!\n");
      return 0;
   }
}

int wins(char board[3][3])
{
   for (int i = 0; i < 3; i++)
   {
      if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
         return 1;
      if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
         return 1;
   }
   if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
      return 1;
   if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
      return 1;
   return 0;
}

void render(char board[3][3], char player)
{
   printf("[---- Jogo da Velha -----]\n");
   printf("[   Vez do jogador: %c    ]\n\n", player);
   for (int i = 0; i < 3; i++)
   {
      printf("      ");
      printf(" %c  |  %c  |  %c \n", board[i][0], board[i][1], board[i][2]);
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
      char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
      char player = 'O';
      int movs = 0;
      system("cls");
      while (1)
      {
         render(board, player);
         if (play(player, board))
         {
            if (wins(board))
            {
               render(board, player);
               printf("Vitoria do jogador: %c\n", player);
               break;
            }
            movs++;
            if (movs == 9)
            {
               render(board, player);
               printf("Deu velha!\n");
               break;
            }
            player = (player == 'O') ? 'X' : 'O';
         }
      }
      int option = 0;
      printf("\n[1] Jogar novamente\n[2] Sair\nEscolha uma opcao: ");
      if (scanf("%d", &option) != 1)
      {
         option = 2;
      }
      fflush(stdin); 
      if (option != 1)
      {
         playing = 0;
         printf("Saindo...\n");
      }
   }
   return 0;
}
