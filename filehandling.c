#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char *filename) {
    FILE *fp = fopen(filename, "w"); // "w" mode overwrites existing content
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fp, "Hello, this is the first line written to the file.\n");
    fprintf(fp, "This file will demonstrate write, append, and read operations.\n");
    fclose(fp);
    printf("File written successfully.\n");
}

void appendToFile(const char *filename) {
    FILE *fp = fopen(filename, "a"); // "a" mode appends content
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }
    fprintf(fp, "Appended line: This content was added later.\n");
    fclose(fp);
    printf("File appended successfully.\n");
}

void readFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r"); // "r" mode reads content
    char ch;
    
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("\nFile Content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    const char *filename = "example.txt";

    // Step 1: Create and Write to file
    writeToFile(filename);

    // Step 2: Append to file
    appendToFile(filename);

    // Step 3: Read from file
    readFromFile(filename);

    return 0;
}
