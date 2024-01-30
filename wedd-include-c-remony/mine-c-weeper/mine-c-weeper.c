//
//  main.c
//  mine-c-weeper
//
//  Created by Cristian Ornelas on 4/21/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "io-utilities.h"
#include "mine-c-weeper.h"

#define BUFFER_SIZE 1024
#define MAX_PROBABILITY 100

#define OPEN_CHAR '.'
#define WEEPER_CHAR 'W'

// ***** IMPLEMENT ME! *****
/**
 * Allocates the memory required for a game with the given dimensions, and sets those dimensions
 * in the resulting game structures `width` and `height` fields.
 *
 * In particular, sufficient memory should be allocated for:
 * - The `mcw_game` structure
 * - The two-dimensional `field` array of square contents (`open` or `weeper`)
 * - The two-dimensional `status` array reflecting the player’s progress
 *   (squares start out `hidden` then are either `revealed` or `flagged` as the game progresses)
 *
 * This function is given enough information to allocate memory _precisely_—no more and no less
 * than required. The implementation must reflect this precision.
 *
 * This function is only supposed to _allocate_ memory for the game, not initialize its squares.
 * Aside from memory, the only other values that this function should set are the `width` and
 * `height` of the game, as indicated by the function arguments.
 *
 * Excessively large hard-coded memory allocations will incur large deductions even if they
 * produce a functional game.
 *
 * You can use the given `initialize_random_game` and `initialize_file_game` functions as
 * references for how a correctly-allocated game structure and arrays will be used.
 */
mcw_game* alloc_game(int width, int height) {
    
    mcw_game *game = (mcw_game *) malloc(sizeof(mcw_game));
    
    game->width = width;
    game->height = height;
    
    game->field = (mcw_square **) malloc(sizeof(mcw_square *) * height);
    
    if (game->field == NULL){
        return NULL;
    }
    
    for(int i=0;i<height;i++){
        game->field[i] = (mcw_square *) malloc(sizeof(mcw_square) * width);
        if (game->field[i] == NULL){
            return NULL;
        }
    }
    
    game->status = (mcw_status **) malloc(sizeof(mcw_status *) * height);
    if (game->status == NULL){
        return NULL;
    }
    for(int i=0;i<height;i++){
        game->status[i] = (mcw_status *) malloc(sizeof(mcw_status) * width);
        if (game->status[i] == NULL){
            return NULL;
        }
    }
    
    return game;
}

// ***** IMPLEMENT ME! *****
void free_game(mcw_game *game) {
    int height = game->height;
 
    for(int i=0;i<height;i++){
        free(game->field[i]);
        game->field[i] = NULL;
    }
    
    free(game->field);
    game->field = NULL;
    

    for(int i=0;i<height;i++){
        free(game->status[i]);
        game->status[i] = NULL;
    }
    
    free(game->status);
    game->status = NULL;
    
    return;
}

// ***** IMPLEMENT ME! *****
void show_all(mcw_game* game) {
    int height = game->height;
    int width = game->width;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            game->status[i][j] = 1;
        }
    }
    
    return;
}

// ***** IMPLEMENT ME! *****
// This isn’t a “public” function but is used by the initialize functions.
// If you can implement `show_all`, then `hide_all` won’t be that far behind.
// You can even write a helper function (hint hint) that would make these functions
// one-liners.
void hide_all(mcw_game* game) {

    int height = game->height;
    int width = game->width;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            game->status[i][j] = hidden;
        }
        printf("\n");
    }
    
    return;
}

// The initialization functions have been written for you, but note they will not work
// until `alloc_game` has been implemented.
mcw_game* initialize_random_game(int width, int height, int probability) {
    mcw_game* game = alloc_game(width, height);
    if (game == NULL) {
        return NULL;
    }

    int threshold = probability > MAX_PROBABILITY ? MAX_PROBABILITY : probability;

    int x, y;
    for (y = 0; y < game->height; y++) {
        for (x = 0; x < game->width; x++) {
            int mine_roll = random() % MAX_PROBABILITY;
            game->field[y][x] = mine_roll < threshold ? weeper : open;
        }
    }
    
    return game;
}

