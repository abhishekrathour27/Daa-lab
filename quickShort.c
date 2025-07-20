#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Partition function for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choosing last element as pivot
    int i = low - 1; // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // place pivot at correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // pivot index

        // Recursively sort left and right of pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[10000], n;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Generate random array
    srand(time(NULL));
    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 to 999
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Time before sorting
    start = clock();

    quickSort(arr, 0, n - 1); // Call quicksort

    // Time after sorting
    end = clock();

    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print time taken
    printf("Time taken to sort %d elements: %.2f milliseconds\n", n, time_taken);

    return 0;
}
