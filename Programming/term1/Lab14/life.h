#include "bmp.h"

#ifndef LIFE_H
#define LIFE_H
typedef unsigned char  BYTE;
typedef unsigned int   SIZE;

typedef struct LIFEGAMESTRUCT {
    BYTE *table;
    SIZE width;
    SIZE height;
    SIZE gen;
} LifeGame;

LifeGame *createGame(BMP *file);
LifeGame *nextGen(LifeGame *game);
LifeGame *nextDump(LifeGame *game, SIZE freq);
BMP *dumpGame(LifeGame *game, BMP *file);
void freeGame(LifeGame *game);

#endif