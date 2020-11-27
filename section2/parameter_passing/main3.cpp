#include<iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

struct Test {
    int A[5];
    int n;
};

int area(struct Rectangle r){
    int a;
    a = r.length*r.breadth;
    return a;
}


void changeLength(struct Rectangle *r, int l){
    (*r).length = l;
}

void fun(struct Test t1){
    t1.A[0] = 10;
    t1.A[1] = 9;
}

struct Rectangle * fun2(){
    struct Rectangle *p;
    p = new Rectangle;

    p->breadth = 5;
    p->length = 7;

    return p;
}

int main(){

    struct Rectangle r={10, 5};
    struct Test t = {{2,3,4,5,6}, 10};

    cout << area(r) << endl;
    changeLength(&r, 20);
    cout << area(r) << endl;

    fun(t);

    for (int i=0; i<5; i++){
        cout << t.A[i] << endl;
    }

    struct Rectangle *ptr = fun2();
    cout << "Length: " << (*ptr).length << " " <<  "Breadth: " << (*ptr).breadth << endl;

    return 0;
}