#pragma once

#include <stdbool.h>

typedef enum {STILL_PLAYING, WON, LOST, DRAW} state_t;

#define SIZE      3
#define MAX_TURNS 9

#define EMPTY  ' '
#define CROSS  'X'
#define NOUGHT 'O'

typedef struct game {
  char board[SIZE][SIZE];
  char user_symbol;
  char comp_symbol;
  bool user_plays;
  int turn_no;
} game_t;
