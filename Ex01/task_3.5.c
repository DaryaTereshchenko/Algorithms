#include <stdio.h>

void bubbleSort(int array[], int length) {
    int temp;
    for (int i = length - 1; i > 0; i--) {
        for (int j = 1; j < i + 1; j++) {
            if (array[j] < array[j - 1]) {
                // Swap array[j] and array[j + 1]
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

int main() {
    int length = 100000;
    bubbleSort(array, length);
    return 0;
}