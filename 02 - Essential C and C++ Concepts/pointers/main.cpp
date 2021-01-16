#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


struct Rectangle {
    int length;
    int breath;
};

int main(){


    // Excercise 1
    // int a = 10;
    // int *p;  // Declaration of Pointer. Using * operator

    // p = &a; // Assign address to which p will point. Using & operator.

    // cout << a << endl;
    // cout << *p << endl;
    // cout << p << endl;



    // Excercise 2
    // int A[5] = {2, 4, 6, 8, 10}; // Array Created in Stack
    // int *p;
    
    // p = A;

    // A[2] = 45;

    // for (int i=0; i<5; i++){
    //     cout << p[i] << endl;
    // }

    // Excercice 3

//     int *p;

//    // p = (int *)malloc(5*sizeof(int)); // Array created in Heap. C
//     p = new int[5]; // Array Created in Heap. C++.

//     p[3] = 10;

//     for (int i=0; i<5; i++){
//         cout << p[i] << endl;
//     }

//     delete [] p; // Release memory in C++. Deallocation
//     //free(p); // Release memory in c

    // Excercice 4

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout <<sizeof(p1)<<endl;// Pointer size is indepejndent of data type.
    cout <<sizeof(p2)<<endl;
    cout <<sizeof(p3)<<endl;
    cout <<sizeof(p4)<<endl;
    cout <<sizeof(p5)<<endl;

    cout <<sizeof(*p1)<<endl;
    cout <<sizeof(*p2)<<endl;
    cout <<sizeof(*p3)<<endl;
    cout <<sizeof(*p4)<<endl;
    cout <<sizeof(*p5)<<endl;

    return 0;
}