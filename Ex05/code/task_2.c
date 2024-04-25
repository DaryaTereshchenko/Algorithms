#include "stdio.h"

int counter = 0;

void swap(int array[], int index1, int index2) {
    int tmp = array[index2];
    array[index2] = array[index1];
    array[index1] = tmp;
}

int partition(int arr[], int leftIndex, int rightIndex){
    int pivot = arr[rightIndex];

    int l = leftIndex - 1;
    int r = rightIndex + 1;

    while (1){
        // Find the value in the left side larger than pivot
         do{
            counter ++;
            l++;
         }while(arr[l] < pivot);

        // Find the value in the right side smaller than pivot 
        do{
            counter ++;
            r --;
        }while(arr[r] > pivot);

        // If two pointers meet 
        if (l >= r){
            return l;
        }
        swap(arr, l, r);
    }
}

void quicksort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int m = partition(array, leftIndex, rightIndex);
        quicksort(array, leftIndex, m - 1);
        quicksort(array, m, rightIndex);
    }
}

int main() {
    int array[] = {6, 8, 4, 5, 3, 7, 2, 1, 0, 9};
    int n = sizeof(array) / sizeof(array[0]);
    quicksort(array, 0, n - 1);
    printf("Counter: %d \n", counter);
    for (int i = 0; i < n; i++) {
        printf("%d, ", array[i]);
    }
    return 0;
}
