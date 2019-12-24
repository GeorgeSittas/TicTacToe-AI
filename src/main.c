#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/tic_tac_toe.h"
#include "../include/utilities.h"
#include "../include/board.h"

game_t game;

int main(int argc, char **argv) {
  process_CLA(argc, argv);
  init_game();

  while (true) {
    print_board();

    if (user_plays()) {
      printf("User's turn\n");
      user_move();
    }
    else {
      printf("Computer's turn\n");
      usleep(MOVE_DELAY);
      computer_move();
    }

    /* Check if the game is over, in which case the program will terminate */
    switch (game_state()) {
      case WON:  print_board(); terminate_game_session("You win!");
      case LOST: print_board(); terminate_game_session("You lose!");
      case DRAW: print_board(); terminate_game_session("Draw!");
      case STILL_PLAYING: break;
    }

    /* Alternate computer and user moves */
    next_turn();
  }

  return 0;
}
