#include<stdio.h>

int recursive_factorial(int n){
    if (n>0){
        return recursive_factorial(n-1)*n;
    }
    else {
        return 1;
    }
}

int iterative_factorial(int n){
    int i, f=1;
    for (i=1; i<=n; i++){
        f = f*i;
    }
    return f;
}

int main(){
    int r, ri;
    r = recursive_factorial(5);
    ri = iterative_factorial(5);
    printf("%d \n", r);
    printf("%d \n", ri);
}