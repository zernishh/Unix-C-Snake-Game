
/*
   Scope and Goal:
   This file contains the main function for my snake game. The file
   initializes a game board (the map) based on user-provided dimensions,
   and allows the user to control player character 'P' to avoid snake symbol '~'
   and collect food symbol '@', and displays game over messages based on game outcome.
   Implements other source files (as included)

   Author: Zernish Shahid Nazir
   Student ID: 21848838
*/

#include <stdio.h>
#include <stdlib.h>
#include "game_init.h"
#include "game_management.h"

#define PLAYER_SYMBOL 'P'
#define SNAKE_SYMBOL '~'
#define FOOD_SYMBOL '@'

int main(int argc, char *argv[]) {
    char *mapFile;
    int rows, cols;
    char input;
    GameState *game;
    LinkedList *undoList;
    int exit_code = 0;

    /* Argument validation */
    if (argc != 2) {
        printf("Usage: %s <map_file>\n", argv[0]);
        exit_code = 1;
    } else {
        mapFile = argv[1];

        /* File reading and dimension validation */
        if (read_map_dimensions(mapFile, &rows, &cols) != 0) {
            fprintf(stderr, "Error reading dimensions from file %s\n", mapFile);
            exit_code = 1;
        } else if (rows <= 0 || cols <= 0 || rows < 5 || cols < 5) {
            fprintf(stderr, "Invalid dimensions read from file\n");
            exit_code = 1;
        } else {
            /* Game initialization */
            game = game_init(mapFile);
            if (game == NULL) {
                fprintf(stderr, "Error: Failed to initialize game.\n");
                exit_code = 1;
            } else {
                /* Undo system setup */
                undoList = createLinkedList();
                if (undoList == NULL) {
                    fprintf(stderr, "Error: Failed to create undo list.\n");
                    game_free(game);
                    exit_code = 1;
                } else {
                    /* [CORE GAME LOOP REMOVED FOR ACADEMIC INTEGRITY] */
          
                    /* Memory cleanup */
                    freeLinkedList(undoList);
                }
                game_free(game);
            }
        }
    }
    return exit_code;
}
