#include <stdio.h>
#include <time.h> // measuring run time
#include <math.h>


int algo1(int A[], int n, int k){
    int sum = 0;
    for (int i = 0; i <= k; i++){
        int maxi = i;
        for (int j = i; j < n; j++){
            if (A[j] > A[maxi]){
                maxi = j;
            }
        }
    sum = sum + A[maxi];
    int swp = A[i];
    A[i] = A[maxi];
    A[maxi] = swp;
    }
    return sum;
}

int main() {
    clock_t start, end;
    //int A[] = {5, 10, 3, 6, 4, 8};
    int length = sizeof(A) / sizeof(A[0]);
    int k = length / 2;
    int n = length;
    start = clock();
    printf("The sum of the array is %d\n", algo1(A, n, k)); 
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Also takes : %f millseconds\n", run_time); 
}