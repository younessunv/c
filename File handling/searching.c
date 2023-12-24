#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int checkTextInFile(char *filename, char *textToFind);

int main() {
    char textToFind[MAX_LINE_LENGTH];
    /* HERE I CHOOSE 3 RANDOM FILES FOR EXAMPLE, IT SHOULD BE CHANGED WITH YOUR WORKING FILES*/
    char *filenames[] = {"data.txt", "data1.txt", "data2.txt"};

    printf("Insert the data looking for: ");
    fgets(textToFind, MAX_LINE_LENGTH, stdin);

    size_t len = strlen(textToFind);
    if (len > 0 && textToFind[len - 1] == '\n') {
        textToFind[len - 1] = '\0';
    }

    int foundInAnyFile = 0;

    for (int i = 0; i < sizeof(filenames) / sizeof(filenames[0]); i++) {
        int found = checkTextInFile(filenames[i], textToFind);

        if (found) {
            foundInAnyFile = 1;
            printf("\n");
        }
    }

    if (!foundInAnyFile) {
        printf("Text not found in any file\n");
    }

    return 0;
}

int checkTextInFile(char *filename, char *textToFind) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 0; // Unable to open file
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int found = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        lineNumber++;

        if (strstr(line, textToFind) != NULL) {
            found = 1;
            printf("Text found in file %s at line %d: %s", filename, lineNumber, line);
            // Don't break, continue searching in the same file
        }
    }

    fclose(file);

    return found;
}