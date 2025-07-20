#include <stdio.h>

// Recursive function to find binomial coefficient C(n, k)
int binomialCoeff(int n, int k) {
    // If k > n, it's invalid
    if (k > n)
        return 0;

    // Base cases
    if (k == 0 || k == n)
        return 1;

    // Recursive formula
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

int main() {
    int n = 5, k = 2;

    printf("Value of C(%d, %d) is %d\n", n, k, binomialCoeff(n, k));

    return 0;
}
