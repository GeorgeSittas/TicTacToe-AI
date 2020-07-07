#pragma once

#include "types.h"

extern game_t game;

void init_game(void);
void next_turn(void);
void user_move(void);
void computer_move(void);

#define P_INF   +1
#define M_INF   -1
#define DRAW_VAL 0

int minimax(bool, bool *, int turn, int *, int *);

bool winning_sequence_exists(char);
state_t game_state(void);
