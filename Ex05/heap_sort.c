#include <stdio.h>
#include <string.h>

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int controlMaxHeap(int array[], int currentIndex, int length){
    int left_child = (currentIndex * 2) + 1;
    int right_child = (currentIndex * 2) + 2;

    if (left_child < length){
        if (array[left_child] > array[currentIndex]){
            return currentIndex;
        }
        int LeftViolation = controlMaxHeap(array, left_child, length);
        if (LeftViolation != -1){
            return LeftViolation;
        }
    }
    if (right_child < length){
        if (array[right_child] > array[currentIndex]){
            return currentIndex;
        }
        int RightViolation = controlMaxHeap(array, right_child, length);
        if (RightViolation != -1){
            return RightViolation;
        }
    }
    return -1;
    }


void heapify(int array[], int currentIndex, int length){
    int largest = currentIndex;
    int right = (2 * currentIndex) + 2;
    int left = (2 * currentIndex) + 1;

    if (left < length && array[left] > array[largest]){
        largest = left;
    }
    if (right < length && array[right] > array[largest]){
        largest = right;
    }
    if (largest != currentIndex){
        int temp = array[largest];
        array[largest] = array[currentIndex];
        array[currentIndex] = temp;
        heapify(array, largest, length);
        printArray(array, length);
    }
}

void fixHeap(int array[], int length){
    int index = controlMaxHeap(array, 0, length);
    while (index != -1) {
        heapify(array, index, length);
        index = controlMaxHeap(array, 0, length);
    }
}

void insertValue(int array[], int val, int length){
    length++;
    array[length - 1] = val;

    int index = length - 1;

    while (index > 0 && array[index] > array[(index - 1) / 2]){
        int temp = array[(index - 1) / 2];
        array[(index - 1) / 2] = array[index];
        array[index] = temp;

        index = (index - 1) / 2;
    }
   printArray(array, length);
}

int main(){
    int A[] = {4, 10, 3, 5, 1};
    int n = sizeof(A) / sizeof(A[0]);

    int array1[] = {5,5,3,2,1,3};
    int larray1 = sizeof(array1) / sizeof(array1[0]);

    int res = controlMaxHeap(array1, 0, larray1);
    //printf("%d", res);
    //printf("\n");

    //fixHeap(array1, larray1);

    insertValue(array1, 6, larray1);

    return 0;

}
