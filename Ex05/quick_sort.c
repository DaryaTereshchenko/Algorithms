#include <stdio.h>
#include <string.h>


void swap(int array[], int index1, int index2) {
    int tmp = array[index2];
    array[index2] = array[index1];
    array[index1] = tmp;
}


int counter = 0;

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


void quickSort(int array[], int leftIndex, int rightIndex){
    if (leftIndex < rightIndex){
        int pi = partition(array, leftIndex, rightIndex);

        quickSort(array, leftIndex, pi-1);
        quickSort(array, pi, rightIndex);
    }
}


int findMedian(int array[], int n){
    if (n % 2 == 0){
        int mid = (n - 1) / 2;
        return array[mid];
    } else{
        int right =  ((n - 1) / 2);
        int left = right + 1;
        printf("Left: %d", left);
        printf("Right: %d", right);
        float mid = (float)(array[left] + array[right]) / 2.0;
        return mid;
    }
}
int main() {
    int array[] = {6, 8, 4, 5, 3, 7, 2, 1, 0, 9};
    int n = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, n - 1);
    printf("Counter: %d \n", counter);
    for (int i = 0; i < n; i++) {
        printf("%d, ", array[i]);
    }
    float median = findMedian(array, n);
    printf("Median: %.2f \n", median);
    return 0;
}
