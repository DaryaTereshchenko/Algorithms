#include <stdio.h>

int zeroSubarray(int array[], int length){
    for (int i = 0; i < length; i++){
        if (array[i] == 0) {
            return 1;
        }
        for (int j = i; j < length; j++){
            if ((array[i] + array[j]) == 0){
                return 1;
            } 
        } 
    }
    return 0;
}


int main(){
    int array[] = {3, -2, 4, 2, 1, -5};
    int length = sizeof(array) / sizeof(array[0]);
    
    // Call zeroSubarray function and store the result
    int result = zeroSubarray(array, length);

    // Print the result
    printf("Result: %d\n", result);
    return 0;
}