mcw_game* initialize_file_game(char* filename) {
    FILE* game_file = fopen(filename, "r");
    if (!game_file) {
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    mcw_game* game = NULL;
    int y = 0;
    while (!feof(game_file)) {
        fgets(buffer, BUFFER_SIZE, game_file);
        if (game == NULL) {
            int width;
            int height;
            int successful_scans = sscanf(buffer, "%d %d", &width, &height);
            if (successful_scans < 2) {
                fclose(game_file);
                return NULL;
            } else {
                game = alloc_game(width, height);
                if (game == NULL) {
                    fclose(game_file);
                    return NULL;
                }
            }
        } else {
            if (y >= game->height) {
                break;
            }

            int x;
            for (x = 0; x < game->width; x++) {
                if (buffer[x] == OPEN_CHAR || buffer[x] == WEEPER_CHAR) {
                    game->field[y][x] = buffer[x] == OPEN_CHAR ? open : weeper;
                } else {
                    fclose(game_file);
                    return NULL;
                }
            }

            y++;
        }
    }

    fclose(game_file);
    return game;
}

// Don’t hesitate to write helper functions for yourself when implementing the “public” functions.
// They will reduce code duplication and, with good names, they will make your code more readable.

// ***** IMPLEMENT ME! *****
void display_game_field(mcw_game* game) {
    int height = game->height;
    int width = game->width;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(game->field[i][j] == 0){
                printf("%d",get_adjacent_weeper_count(game,j,i));
                printf(" ");
            }
            if(game->field[i][j] == 1){
                emit_utf_8(WEEPER);
                printf(" ");
            }
            
        }
        printf("\n");
    }
    return ;
}

// ***** IMPLEMENT ME! *****
int get_weeper_count(mcw_game* game) {
    int height = game->height;
    int width = game->width;
    int count = 0;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(game->field[i][j]==1){
                count++;
        }
    }
    }
    return count;
}

// ***** IMPLEMENT ME! *****
int get_flag_count(mcw_game* game) {
    int height = game->height;
        int width = game->width;
        int count = 0;
        
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(game->status[i][j]==2){
                    count++;
            }
        }
        }
        return count;
}

// ***** IMPLEMENT ME! *****
int get_adjacent_weeper_count(mcw_game* game, int x, int y) {
    int height = game->height;
    int width = game->width;
    int weeper_count = 0;

    if((x < width && x>= 0) && (y < height && y>=0)){
        if (y-1 >= 0 && x-1 >= 0 && game->field[y-1][x-1] == 1){
            weeper_count++;
        }
        if (y-1 >= 0 && x+1 < width &&game->field[y-1][x+1] == 1){
            weeper_count++;
        }
        if (y+1 < height && x-1 >= 0 && game->field[y+1][x-1] == 1){
        weeper_count++;
        }
        if (x+1 < width && y+1 < height && game->field[y+1][x+1] == 1){
        weeper_count++;
        }
        if (y-1 >= 0 && game->field[y-1][x] == 1){
            weeper_count++;
        }
        if (x-1 >= 0 && game->field[y][x-1] == 1){
            weeper_count++;
        }
        if (y+1 < height && game->field[y+1][x] == 1){
        weeper_count++;
            
        }
        if (x+1 < width && game->field[y][x+1] == 1){
        weeper_count++;
        }
    }
        return weeper_count;
}

