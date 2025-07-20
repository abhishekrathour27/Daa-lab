#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear search function
int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key)
            return i;  // Element found at index i
    }
    return -1; // Element not found
}

int main() {
    int a[100], n, key, res;
    clock_t start, end;
    double time_taken;

    // Input size of array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input the key to search
    printf("Enter the key element to search: ");
    scanf("%d", &key);

    // Measure time before and after search
    start = clock();
    res = linearSearch(a, n, key);
    end = clock();

    // Calculate time taken in milliseconds
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    // Output results
    if (res == -1) {
        printf("The search element is not found.\n");
    } else {
        printf("The search element is found at position %d.\n", res + 1);
    }

    printf("The execution time is: %.2f milliseconds\n", time_taken);

    return 0;
}
