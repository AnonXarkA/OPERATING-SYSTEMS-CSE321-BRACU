#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_STRING_LENGTH 100


void getFile_fromCommand(char *filename, int argc, char *argv[]) {
    if (argc < 2) {
        exit(1);
    }
    strcpy(filename, argv[1]);
}


FILE *openFile(char *filename) {
    FILE *filePointer = fopen(filename, "w");
    if (filePointer == NULL) {
        printf("Unable to open %s.\n", filename);
        exit(1);
    }
    return filePointer;
}


void input_string(FILE *filePointer) {
    char userInput[MAX_STRING_LENGTH];
    printf("To quit Enter '-1' \n");
    printf("Enter string:\n");
    scanf("%s", userInput);
    while (strcmp(userInput, "-1") != 0) {
        fprintf(filePointer, "%s\n", userInput);
        printf("Enter another string: \n");
        scanf("%s", userInput);
    }
}

int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LENGTH];
    getFile_fromCommand(filename, argc, argv);
    FILE *filePointer = openFile(filename);
    input_string(filePointer);
    fclose(filePointer);
    printf("String has been written to %s.\n", filename);
    return 0;
}

