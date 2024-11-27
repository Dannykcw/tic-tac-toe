#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


Board create_board(int dimensions, char blank_char);

int pick_who_goes_first(int num_players);

char* get_player_name(Player* players_in_game, int len);
