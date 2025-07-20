#include <stdio.h>

int main() {
    float a[100], sum = 0, x;
    int n, i;

    // Input degree of the polynomial
    printf("Enter degree of the polynomial: ");
    scanf("%d", &n);

    // Input coefficients from highest degree to constant term
    printf("Enter coefficients of the polynomial:\n");
    for (i = n; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%f", &a[i]);
    }

    // Input value of x
    printf("Enter the value of x: ");
    scanf("%f", &x);

    // Evaluate polynomial using Horner's Rule
    for (i = n; i > 0; i--) {
        sum = (sum + a[i]) * x;
    }
    sum = sum + a[0];

    // Print result
    printf("Value of the polynomial = %.2f\n", sum);

    return 0;
}
