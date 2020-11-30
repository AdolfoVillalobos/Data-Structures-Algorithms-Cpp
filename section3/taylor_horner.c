#include<stdio.h>


double e(int x, int n){
    static double s=1;
    if (n==0){
        return s;
    }
    else{
        s= 1+(x*s/n);
        return e(x, n-1);
    }
}

double ei(int x, int n){
    double s= 1;
    double r;
    for (; n>0; n--){
        r = ((double)x/(double)n);
        s = 1.0+r*s;
    }
    return s;
}

int main(){
    double r;
    r = e(1, 20);
    printf("%lf ", r);
}