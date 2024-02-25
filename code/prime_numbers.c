#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* prime_numbers(int n) {
    bool* array = (bool*)malloc((n + 1) * sizeof(bool));

    // Initialize all elements of the array to true
    for (int i = 0; i <= n; ++i) {
        array[i] = true;
    }
    array[0] = false;
    array[1] = false;

    // Mark non-prime numbers as false
    for (int i = 2; i <= n / 2; ++i) {
        for (int j = 2; j <= n / i; ++j) {
            array[i * j] = false;
        }
    }

    return array;
}

int main() {
    int n = 15;
    bool* primes = prime_numbers(n);
    printf("Prime numbers between 0 and %d are: ", n);
    for (int i = 0; i <= n; ++i) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(primes); // Free allocated memory
    return 0;
}
