#include <stdio.h>

#define ARRAY_SIZE 8

void print_int_by_array(int array[]) {
    printf("Printing int array by array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d, ", array[i]); // Printing by index in the array
    }
    printf("\n");
}

void print_int_by_ptr(int *ptr) {
    printf("Printing int array by pointer: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d, ", *(ptr + i)); // Printing by the pointer plus offset
    }
    printf("\n");
}

void print_int_array_address(int *ptr) {
    printf("Printing addresses of array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%p, ", (ptr + i)); // Printing addresses by not using *
    }
    printf("\n");
}

void print_char_by_array(char array[]) {
    printf("Printing char array by array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%c, ", array[i]); // printing by index in the array
    }
    printf("\n");
}

void print_char_array_by_ptr(char *ptr) {
    printf("Printing char array by pointer: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%c, ", *(ptr + i)); // Printing by the offset i
    }
    printf("\n");
}

void print_char_array_address(char *ptr) {
    printf("Printing char array address: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%p, ", ptr + i); // Printing addresses by not using * and still using the offset i
    }
    printf("\n");
}

int main() {
    int number_array[ARRAY_SIZE];
    int *number_ptr = number_array;
    char char_array[ARRAY_SIZE];
    char *char_ptr = char_array;

    // Get the inputs for the arrays
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter %d number: ", i+1);
        scanf("%d", &number_array[i]);
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter %d char: \n", i+1);
        scanf("\n%c", &char_array[i]);
    }

    printf("\n");

    // Going through the functions of printing
    print_int_by_array(number_ptr);
    print_char_by_array(char_array);
    print_int_by_ptr(number_ptr);
    print_char_array_by_ptr(char_ptr);
    print_int_array_address(number_ptr);
    print_char_array_address(char_ptr);

    return 0;
}