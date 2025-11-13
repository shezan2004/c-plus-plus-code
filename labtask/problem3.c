#include <stdio.h>

int main() {
    char str[100], newStr[100];
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
        if (str[i] != ' ') {
            newStr[j] = str[i];
            j++;
        }
        i++;
    }
    newStr[j] = '\0';       

    printf("String without spaces: %s\n", newStr);

    return 0;
}

