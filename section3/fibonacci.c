#include<stdio.h>


int fib(int n) {
    if (n==0){
        return 0;
    } 
    else if (n==1){
        return 1;
    }
    else {
        return fib(n-2)+fib(n-1);
    }
}

int fibiter(int n){
    int t0=0, t1=1, s;
    if (n<=1) {
        return n;
    }
    else {
        for (int i=2; i<=n; i++){
            s = t0+t1;
            t0 = t1;
            t1 = s;
        }
        return s;
    }
}


int F[50];
int mfib(int n){
    if (n<=1){
        F[n] = n;
        return n;
    }
    else{
        if (F[n-2] == -1){
            F[n-2] = mfib(n-2);
        }
        if (F[n-1] == -1){
            F[n-1] = mfib(n-1);
        }
        F[n] = F[n-2]+F[n-1];
        return F[n-2]+F[n-1];
    }
}

int main(){
    for (int i=0; i<50; i++){
        F[i] = -1;
    }
    printf("%d " , mfib(13));
    return 0;
}