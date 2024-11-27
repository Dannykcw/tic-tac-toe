#include "win.h"

bool all_same(int* values, int len) {
    for (int i = 0; i < len; i++)
    {
        if(values[i])
    }
    
}
bool someone_won(const Board* board) {
    return someone_won_horizontally(board) || someone_won_vertically(board) || someone_won_diagonally(board);
}

bool is_full(const Board* board) {
    for (int i = 0; i < board->dimensions; i++)
    {
        for (int j = 0; j < board->dimensions; j++)
        {
            if(board->contents[i][j] == board->blank_char) {
                return false;
            }
        }
    }
    return true;
}

bool tie(Board* board) {
    return is_full(board) && !someone_won(board);
}

bool someone_won_diagonally_right(const Board* board) {
    for (int i = board->dimensions - 2; i > 0; i--)
    {
        char* diagonal = get_diagonal();
        if(all_same(diagonal, board->dimensions)) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }
    return false;
}

bool someone_won_diagonally_left(const Board* board) {
    for (int i = 0; i < board->dimensions; i++)
    {
        char* diagonal = get_diagonal();
        if(all_same(diagonal, board->dimensions)) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }
    return false
}

bool someone_won_diagonally(const Board* board) {
    return someone_won_diagonally_right() || someone_won_diagonally_left();
}

bool someone_won_vertically(const Board* board) {
    for (int i = 0; i < board->dimensions; i++) {
        char* column = get_column_i();
        if (all_same(column, board->dimensions)) {
            free(column);
            return true;
        }
        free(column);
    }
    return false;
}

bool someone_won_horizontally(const Board* board) {
    for (int i = 0; i < board->dimensions; i++) {
        if (all_same(board->contents[i], board->dimensions)) {
            return true;
        }
    }
    return false;
}