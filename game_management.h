#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "game_init.h"

/* 
   Function prototypes for managing game operations in the snake game.
   Includes functions for player and snake movements, screen manipulation, 
   game state updates, and board creation.
*/

/* 
   Moves the player and the snake to new positions.
   Updates the game state with the new positions of the player and snake.
*/
void move_player_and_snake(GameState *game, int new_player_row, int new_player_col, int new_snake_row, int new_snake_col);

/* 
   Disables terminal input buffering.
   Ensures immediate processing of input characters.
*/
void disableBuffer(void);

/* 
   Enables terminal input buffering.
   Restores normal input processing.
*/
void enableBuffer(void);

/* 
   Pauses the program execution for a specified duration.
   Allows for controlled timing in the game loop.
*/
void newSleep(float sec);

/* 
   Clears the terminal screen.
   Provides a fresh display of the game board.
*/
void clear_screen(void);

/* 
   Wraps around the map edges when the player moves off the edge.
   Adjusts row and column values to stay within the map boundaries.
*/
void wrap_around(int *row, int *col, int max_row, int max_col);

/* 
   Saves the current game state to the linked list.
   Includes positions of the player, snake, and food.
*/
void save_game_state(LinkedList *list, char **game_board, int rows, int cols, int player_row, int player_col, int snake_row, int snake_col);

/* 
   Updates the game state based on user input.
   Processes input to move the player or snake and updates the game board.
*/
void update_game_state(char input, char **game_board, int map_row, int map_col, LinkedList *moves);

/* 
   Checks if the game is over.
   Determines if the player has lost based on the game board state.
*/
int is_game_over(char **game_board, int map_row, int map_col);

/* 
   Checks if the game is won.
   Determines if the player has won based on the game board state.
*/
int is_game_won(char **game_board, int map_row, int map_col);

/* 
   Moves the snake to a new position randomly.
   Updates the game board with the snake's new position.
*/
void move_snake_randomly(char **game_board, int rows, int cols, int player_row, int player_col);

/* 
   Creates a new game board based on the last move.
   Allocates memory for the new board, sets up borders, and places player, snake, and food.
*/
char **create_new_board(int rows, int cols, Move *last_move);

#endif /* GAME_MANAGEMENT_H */

