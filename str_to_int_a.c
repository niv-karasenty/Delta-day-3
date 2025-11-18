#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int number;
    char *str;

    printf("Enter a number: ");
    scanf("%s", str);

    if (number = atoi(str)) {
        printf("The number is %d\n", number + 36);
    }
    else {
        printf("The string is not a number\n");
    }
    return 0;
}