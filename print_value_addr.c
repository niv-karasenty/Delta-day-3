#include <stdio.h>

#define ARRAY_SIZE (8)

void print_int_by_array(int array[]) {
    printf("Printing int array by array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("The address: %p, value: %d \n", &array[i], array[i]); // Printing by index in the array
    }
    printf("\n");
}

void print_int_by_ptr(int *ptr) {
    printf("Printing int array by pointer: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("The address: %p, value: %d \n", (ptr+i), *(ptr + i)); // Printing by the pointer plus offset
    }
    printf("\n");
}

void print_char_by_array(char array[]) {
    printf("Printing char array by array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("The address: %p, value: %c \n", &array[i], array[i]); // printing by index in the array
    }
    printf("\n");
}

void print_char_array_by_ptr(char *ptr) {
    printf("Printing char array by pointer: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("The address: %p, value: %c \n", (ptr+i), *(ptr + i)); // Printing by the offset i
    }
    printf("\n");
}

void print_all(int *int_ptr, char *char_ptr, int num_array[], char char_array[]) {
    print_int_by_array(num_array);
    print_char_by_array(char_array);
    print_int_by_ptr(int_ptr);
    print_char_array_by_ptr(char_ptr);
}

int main() {
    int number_array[ARRAY_SIZE];
    int *number_ptr = number_array;
    char char_array[ARRAY_SIZE];
    char *char_ptr = char_array;

    // Get the inputs for the arrays
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter %d number: ", i+1);
        if (scanf("%d", &number_array[i]) != 1) {
            printf("Invalid input\n");
            return 1;
        }
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter %d char: \n", i+1);
        if (scanf("\n%c", &char_array[i]) != 1) {
            printf("Invalid input\n");
            return 1;
        }
    }

    print_all(number_ptr, char_ptr, number_array, char_array);

    printf("\n");


    return 0;
}