#include <stdio.h>
#include <time.h> // measuring run time
#include <math.h>

int n, t;
int A[100000000];

int whatDoesitDo(int A[], int n, int t){
    int result = -1000;
    for (int i = 0; i < n; i++){
        int current = 0;
        for (int j = i; j < n;){j = j + t; current = current + A[j];}
        if (current > result){result = current;}
    }
    return result;
}

int main() {
    clock_t start, end;
    printf("Enter an integer for n: ");
    scanf("%d", &n); 
    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    printf("Enter an integer for t: \n");
    scanf("%d", &t); 
    start = clock();
    whatDoesitDo(A, n, t); // your implementation
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("whatDoesitDo takes : %f millseconds\n", run_time); 
}