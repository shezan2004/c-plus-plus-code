#include <stdio.h>
int main() {
    char str[100];
    int i = 0, isValid = 1;

    printf("Enter an identifier: ");
    scanf("%s", str);

    // Check first character
    if (!((str[0] >= 'a' && str[0] <= 'z') ||
          (str[0] >= 'A' && str[0] <= 'Z') ||
           str[0] == '_')) {
        isValid = 0;
    }
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= '0' && str[i] <= '9') ||
               str[i] == '_')) {
            isValid = 0;
            break;
        }
        i++;
    }
    if (isValid == 1) {
        printf("Valid identifier\n");
    } else {
        printf("Not a valid identifier\n");
    }

    return 0;
}
