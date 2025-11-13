#include <stdio.h>

int main() {
    char str[200], words[50][50];
    int count[50] = {0};
    int i = 0, j = 0, k = 0;

    printf("Enter a string: ");
    while ((str[i] = getchar()) != '\n') {
        i++;
    }
    str[i] = '\0';
    i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            words[k][j] = str[i];
            j++;
        } else {
            words[k][j] = '\0';
            k++;
            j = 0;
        }
        i++;
    }
    words[k][j] = '\0';
    int totalWords = k + 1;
    for (i = 0; i < totalWords; i++) {
        if (words[i][0] == '\0') continue;
        count[i] = 1;

        for (j = i + 1; j < totalWords; j++) {
            int same = 1;
            int a = 0;
            while (words[i][a] != '\0' || words[j][a] != '\0') {
                if (words[i][a] != words[j][a]) {
                    same = 0;
                    break;
                }
                a++;
            }

            if (same) {
                count[i]++;
                words[j][0] = '\0'; 
            }
        }
    }
    printf("\nUnique words and their frequencies:\n");
    for (i = 0; i < totalWords; i++) {
        if (words[i][0] != '\0') {
            printf("%s: %d\n", words[i], count[i]);
        }
    }

    return 0;
}
