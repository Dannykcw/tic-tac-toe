#ifndef WIN_H
#define WIN_H

#include <stdbool.h>

bool all_same(int* values, int len);
bool someone_won(Board* board);
bool is_full(const Board* board);
bool tie(Board* board);
bool someone_won_diagonally_right(const Board* board);
bool someone_won_diagonally_left(const Board* board);
bool someone_won_diagonally(const Board* board);
bool someone_won_vertically(const Board* board);
bool someone_won_horizontally(const Board* board);
bool someone_won(Board* board);

#endif