#include <stdio.h>
#include <string.h>

int maxOverlap(int Arr[], int low, int mid, int high){
    int leftSum = 0;
    int rightSum = 0;

    int left = -9999;
    int right = -9999;

    for (int i = mid; i >= low; i--){
        leftSum += Arr[i];
        if (leftSum > left){
            left = leftSum;
        }
    }
    for (int j = mid + 1; j <= high; j ++){
        rightSum += Arr[j];
        if (rightSum > right){
            right = rightSum;
        }
    }
    return right + left;
}


int maxSum(int Arr[], int low, int high){
    if (low == high){
        return Arr[low];
    }

    int mid = (low + high) / 2;

    int left_sum = maxSum(Arr, low, mid);
    int right_sum = maxSum(Arr, mid + 1, high);
    int overlap = maxOverlap(Arr, low, mid, high);

    if (left_sum > overlap && left_sum > right_sum){
        return left_sum;}
    else if (right_sum > overlap && right_sum > left_sum){
        return left_sum;}
    else{return overlap;}
}

void print_array(int Arr[], int n){
    for(int i = 0; i < n-1; i++){
        printf("%d, ", Arr[i]);
    }
    printf("%d", Arr[n-1]);
}

int main(){
    int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;

    int max_sum = maxSum(A, 0, n-1);
    
    printf("The sum of the maximum subarray in array A = [");
    print_array(A, n);
    printf("] is %d.", max_sum);
    return 0;

}