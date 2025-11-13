#include <stdio.h>
int main() {
    char str[100];
    int i = 0, count = 0;
    char ch;
    printf("Enter a string: ");

    while ((ch = getchar()) != '\n') {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
    i = 0;
    while (str[i] != '\0') {
        char c = str[i];

        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count = count + 1;
        }
        i = i + 1;
    }
    printf("Number of vowels: %d\n", count);
    return 0;
}
