#include<stdio.h>

int recursive_power(int m, int n){
    if (n>0){
        if (n%2 == 0){
            return recursive_power(m*m, n/2);
        }
        else {
            return recursive_power(m*m, (n-1)/2)*m;
        }

    }
    else  {
        return 1;
    }
}

int iterative_power(int m, int n){
    int p=1, i;
    for (i=1; i<=n; i++){
        p = p*m;
    }
    return p;
}

int main(){
    int n =10;
    int m = 3;
    int r, ri;

    r= recursive_power(m, n);
    ri = iterative_power(m, n);

    printf("%d \n", r);
    printf("%d ", ri);
}