#include <stdio.h>

#include "utilities.h"
#include "board.h"

void init_board(void) {
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      set_board(i, j, EMPTY);
}

void print_board(void) {
  putchar('\n');

  printf(" A   B   C\n\n");
  for (int i = 0; i < SIZE; i++) {
    printf(" %c | %c | %c   %d\n", get_board(i,0),
                                   get_board(i,1),
                                   get_board(i,2),
                                   i+1);

    if (i < SIZE-1) printf("---+---+---\n");
  }

  putchar('\n');
}
