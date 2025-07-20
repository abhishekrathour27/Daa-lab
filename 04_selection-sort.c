#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void generate_random_numbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int n = 5; // Change this value to test different sizes
    int arr[n];
    
    generate_random_numbers(arr, n);
    
    printf("Original array:\n");
    print_array(arr, n);
    
    clock_t start = clock();
    selection_sort(arr, n);
    clock_t end = clock();
    
    printf("Sorted array:\n");
    print_array(arr, n);
    
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);
    
    return 0;
}
