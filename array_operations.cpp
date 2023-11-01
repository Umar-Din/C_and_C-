#include<iostream>
#include<stdlib.h>
using namespace std;


// structure
struct  Array
{
    int* A;
    int length;
    int size;
};

//global swap function
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = *x;
}

bool length(struct Array arr){
    if(arr.length==0){
        return false;
    }
    return true;
}

//creating array
void create(struct Array* arr){
    arr->A = (int *)malloc(10*sizeof(int));
    arr->size = 10;
    int list[5] = {10,20,30,40,50};
    for(int i=0;i<5;i++){
        arr->A[i] = list[i];
    }
    
    arr->length = 5;
}
//display array elements
void display(struct Array arr){
    if(length(arr)==false){
        return;
    }
    
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<endl;
    }
    return;
}

// append the element at end
int append(struct Array* arr, int value){
    if(arr->size==arr->length){
        return -1;
    }
    arr->A[arr->length] = value;
    arr->length ++;
    return value;
}

//pop the element at last
int pop(struct Array* arr){
    if(arr->length==0 && arr->size==0){
        return -1;
    }
    int temp = arr->A[arr->length];
    arr->A[arr->length] = 0;
    arr->length--;
    return temp;
}

//remove at index 
int remove(struct Array* arr, int index){
    if(index>=arr->length || index>0){
        return -1;
    }
    int temp = arr->A[index];
    int i = index;
    for(i;i<arr->length-1;i++){
        arr->A[i]=arr->A[i+1];
        
    }
    arr->length--;
    return temp;
}

//add at specific index

void add(struct Array* arr, int index, int value){
    if(index>=arr->size || index>arr->length){
        return;
    }
    int i= arr->length-1;
    for(i;i>index;i--){
        arr->A[i+1]=arr->A[i]; 
    }
    arr->A[index] = value;
    arr->length++;
    return;
}
//sum of the array elements

float sum(struct Array arr){
    if(length(arr)==false){
        return 0;
    }
    float sum = 0;
    for(int i=0; i<arr.length; i++){
        sum+=i;
    }
    return sum;
}

//min value in array

int min(struct Array arr){
    if(length(arr)==false){
        return;
    }
    int min = arr.A[0];
    for(int i=1; i<arr.length;i++){
        if(min>arr.A[i]){
            swap(&min,&arr.A[i]);
        }
    }
    return min;
}

//max value in array

int max(struct Array arr){
    if(length(arr)==false){
        return;
    }
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(max<arr.A[i]){
            swap(&max,&arr.A[i]);
        }
    }
    return max;
}

//average of array elements

float average(struct Array arr){
    if(length(arr)==false){
        return;
    }
    float avg = 0;
    avg = sum(arr)/arr.length;
}

// main function
int main(){
    struct Array arr;
    create(&arr);
    // pop(&arr);
    // append(&arr, 60);
    // remove(&arr,0);
    // add(&arr,1,100);
    display(arr);

    return 0;
}