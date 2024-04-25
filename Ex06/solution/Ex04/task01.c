#include <stdio.h>
#include <time.h> // measuring run time
#include <math.h>


int closestNumber(int A[], int t, int n){
    int l = 0;
    int r = n - 1;
    int m;
    
    
    while (l < r){
        m = l + (r - l) / 2;
        if (A[m] == t){return A[m];}
        if (abs(A[m] - t) < abs(A[m + 1] - t)){
            r = m;}
        else{l = m + 1;}
    }
    return A[m];
}

int main()
{
    int a[]
        = {0, 5, 8, 9, 13, 17, 45, 67};
    int n = sizeof(a) / sizeof(a[0]);

    printf("The closest number is %d\n", closestNumber(a, 7, n));
    return 0;
}