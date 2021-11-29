#include <stdio.h>
#include <string.h>

#include "arc.h"

int main(int argc, char *argv[]) {
    char *archiveName = "";
    for (int i = 0; i < argc; i++) {
        if (!strcmp("--file", argv[i])) {
            archiveName = argv[i + 1];
        }
        if (!strcmp("--create", argv[i])) {
            create(archiveName, argc, argv);
            break;
        }
        if (!strcmp("--extract", argv[i])) {
            extract(archiveName);
        }
        if (!strcmp("--list", argv[i])) {
            list(archiveName);
        }
    }
    return 0;
}
