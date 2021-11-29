#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bmp.h"
#include "life.h"

void is_ok(int a, int b) {
	if (a > b) {
		printf("Program has no arguments!\n");
		exit(1);
	}
}

int main(int argc, char *argv[]) {
	char *fileName = "";
	char *output;
	int N = 100;
	int freq = 1;
	is_ok(2, argc);
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "--input")) {
			is_ok(i + 1, argc);
			fileName = argv[i + 1];
			continue;
		}
		if (!strcmp(argv[i], "--output")) {
			is_ok(i + 1, argc);
			output = argv[i + 1];
			continue;
		}
		if (!strcmp(argv[i], "--max_iter")) {
			is_ok(i + 1, argc);
			N = atoi(argv[i + 1]);
			continue;
		}
		if (!strcmp(argv[i], "--dump_freq")) {
			is_ok(i + 1, argc);
			freq = atoi(argv[i + 1]);
			continue;
		}
	}

	BMP *file = readBMP(fileName);

	LifeGame *game = createGame(file);
    printf("Current generation is %d.\n", game->gen);
    writeBMP(file, output, game->gen);
    //printBMP(file);

    while(game->gen < N) {
        game = nextDump(game, freq);
        BMP *temp = dumpGame(game, file);
        printf("Current generation is %d.\n", game->gen);
        //printBMP(temp);
        writeBMP(temp, output, game->gen);
        freeBMP(temp);
    }
	//printBMP(file);
    freeGame(game);
	freeBMP(file);

    /*FILE *fin = fopen(fileName, "rb");
    int c;
    while((c = getc(fin)) != EOF) {
        printf("%d ", c);
    }*/

}