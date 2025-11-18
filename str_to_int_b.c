#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
    int number = 0, temp;
    char str[100];
    char * ptr = str;

    printf("Enter a number: ");
    fgets(str, 100, stdin);

    while (*ptr != '\0' && *ptr != '\n') {
        if (!isdigit(*str)) {
            printf("The number is invalid.\n");
            return 1;
        }
        else {
            temp = *ptr - '0';
            number *= 10;
            number += temp;
        }
        ptr = ptr + 1;
    }

    printf("The number is %d\n", number);

    return 0;
}