#include <stdio.h>
int is_space(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t';
}

char to_lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}
int is_article(char word[]) {
    char w[4];
    int i = 0;
    while (word[i] != '\0') {
        w[i] = to_lower(word[i]);
        i++;
    }
    w[i] = '\0';

    if ((w[0] == 'a' && w[1] == '\0') ||
        (w[0] == 'a' && w[1] == 'n' && w[2] == '\0') ||
        (w[0] == 't' && w[1] == 'h' && w[2] == 'e' && w[3] == '\0')) {
        return 1;
    }
    return 0;
}
int main() {
    char ch, word[20];
    int i = 0, count = 0;

    printf("Enter a string: ");

    while ((ch = getchar()) != '\n') {
        if (!is_space(ch)) {
            word[i] = ch;
            i++;
        } else {
            word[i] = '\0';
            if (i > 0 && is_article(word)) {
                count++;
            }
            i = 0;
        }
    }
    word[i] = '\0';
    if (i > 0 && is_article(word)) {
        count++;
    }
    printf("Number of articles (a, an, the): %d\n", count);
    return 0;
}