// ***** IMPLEMENT ME! *****
void display_game_state(mcw_game* game) {
    int height = game->height;
    int width = game->width;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(game->status[i][j] == 0){
                emit_utf_8(HIDDEN);
                printf(" ");
            }
            if(game->status[i][j] == 1){
                if(game->field[i][j] == 0){
                    printf("%d",get_adjacent_weeper_count(game,j,i));
                }else{
                    emit_utf_8(WEEPER);
                }
                printf(" ");
            }
            if(game->status[i][j] == 2){
                emit_utf_8(MARKER);
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return ;
}

// ***** IMPLEMENT ME! *****
bool is_in_game_bounds(mcw_game* game, int x, int y) {
    int height = game->height;
    int width = game->width;
    
    if ((x < width && x>=0) && (y<height && y>=0)){
        return true;
    }
    return false;
}

// ***** IMPLEMENT ME! *****
void mark_game_square(mcw_game* game, int x, int y) {
    int height = game->height;
    int width = game->width;
    
    if ((x < width && x>=0) && (y<height && y>=0)){
        if(game->status[y][x] == 2){
            game->status[y][x] = 0;
        } else {
            game->status[y][x] = 2;
        }
    }
}

// ***** IMPLEMENT ME! *****
void reveal_game_square(mcw_game* game, int x, int y) {
int height = game->height;
    int width = game->width;

        if((x < width && x>= 0) && (y < height && y>=0) && game->status[y][x] == 0){
            game->status[y][x] = 1; // Revealed
            
            
            if (y-1 >= 0 && x-1 >= 0 && game->status[y-1][x-1] == 0 && game->field[y-1][x-1] == 0 ){
                game->status[y-1][x-1] = 1; // Revealed
            }
            if (y-1 >= 0 && x+1 < width && game->status[y-1][x+1] == 0 && game->field[y-1][x+1] == 0){
                game->status[y-1][x+1] = 1;
            }
            if (y+1 < height && x-1 >= 0 && game->status[y+1][x-1] == 0 && game->field[y+1][x-1] == 0){
                game->status[y+1][x-1] = 1;
            }
            if (x+1 < width && y+1 < height && game->status[y+1][x+1] == 0 && game->field[y+1][x+1] == 0){
                game->status[y+1][x+1] = 1;
            }
            if (y-1 >= 0 && game->status[y-1][x] == 0 && game->field[y-1][x] == 0){
               game->status[y-1][x] = 1;
            }
            if (x-1 >= 0 && game->status[y][x-1] == 0 && game->field[y][x-1] == 0){
                game->status[y][x-1] = 1;
            }
            if (y+1 < height && game->status[y+1][x] == 0 && game->field[y+1][x] == 0){
                game->status[y+1][x] = 1;
            }
            if (x+1 < width && game->status[y][x+1] == 0 && game->field[y][x+1] == 0){
                game->status[y][x+1] = 1;
            }
        }
}

// ***** IMPLEMENT ME! *****
bool is_game_over_loss(mcw_game* game) {
    int height = game->height;
    int width = game->width;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if((game->status[i][j] == 1) && (game->field[i][j] == 1)){
                return true;
            }
        }
            
    }
            return false;
}

// ***** IMPLEMENT ME! *****

bool is_game_over_win(mcw_game* game) {
 int height = game->height;
 int width = game->width;
 bool flag = false;

 for(int i=0;i<height;i++){
     for(int j=0;j<width;j++){
         if(game->status[i][j] == 2){

             if(game->field[i][j] == 1){

                  for(int k=0;k<height;k++){
                    for(int l=0;l<width;l++){

                        if (k == i && l == j){
                            continue;
                        }else if(game->status[k][l] == 1 || game->status[k][l] == 2){
                            flag = true;
                        }else{
                            return false;
                        }
                    }
                  }
             } else {
                 return false;
             }
         }
     }

 }
    return flag;
}
//bool is_game_over_win(mcw_game* game) {
// int height = game->height;
// int width = game->width;
// bool flag = false;
//
// for(int i=0;i<height;i++){
//     for(int j=0;j<width;j++){
//         if(game->status[i][j] == 2){
//
//             if(game->field[i][j] == 1){
//
//                  for(int k=0;k<height;k++){
//                    for(int l=0;l<width;l++){
//
//                        if (k == i && l == j){
//                            continue;
//                        }else if(game->status[k][l] == 1){
//                            flag = true;
//                        }else{
//                            return false;
//                        }
//                    }
//                  }
//             } else {
//                 return false;
//             }
//         }
//     }
//
// }
//    return flag;
//}
//
//
