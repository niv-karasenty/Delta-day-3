#include <stdio.h>
#define ARRAY_SIZE (10)

// Printing an array of numbers
void print_arrays_with_addresses(int* array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Address: %p, value: %d \n", array[i], *array[i]);
    }
}

// Initializing the pointer array to point at the matching items in the numbers array
void initialize_ptr_array(int* ptr_array[], int num_array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr_array[i] = &num_array[i];
    }
}

// Swapping the values of 2 pointers
void swap(int* ptr_array[], int index_1, int index_2) {
    int *temp = ptr_array[index_1];
    ptr_array[index_1] = ptr_array[index_2];
    ptr_array[index_2] = temp;
}

// Organizing the array by finding the biggest number, then putting it first
// To overcome the problem of not wanting to touch the first array, we will only look at the numbers by the pointers array and if we have checked one and it's the biggest we will not check it again
// Of course there are faster ways to sort an array, but this is not the heart of the problem
void organize_ptr_array(int* ptr_array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = i+1; j < ARRAY_SIZE; j++) {
            if (*ptr_array[j] < *ptr_array[i]) {
                swap(ptr_array, i, j);
            }
        }
    }
}

int main() {
    int num_array[ARRAY_SIZE];
    int *ptr_array[ARRAY_SIZE];

    // Initializing pointer array
    initialize_ptr_array(ptr_array, num_array);

    // Input from user
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter %d number: ", i+1);
        scanf("%d", &num_array[i]);
    }

    print_arrays_with_addresses(ptr_array);

    printf("\nSorting pointers array...\n\n");

    // Sorting the array
    organize_ptr_array(ptr_array);

    // Printing the addresses and values
    print_arrays_with_addresses(ptr_array);

    return 0;
}