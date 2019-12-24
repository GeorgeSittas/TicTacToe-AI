#pragma once

#define SEC_IN_MICROSEC 1000000
#define MOVE_DELAY SEC_IN_MICROSEC /* Computer has a 1 sec move delay */

#include "types.h"

void process_CLA(int, char **);

bool_t valid_index(int);
bool_t valid_indeces(int, int);

void set_board(int, int, char);
char get_board(int, int);
bool_t is_board(int, int, char);

char user_symbol(void);
char comp_symbol(void);
bool_t user_plays(void);
int turn_no(void);

void skip_whitespace(void);
void flush_input(void);
void terminate_game_session(char *);
