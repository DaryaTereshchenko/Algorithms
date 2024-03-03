#include <stdio.h>

int main(){
  int n = 5;
  int A[] = {11, 1, 4, -3, 22};

  int pos1 = 0;
  int temp1 = A[pos1];
  int pos2;
  int temp2;

  for(int i = 0; i < n; i++){
    if(A[i] > temp1){
      temp1 = A[i];
      temp2 = temp1;
    } else if (A[i] > temp2 && A[i] < temp1){
      temp2 = A[i];
    }
    printf("%d\n", temp2);
  }
}