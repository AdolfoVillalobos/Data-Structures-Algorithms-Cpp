#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main(){

    // struct Rectangle r = {10, 5};

    // cout << r.length << endl;
    // cout << r.breadth << endl;

    // struct Rectangle *p=&r;

    // cout << p->length << endl;
    // cout << p->breadth << endl;

    struct Rectangle *p;
    //p = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // C dynamic memory allocation
    p = new Rectangle; // C++ dynamic memory allocation.
    p->length = 15;
    p->breadth = 7;

    cout << p->length << endl;
    cout << p->breadth << endl;
    cout << (*p).length <<endl;
    cout << (*p).breadth << endl;

    return 0;
}