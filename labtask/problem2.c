#include <stdio.h>

int main() {
    char str[100];
    int i = 0;
    int spaceCount = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); 

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == ' ') {
            spaceCount = spaceCount + 1;  // count space
        }
        i = i + 1;
    }

    printf("Number of spaces in the string: %d\n", spaceCount);

    return 0;
}

