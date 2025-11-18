#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Creating a new type for easier use of the types we are classifying
enum ArrayType {
    INCREASING = 1,
    DECREASING = 2,
    CONSTANT = 3,
    MESSED_UP = 4
};

int main () {
    int num_array[15] = {};
    int type;
    for (int i = 0; i < 15; i++) {
        // Input of a new element
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num_array[i]);

        // checking the input and classifying the array type
        if (i == 0) {
            continue;
        }
        else if (i == 1) {
            if (num_array[0] < num_array[1]) {
                type = INCREASING;
            }
            if (num_array[0] > num_array[1]) {
                type = DECREASING;
            }
            if (num_array[0] == num_array[1]) {
                type = CONSTANT;
            }
        }
        else {
            // in each case of the current input we check if it stays or changes
            switch (type) {
                case INCREASING:
                    if (num_array[i] < num_array[i - 1]) {
                        type = MESSED_UP;
                    }
                    break;
                case DECREASING:
                    if (num_array[i] > num_array[i - 1]) {
                        type = MESSED_UP;
                    }
                    break;
                // Special case because it can still become increasing or decreasing
                case CONSTANT:
                    if (num_array[i] < num_array[i - 1]) {
                        type = DECREASING;
                    }
                    else if (num_array[i] > num_array[i - 1]) {
                        type = INCREASING;
                    }
                default:
                    break;
            }
        }
    }

    // printing the type of the array
    switch (type) {
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