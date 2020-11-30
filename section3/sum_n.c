#include<stdio.h>

int sum_n(int n){
    if (n>0){
        return sum_n(n-1)+n;
    }
    else {
        return 0;
    }
}

int iterative_sum(int n){
    int s=0;
    int i;
    for (i=1; i<=n;i++){
        s = s+i;
    }
        
    return s;
}


int main(){
    int r, ri;
    int n = 400;
    r = sum_n(n);
    ri = iterative_sum(n);
    printf("The recursive sum of %d first numbers: %d. \n", n, r);
    printf("The iterative sum of %d first numbers: %d. ", n, ri);
    return 0;
}