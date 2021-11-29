#include "life.h"
#include <stdio.h>
#include <stdlib.h>

LifeGame *createGame(BMP *file) {
    LifeGame *game = malloc(sizeof(LifeGame));
    game->height = file->infoHeader->height;
    game->width = file->infoHeader->width;
    game->table = malloc(game->height * game->height * sizeof(BYTE));
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            game->table[i * game->width + j] = file->data[i * game->width + j];
        }
    }
    game->gen = 1;
}

int get_neighbours(LifeGame *game, SIZE i, SIZE j) {
    int ans = 0;
    int d[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
    for(int ni = 0; ni < 8; ni++) {
        if(i + d[ni][0] >= 0 && j + d[ni][1] >= 0 &&
                i + d[ni][0] < game->height && j + d[ni][1] < game->width
                && game->table[(i + d[ni][0]) * game->width + j + d[ni][1]] == 0) {
            ans++;
        }
    }
    return ans;
}

LifeGame *nextGen(LifeGame *game) {
    LifeGame *newGame = malloc(sizeof(LifeGame));
    newGame->height = game->height;
    newGame->width = game->width;
    newGame->table = malloc(newGame->height * newGame->width * sizeof(BYTE));
    for (int i = 0; i < newGame->height; i++) {
        for (int j = 0; j < newGame->width; j++) {
            int neighbours = get_neighbours(game, i, j);
            if(game->table[i * game->width + j] == '\017' && neighbours == 3) {
                newGame->table[i * game->width + j] = '\000';

            } else if(game->table[i * game->width + j] == '\000' && (neighbours < 2 || neighbours > 3)) {
                newGame->table[i * game->width + j] = '\017';
            } else {
                newGame->table[i * game->width + j] = game->table[i * game->width + j];
            }
        }
    }
    newGame->gen = game->gen + 1; 
    return newGame;
}

LifeGame *nextDump(LifeGame *game, SIZE freq) {
    for(int i = 0; i < freq; i++) {
        game = nextGen(game);
    }
    return game;
}

BMP *dumpGame(LifeGame *game, BMP *file) {
    BMP *res = copyBMP(file);
    int shift = file->infoHeader->width * sizeof(BYTE) % 4;
    shift = (shift == 0 ? shift : 4 - shift);
    for(int i = 0; i < game->height; i++) {
        for(int j = 0; j < game->width; j++) {
            int t = game->table[i * game->width + j];
            res->data[i * game->width + j + i * shift] = game->table[i * game->width + j];
        }
    }
    return res;
}

void freeGame(LifeGame *game) {
    free(game->table);
    free(game);
}