#include <stdio.h>

void bubbleSort(int array[], int length) {
    int temp;
    for (int i = length - 1; i > 0; i--) {
        for (int j = 1; j < i + 1; j++) {
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

int main() {
    int array[] = {5, 10, 3, 6, 4, 8};
    int length = sizeof(array) / sizeof(array[0]);

    // Call bubbleSort function
    bubbleSort(array, length);

    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
