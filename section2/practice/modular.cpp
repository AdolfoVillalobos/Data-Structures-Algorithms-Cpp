#include<iostream>
#include<stdlib.h>

using namespace std;

class Rectangle {
public:
    int length;
    int breadth;

void initialise(int l, int b){
    length = l;
    breadth =b;
}

int area(){
    return length*breadth;
}

int perimeter(){
    return 2*(length+breadth);
}

};

int main(){
    
    Rectangle r;

    int l, b;
    printf("Enter Length and Breadth: \n");
    cin >> l >> b;

    r.initialise(l, b);
    int a =r.area();
    int peri = r.perimeter();

    printf("Area=%d, Perimeter=%d \n", a, peri);

}