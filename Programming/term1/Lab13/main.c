#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE (10)

typedef union TAGHEADER {

    char buffer[HEADER_SIZE];

    struct {
        unsigned char id[3];
        unsigned char ver[2];
        unsigned char flags;
        unsigned int size;
    } data;
} TagHeader;

typedef union FRAMEHEADER {
    char buffer[HEADER_SIZE];

    struct {
        unsigned char name[4];
        unsigned int size;
        unsigned char flags[2];
    } data;
} FrameHeader;

unsigned int get_size(unsigned int a) {
    return (((a << 24) & 0xff000000) |
            ((a <<  8) & 0x00ff0000) |
            ((a >>  8) & 0x0000ff00) |
            ((a >> 24) & 0x000000ff));
}

void common(unsigned char *framename, unsigned char *filename, int isGet) {
    FILE* fin;
    fin = fopen(filename, "rb");
    if(fin == NULL) {
        printf("File not found!\n");
        return;
    }

    TagHeader tagHeader;
    fread(tagHeader.buffer, sizeof(char), HEADER_SIZE, fin);
    tagHeader.data.size = get_size(tagHeader.data.size);
    if(isGet == -1) { //--show
        printf("%c%c%cv2.%d.%d\n", tagHeader.data.id[0], tagHeader.data.id[1], tagHeader.data.id[2],
               tagHeader.data.ver[0], tagHeader.data.ver[1]);
    }

    while (ftell(fin) < tagHeader.data.size + HEADER_SIZE) {
        FrameHeader frameHeader;
        fread(frameHeader.buffer, sizeof(char), HEADER_SIZE, fin);
        if(frameHeader.data.name[0] == 0) {
            continue;
        }
        frameHeader.data.size = get_size(frameHeader.data.size);

        if((frameHeader.data.name[0] == 'T' && isGet == -1) || //--show
                (frameHeader.data.name[0] == framename[0] &&
                        frameHeader.data.name[1] == framename[1] &&
                        frameHeader.data.name[2] == framename[2] &&
                        frameHeader.data.name[3] == framename[3] && isGet != -1)) { //--get
            unsigned char *data = malloc(frameHeader.data.size * sizeof(char));
            fread(data, sizeof(char), frameHeader.data.size, fin);
            printf("%c%c%c%c: ", frameHeader.data.name[0], frameHeader.data.name[1], frameHeader.data.name[2], frameHeader.data.name[3]);
            for(int i = 0; i < frameHeader.data.size; i++) {
                printf("%c", data[i]);
            }
            printf("\n");
            free(data);
            if(isGet != -1) { //--get
                fclose(fin);
                return;
            }
        } else {
            fseek(fin, frameHeader.data.size, SEEK_CUR);
        }

    }
    if(isGet != -1) { //--get
        printf("There is no field with that name.\n");
    }
    fclose(fin);
}

void show(char *filename) {
    common("nothing", filename, -1);
}

void get(char *framename, char *filename) {
   common(framename, filename, 1);
}

void set(char *framename, char *value, char *filename) {
    FILE *fin;
    fin = fopen(filename, "rb");
    if (fin == NULL) {
        printf("File not found!\n");
        return;
    }

    TagHeader tagHeader;
    fread(tagHeader.buffer, sizeof(char), HEADER_SIZE, fin);
    tagHeader.data.size = get_size(tagHeader.data.size);

    int oldPos = 0;
    int oldSize = 0;
    while (ftell(fin) < tagHeader.data.size + HEADER_SIZE) {
        FrameHeader frameHeader;
        fread(frameHeader.buffer, sizeof(char), HEADER_SIZE, fin);
        if (frameHeader.data.name[0] == 0) {
            continue;
        }
        frameHeader.data.size = get_size(frameHeader.data.size);
        if (frameHeader.data.name[0] == framename[0] &&
            frameHeader.data.name[1] == framename[1] &&
            frameHeader.data.name[2] == framename[2] &&
            frameHeader.data.name[3] == framename[3]) {
            oldPos = ftell(fin) - HEADER_SIZE;
            oldSize = frameHeader.data.size;
            break;
        } else {
            fseek(fin, frameHeader.data.size, SEEK_CUR);
        }
    }

    int valueSize = strlen(value);
    int newSize = tagHeader.data.size - oldSize + valueSize + HEADER_SIZE;

    int flag = -1;
    if (oldPos == 0) {
        flag = 1;
        oldPos = ftell(fin);
        newSize -= HEADER_SIZE;
    } else if(valueSize == 0) {
        newSize -= HEADER_SIZE;
    }

    FILE *copyFile = fopen("temp.txt", "wb");
    fseek(fin, 0, SEEK_SET);

    int c;
    while((c = getc(fin)) != EOF) {
        putc(c, copyFile);
    }

    fclose(copyFile);
    fclose(fin);

    copyFile = fopen("temp.txt", "rb");
    FILE *fout = fopen(filename, "wb");

    tagHeader.data.size = get_size(newSize);
    fwrite(tagHeader.buffer, sizeof(char), HEADER_SIZE, fout);
    fseek(copyFile, HEADER_SIZE, SEEK_SET);

    for(int i = ftell(copyFile); i < oldPos; i++) {
        putc(getc(copyFile), fout);
    }

    FrameHeader frameHeader;
    for (unsigned int i = 0; i < 4; ++i) {
        frameHeader.data.name[i] = framename[i];
    }
    frameHeader.data.size = get_size(valueSize);
    frameHeader.data.flags[0] = 0;
    frameHeader.data.flags[1] = 0;
    fwrite(frameHeader.buffer, sizeof(char), HEADER_SIZE, fout);

    fwrite(value, sizeof(char), valueSize, fout);

    if(flag == 1) {
        fseek(copyFile, oldPos + HEADER_SIZE + oldSize, SEEK_SET);
    } else {
        fseek(copyFile, oldPos, SEEK_SET);
    }

    while((c = getc(copyFile)) != EOF) {
        putc(c, fout);
    }

    printf("%s: %s\n", framename, value);

    fclose(fout);
    fclose(copyFile);
    remove("temp.txt");
}

int main(int argc, char *argv[]) {
    char *filename = strpbrk(argv[1], "=") + 1;
    if(argv[2][3] == 'h') {
        show(filename);
    } else if (argv[2][2] == 'g') {
        get(strpbrk(argv[2], "=") + 1, filename);
    } else {
        set(strpbrk(argv[2], "=") + 1, strpbrk(argv[3], "=") + 1, filename);
    }
    return 0;
}
