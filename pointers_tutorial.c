#include <stdio.h>
void swap(int *a, int*b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//arguments passed by value in C (by default)

int main(){
    int a;
    int b;

    a = 42;
    b = 56;

    //change_value(&nb);
    printf("a->%d\tb->%d\n", a, b);
    swap(&a, &b);
    printf("a->%d\tb->%d\n", a, b);
    return 0;
}


// Declaration tells me 'how to use': int n;
//To get an int just dereference n: int *n; 

