#include "stdlib.h"
#include "stdio.h"

void create(char *archiveName, int filecount, char *files[]) {
    FILE *archive = fopen(archiveName, "wb");
    for (int i = 4; i < filecount; i++) {
        FILE *file = fopen(files[i], "rb");
        if (file == NULL) {
            printf("File %s not found\n", files[i]);
            continue;
        }
        fseek(file, 0, SEEK_END);
        fprintf(archive, "[%s %lu]", files[i], ftell(file));
        fclose(file);
    }
    fprintf(archive, "\n");
    for (int i = 4; i < filecount; i++) {
        FILE *file = fopen(files[i], "rb");
        if (file != NULL) {
            int temp;
            while ((temp = getc(file)) != EOF) {
                putc(temp, archive);
            }
            fclose(file);
            printf("File %s added\n", files[i]);
        }
    }
    printf("Packing complete\n");
    fclose(archive);
}

void extract(char *archiveName) {
    FILE *archive = fopen(archiveName, "rb");
    if (archive == NULL) {
        printf("Archive not found");
        return;
    }
    unsigned long long int curPosition = 0;
    unsigned long long int text = 0;
    int c = getc(archive);
    while (c != '\n') {
        if (c == EOF) {
            printf("Archive is empty");
            return;
        }
        text++;
        c = getc(archive);
    }
    text++;
    fseek(archive, 0, SEEK_SET);
    char fileName[256] = {0};
    unsigned long fileSize;
    FILE *file;
    while (fscanf(archive, "[%s %lu]", fileName, &fileSize) != 0) {
        file = fopen(fileName, "wb");
        if (file == NULL) {
            printf("write error");
            break;
        }
        curPosition = ftell(archive);
        fseek(archive, text, SEEK_SET);
        text += fileSize;
        while (fileSize-- > 0)
            putc(getc(archive), file);
        fseek(archive, curPosition, SEEK_SET);
        fclose(file);
    }
    printf("Unpacking completed\n");
}

void list(char *archiveName) {
    FILE *archive = fopen(archiveName, "rb");
    if (archive == NULL) {
        printf("Archive not found");
        return;
    }
    char fileName[256] = {0};
    //unsigned long int  size;
    printf("File list:\n");
    while (fscanf(archive, "[%s %lu]", fileName) > 0) {
        printf("%s\n", fileName);
    }
    fclose(archive);
}
