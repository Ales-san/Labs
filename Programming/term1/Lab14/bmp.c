#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "bmp.h"

/*void skip(FILE *fin, int n) {
	for (int i = 0; i < n; i++) {
		getc(fin);
	}
}

void print_none(FILE *fout, int n) {
	for (int i = 0; i < n; i++) {
		putc('\017', fout);
	}
}*/

BMP *readBMP(char *dir) {
	FILE *fin;
	fin = fopen(dir, "rb");
	if (fin == NULL) {
		printf("File in directory %s doesn't exist.\n", dir);
		exit(1);
	}

	BMP *file = malloc(sizeof(BMP));
	file->fileHeader = malloc(sizeof(BITMAPFILEHEADER));
	fread(file->fileHeader, sizeof(BITMAPFILEHEADER), 1, fin);
	file->infoHeader = malloc(sizeof(BITMAPINFOHEADER));
	fread(file->infoHeader, sizeof(BITMAPINFOHEADER), 1, fin);
	file->nonUsed = malloc(file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER));
	fread(file->nonUsed, file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER), 1, fin);
	//skip(fin, file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER));
	int shift = file->infoHeader->width * sizeof(BYTE) % 4;
	shift = (shift == 0 ? shift : 4 - shift);
	int size = file->infoHeader->height * file->infoHeader->width * sizeof(BYTE)
		+ file->infoHeader->height * shift * sizeof(BYTE);
	file->data = malloc(size * sizeof(BYTE));
	fread(file->data, size, 1, fin);
	fclose(fin);

	return file;
}

void writeBMP(BMP *file, char *dir, int num) {
    mkdir(dir);
    char *fileName = malloc(sizeof(char) * 100);
    fileName = strcpy(fileName, dir);
    char number[10] = {0};
    itoa(num, number, 10);
    fileName = strcat(fileName, "\\dump");
    fileName = strcat(fileName, number);
    fileName = strcat(fileName,  ".bmp");
	FILE *fout;
	fout = fopen(fileName, "wb+");
	if (fout == NULL) {
		printf("Directory %s doesn't exist.\n", fileName);
		free(fileName);
		exit(1);
	}

    FILE *checker = fopen("checker.txt", "wb+");
	fwrite(file->fileHeader, sizeof(BITMAPFILEHEADER), 1, fout);
	fwrite(file->infoHeader, sizeof(BITMAPINFOHEADER), 1, fout);
    fwrite(file->fileHeader, sizeof(BITMAPFILEHEADER), 1, checker);
    fwrite(file->infoHeader, sizeof(BITMAPINFOHEADER), 1, checker);

    fwrite(file->nonUsed, file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER), 1, fout);
    fwrite(file->nonUsed, file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER), 1, checker);

    //print_none(fout, file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER));
    //print_none(checker, file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER));

    int shift = file->infoHeader->width * sizeof(BYTE) % 4;
	shift = (shift == 0 ? shift : 4 - shift);
	int size = file->infoHeader->height * file->infoHeader->width * sizeof(BYTE)
		+ file->infoHeader->height * shift * sizeof(BYTE);

	fwrite(file->data, size, 1, checker);
	fwrite(file->data, size, 1, fout);
	free(fileName);
	fclose(fout);
	fclose(checker);
}

void printBMP(BMP *file) {
	for (int i = 0; i < file->infoHeader->height; i++) {
		for (int j = 0; j < file->infoHeader->width; j++) {
		    BYTE c = file->data[i * file->infoHeader->width + j];
			printf("%c ", file->data[i * file->infoHeader->width + j]);
		}
		printf("\n");
	}
}

BMP *copyBMP(BMP *file) {
    BMP *res = malloc(sizeof(BMP));
    res->fileHeader = malloc(sizeof(BITMAPFILEHEADER));
    memcpy(res->fileHeader, file->fileHeader, sizeof(BITMAPFILEHEADER));
    res->infoHeader = malloc(sizeof(BITMAPINFOHEADER));
    memcpy(res->infoHeader, file->infoHeader, sizeof(BITMAPINFOHEADER));
    res->nonUsed = malloc(file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER));
    memcpy(res->nonUsed, file->nonUsed, file->fileHeader->offBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER));
    int shift = file->infoHeader->width * sizeof(BYTE) % 4;
    shift = (shift == 0 ? shift : 4 - shift);
    int size = file->infoHeader->height * file->infoHeader->width * sizeof(BYTE)
               + file->infoHeader->height * shift * sizeof(BYTE);
    res->data = malloc(size);
    return res;
}

void freeBMP(BMP *file) {
    free(file->data);
    free(file->fileHeader);
    free(file->infoHeader);
    free(file->nonUsed);
    free(file);
}