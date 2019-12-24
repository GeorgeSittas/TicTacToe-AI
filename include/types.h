#pragma once

typedef enum {false=0, true=1} bool_t;
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
  bool_t user_plays;
  int turn_no;
} game_t;
