#ifndef GAME_INIT_H
#define GAME_INIT_H

#include <stdio.h>
#include <stdlib.h>

/* 
   Struct to represent a move in the game. 
   Contains current and previous positions of the player, snake, and food.
   Also includes types for the player and snake.
*/
typedef struct {
    int player_row;
    int player_col;
    int prev_player_row;
    int prev_player_col;
    char player_type;
    int snake_row;
    int snake_col;
    int prev_snake_row;
    int prev_snake_col;
    char snake_type;
    int food_row;  
    int food_col;
} Move;

/* 
   Struct for a node in a linked list.
   Contains data of type void* and a pointer to the next node.
*/
typedef struct ListNode {
    void *data;
    struct ListNode *next;
} ListNode;

/* 
   Struct for a linked list.
   Contains a pointer to the head node of the list.
*/
typedef struct {
    ListNode *head;
} LinkedList;

/* 
   Struct representing the game state.
   Contains the game board (2D array), dimensions of the map, and a linked list of moves.
*/
typedef struct {
    char **game_board; // ptr to ptr of char used to represent 2d arracy of chars
					   // this is where map is stored 
    int map_row;  
    int map_col;  
    LinkedList *moves; // moves is a ptr to linked list  
} GameState;

/* Linked List Functions */

/* 
   Creates a new linked list.
   Allocates memory for the list and initializes its head to NULL.
*/
LinkedList *createLinkedList(void);

/* 
   Frees the memory used by the linked list.
   Iterates through the list and frees each node and its data.
*/
void freeLinkedList(LinkedList *list);

/* 
   Checks if the linked list is empty.
   Returns 1 if the list is empty, otherwise 0.
*/
int isEmpty(LinkedList *list);

/* 
   Inserts a new data item at the start of the linked list.
   Allocates memory for the new node and updates the head pointer.
*/
void insertStart(LinkedList *list, void *data);

/* 
   Removes and returns the data from the start of the linked list.
   Updates the head pointer and frees the old head node.
*/
void *removeStart(LinkedList *list);

/* 
   Retrieves the last node in the linked list.
   Returns a pointer to the last node or NULL if the list is empty.
*/
ListNode *getLast(LinkedList *list);

/* Game Board Functions */

/* 
   Creates a game board from a file.
   Allocates memory for the board, initializes it based on file contents, and sets borders.
*/
char **create_game_board(const char *filename);

/* 
   Prints the game board to the console.
   Displays the board with its current state, including borders.
*/
void print_game_board(char **game_board, int map_row, int map_col);

/* 
   Frees the memory allocated for the game board.
   Iterates through the rows and frees each row, then frees the board itself.
*/
void free_game_board(char **board, int rows);

/* Game Initialization Functions */

/* 
   Initializes the game state from a file.
   Allocates memory for the GameState struct, creates the game board, and initializes the linked list of moves.
*/
GameState *game_init(const char *filename);

/* 
   Frees the memory used by the game state.
   Calls functions to free the game board and the linked list of moves, then frees the GameState struct.
*/
void game_free(GameState *game);

/* 
   Reads the map dimensions (rows and columns) from a file.
   Stores the dimensions in the provided pointers and returns 0 on success or -1 on error.
*/
int read_map_dimensions(const char *filename, int *rows, int *cols);

/* Undo Function */

/* 
   Undoes the last move by restoring the previous game state.
   Updates the game board and dimensions based on the last move stored in the linked list.
*/
void undo_move(LinkedList *list, char ***game_board, int *rows, int *cols);


#endif /* GAME_INIT_H */
