#include <stdio.h>

#include "tic_tac_toe.h"
#include "board.h"
#include "utilities.h"

void init_game(void) {
  init_board();
  game.user_plays = (user_symbol() == CROSS); // X plays first
  game.turn_no = 1;
}

void next_turn(void) { game.user_plays ^= 1, game.turn_no++; }

void user_move(void) {
  printf("> "); skip_whitespace();

  int row, col;
  int token = getchar();

  if (token == 'q' || token == 'Q') terminate_game_session("Ciao!");

  if (!valid_index(col = token - 'A')) {
    printf("Invalid directive, try again\n");
    flush_input(); user_move(); return;
  }

  token = getchar();
  if (!valid_index(row = token - '1')) {
    printf("Invalid directive, try again\n");
    flush_input(); user_move(); return;
  }

  if (!is_board(row, col, EMPTY)) {
    printf("Occupied position, try again\n");
    flush_input(); user_move(); return;
  }

  skip_whitespace();
  if ((token = getchar()) != '\n') {
    printf("Invalid directive, try again\n");
    flush_input(); user_move(); return;
  }

  printf("User played: %c%d\n", 'A'+col, 1+row);
  set_board(row, col, user_symbol());
}

void computer_move(void) {
  int row, col;

  /* Extra flag that's used to stop the search in case terminal
   * states are reached early (in the first or second move)
   */

  bool stop = false;

  minimax(true, &stop, turn_no(), &row, &col);
  if (!valid_indeces(row, col))
    terminate_game_session("error: invalid move for computer");

  printf("Computer played: %c%d\n", 'A'+col, 1+row);
  set_board(row, col, comp_symbol());
}

int minimax(bool max_plays, bool *stop, int turn, int *row, int *col) {
  if ( max_plays && winning_sequence_exists(comp_symbol())) return P_INF;
  if (!max_plays && winning_sequence_exists(user_symbol())) return M_INF;
  if (turn > MAX_TURNS)                                     return DRAW_VAL;

  int evaluation;

  if (max_plays) {

    // Initially, any move is the best move for the maximizing player
    int max_evaluation = M_INF;

    /* Regard every possible move the maximizing player can
     * play as a next game state
     */

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        if (is_board(i, j, EMPTY)) {

          // Simulate next game state to call minimax again and then undo it
          set_board(i, j, comp_symbol());
          evaluation = minimax(false, stop, turn+1, row, col);
          set_board(i, j, EMPTY);

          /* User may have a winning move that needs to be blocked (the stop
           * flag gets triggered only on the first recursive call of minimax)
           */

          if (*stop) return M_INF; // The search stops here

          if (max_evaluation < evaluation) {
            max_evaluation = evaluation;

            /* The best move is decided on the first level of the minimax
             * tree, and if a winning move is reached for the computer, the
             * search stops
             */

            if (turn == turn_no()) {
              *row = i, *col = j;
              if (max_evaluation == P_INF) return P_INF;
            }
          }
        }
      }
    }

    return max_evaluation;
  }

  // Initially, any move is the worst move for the minimizing player
  int min_evaluation = P_INF;

  /* Regard every possible move the minimizing player can
   * play as a next game state
   */

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (is_board(i, j, EMPTY)) {

        // Simulate next game state to call minimax again and then undo it
        set_board(i, j, user_symbol());
        evaluation = minimax(true, stop, turn+1, row, col);
        set_board(i, j, EMPTY);

        if (min_evaluation > evaluation) {
          min_evaluation = evaluation;

          /* If the user's next move is a winning one, then the computer
           * needs to block it. For that purpose, the stop flag is activated
           * and the indeces of that winning move are saved
           */

          if (turn == turn_no() - 1 && min_evaluation == M_INF) {
            *row = i, *col = j;
            *stop = true;
            return M_INF;
          }
        }
      }
    }
  }

  return min_evaluation;
}

bool winning_sequence_exists(char symbol) {
  for (int i = 0; i < SIZE; i++) {
    if (is_board(i, 0, symbol)
     && is_board(i, 1, symbol)
     && is_board(i, 2, symbol)) return true;

    if (is_board(0, i, symbol)
     && is_board(1, i, symbol)
     && is_board(2, i, symbol)) return true;
  }

  if (is_board(0, 0, symbol)
   && is_board(1, 1, symbol)
   && is_board(2, 2, symbol)) return true;

  if (is_board(0, 2, symbol)
   && is_board(1, 1, symbol)
   && is_board(2, 0, symbol)) return true;

  return false;
}

/* Checks whether the game has ended, in which case the
 * appropriate signalling (state) value is returned
 */

state_t game_state(void) {
  if (winning_sequence_exists(user_symbol())) return WON;
  if (winning_sequence_exists(comp_symbol())) return LOST;
  if (turn_no() == MAX_TURNS)                 return DRAW;

  return STILL_PLAYING;
}
