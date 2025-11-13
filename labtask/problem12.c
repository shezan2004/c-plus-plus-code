#include <stdio.h>
int main() {
    char str[200], words[50][50];
    int i = 0, j = 0, k = 0;
    int count[50] = {0};
    int max = 0, maxIndex = 0;

    printf("Enter a string: ");
    while ((str[i] = getchar()) != '\n') {
        i++;
    }
    str[i] = '\0';

    i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\n') {
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
    int wordCount = k + 1;

    for (i = 0; i < wordCount; i++) {
        count[i] = 1;
        for (j = i + 1; j < wordCount; j++) {
            int same = 1;
            for (int x = 0; words[i][x] != '\0' || words[j][x] != '\0'; x++) {
                if (words[i][x] != words[j][x]) {
                    same = 0;
                    break;
                }
            }
            if (same) {
                count[i]++;
                for (int x = 0; words[j][x] != '\0'; x++) {
                    words[j][x] = '\0';  // Mark as counted
                }
            }
        }
    }
    for (i = 0; i < wordCount; i++) {
        if (count[i] > max && words[i][0] != '\0') {
            max = count[i];
            maxIndex = i;
        }
    }
    printf("Most frequent word: %s\n", words[maxIndex]);
    printf("Frequency: %d\n", max);
    return 0;
}
