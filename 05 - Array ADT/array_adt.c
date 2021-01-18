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


int Sum(struct Array arr){
  int total=0;
  for (int i=0; i< arr.length; i++){
    total = total+arr.A[i];
  }
  return total;
}


float AVG(struct Array arr){
  float total= 0;
  for (int i=0; i< arr.length; i++) {
    total = total+arr.A[i];
  }
  total = total/arr.length;
  return total;
}

int Get(struct Array arr, int index){
  if (index>=0 && index < arr.length){
    return arr.A[index];
  }
  return -1;
}

void Set(struct Array *arr, int index, int x){
  if (index>=0 && index < arr->length){
    arr->A[index] = x;
  }
}

int Min(struct Array arr){
  int min = arr.A[0];
  int i;
  for (i=1; i<arr.length; i++){
    if (arr.A[i]<min){
      min  = arr.A[i];
    }
  }
  return min;
}
int Max(struct Array arr){
  int max = arr.A[0];
  int i;
  for (i=1; i<arr.length; i++){
    if (arr.A[i]>max){
      max = arr.A[i];
    }
  }
  return max;
}

void Reverse(struct Array *arr){
  int i, j;
  int temp;
  for (i=0, j=arr->length-1; i<j; i++, j--){
    Swap(&arr->A[i], &arr->A[j]);
  }
}

void ShiftRight(struct Array *arr){
  int i;
  for (i=arr->length-1; i>= 0; i--){
    Swap(&arr->A[i], &arr->A[i+1]);
  }
  arr->A[0] = 0;
}

void ShiftLeft(struct Array *arr){
  int i;
  for (i=0; i< arr->length-1; i++){
    Swap(&arr->A[i], &arr->A[i+1]);
  }
  arr->A[arr->length-1] = 0;
}

void InsertSorted(struct Array *arr, int x){
  int i=arr->length-1; 
  if (arr->length == arr->size)
    return;
  while (arr->A[i]>x && i>=0){
    arr->A[i+1] = arr->A[i];
    i--;
  }
  arr->A[i+1] = x;
  arr->length++;
}

int isSorted(struct Array arr){
  int i;
  for (i=0; i<arr.length-1; i++){
    if (arr.A[i]>arr.A[i+1])
       return 0;
  }
  return 1;
}

void Rearrange(struct Array *arr){
 int i, j; 
 i = 0;
 j = arr->length-1;
 while (i<j){
  while(arr->A[i]< 0) i++;
  while (arr->A[j]>0) j--;
  if (i<j)  Swap(&arr->A[i], &arr->A[j]);
 }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2){
  int i,j, k;
  i=j=k=0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  
  while (i < arr1->length && j < arr2->length){
    if (arr1->A[i] < arr2->A[j])
      arr3->A[k++] = arr1->A[i++];
    else
      arr3->A[k++] = arr2->A[j++];
  }
  for (; i<arr1->length; i++) {
    arr3->A[k++] = arr1->A[i];
  }
  for (; j<arr2->length; j++) {
    arr3->A[k++] = arr2->A[j];
  }
  arr3->length = arr1->length+arr2->length;
  arr3->size=20;
  return arr3;
}


struct Array* UnionSorted(struct Array *arr1, struct Array *arr2){
  int i,j, k;
  i=j=k=0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  
  while (i < arr1->length && j < arr2->length){
    if (arr1->A[i] < arr2->A[j])
      arr3->A[k++] = arr1->A[i++];
    else if (arr1->A[i] >  arr2->A[j])
      arr3->A[k++] = arr2->A[j++];
    else {
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }
  for (; i<arr1->length; i++) {
    arr3->A[k++] = arr1->A[i];
  }
  for (; j<arr2->length; j++) {
    arr3->A[k++] = arr2->A[j];
  }
  arr3->length = k;
  arr3->size=20;
  return arr3;
}

struct Array* Union(struct Array *arr1, struct Array *arr2){
  int i, j, k;
  k=0;
  int search;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  for (i=0; i<arr1->length; i++){
    arr3->A[k++] = arr1->A[i];
    printf("%d \n", arr1->A[i]);
  }
  for (j=0; j< arr2->length; j++){
    search = BinarySearch(*arr1, arr2->A[j]);
    if (search == -1){
      arr3->A[k++] = arr2->A[j];
    }
  }
  arr3->length = k;
  arr3->size = 20;
  return arr3;
}

struct Array* IntersectionSorted(struct Array *arr1, struct Array *arr2){
  int i,j, k;
  i=j=k=0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  
  while (i < arr1->length && j < arr2->length){
    if (arr1->A[i] < arr2->A[j])
      i++;
    else if (arr1->A[i] >  arr2->A[j])
      j++;
    else {
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }
  arr3->length = k;
  arr3->size=20;
  return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2){
  int i,  k;
  k=0;
  int search;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  for (i=0; i<arr1->length; i++){

    search = BinarySearch(*arr2, arr1->A[i]);
   if (search != -1){
    arr3->A[k++] = arr1->A[i];
   } 

  }
  arr3->length = k;
  arr3->size = 20;
  return arr3;
}


struct Array* DifferenceSorted(struct Array *arr1, struct Array *arr2){
  int i,j, k;
  i=j=k=0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  
  while (i < arr1->length && j < arr2->length){
    if (arr1->A[i] < arr2->A[j])
      arr3->A[k++] = arr1->A[i++];
    else if (arr1->A[i] >  arr2->A[j])
      j++;
    else {
      i++;
      j++;
    }
  }
  for (;i<arr1->length; i++){
    arr3->A[k++] = arr1->A[i];
  }
  arr3->length = k;
  arr3->size=20;
  return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2){
  int i,  k;
  k=0;
  int search;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  for (i=0; i<arr1->length; i++){

    search = BinarySearch(*arr2, arr1->A[i]);
   if (search == -1){
    arr3->A[k++] = arr1->A[i];
   } 

  }
  arr3->length = k;
  arr3->size = 20;
  return arr3;
}

int main(){

  struct Array arr1 = {{2,  6, 10, 15, 25}, 10, 5};
  struct Array arr2 = {{3, 6, 7, 15, 20  }, 10,5};
  struct Array *arr3;
 
  arr3 =  Difference(&arr1, &arr2);
  Display(*arr3);
  return 0;
}
