#include <stdio.h>

void InsertionSort(int array[], int length) {
    int temp;
    for (int i = 1; i < length; i++) {
        temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp < array[j]){
            array[j + 1] = array[j];
            j --;
            }
        array[j+1] = temp;
        }
    }


int main() {
    int array[] = {5, 10, 3, 6, 4, 8};
    int length = sizeof(array) / sizeof(array[0]);

    // Call bubbleSort function
    InsertionSort(array, length);

    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
