#include "tic_tac_toe.h"
#include "win.h"

typedef struct Game_struct
{
    Board board;
    int curr_player_turn;
    int curr_player_count;
    Player* Players;
} Game;

typedef struct board_struct {
    char** contents;
    int dimensions;
    char blank_char;
} Board;

typedef struct Player_struct {
    char* name;
    char piece;
} Player;

Board create_board (int dimensions, char blank_char) {
    Board board {NULL, dimensions, blank_char};
    board.contents = (char**) calloc(dimensions, sizeof(char*));
    for (int i = 0; i < dimensions; i++)
    {
        board.contents[i] = (char*) calloc(dimensions, sizeof(char));
        for (int j = 0; j < dimensions; j++)
        {
            board.contents[i][j] = blank_char;
        }
    }
    return board;
}

int pick_who_goes_first(int num_players) {
    return rand() % num_players;
}

char* get_player_name(Player* players_in_game, int len) {
    char* name = NULL;
    do
    {
        if(name != NULL) {
            free(name);
            name = NULL;
        }
        printf("Enter your name: \n");
        name = get_any_len_string();
        if (!is_valid_format(1,1)) {
            printf("Your name can only be one word long.\n");
            continue;
        } else if(!is_player_in_game(name, players_in_game, len)) {
            printf("%s is already in the the game. Choose another name\n", name);
        }
    } while (true);
    return name;
    
}

char get_player_piece(Player* players_in_game, int len) {
    char piece;
    while (true)
    {
        piece = get_valid_char("Please  choose your piece: ")
        if (is_piece_already_chosen(piece, players_in_game, len))
        {
            
        }
        
    }
    
}

Player* player_pick_name_and_pieces(int num_players) {
    Player* players = (Player*) calloc(num_players, sizeof(Player));
    for (int i = 0; i < num_players; i++)
    {
        players[i].name = get_player_name();
        players[i].piece = get_player_piece();
    }
    return players;
}

Game setup_game(int dimensions, int blank_char) {
    Game game;
    game.board = create_board(dimensions, blank_char);
    game.curr_player_turn = pick_who_goes_first(2);
    player_pick_pieces();
    return game;
}

bool is_game_over() {
    return someone_won(board) || tie(board);
}

void take_turns(Game* game) {
    Player* cur_player = get_curr_player();
    Move move = get_move();
    game->board->contents[move.row][move.col] = cur_player->piece;
}

Player* get_cur_player(Game* game) {
    return game->players->game->curr_player_turn};
}

void announce_result(const Board board) {
    if(someone_won(board)) {
        Player* winner = get_winning_player();
        printf("%s won the game!\n", winner->game);
    } else {
        printf("draw\n");
    }
}

void play_game(Game* game) {
    while(!is_game_over()) {
        take_turn();
        if (is_game_over()) {
            break;
        }
        switch_turn();
    }
    announce_results();
}