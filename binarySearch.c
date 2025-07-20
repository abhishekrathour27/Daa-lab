#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary search function
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;  // Element found
        else if (a[mid] < key)
            low = mid + 1;  // Search in right half
        else
            high = mid - 1; // Search in left half
    }

    return -1; // Element not found
}

int main() {
    int a[100], n, key, res;
    clock_t start, end;
    double time_taken;

    // Input number of elements
    printf("Enter number of elements in sorted array: ");
    scanf("%d", &n);

    // Input elements (must be sorted for binary search)
    printf("Enter sorted elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input key to search
    printf("Enter the key element to search: ");
    scanf("%d", &key);

    // Measure time
    start = clock();
    res = binarySearch(a, n, key);
    end = clock();

    // Calculate time in milliseconds
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    // Output result
    if (res == -1)
        printf("The search element is not found.\n");
    else
        printf("The search element is found at position %d.\n", res + 1);

    printf("The execution time is: %.2f milliseconds\n", time_taken);

    return 0;
}
