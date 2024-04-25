#include <stdio.h>
#include <string.h>

int countOcurrances(int Arr[], int num, int n){
    int count = 0;

    for (int i = 0; i <= n; i++){
        if (Arr[i] == num){
            count ++;
        }
    }
    return count;
}


// Find the majority element using recursion 
int findMajorityUtil(int Arr[], int low, int high){
    // base case -> single element 
    if (low == high){
        return Arr[low];
    }
    //find the mid point 
    int mid = (low + high) / 2;

    int left_majority = findMajorityUtil(Arr, low, mid);
    int right_majority = findMajorityUtil(Arr, mid + 1, high);

    //If left and right parts have the same majority element 
    if (left_majority == right_majority){
        return left_majority;
    }

    // count the occurances of the majority element in both arrays 
    int left_count = countOcurrances(Arr, left_majority, high-low+1);
    int right_count = countOcurrances(Arr, right_majority, high-low+1);

    if (left_count > (high-low+1) / 2 ){
        return left_majority;
    }
    else if (right_count > (high-low+1) / 2){
        return right_majority;
    }
    return -1;
}

void findMajority(int arr[], int n) {
    int majority = findMajorityUtil(arr, 0, n-1);
    if (majority != -1)
        printf("%d\n", majority);
    else
        printf("No Majority Element\n");
}
 
int main() {
    int arr[] = {1, 3, 3, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    findMajority(arr, n);
 
    return 0;
}