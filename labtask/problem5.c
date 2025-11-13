#include <stdio.h>
int main() {
    char str[100], result[100];
    int i = 0, j = 0, k;
    int isDuplicate;
    printf("Enter a string: ");
    while ((str[i] = getchar()) != '\n') {
        i++;
    }
    str[i] = '\0';  
    i = 0;
    while (str[i] != '\0') {
        isDuplicate = 0;
        for (k = 0; k < j; k++) {
            if (str[i] == result[k]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate == 0) {
            result[j] = str[i];
            j++;
        }
        i++;
    }
    result[j] = '\0';  
    printf("String after removing duplicates: %s\n", result);
    return 0;
}
