#include <stdio.h>

int main() {
    char ch;
    int lineCount = 0;

    printf("Enter multiple lines of text (Press Ctrl + Z then Enter to end on Windows):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }

    printf("Number of lines entered: %d\n", lineCount);

    return 0;
}
