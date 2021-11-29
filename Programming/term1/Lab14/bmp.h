#ifndef BMP_H
#define BMP_H
#pragma pack(push, 1)

typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned long  DWORD;
typedef long		   LONG;

typedef struct BITMAPFILEHEADERSTRUCT {
	WORD type;		//big-endian/little-endian
	DWORD size;		//size in bytes
	WORD reserved1; //reserved for 0
	WORD reserved2; //reserved for 0
	DWORD offBits;	//pixel data from beginning
} BITMAPFILEHEADER;

typedef struct BITMAPINFOSTRUCT {
	DWORD size;			//size in bytes
	LONG width;			//should be positive - width
	LONG height;		//abs is real height in pixels, sign is the strings order
	WORD planes;		//should be 1
	WORD bitCount;		//bit per pixel
	DWORD compression;	//how pixels are saved
	DWORD sizeImage;	//size of pixel data in bytes
	LONG xPelsPerMeter; //pixels per horisontal
	LONG yPelsPerMeter; //pixels per vertical
	DWORD clrUsed;		//size of color table
	DWORD clrImportant; //cells from beginning of color table to last used
} BITMAPINFOHEADER;

typedef struct BMPSTRUCT {
	BITMAPFILEHEADER *fileHeader;
	BITMAPINFOHEADER *infoHeader;
	BYTE *nonUsed;
	BYTE *data;
} BMP;
#pragma pack(pop)

BMP *readBMP(char *dir);
BMP *copyBMP(BMP *file);
void writeBMP(BMP *file, char *dir, int num);
void printBMP(BMP *file);
void freeBMP(BMP *file);
#endif


