#include <stdio.h>
#include <stdlib.h>

#include "tic_tac_toe.h"
#include "utilities.h"

// Processes command line arguments
void process_CLA(int argc, char **argv) {
  game.user_symbol = NOUGHT; // Default user symbol
  game.comp_symbol = CROSS; // Default computer symbol

  if (argc == 1) return;

  if (argc > 2 || argv[1][0] != '-')
    terminate_game_session("Invalid program arguments");

  switch (argv[1][1]) {
    case 'x': case 'X':
      game.user_symbol = CROSS;
      game.comp_symbol = NOUGHT;
      break;

    default: terminate_game_session("Invalid program arguments");
  }

  if (argv[1][2] != '\0') terminate_game_session("Invalid program arguments");
}

bool valid_index(int index) { return (index >= 0 && index < SIZE); }

bool valid_indeces(int row, int col) {
  return (valid_index(row) && valid_index(col));
}

void set_board(int row, int col, char symbol) {
  if (!valid_indeces(row, col))
    terminate_game_session("error: invalid indeces (set_board)");

  game.board[row][col] = symbol;
}

char get_board(int row, int col) {
  if (!valid_indeces(row, col))
    terminate_game_session("error: invalid indeces (get_board)");

  return game.board[row][col];
}

bool is_board(int row, int col, char symbol) {
  if (!valid_indeces(row, col))
    terminate_game_session("error: invalid indeces (is_board)");

  return (get_board(row, col) == symbol);
}

char user_symbol(void)  { return game.user_symbol; }
char comp_symbol(void)  { return game.comp_symbol; }
bool user_plays(void) { return game.user_plays;  }
int turn_no(void)       { return game.turn_no;     }

void skip_whitespace(void) {
  int token = getchar();

  while (token == ' ' || token == '\t')
    token = getchar();

  ungetc(token, stdin);
}

void flush_input(void) { while (getchar() != '\n'); }

void terminate_game_session(char *msg) {
  printf("%s\n", msg);
  exit(EXIT_SUCCESS);
}
