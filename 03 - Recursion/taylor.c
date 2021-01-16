#include<stdio.h>


double taylor(float x, int n){
    static double p=1, f=1;
    double r;
    if (n==0){
        return 1;
    }
    else {
        r = taylor(x, n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }
}

int main(){
    int x=4, n=30;
    double e;
    e = taylor(x, n);
    printf("%lf ", e);

}