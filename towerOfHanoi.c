#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        // Base case: only one disk, move directly
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move the nth (largest) disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Step 3: Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    // Input number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the recursive function
    printf("\nSteps to solve Tower of Hanoi for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C'); // A = source, B = auxiliary, C = destination

    return 0;
}
