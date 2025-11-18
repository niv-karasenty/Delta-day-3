#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum ArrayType {
    INCREASING = 1,
    DECREASING = 2,
    CONSTANT = 3,
    MESSED_UP = 4
};

int determine_array_type(int num_array[]) {
    int array_type;
    if (num_array[0] < num_array[1]) {
        array_type = INCREASING;
    }
    else if (num_array[0] > num_array[1]) {
        array_type = DECREASING;
    }
    else if (num_array[0] == num_array[1]) {
        array_type = CONSTANT;
    }
    else {
        return 0;
    }

    for (int i = 2; i < sizeof(num_array)/sizeof(int); i++) {
        if (num_array[i] < num_array[i - 1] && array_type != INCREASING) {
            return MESSED_UP;
        }
        else if (num_array[i] > num_array[i - 1] && array_type != DECREASING) {
            return MESSED_UP;
        }
        else if (num_array[i] == num_array[i - 1] && array_type != CONSTANT) {
            return MESSED_UP;
        }
    }
    return array_type;
}

int main () {
    int num_array[15] = {};
    for (int i = 0; i < 15; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num_array[i]);
    }

    switch (determine_array_type(num_array)) {
        case INCREASING:
            printf("Increasing array\n");
            break;
        case DECREASING:
            printf("Decreasing array\n");
            break;
        case CONSTANT:
            printf("Constant array\n");
            break;
        case MESSED_UP:
            printf("Meased up array\n");
            break;
        default:
            printf("Invalid array type\n");
            break;
    }

    return 0;
}