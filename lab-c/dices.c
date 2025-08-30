#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int die1 = (rand() % 6) + 1;
    int die2 = (rand() % 6) + 1;
    int die3 = (rand() % 6) + 1;

    printf("Resultados dos dados: %d, %d, %d\n", die1, die2, die3);
    printf("Soma dos dados: %d\n", die1 + die2 + die3);

    return 0;
}
