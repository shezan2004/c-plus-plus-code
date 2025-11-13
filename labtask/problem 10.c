#include <stdio.h>

int main() {
    char str[100], clean[100];
    int i = 0, j = 0;
    char ch;

    printf("Enter a string: ");
    
    while ((ch = getchar()) != '\n') {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
    i = 0;
    while (str[i] != '\0') {
        ch = str[i];
        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9') ||
            (ch == ' ')) {
            clean[j] = ch;
            j++;
        }
        i++;
    }
    clean[j] = '\0';
    printf("String without special characters: %s\n", clean);
    return 0;
}
