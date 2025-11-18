#include <stdio.h>

const int ARRAY_LENGTH = 26;


// Convert from int array to char array
void to_char(int array[], char out[]) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        out[i] = (char)array[i];
    }
    return;
}


// Move all array items a certain number of times forward
void move_number_of_times(int array[], int times) {
    int help_array[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        // Moving forward using the modulo operation for going back to the start
        help_array[i] = array[(i + times) % ARRAY_LENGTH];
    }
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = help_array[i];
    }
    return;
}

// Adding a number to all items in the array
void add_number_to_array(int array[], int number) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] += number;
    }
    return;
}


// Divide all even numbers by a certain value
void divide_number_to_even(int array[], int number) {
    for (int i = 0; i < ARRAY_LENGTH; i+= 2) {
        array[i] /= number;
    }
    return;
}

// reverse the operation that adds to each cell the cell before it
void reverse_last_cell_added(int array[]) {
    for (int i = 1; i < ARRAY_LENGTH; i++) {
        array[i] -= array[i - 1];
    }
    return;
}

// Switches the two halves of the array around the middle
void switch_halves(int array[]) {
    int help_array[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH/2; i++) {
        help_array[i] = array[i + ARRAY_LENGTH/2];
    }
    for (int i = ARRAY_LENGTH/2; i < ARRAY_LENGTH; i++) {
        help_array[i] = array[i - ARRAY_LENGTH/2];
    }
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = help_array[i];
    }
    return;
}

// Combining all the operations needed into one function
void reverse(int array[]) {
    switch_halves(array);
    reverse_last_cell_added(array);
    move_number_of_times(array, 5);
    divide_number_to_even(array, 7);
    move_number_of_times(array, ARRAY_LENGTH - 6);
    add_number_to_array(array, -5);
}

int main () {
    int input_array[ARRAY_LENGTH];
    char out[ARRAY_LENGTH];

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("Input number %d: ", i + 1);
        scanf("%d", &input_array[i]);
    }

    reverse(input_array);
    to_char(input_array, out);

    // Printing the message
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%c", out[i]);
    }

    return 0;
}