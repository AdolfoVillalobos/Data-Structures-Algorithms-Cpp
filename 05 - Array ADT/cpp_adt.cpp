#include<iostream>

#include<stdio.h>
#include<stdlib.h>


using namespace std;

class Array 
{
  private:
    int *A;
    int size;
    int length;
  public:
    Array() {
      size = 10;
      length = 0;
      A = new int[size];
    }
    Array(int sz) {
      size = sz;
      length = 0;
      A = new int[size];
    }
    ~Array()
    {
      delete []A;
    }

  void Display();
  void Append(int x);
  void Insert(int index, int x);
  int Delete(int index);
  void Swap(int *x, int *y);
  int LinearSearch( int key);
  int BinarySearch( int key);
  int Sum();
  float AVG();
  int Get(int index);
  void Set(int index, int x);
  int Min();
  int Max();
  void Reverse();
  void ShiftLeft();
  void ShiftRight();
  void InsertSorted(int x);
  int IsSorted();
   void Rearrange();
  Array* Merge(Array arr2);
  Array* Union(Array arr2);
  Array* Diff(Array arr2);
  Array* Inter(Array arr2);
};

void Array::Display() {
  int i;
  printf("Elements are: \n");
  for (i=0; i<length; i++){
    printf("%d ", A[i]);
  }
}

void Array::Append(int x){
  if (length<size){
    A[length++] = x;
  }
}

void Array::Insert(int index, int x) {
  int i;
  if (index>=0 && index<=length){
    for (i=length; i>index; i--){
      A[i] = A[i-1];
    }
    A[index] = x;
    length++;
  }
}

int Array::Delete(int index){
  int i, x;
  if (index >=0 && index < length){
    x = A[index]; 
    for (i=index; i< length-1; i++) {
      A[i] = A[i+1];
    }
    length--;
    return x;
  }
  return 0;
}


void Array::Swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int Array::LinearSearch( int key){
 int i;
 for (i=0; i< length; i++){
    if (key == A[i]) {
      Swap(&A[i], &A[i-1]);
      return i-1;
    }
 }
 return -1;
}
int Array::BinarySearch(int key){
  int l, mid, h;
  l = 0;
  h = length-1;
  while (l<= h) {
    mid = (l+h)/2;
    if (key==A[mid]){
      return mid;
    } else if (key > A[mid]){
      l = mid+1;
    } else {
       h = mid-1;
    }
  }
  return -1;
}


int Array::Sum(){
  int total=0;
  for (int i=0; i< length; i++){
    total = total+A[i];
  }
  return total;
}


float Array::AVG(){
  float total= 0;
  for (int i=0; i< length; i++) {
    total = total+A[i];
  }
  total = total/length;
  return total;
}

int Array::Get(int index){
  if (index>=0 && index < length){
    return A[index];
  }
  return -1;
}

void Array::Set(int index, int x){
  if (index>=0 && index < length){
    A[index] = x;
  }
}

int Array::Min(){
  int min = A[0];
  int i;
  for (i=1; i<length; i++){
    if (A[i]<min){
      min  = A[i];
    }
  }
  return min;
}
int Array::Max(){
  int max = A[0];
  int i;
  for (i=1; i<length; i++){
    if (A[i]>max){
      max = A[i];
    }
  }
  return max;
}

void Array::Reverse(){
  int i, j;
  int temp;
  for (i=0, j=length-1; i<j; i++, j--){
    Swap(&A[i], &A[j]);
  }
}

void Array::ShiftRight(){
  int i;
  for (i=length-1; i>= 0; i--){
    Swap(&A[i], &A[i+1]);
  }
  A[0] = 0;
}

void Array::ShiftLeft(){
  int i;
  for (i=0; i< length-1; i++){
    Swap(&A[i], &A[i+1]);
  }
  A[length-1] = 0;
}

void Array::InsertSorted(int x){
  int i=length-1; 
  if (length == size)
    return;
  while (A[i]>x && i>=0){
    A[i+1] = A[i];
    i--;
  }
  A[i+1] = x;
  length++;
}

