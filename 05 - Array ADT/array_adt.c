#include<stdio.h>
#include<stdlib.h>

// 
// Array Declaration:
//  - Declare in the stack 
//  - Declare in the heap

struct Array {
  int A[10];
  int size;
  int length;
};

void Display(struct Array arr) {
  int i;
  printf("Elements are: \n");
  for (i=0; i<arr.length; i++){
    printf("%d ", arr.A[i]);
  }
}

void Append(struct Array *arr, int x){
  if (arr ->length<arr->size){
    arr->A[arr->length++] = x;
  }
}

void Insert(struct Array *arr, int index, int x) {
  int i;
  if (index>=0 && index<=arr->length){
    for (i=arr->length; i>index; i--){
      arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = x;
    arr->length++;
  }
}

int Delete(struct Array *arr, int index){
  int i, x;
  if (index >=0 && index < arr->length){
    x = arr->A[index]; 
    for (i=index; i< arr->length-1; i++) {
      arr->A[i] = arr->A[i+1];
    }
    arr->length--;
    return x;
  }
  return 0;
}


void Swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int LinearSearch(struct Array *arr,  int key){
 int i;
 for (i=0; i< arr->length; i++){
    if (key == arr->A[i]) {
      Swap(&arr->A[i], &arr->A[i-1]);
      return i-1;
    }
 }
 return -1;
}
int BinarySearch(struct Array arr, int key){
  int l, mid, h;
  l = 0;
  h = arr.length-1;

  while (l<= h) {
    mid = (l+h)/2;

    if (key==arr.A[mid]){
      return mid;
    } else if (key > arr.A[mid]){
      l = mid+1;
    } else {
       h = mid-1;
    }
  }
  return -1;

}


int RBinarySearch(struct Array arr, int l, int h, int key){
  int  mid; 

  if (l<= h) {
    mid = (l+h)/2;

    if (key==arr.A[mid]){
      return mid;
    } else if (key > arr.A[mid]){
      return RBinarySearch(arr, mid+1, h, key);
    } else {
       return RBinarySearch(arr, l, mid-1, key);
    }
  }
  return -1;

}

int main(){

  struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
  
  printf("%d\n ", RBinarySearch(arr, 0, arr.length-1, 9));

  Display(arr);
  return 0;
}