int Array::IsSorted(){
  int i;
  for (i=0; i<length-1; i++){
    if (A[i]>A[i+1])
       return 0;
  }
  return 1;
}

void Array::Rearrange(){
 int i, j; 
 i = 0;
 j = length-1;
 while (i<j){
  while(A[i]< 0) i++;
  while (A[j]>0) j--;
  if (i<j)  Swap(&A[i], &A[j]);
 }
}

^//Array* Array::Merge(Array arr2){
^//  int i,j, k;
^//  i=j=k=0;
^//  Array * array3 = new Array(length+arr2.length);
^//  while (i < length && j < arr2.length){
^//    if (A[i] < arr2.A[j])
^//      arr3.A[k++] = A[i++];
^//    else
^//      arr3.A[k++] = arr2.A[j++];
^//  }
^//  for (; i<length; i++) {
^//    arr3.A[k++] = A[i];
^//  }
^//  for (; j<arr2.length; j++) {
^//    arr3.A[k++] = arr2.A[j];
^//  }
^//  arr3.length = length+arr2.length;
^//  arr3.size=20;
^//  return arr3;
^//}
^//
^//
^//
^//Array* Array::Union(Array arr2){
^//  int i, j, k;
^//  k=0;
^//  int search;
^//  Array* array3 = new Array(length+arr2.length);
^//
^//  for (i=0; i<length; i++){
^//    arr3.A[k++] = A[i];
^//    printf("%d \n", A[i]);
^//  }
^//  for (j=0; j< arr2.length; j++){
^//    search = arr2.BinarySearch(A[j]);
^//    if (search == -1){
^//      arr3->A[k++] = arr2.A[j];
^//    }
^//  }
^//  arr3.length = k;
^//  arr3.size = 20;
^//  return arr3;
^//}
^//
^//Array* Array::Inter(Array arr2{
^//  int i,  k;
^//  k=0;
^//  int search;
^//  Array *array3 = new Array(length+arr2.length);
^//
^//  for (i=0; i<length; i++){
^//
^//    search = arr2.BinarySearch(A[i]);
^//   if (search != -1){
^//    arr3.A[k++] = A[i];
^//   } 
^//
^//  }
^//  arr3.length = k;
^//  arr3.size = 20;
^//  return arr3;
^//}
^//
^//Array* Array::Diff(Array arr2){
^//  int i,  k;
^//  k=0;
^//  int search;
^//  Array *array3 = new Array(length+arr2.length);
^//
^//  for (i=0; i<length; i++){
^//
^//    search = arr2.BinarySearch(A[i]);
^//   if (search == -1){
^//    arr3.A[k++] = A[i];
^//   } 
^//
^//  }
^//  arr3.length = k;
^//  arr3.size = 20;
^//  return arr3;
^//}

int main(){

  Array *arr1;
  int x, index;
  int ch;

  printf(" Enter the size of the Array: \n");
  scanf("%d", &sz);

  arr1 = new Array(sz);
  do {
  printf("\n\n Menu\n\n");
  printf("1. Insert\n");  
  printf("2. Delete\n");  
  printf("3. Search\n");  
  printf("4. Sum\n");  
  printf("5. Display\n");  
  printf("6. Exit\n");  


  printf("\nEnter your choice: \n");
  scanf("%d", &ch);

  switch(ch){
    case 1:
      printf("Enter an element and index: \n");
      scanf("%d%d", &x, &index);
      Insert(&arr1, index, x);
      break;
    case 2:
      printf("Enter index: \n");
      scanf("%d", &index);
      x = Delete(&arr1, index);
      printf("Deleted element is %d: \n", x);
      break;
    case 3:
        printf("Enter element to search: \n");
        scanf("%d", &x);
        index = BinarySearch(arr1, x);
        printf("Element index: %d \n", index);
        break;
    case 4:
        printf("Sum is %d \n", Sum(arr1));
        break;
    case 5:
        Display(arr1);
  }
} while(ch<6);
  return 0;
}
